//Versão Vítor e Mentz

delim 		[ \t]
ws 			{delim}+
digito 		[0-9]
letra 		[A-Za-z]
int 		{digito}+
float 		{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
id 			(\_|{letra})(\_|{letra}|{digito})*
literal 	\".*\"



%%
{ws}		{}
"+"			{return TADD;}
"-"			{return TSUB;}
"*"			{return TMUL;}
"/"			{return TDIV;}
"("			{return TAPAR;}
")"			{return TFPAR;}
"<"			{return TMEQ}
">"			{return TMAQ}
"<="		{return TMEIG}
">=" 		{return TMAIG}
"=="		{return TEQ}
"!="		{return TDIF}
"&&" 		{return TAND}
"||"		{return TOR}
"!"			{return TNOT}
"int" 		{return TINT}
"float" 	{return TFLOAT}
"string"	{return TSTRING}
\n			{return TFIM;}
{int}		{yylval=atof(yytext); return TINT;} 
{float}		{yylval=atoi(yytext); return TFLOAT;} 
