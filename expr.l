//Versão Vítor e Mentz

delim 		[ \t]
ws 			{delim}+
digito 		[0-9]
letra 		[a-zA-Z]
int 		{digito}+
float 		{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
id 			(\_|{letra})(\_|{letra}|{digito})*
literal 	\".*\"

%%
{ws}		{}
"if"		{return TIF;}
"else"		{return TELSE;}
"while"		{return TWHILE;}
"void"		{return TVOID;}
"+"			{return TADD;}
"-"			{return TSUB;}
"*"			{return TMUL;}
"/"			{return TDIV;}
"("			{return TAPAR;}
")"			{return TFPAR;}
"{"			{return TACHV;}
"}"			{return TFCHV;}
"<"			{return TMEQ;}
">"			{return TMAQ;}
"<="		{return TMEIG;}
">=" 		{return TMAIG;}
"=="		{return TEQ;}
"!="		{return TDIF;}
"&&" 		{return TAND;}
"||"		{return TOR;}
"!"			{return TNOT;}
"int" 		{return TINT;}
"float" 	{return TFLOAT;}
"string"	{return TSTRING;}
\n			{return TFIM;}
{id}		{return TID;}
{int}		{yylval=atoi(yytext); return TINT;} 
{float}		{yylval=atof(yytext); return TFLOAT;} 
