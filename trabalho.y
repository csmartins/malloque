%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <list>

using namespace std;

struct Type {
  string name;
  int s;  // array size when attribute is an array.
  int s2; // 
  
  Type() {}
  Type( string name ) {
    this->name = name;
    this->s = 0;
    this->s2 = 0;
  }
};

struct Attribute {
  string v;  // Value
  Type   t;  // type
  string c;  // code
  list<Attribute> l; // List of related attributes.
  string d;  // variable declaration
  
  Attribute() {}  // automatic inicialization to empty ""
  Attribute( string v, string t = "", string c = "" ) {
    this->v = v;
    this->t.name = t;
    this->c = c;
  }
};

struct Function {
    string name;
    Type returnType; // "void" for void
    list<Attribute> parameterList;
    
    Function() { }
    
    Function(string name, Type returnType, list<Attribute> parameterList) {
        this->name = name;
        this->returnType = returnType;
        this->parameterList = parameterList;
    }
    
    Function(const Function &f) {
        this->name = f.name;
        this->returnType = f.returnType;
        this->parameterList = f.parameterList;
    }
};

typedef map< string, Type > TS;
TS ts;
TS tsl;

typedef map<string, Function> TF;
TF tf;

string activePipe; 
string activePipeStep; 

const int MAX_STR = 256;

void error(string msg);

string toStr( int n );
int parseInt( string s );
string trimId(string id);

string generateTemp(Type type);
string generateLabel( string cmd );
string generateTempDeclaration();
void resetTempVariables();
void initOperatorResultTable();
Type resultType( Type a, string op, Type b );
string getFormatStringForType(const Type &t);

void generateBinaryOperatorCode( Attribute* SS, const Attribute& S1, const Attribute& S2, const Attribute& S3 );
void generateUnaryOperatorCode(Attribute* SS, const Attribute& S1, const Attribute& S2);

void generateIfCodeWithElse( Attribute* SS, const Attribute& expr, const Attribute& cmdThen, const Attribute& cmdElse );
void generateIfCodeWithoutElse( Attribute* SS, const Attribute& expr, const Attribute& cmdThen );
void generateForCode( Attribute* SS, const Attribute& initial, const Attribute& condition, const Attribute& step, Attribute& cmd );
void generateWhileCode( Attribute* SS, const Attribute& expr, Attribute& cmd);
void generateDoWhileCode( Attribute* SS, Attribute& cmd, const Attribute& expr);
void generateSwitchCode(Attribute* SS, const Attribute& expr , Attribute& cases, const Attribute& defaultCase);
void generateCaseCode(Attribute* SS, const Attribute& intCase, Attribute& caseCode);
void generateFunctionCallWithParametersCode(Attribute* SS, const Attribute& id, const Attribute& params);
void generateFunctionCallWithoutParametersCode(Attribute* SS, const Attribute& id);

void generateAssignmentCode( Attribute* SS, Attribute& lvalue, const Attribute& rvalue );
void generateOutputCode(Attribute *SS, const Attribute &exp);
void generateInputCode(Attribute *SS, const Attribute &id);

void generateArrayCode(Attribute *SS, const Attribute& arrSize);
void generateBidimensionalArrayCode(Attribute *SS, const Attribute& arrSize1, const Attribute& arrSize2);

void insertVarTS( TS&, string nameVar, Type type );
bool searchVarTS( TS&, string nameVar, Type* type );
bool searchVar( string nameVar, Type* type );

void insertFuncTF(TF&, Function *f);
bool searchFuncTF(TF&, string nameFunc, Function* function);

void generateFunctionHeader(Attribute *SS,
                                 const Attribute& type,
                                 const Attribute& id,
                                 const Attribute& paramDecList);

void generateVarDeclaration( Attribute* SS, const Attribute& type, const Attribute& id );
void generateFunctionDeclaration(Attribute *SS,
                                 const Attribute& header,
                                 const Attribute& cmd);

void resetTempParameterList();
void addParamToParameterList(Attribute* SS, const Attribute& type, const Attribute& id);

void replaceBreakLabel(Attribute& block, string realLabel);

void generatePipeCode(Attribute* SS, const Attribute& start, const Attribute& end, const Attribute& pipes, const Attribute& consume);
void generateArrayPipeCode(Attribute* SS, const Attribute& id, const Attribute& pipes, const Attribute& consume);
void generateFilterCode( Attribute* SS, const Attribute& cond );
void generateFirstNCode( Attribute* SS, const Attribute& cond );

#define YYSTYPE Attribute

int yylex();
int yyparse();
void yyerror(const char *);
%}

%token _CTE_INT _CTE_CHAR _CTE_DOUBLE _CTE_FLOAT _CTE_BOOL _CTE_STRING _ID 
%token _IF _THEN _ELSE _RETURN _FOR _WHILE _DO _SWITCH _CASE _DEFAULT _BREAK
%token _FILTER _FIRST_N _FOR_EACH _LAST_N _SORT _RANGE _2PTS _PIPE _X
%token _INT _CHAR _BOOL _DOUBLE _FLOAT _STRING _CMD_OUT _CMD_IN _CMD_VAR _FUNCTION _BEGIN _END
%token _OPR_ATR _OPR_NOT _OPR_LESS_EQUAL _OPR_GREATER_EQUAL _OPR_COMP _OPR_AND _OPR_OR _OPR_DIF

%left _OPR_AND _OPR_OR
%nonassoc '<' '>' _OPR_LESS_EQUAL _OPR_GREATER_EQUAL _OPR_COMP _OPR_NOT _OPR_DIF
%left '+' '-'
%left '*' '/' '%'

%%

S1  : S { cout << "#include <stdio.h>\n"
               "#include <stdlib.h>\n"
               "#include <string.h>\n\n"
            << $1.d << $1.c << endl << "int main() {\nprincipal();\nreturn 0;\n}"; }
    ;

S : S FUNC_DECL { $$ = Attribute();
                  $$.c = $1.c + $2.c; 
                  $$.d = $1.d;
                }
                  
  | S VAR_GLOB ';' { $$ = Attribute();
                     $$.c = $1.c; 
                     $$.d = $1.d + $2.d;
                   }
                  
  | FUNC_DECL  { $$ = $1; }
  
  | VAR_GLOB ';' { $$ = $1; }
  ;

TYPE : _INT
     | _CHAR
     | _BOOL
     | _DOUBLE
     | _FLOAT
     | _STRING
     ;
     
ID : _ID { $$ = Attribute();
           $$.v = $1.v;
           searchVar($1.v, &($$.t));
         }
   | _ID '[' E ']' { Type idType;
                     searchVar($1.v, &idType);
                     
                     if ($3.t.name == "int") {
                         $$ = Attribute();
                         $$.c = $3.c;
                         $$.t.name = idType.name;
                         $$.v = $1.v + "[" + $3.v + "]";
                     } else {
                         error("Tipo do indice do array " + $1.v + " deve ser um int. Tipo encontrado: " + $3.t.name);
                     }
                     
                   }
   | _ID '[' E ']' '[' E ']' { Type idType;
                               Type typeInt = Type("int");
                               Attribute indexTemp1 = generateTemp(typeInt);
                               Attribute indexTemp2 = generateTemp(typeInt);
                               
                               searchVar($1.v, &idType);
                               $$ = Attribute();
                               //cout << toStr(idType.s2) << endl;
                               $$.c = $3.c + $6.c +
                                      indexTemp1.v + " = " + toStr(idType.s2) + " * " + $3.v + ";\n" + 
                                      indexTemp2.v + " = " + indexTemp1.v + " + " + $6.v + ";\n";
                               $$.t.name = idType.name;
                               $$.v = $1.v + "[" + indexTemp2.v + "]";
                             }
   ;

E : E '+' E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }   
  | E '-' E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }
  | E '*' E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }
  | E '/' E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }
  | E '%' E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }
  | E '<' E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }
  | E '>' E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }
  | E _OPR_LESS_EQUAL E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }
  | E _OPR_GREATER_EQUAL E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }
  | E _OPR_COMP E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }
  | E _OPR_DIF E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }
  | E _OPR_AND E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }
  | E _OPR_OR E { generateBinaryOperatorCode( &$$, $1, $2, $3 ); }
  | _OPR_NOT E {generateUnaryOperatorCode(&$$, $1, $2);}
  | F
  ;

F : FUNC
  | _X
    { if( activePipe != "" ){
        $$ = Attribute(); 
        $$.v = "x_" + activePipe;
        $$.t = Type(activePipe);
    }
      else
        error( "Variavel 'x' so pode ser usada dentro de pipe" );
      //cout << $$.c << " " << $$.t.name << " " << $$.v << endl;
    }
  | ID
      { $$ = $1;
	    if ($$.v.find("[", 0) != string::npos) {
		    Type idType;
    		searchVar(trimId($$.v), &idType);
    		Attribute valueTemp = generateTemp(idType);
    
    		$$.c += valueTemp.v + " = " + $$.v + ";\n";
    		$$.v = valueTemp.v;
	    }
      }
  | _CTE_INT
    {  $$.v = $1.v; 
       $$.t = Type( "int" ); }
  | _CTE_DOUBLE
    {  $$.v = $1.v; 
       $$.t = Type( "double" ); }
  | _CTE_FLOAT
    {  $$.v = $1.v; 
       $$.t = Type( "float" ); }
  | _CTE_CHAR
    {  $$.v = $1.v; 
       $$.t = Type( "char" ); }
  | _CTE_BOOL 
    {  $$.v = $1.v; 
       $$.t = Type( "bool" ); }
  | _CTE_STRING
    {  $$.v = $1.v; 
       $$.t = Type( "string" ); }
       
  | '(' E ')' { $$ = $2; }
  ;
  
PIPE : _RANGE '[' E _2PTS INIT_PIPE ']' PIPES CONSUME {
                                                       generatePipeCode(&$$, $3, $5, $7, $8.c);
                                                       }
     | PIPE_ARRAY PIPES CONSUME {
                            generateArrayPipeCode(&$$, $1, $2, $3);
                         }
     ;

PIPE_ARRAY: _ID 
             { $$ = $1;
               Type idType;
               searchVar($1.v, &idType);
               activePipe = idType.name;
               activePipeStep = generateLabel( "pipe" ); 
             }
          ;

PIPES : _PIPE {$$ = Attribute();}
      | _PIPE PIPE_FUNCTION PIPES { $$.c = $2.c + $3.c; $$.d = $2.d + $3.d;}
      ;

PIPE_FUNCTION : FILTER
              | FIRST_N
              | LAST_N
              | SORT
              ;
              
CONSUME : FOR_EACH { $$.c = $1.c; }
        ;
        
INIT_PIPE : E { $$ = $1;
                activePipe =  $1.t.name;
                //cout << activePipe << endl;
	            activePipeStep = generateLabel( "pipe" ); 
              }
	 ;    
          
FILTER : _FILTER '[' E ']' { generateFilterCode( &$$, $3 );}
       ;
             
FOR_EACH : _FOR_EACH '[' CMD ']' { $$.c = $3.c; }
         ;
         
FIRST_N : _FIRST_N '[' E ']' {generateFirstNCode(&$$, $3);}
        ;
        
LAST_N : _LAST_N '[' E ']'
       ;
       
SORT : _SORT '[' E ']'
     ;
      
FUNC : _ID '(' PARAMS ')' { generateFunctionCallWithParametersCode(&$$, $1, $3); }
     | _ID '(' ')' { generateFunctionCallWithoutParametersCode(&$$, $1); }
     ;

PARAMS : PARAMS ',' E 
            { $$ = $1;
              $$.c = $$.c + $3.c;
              $$.l.push_back($3);
            }
       | E 
            { $$ = Attribute();
              $$.c = $1.c;
              $$.l.push_back($1);
            }
       ;

FUNC_HEADER: _FUNCTION TYPE _ID '(' PARAM_DEC_LIST ')'
                {
                    generateFunctionHeader(&$$, $2, $3, $5);
                }
                
           | _FUNCTION _ID '(' PARAM_DEC_LIST ')' 
                {
                    Attribute v = Attribute();
                    v.t.name = "void";
                    generateFunctionHeader(&$$, v, $2, $4);
                }
           ;
  
FUNC_DECL: FUNC_HEADER '{' CMD '}' 
                {
                    generateFunctionDeclaration(&$$, $1, $3);
                }
           ;

PARAM_DEC_LIST  : PARAM_DEC { $$ = $1; }
                | /*producao vazia*/ { $$ = Attribute(); }
                ;

PARAM_DEC : PARAM_DEC ',' TYPE _ID
                                  { $$ = $1;
                                    addParamToParameterList(&$$, $3, $4);
                                    $$.v += ", " + $3.t.name + " " + $4.v;
                                  }
          | TYPE _ID
                    { $$ = Attribute();
                      addParamToParameterList(&$$, $1, $2);
                      $$.v = $1.t.name + " " + $2.v;
                    }
          ;

C : _BEGIN CMD _END { $$ = Attribute(); $$.c = $2.c; $$.d = $2.d; }
    | E ';' { $$.c = $1.c + $1.v + ";\n" ; }
    | VAR ';'
    | ATR ';'
    | OUT ';' 
    | IN ';' 
    | IF 
    | SWITCH 
    | FOR 
    | WHILE 
    | DO_WHILE ';' 
    | RETURN ';'
    | PIPE ';'
    | _BREAK ';' { $$ = Attribute(); $$.c = "goto BREAK_LABEL;\n"; }
    | ';' 
    ;

CMD : C CMD { $$ = Attribute(); $$.c = $1.c + $2.c; $$.d = $1.d + $2.d; }
    | { $$ = Attribute(); }
    ;
    
RETURN : _RETURN E { $$ = Attribute(); $$.c = $2.c + "return " + $2.v + ";"; }
       ;
    
VAR : VAR ',' VAR_DEC { $3.t.name = $1.t.name;
                        insertVarTS(tsl, trimId($3.v), $3.t);
                        generateVarDeclaration(&$$, $1, $3);
                        $$.c = $1.c + $3.c;
                      }
                      
    | _CMD_VAR TYPE VAR_DEC { $3.t.name = $2.t.name;
                              insertVarTS(tsl, trimId($3.v), $3.t);
                              generateVarDeclaration(&$$, $2, $3);
                              $$.t = $2.t;
                              $$.c = $3.c;
                            }
    ;
    
VAR_DEC : _ID VAR_INIC {$$ = Attribute();
                        $$.v = $1.v;
                        if($2.v != "")
                            $$.c = $2.c + $1.v + " = " + $2.v + ";\n";
                        }
        | ARR 
        ;
        
VAR_GLOB : VAR_GLOB ',' VAR_GLOB_DEC { insertVarTS(ts, $3.v, $1.t);
                                       generateVarDeclaration(&$$, $1, $3);
                                     }
                      
    | _CMD_VAR TYPE VAR_GLOB_DEC { insertVarTS(ts, $3.v, $2.t);
                                   generateVarDeclaration(&$$, $2, $3);
                                 }
    ;
    
VAR_GLOB_DEC : _ID { $$ = Attribute();
                     $$.v = $1.v;
                    }
             | ARR {$$ = Attribute();
                    $$.v = $1.v;
                    }
             ;
    
ARR : _ID '[' _CTE_INT ']' {generateArrayCode(&$$, $3);}
    | _ID '[' _CTE_INT ']' '[' _CTE_INT ']' { generateBidimensionalArrayCode(&$$, $3, $6); }
    ;
    
VAR_INIC : _OPR_ATR E { $$ = Attribute();
                        $$.v = $2.v;
                        $$.c = $2.c;
                      }
         | { $$ = Attribute(); }
         ;

ATR : ID _OPR_ATR E { generateAssignmentCode( &$$, $1, $3 ); }
    ;
    
OUT : _CMD_OUT E { generateOutputCode(&$$, $2);} 
    ;

IN : _CMD_IN ID { generateInputCode(&$$, $2); }
   ;
   
IF : _IF E _THEN C { generateIfCodeWithoutElse( &$$, $2, $4 ); }
   | _IF E _THEN C _ELSE C { generateIfCodeWithElse( &$$, $2, $4, $6 ); }
   ;
   
WHILE : _WHILE E C { generateWhileCode(&$$, $2, $3); }
      ;

DO_WHILE : _DO _BEGIN CMD _END _WHILE E { generateDoWhileCode( &$$, $3, $6 ); }
         ;
         
FOR : _FOR '(' ATR ';' E ';' ATR ')' C { generateForCode(&$$, $3, $5, $7, $9); }
    ;
    
SWITCH : _SWITCH '(' E ')' _BEGIN SWITCH_CASES DEFAULT_CASE _END {generateSwitchCode(&$$, $3 , $6, $7);}
       ;

SWITCH_CASES : CASE {$$.l.push_front($1); $$.c = $1.c;}
             | SWITCH_CASES CASE { $$.l.push_front($2); $$.c = $1.c + $2.c;}
             ;
             
CASE : _CASE _CTE_INT ':' CMD {generateCaseCode(&$$, $2, $4);}
     ;
     
DEFAULT_CASE : _DEFAULT ':' CMD {$$.c = $3.c;}
             | /* producao vazia */
             ; 

%%
int nline = 1;

map<string,int> n_var_temp;
map<string,Type> operatorResult;
map<string,int> label;

#include "lex.yy.c"

int yyparse();

string toStr( int n ) {
  char buf[1024] = "";
  
  sprintf( buf, "%d", n );
  
  return buf;
}

int parseInt( string s ) {
  int buf;
  
  sscanf( s.c_str() , "%d", &buf );
  
  return buf;
}

string trimId(string id) {
    int bracketPos = id.find_first_of("[");
    
    if (bracketPos == string::npos)
        return id;
    else
        return id.substr(0, bracketPos);
}


string generateLabel( string cmd ) {
  return "L_" + cmd +"_" + toStr( ++label[cmd] );
}

void yyerror( const char* st )
{
  puts( st );
    printf( "Linha: %d\nPerto de: '%s'\n", nline, yytext );
}

void error(string msg) {
    yyerror(msg.c_str());
}

void initOperatorResultTable() {
  operatorResult["string+string"] = Type( "string" );
  operatorResult["string+int"] = Type( "string" );
  
  operatorResult["int+int"] = Type( "int" );
  operatorResult["int-int"] = Type( "int" );
  operatorResult["int*int"] = Type( "int" );
  operatorResult["int%int"] = Type( "int" );
  operatorResult["int/int"] = Type( "int" );
  
  operatorResult["double+double"] = Type( "double" );
  operatorResult["double-double"] = Type( "double" );
  operatorResult["double*double"] = Type( "double" );
  operatorResult["double/double"] = Type( "double" );
  
  operatorResult["float+float"] = Type( "float" );
  operatorResult["float-float"] = Type( "float" );
  operatorResult["float*float"] = Type( "float" );
  operatorResult["float/float"] = Type( "float" );
  
  operatorResult["int==int"] = Type( "bool" );
  operatorResult["char==char"] = Type("bool");
  operatorResult["string==string"] = Type("bool");
  operatorResult["float==float"] = Type("bool");
  operatorResult["double==double"] = Type("bool");
  operatorResult["bool==bool"] = Type("bool");
  
  operatorResult["int!=int"] = Type( "bool" );
  operatorResult["char!=char"] = Type("bool");
  operatorResult["string!=string"] = Type("bool");
  operatorResult["float!=float"] = Type("bool");
  operatorResult["double!=double"] = Type("bool");
  operatorResult["bool!=bool"] = Type("bool");
  
  operatorResult["int<int"] = Type( "bool" );
  operatorResult["int>int"] = Type( "bool" );
  operatorResult["int>=int"] = Type( "bool" );
  operatorResult["int<=int"] = Type( "bool" );
  
  operatorResult["double<double"] = Type( "bool" );
  operatorResult["double>double"] = Type( "bool" );
  operatorResult["double>=double"] = Type( "bool" );
  operatorResult["double<=double"] = Type( "bool" );
  
  operatorResult["float<float"] = Type( "bool" );
  operatorResult["float>float"] = Type( "bool" );
  operatorResult["float>=float"] = Type( "bool" );
  operatorResult["float<=float"] = Type( "bool" );
  
  operatorResult["bool&&bool"] = Type( "bool" );
  operatorResult["bool||bool"] = Type( "bool" );
  operatorResult["!bool"] = Type( "bool" );
  
  operatorResult["double+int"] = Type( "double" );
  operatorResult["int+double"] = Type( "double" );
  operatorResult["double-int"] = Type( "double" );
  operatorResult["int-double"] = Type( "double" );
  operatorResult["double*int"] = Type( "double" );
  operatorResult["int*double"] = Type( "double" );
  operatorResult["double/int"] = Type( "double" );
  operatorResult["int/double"] = Type( "double" );
  
  operatorResult["float+int"] = Type( "float" );
  operatorResult["int+float"] = Type( "float" );
  operatorResult["float-int"] = Type( "float" );
  operatorResult["int-float"] = Type( "float" );
  operatorResult["float*int"] = Type( "float" );
  operatorResult["int*float"] = Type( "float" );
  operatorResult["float/int"] = Type( "float" );
  operatorResult["int/float"] = Type( "float" );
  
  operatorResult["double+float"] = Type( "double" );
  operatorResult["float+double"] = Type( "double" );
  operatorResult["double-float"] = Type( "double" );
  operatorResult["float-double"] = Type( "double" );
  operatorResult["double*float"] = Type( "double" );
  operatorResult["float*double"] = Type( "double" );
  operatorResult["double/float"] = Type( "double" );
  operatorResult["float/double"] = Type( "double" );
}

Type resultType( Type a, string op, Type b ) {
  if( operatorResult.find( a.name + op + b.name ) == operatorResult.end() )
    error( "Operacao nao permitida: " + a.name + op + b.name );

  return operatorResult[a.name + op + b.name];
}

string getFormatStringForType(const Type &t) {
    if (t.name == "int")
        return "%d";
    else if (t.name == "double")
        return "%lf";
    else if (t.name == "float")
        return "%f";
    else if (t.name == "char")
        return "%c";
    else if (t.name == "string")
        return "%s";
    else // bool
        return "%s";
}

string generateTempDeclaration() {
  string c;
  
  for( int i = 0; i < n_var_temp["bool"]; i++ )
    c += "  int temp_bool_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["int"]; i++ )
    c += "  int temp_int_" + toStr( i + 1 ) + ";\n";

    for( int i = 0; i < n_var_temp["char"]; i++ )
    c += "  char temp_char_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["double"]; i++ )
    c += "  double temp_double_" + toStr( i + 1 ) + ";\n";

    for( int i = 0; i < n_var_temp["float"]; i++ )
    c += "  float temp_float_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["string"]; i++ )
    c += "  char temp_string_" + toStr( i + 1 ) + "[" + toStr( MAX_STR )+ "];\n";
    
  return c;  
}

void resetTempVariables() {
  n_var_temp["bool"] = 0;
  n_var_temp["int"] = 0;
  n_var_temp["char"] = 0;
  n_var_temp["double"] = 0;
  n_var_temp["float"] = 0;
  n_var_temp["string"] = 0;
}

void generateVarDeclaration( Attribute* SS, const Attribute& type, const Attribute& id ) 
{
  SS->v = "";
  SS->t = type.t;
  if( type.t.name == "string" ) {
    SS->d = SS->d + "char " + id.v + "["+ toStr( MAX_STR ) +"];\n";   
  } else if ( type.t.name == "bool" ) {
    SS->d = SS->d + "int " + id.v + ";\n";
  } else {
    SS->d = SS->d + type.t.name + " " + id.v + ";\n";
  }
}

void generateArrayCode(Attribute *SS, const Attribute& arrSize)
{
    SS->v = SS->v + "[" + arrSize.v + "]";
    SS->t.s = parseInt(arrSize.v);
}

void generateBidimensionalArrayCode(Attribute *SS, const Attribute& arrSize1, const Attribute& arrSize2)
{
    int arrSize = parseInt(arrSize1.v) * parseInt(arrSize2.v);
    SS->v = SS->v + "[" + toStr(arrSize) + "]";
    SS->t.s = parseInt(arrSize1.v);
    SS->t.s2 = parseInt(arrSize2.v);
}

string generateTemp(Type type) {
  return "temp_" + type.name + "_" + toStr( ++n_var_temp[type.name] );
}

void generateUnaryOperatorCode(Attribute* SS, const Attribute& S1, const Attribute& S2){
    SS->t = Type("bool");
    SS->v = generateTemp(SS->t);
    
    if(S2.t.name == "bool")
    {
        SS->c = S2.c + SS->v + "=" + "!" + S2.v + ";\n";
        
    }
    else
        error("O operador '!' só pode ser usado com um bool. Tipo esperado: 'parada', encontrado: " + S2.t.name);
}

void generateBinaryOperatorCode( Attribute* SS, const Attribute& S1, const Attribute& S2, const Attribute& S3 ) {
  SS->t = resultType( S1.t, S2.v, S3.t );
  SS->v = generateTemp( SS->t );
  
  Attribute secondOperand = Attribute();
  secondOperand.v = S3.v;
  secondOperand.t = S3.t;
  
  string castCode;
  
  if (S1.t.name == "string" && S2.v == "+" && S3.t.name == "int") {
    secondOperand.v = generateTemp(S1.t);
    secondOperand.t = S1.t;
    castCode = "\nsprintf(" + secondOperand.v + ", \"%d\", " + S3.v + ");";
  }

  if( SS->t.name == "string" ) {
    // Falta o operador de comparação para string
    SS->c = S1.c + S3.c + castCode + 
            "\n  strncpy( " + SS->v + ", " + S1.v + ", " + 
                        toStr( MAX_STR - 1 ) + " );\n" +
            "  strncat( " + SS->v + ", " + secondOperand.v + ", " + 
                        toStr( MAX_STR - 1 ) + " );\n" +
            "  " + SS->v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n\n";    
  }
  else
    SS->c = S1.c + S3.c + castCode +
            "  " + SS->v + " = " + S1.v + " " + S2.v + " " + secondOperand.v + ";\n";
            
  SS->d = S1.v;
}

void insertVarTS(TS& ts, string nameVar, Type type) {
    if(!searchVarTS(ts, nameVar, &type))
        ts[nameVar] = type;
    else
        error("Variavel ja declarada: " + nameVar);
}

bool searchVarTS(TS& table, string nameVar, Type* type) {
    if(table.find(nameVar) != table.end()) {
        *type = table[nameVar];
        return true;
    }
    else
        return false;
}

bool searchVar(string nameVar, Type *type) {
    if (searchVarTS(tsl, nameVar, type))
        return true;
    else
        return searchVarTS(ts, nameVar, type);
}

void insertFuncTF(TF&, Function *f) {
    if(!searchFuncTF(tf, f->name, f))
        tf[f->name] = *f;
    else
        error("Funcao ja declarada: " + f->name);
}

bool searchFuncTF(TF&, string nameFunc, Function* func) {
    if(tf.find(nameFunc) != tf.end()) {
        *func = tf[nameFunc];
        return true;
    }
    else
        return false;
}

void addParamToParameterList(Attribute* SS, const Attribute& type, const Attribute& id) {
    Attribute param = Attribute();
    param.t = type.t;
    param.v = id.v;
    SS->l.push_front(param);
    
    insertVarTS(tsl, id.v, type.t);
}

void generateFunctionHeader(Attribute *SS,
                                 const Attribute& type,
                                 const Attribute& id,
                                 const Attribute& paramDecList) {
                                 
                    Function f = Function(id.v, type.t , paramDecList.l);
                    insertFuncTF(tf, &f);
                    
                    *SS = Attribute();
                    
                    string typeName;
                     if( type.t.name == "string" ) {
                        typeName = "char*";
                    } else {
                         typeName = type.t.name;
                    }
                    
                    SS->c = typeName + " " + id.v + "(" + paramDecList.v + ") ";
}

void generateFunctionDeclaration(Attribute *SS,
                                 const Attribute& header,
                                 const Attribute& cmd) {
                    *SS = Attribute();
                    
                    SS->c = header.c
                            + "{ \n"
                            + generateTempDeclaration()
                            + cmd.d
                            + cmd.c
                            + "\n}\n\n";
                            
                    tsl.clear();
                    resetTempVariables();
}

void generateIfCodeWithElse( Attribute* SS, const Attribute& expr, const Attribute& cmdThen, const Attribute& cmdElse ) {
  string ifTrue = generateLabel( "if_true" ),
         ifFalse = generateLabel( "if_false" ),
         ifEnd = generateLabel( "if_end" );
      
  *SS = Attribute();
  SS->c = expr.c + 
          "  if( " + expr.v + " ) goto " + ifTrue + ";\n" +
          "  goto " + ifFalse + ";\n" +
          "  " + ifTrue + ":\n" + cmdThen.c +
          "  goto " + ifEnd + ";\n" +
          "  " + ifFalse + ":\n" + cmdElse.c +
          "  " + ifEnd + ":;\n";
}

void generateIfCodeWithoutElse( Attribute* SS, const Attribute& expr, const Attribute& cmdThen ) {
  string ifTrue = generateLabel( "if_true" ),
         ifEnd = generateLabel( "if_end" );
      
  *SS = Attribute();
  SS->c = expr.c + 
          "  if( " + expr.v + " ) goto " + ifTrue + ";\n" +
          "  goto " + ifEnd + ";\n" + 
          "  " + ifTrue + ":\n" + 
          "    " + cmdThen.c +
          "  goto " + ifEnd + ";\n" +
          "  " + ifEnd + ":;\n";
    
}

void generateForCode( Attribute* SS, const Attribute& initial, const Attribute& condition, const Attribute& step, Attribute& cmd) {
  string forCond = generateLabel( "for_cond" ),
         forEnd = generateLabel( "for_end" );
  string valueNotCond = generateTemp( Type("bool"));
  
  replaceBreakLabel(cmd, forEnd);
  *SS = Attribute();
  
  if( condition.t.name != "bool" )
    error( "A expressão de teste deve ser booleana: " + condition.t.name ); 
  

  SS->c = initial.c + forCond + ":\n" + condition.c +
          "  " + valueNotCond + " = !" + condition.v + ";\n" +
          "  if( " + valueNotCond + " ) goto " + forEnd + ";\n" +
          cmd.c +
          step.c +
          "  goto " + forCond + ";\n" + 
          forEnd + ":;\n";
}

void generatePipeCode(Attribute* SS, const Attribute& start, const Attribute& end, const Attribute& pipes, const Attribute& consume){
    Type pipeType = Type(activePipe);
    
    Attribute initial, cond, step, cmd, varPipe;
    
    initial = Attribute(); 
    cond = Attribute(); 
    step = Attribute(); 
    cmd = Attribute();
    *SS = Attribute();
    varPipe = Attribute();
    
    varPipe.v = "x_" + activePipe;
    varPipe.t = pipeType;
    
    insertVarTS(tsl, varPipe.v, activePipe);

    generateVarDeclaration(&initial, varPipe, varPipe);
    initial.c = varPipe.v + " = " + start.v + ";\n";

    cond.t.name = "bool";
    cond.v = generateTemp(Type("bool"));
    cond.c = "  " + cond.v + " = " + "x_" + activePipe + " <= " + end.v + ";\n";
    
    step.c = activePipeStep + ":\n" + "  x_" + activePipe + " = x_" + activePipe + " + 1;\n";
    
    cmd.c = pipes.c + consume.v;
    
    generateForCode(SS, initial, cond, step, cmd);

    SS->d += initial.d;

    activePipe = "";
}

void generateFirstNCode( Attribute* SS, const Attribute& n ){
    Attribute initial, cond, step, cmd, var;
    
    *SS = Attribute();
    SS->v = generateTemp(Type("int"));
    
    initial = Attribute(); 
    cond = Attribute(); 
    step = Attribute(); 
    cmd = Attribute();
    var = Attribute();
    
    var.v = SS->v;
    var.t = Type("int");
    
    insertVarTS(tsl, SS->v, Type("int"));

    generateVarDeclaration(&initial, var, var);
    
    //cout << initial.d << endl;
    
    cond.t.name = "bool";
    cond.v = generateTemp(Type("bool"));
    cond.c = "  " + cond.v + " = " + SS->v + " <= " + n.v + ";\n";
    
    step.c = activePipeStep + ":\n" + "  " + SS->v + " = " + SS->v + " + 1;\n";
    
    generateForCode(SS, initial, cond, step, cmd);

    SS->d += initial.d;
}

void generateArrayPipeCode(Attribute* SS, const Attribute& id, const Attribute& pipes, const Attribute& consume) {
    Type pipeType = Type(activePipe);
    Type idType;
    searchVar(id.v, &idType);
    
    Attribute initial, cond, step, cmd, varPipe, arrayIndex;
    
    initial = Attribute(); 
    cond = Attribute(); 
    step = Attribute(); 
    cmd = Attribute();
    *SS = Attribute();
    varPipe = Attribute();
    arrayIndex = Attribute();
    
    varPipe.v = "x_" + activePipe;
    varPipe.t = pipeType;

    arrayIndex.v = "pipe_arrayIndex";
    arrayIndex.t = Type("int");
    
    insertVarTS(tsl, varPipe.v, activePipe);
    insertVarTS(tsl, arrayIndex.v, arrayIndex.t);

    generateVarDeclaration(&initial, varPipe, varPipe);
    generateVarDeclaration(&initial, arrayIndex, arrayIndex);

    initial.c = arrayIndex.v + " = 0;\n";

    cond.t.name = "bool";
    cond.v = generateTemp(Type("bool"));
    cond.c = "  " + cond.v + " = " + arrayIndex.v + " < " + toStr(idType.s) + ";\n";
    
    step.c = activePipeStep + ":\n" + arrayIndex.v + " = " + arrayIndex.v + " + 1;\n";
    
    cmd.c = varPipe.v + " = " + id.v + "[" + arrayIndex.v + "];\n" +
	    pipes.c + consume.c;
    
    generateForCode(SS, initial, cond, step, cmd);

    SS->d += initial.d;

    activePipe = "";
}



void generateFilterCode( Attribute* SS, const Attribute& cond ){
    *SS = Attribute();
    SS->v = generateTemp( Type( "bool" ) );
    
    SS->c = cond.c 
            + "  " 
            + SS->v 
            + " = !" 
            + cond.v 
            + ";\n" 
            + "  if( " + SS->v + " ) goto " 
            + activePipeStep 
            + ";\n";
    
    SS->d = cond.d;
}


void generateWhileCode( Attribute* SS, const Attribute& expr, Attribute& cmd) {
    string whileTest = generateLabel( "while_test" ),
           whileBody = generateLabel( "while_body" ),
           whileEnd = generateLabel( "while_end" );
    
    replaceBreakLabel(cmd, whileEnd);
    *SS = Attribute();
    
    SS->c = whileTest + ":\n" + expr.c + "if (" + expr.v + 
         ") goto " + whileBody + ";\ngoto " + whileEnd +
         ";\n" + whileBody + ":\n" + cmd.c + "goto " + whileTest +
         ";\n" + whileEnd + ":;\n";
}

void generateSwitchCode(Attribute* SS, const Attribute& expr , Attribute& cases, const Attribute& defaultCase)
{
    *SS = Attribute();
    string caseDefault = generateLabel("default");
    string fimSwitch = generateLabel("fimSwitch");

    replaceBreakLabel(cases, fimSwitch);
    
    for(list<Attribute>::const_iterator i = cases.l.begin(); i != cases.l.end(); i++)
    {
        SS->c = SS->c + "  if( " + expr.v + " == " + (i->c).substr(6, 1) + " ) goto " + (i->c).substr(0, 9) + ";\n";
    }
        SS->c = SS->c + "  goto " + caseDefault + ";\n";

    
    SS->c = SS->c + cases.c;
    
    SS->c = SS->c + caseDefault + ":\n" + "    "  + defaultCase.c; 
    
    SS->c = SS->c + fimSwitch + ":;\n";
}

void generateCaseCode(Attribute* SS, const Attribute& intCase, Attribute& caseCode)
{
    string labelCase = generateLabel( "case" + intCase.v );
    
    *SS = Attribute();
    
    SS->c = SS->c + labelCase + ":\n" + caseCode.c;
}

void generateDoWhileCode( Attribute* SS, Attribute& cmd, const Attribute& expr) {
    string doBody = generateLabel( "do_body" ),
           doEnd = generateLabel( "do_end" );
    
    replaceBreakLabel(cmd, doEnd);
    *SS = Attribute();
    
    SS->c = doBody + ":\n" + cmd.c + expr.c +
	    "if (" + expr.v + ") goto " + doBody + ";\n" +
	    "goto " + doEnd + ";\n";
}

void generateAssignmentCode( Attribute* SS, Attribute& lvalue, const Attribute& rvalue ) {
  Type lvalueType;
  string lvalueId = trimId(lvalue.v);
  
  if( searchVar( lvalueId, &lvalueType ) ) {
    if( lvalueType.name == rvalue.t.name ) {
      if( lvalueType.name == "string" ) {
        SS->c = lvalue.c + rvalue.c + 
                "  strncpy( " + lvalue.v + ", " + rvalue.v + ", " + 
                            toStr( MAX_STR - 1 ) + " );\n" +
                "  " + lvalue.v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n";
      } else {
        SS->c = lvalue.c + rvalue.c + 
                "  " + lvalue.v + " = " + rvalue.v + ";\n"; 
      }
    }
    else
      error( "Expressao " + rvalue.t.name + 
            " nao pode ser atribuida a variavel " +
            lvalue.t.name );
  } 
  else {
    error( "Variavel nao declarada: " + lvalueId );
  }
}

void generateOutputCode(Attribute *SS, const Attribute &exp) {
    *SS = Attribute();
    SS->c = exp.c + 
        "printf(\"" +
        getFormatStringForType(exp.t) +
        "\\n\", " +
        exp.v + 
        ");\n";
}

void generateInputCode(Attribute *SS, const Attribute &id) {
    *SS = Attribute();
    Type idType;
    
    if (searchVar( id.v, &idType)) {
        SS->c = "scanf(\"" +
            getFormatStringForType(idType) +
            "\", &" +
            id.v + 
            ");";
    } else {
        error("Variavel nao declarada: " + id.v);
    }
}

void generateFunctionCallWithParametersCode(Attribute* SS, const Attribute& id, const Attribute& params) {
    Function func;
    
    if (!searchFuncTF(tf, id.v, &func)) {
        error("Funcao nao declarada: " + id.v);
    }
       
    if (func.parameterList.size() != params.l.size()) {
        error( "Funcao " + id.v + " espera " + toStr(func.parameterList.size()) + " parametros e recebeu " + toStr(params.l.size()) );
    }
    
    list<Attribute>::const_iterator passedParam = params.l.begin();
    list<Attribute>::const_iterator expectedParam = func.parameterList.begin();
    int paramCount = 1;
    string paramListCode;
    
    while (passedParam != params.l.end()) {
        if (passedParam->t.name != expectedParam->t.name) {
            error("Tipo incompativel no parametro " + toStr(paramCount) +
                  " da funcao " + id.v + ": esperava " + expectedParam->t.name +
                  ", encontrou " + passedParam->t.name);
        }
        
        paramListCode += passedParam->v;
        if (paramCount < params.l.size()) paramListCode += ", ";
        
        SS->c += passedParam->c;
        
        passedParam++;
        expectedParam++;
        paramCount++;
    }
    
    SS->t = func.returnType;
    SS->v = id.v + "(" + paramListCode + ")";
}

void generateFunctionCallWithoutParametersCode(Attribute* SS, const Attribute& id) {
    Function func;
    
    if (!searchFuncTF(tf, id.v, &func)) {
        error("Funcao nao declarada: " + id.v);
    }
       
    if (func.parameterList.size() != 0) {
        error( "Funcao " + id.v + " espera " + toStr(func.parameterList.size()) + " parametros e recebeu 0" );
    }
    
    SS->t = func.returnType;
    SS->v = id.v + "()";
}

void replaceAll(string& str, const string& oldStr, const string& newStr) {
  size_t pos = 0;
  while((pos = str.find(oldStr, pos)) != string::npos) {
     str.replace(pos, oldStr.length(), newStr);
     pos += newStr.length();
  }
}

void replaceBreakLabel(Attribute& block, string realLabel) {
	replaceAll(block.c, "BREAK_LABEL", realLabel);
}

int main( int argc, char* argv[] ) {
  initOperatorResultTable();
  yyparse();
}