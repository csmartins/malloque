DELIM    [\t ]
LINE     [\n]
DIGIT    [0-9]
NUMBER   [+-]?{DIGIT}+
LETTER   [A-Za-z_]
INT      {NUMBER}
DOUBLE   {NUMBER}(\.{DIGIT}+)?
FLOAT    {DOUBLE}f
ID       {LETTER}({LETTER}|{DIGIT})*
STRING   \"[^"\n]*\"
CHAR     \'[^"\n]\'
BOOL     ["blz"|"cao"]
COMMENT  "//".*

%%

{LINE}          { nline++; }
{DELIM}         {}
{COMMENT}       {}

"<="            { yylval = Attribute( yytext ); return _OPR_LESS_EQUAL; }
">="            { yylval = Attribute( yytext ); return _OPR_GREATER_EQUAL; }
"=="            { yylval = Attribute( yytext ); return _OPR_COMP; }
"!="            { yylval = Attribute( yytext ); return _OPR_DIF; }
"e"             { yylval = Attribute( "&&" ); return _OPR_AND; }
"ou"            { yylval = Attribute( "||" ); return _OPR_OR; }
"nao"           { yylval = Attribute( "!" ); return _OPR_NOT; }

"inteiro"       {  yylval = Attribute( "", "int" ); return _INT; }
"letra"         {  yylval = Attribute( "", "char" ); return _CHAR; }
"parada"        {  yylval = Attribute( "", "bool" ); return _BOOL; }
"real"          {  yylval = Attribute( "", "double" ); return _DOUBLE; }
"decimal"       {  yylval = Attribute( "", "float" ); return _FLOAT; }
"texto"         {  yylval = Attribute( "", "string" ); return _STRING; }

"ficaLigado"    {  yylval = Attribute( yytext ); return _CMD_IN; }
"daOPapo"       {  yylval = Attribute( yytext ); return _CMD_OUT; }

"blz"           { yylval = Attribute( "1" ); return _CTE_BOOL; }
"cao"           { yylval = Attribute( "0" ); return _CTE_BOOL; }

"mano,"         { yylval = Attribute( yytext ); return _CMD_VAR; }

"seLiga"        { yylval = Attribute( yytext ); return _BEGIN; }
"sacou?"        { yylval = Attribute( yytext ); return _END; }

"trampo"        { yylval = Attribute( yytext ); return _FUNCTION; }

"vaza"          { yylval = Attribute( yytext ); return _BREAK; }

"sePah"         { yylval = Attribute( yytext ); return _IF; }
"daih"          { yylval = Attribute( yytext ); return _THEN; }
"naoMeteEssa"   { yylval = Attribute( yytext ); return _ELSE; }
"flws"          { yylval = Attribute( yytext ); return _RETURN; }

"roleh"         { yylval = Attribute( yytext ); return _FOR; }

"enquanto"      { yylval = Attribute( yytext ); return _WHILE; }

"fazAi"         { yylval = Attribute( yytext ); return _DO; }

"qualVaiSer"    { yylval = Attribute( yytext ); return _SWITCH; }
"treta"         { yylval = Attribute( yytext ); return _CASE; }
"padrao"        { yylval = Attribute( yytext ); return _DEFAULT; }

"eh"            { yylval = Attribute( yytext ); return _OPR_ATR; }
     
"intervalo"     { yylval = Attribute( yytext ); return _RANGE; }
".."		    { yylval = Attribute( yytext ); return _2PTS; }
"filtro"        { yylval = Attribute( yytext ); return _FILTER; }
"paraCada"      { yylval = Attribute( yytext ); return _FOR_EACH; }
"primeiros"     { yylval = Attribute( yytext ); return _FIRST_N; }
"ultimos"       { yylval = Attribute( yytext ); return _LAST_N; }
"ordena"        { yylval = Attribute( yytext ); return _SORT; } 
"|"		        { yylval = Attribute( yytext ); return _PIPE; }
"x"		        { yylval = Attribute( yytext ); return _X; }

{ID}            { yylval = Attribute( yytext ); return _ID; }
{INT}           { yylval = Attribute( yytext ); return _CTE_INT; }
{DOUBLE}        { yylval = Attribute( yytext ); return _CTE_DOUBLE; }
{FLOAT}         { yylval = Attribute( yytext ); return _CTE_FLOAT; }
{CHAR}          { yylval = Attribute( yytext ); return _CTE_CHAR; }
{BOOL}          { yylval = Attribute( yytext ); return _CTE_BOOL; }
{STRING}        { yylval = Attribute( yytext ); return _CTE_STRING; }

.               { yylval = Attribute( yytext ); return *yytext; }

%%