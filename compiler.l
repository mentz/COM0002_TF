comment		\/\*.*\*\/
delim 		[ \t]
ws 			{delim}+
digito 		[0-9]
letra 		[a-zA-Z]
int 		{digito}+
float 		{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
id 			(\_|{letra})(\_|{letra}|{digito})*
literal 	\".*\"
newline     \n

%%
"if"		{return TIF;}
"int" 		{return TINT;}
"else"		{return TELSE;}
"float" 	{return TFLOAT;}
"print"		{return TPRINT;}
"read"		{return TREAD;}
"return"	{return TRETURN;}
"string"	{return TSTRING;}
"void"		{return TVOID;}
"while"		{return TWHILE;}

";"			{return ';';}
","			{return ',';}
"="			{return '=';}
"+"			{return '+';}
"-"			{return '-';}
"*"			{return '*';}
"/"			{return '/';}
"("			{return '(';}
")"			{return ')';}
"{"			{return '{';}
"}"			{return '}';}
"<"			{return '<';}
">"			{return '>';}
"!"			{return '!';}

"<="		{return TMEIG;}
">=" 		{return TMAIG;}
"=="		{return TEQ;}
"!="		{return TDIF;}
"&&" 		{return TAND;}
"||"		{return TOR;}

{id}		{strncpy(yylval.id, yytext, MAX_ID_LEN - 1); return TID;}
{int}		{yylval.ival = atoi(yytext); return TINT;}
{float}		{yylval.fval = atof(yytext); return TFLOAT;}
{literal}	{return TLITERAL;}
{newline}	{linha++;}
{ws}		{}
{comment}	{}

.			{printf("Token não reconhecido: %s (linha %d)\n", yytext, linha);}
