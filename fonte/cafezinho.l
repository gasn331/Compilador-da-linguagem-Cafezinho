%{
	#include "type.h"
	#include <stdio.h>
	#include "cafezinho.tab.h"
	void yyerror();
	void print(char *token_type);
%}

%x ML_COMMENT
%x ML_STRING

alfa 	[a-zA-Z]
digito 	[0-9]
alfanum	{alfa}|{digito}

ID		{alfa}+{alfanum}* 	   
INTCONST 	"0"|[0-9]{digito}* 
CARCONST	\'.\'			   
STRING		\"([^"]*)\"		  

%%
"programa"|"PROGRAMA"	{	return (PROGRAMA);		}
"int"|"INT"		{	return (DECLARACAO_INT);	} 
"car"|"CAR"		{	return (DECLARACAO_CAR);	}
"retorne"|"RETORNE" 	{	return (RETORNE);		}
"leia"|"LEIA"	 	{	return (LEIA);			}
"escreva"|"ESCREVA" 	{	return (ESCREVA);		}
"novalinha"|"NOVALINHA" {	return (NOVALINHA);		}
"se"|"SE" 		{	return (SE);			}
"entao"|"ENTAO" 	{	return (ENTAO);			}
"senao"|"SENAO" 	{	return (SENAO);			}
"enquanto"|"ENQUANTO" 	{	return (ENQUANTO);		}
"execute"|"EXECUTE" 	{	return (EXECUTE);		}


"+"      		{ return (MAIS); 	}
"-"      		{ return (MENOS);	}
"*"      		{ return (VEZES); 	}
"/"      		{ return (DIV); 	}
"%"      		{ return (RESTO); 	}
"ou"         	{ return (OUEXPR); 	}
"e"	     		{ return (EEXPR); 	}
"!"	     		{ return (ANULEXPR);	}
"=="      		{ return (DBIGUAL); 	}
"!="    		{ return (DIFF); 	}
">"      		{ return (MAIORQ); 	}
"<"      		{ return (MENORQ); 	}
">="      		{ return (MAIORIGQ); 	}
"<="	      		{ return (MENORIGQ); 	}
"?"      		{ return (INTERROG); 	}
":"      		{ return (DOISPONT); 	}

"("   			{ return (EPAREN); 	}
")"      		{ return (DPAREN); 	}
"]"      		{ return (DBRACK); 	}
"["      		{ return (EBRACK); 	}
"{"      		{ return (EBRACE);	}
"}"      		{ return (DBRACE);	}
";"      		{ return (SEMI); 	}
","      		{ return (VIRGULA); 	}
"="      		{ return (ATRIB); 	}

{ID}         		{ yylval.string = yytext; return (ID); 		}
{INTCONST}   		{ yylval.string = atoi(yytext);return (INTCONST); 	}
{CARCONST}    		{ yylval.string = yytext;return (CARCONST); 	}
{STRING}     		{ yylval.string = yytext;return (STRING);	}

"\n"		   { yylineno++; }
[ \t\r\f]+

"/*"		    BEGIN(ML_COMMENT);
<ML_COMMENT>[^*\n]*
<ML_COMMENT>"*"+[^/\n]  
<ML_COMMENT><<EOF>> {yyerror("COMENTARIO NAO TERMINA");}
<ML_COMMENT>\n yylineno++;    
<ML_COMMENT>"*"+"/"    BEGIN(INITIAL);


"\""		{ BEGIN(ML_STRING); }
<ML_STRING>"\"" 	{ BEGIN(INITIAL); }
<ML_STRING>[^*\n]+					
<ML_STRING>\n	{ yyerror("CADEIA MULTILINHA"); yylineno += 1; }
<ML_STRING><<EOF>> {yyerror("CADEIA NAO TERMINA");}


.		   { yyerror("CARACTER INVALIDO"); }
%%

void print(char *token_type){
	printf("yytext: %s\ttoken: %s\tlinha: %d\n", yytext, token_type, yylineno);
}

void yyerror(char *message){
   printf("ERRO: \"%s\" na linha %d.\n", message, yyget_lineno());
   exit(1);
}
