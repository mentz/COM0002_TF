//Versão Vítor e Mentz

delim	[ \t]
ws	{delim}+
digito	[0-9]
letra 	[A-Za-z]
num	{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
id 	(\_|{letra})(\_|{letra}|{digito})*
literal \".*\"



%%
{ws}		{}
"+"		{return TADD;}
"-"		{return TSUB;}
"*"		{return TMUL;}
"/"		{return TDIV;}
"("		return TAPAR;}
")"		{return TFPAR;}
"<"		{return TMEQ}
">"		{return TMAQ}
"<="		{return TMEIG}
">=" 		{return TMAIG}
"=="		{return TEQ}
"!="		{return TDIF}
"&&" 		{return TAND}
"||"		{return TOR}
"!"		{return TNOT}
"int" 		{return TINT}
"float" 	{return TFLOAT}
"string"	{return TSTRING}
\n		{return TFIM;}
{num}		{yylval=atof(yytext); return TNUM;} 
{num}		{yylval=atoi(yytext); return TNUM;} 
