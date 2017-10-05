delim 		[ \t]
ws 			{delim}+
digito 		[0-9]
letra 		[a-zA-Z]
int 		{digito}+
float 		{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
id 			(\_|{letra})(\_|{letra}|{digito})*
literal 	\".*\"

%%
"if"		{return TIF;}
"int" 		{return TINT;}
"else"		{return TELSE;}
"float" 	{return TFLOAT;}
"print"		{return TPRINT;}
"read"		{return TREAD;}
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

{id}		{return TID;}
{int}		{yylval=atoi(yytext); return TINT;} 
{float}		{yylval=atof(yytext); return TFLOAT;} 
{literal}	{return TLITERAL;}
{ws}		{}
