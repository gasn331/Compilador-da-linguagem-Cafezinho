%{
        #include "type.h"
	#include <stdio.h>
        #include <string.h>
        static char* enumStrings[] = {"programa","DeclFuncVar1","DeclFuncVar2","DeclFuncVar3","DeclFunc","ListaParametrosCont3",
"ListaParametrosCont4","Bloco1","ListaDeclVar2","ListaDeclVar3","Tipo","ListaComando2","Retorne","Leia","Escreva",
"EscrevaString","Novalinha","Se","SeSenao","Enquanto","Atribuir","SeTernario","Or","And","IgualIgual","Diferente","Menor",
"Maior","MenorIg","MaiorIg","Mais","Menos","Vezes","Divisao","Resto","Negativo","Negacao","IdentificadorBEB","Identificador",
"IdentificadorLista","Carconst","Intconst","Virgula"};
        extern int yylineno;
        node *mknode(Operator type, int line, node *first, node *second, node *third, char *token);
        void printtree(node *tree);
        char *convert2Str(int x);
        node *tree;
	yydebug=1;
%}

%union{
        int lineno;
        char *string;
        node* node_type;
}

%start programa
%type<node_type> DeclFuncVar DeclProg DeclVar DeclFunc;
%type<node_type> ListaParametros ListaParametrosCont Bloco ListaDeclVar;
%type<node_type> Tipo ListaComando Comando Expr AssignExpr CondExpr OrExpr;
%type<node_type> AndExpr EqExpr DesigExpr AddExpr MulExpr UnExpr LValueExpr PrimExpr ListExpr;
%token PROGRAMA DECLARACAO_INT DECLARACAO_CAR 
%token RETORNE LEIA ESCREVA NOVALINHA
%token SE ENTAO SENAO ENQUANTO EXECUTE
%token MAIS MENOS VEZES DIV RESTO OUEXPR EEXPR ANULEXPR DBIGUAL DIFF
%token MAIORQ MENORQ MAIORIGQ MENORIGQ INTERROG DOISPONT
%token EPAREN DPAREN DBRACK EBRACK EBRACE DBRACE SEMI VIRGULA ATRIB
%token ID INTCONST CARCONST STRING

%%
programa : DeclFuncVar DeclProg {tree = mknode(programa,yylineno,$1,$2,NULL,NULL);}
         ;

DeclFuncVar : Tipo ID DeclVar SEMI DeclFuncVar {$$ = mknode(DeclFuncVar1,yylineno,$1,$3,$5,NULL);}
            | Tipo ID EBRACK INTCONST DBRACK DeclVar SEMI DeclFuncVar {$$ = mknode(DeclFuncVar2,yylineno,$1,$6,$8,NULL);}
            | Tipo ID DeclFunc DeclFuncVar {$$ = mknode(DeclFuncVar3,yylineno,$1,$3,$4,NULL);}
            | {$$ = NULL;}
            ;

DeclProg : 
	PROGRAMA Bloco {$$ = $2;}
         ;

DeclVar : VIRGULA ID DeclVar {$$ = $3;}
        | VIRGULA ID EBRACK INTCONST DBRACK DeclVar {$$ = $6;}
        | {$$ = NULL;}
        ;

DeclFunc : EPAREN ListaParametros DPAREN Bloco {$$ = mknode(DeclFunc,yylineno,$2,$4,NULL,NULL);}
         ;

ListaParametros : {$$ = NULL;}
                | ListaParametrosCont {$$ = $1;}
                ;

ListaParametrosCont : Tipo ID {$$ = $1;}
                    | Tipo ID EBRACK DBRACK {$$ = $1;}
                    | Tipo ID VIRGULA ListaParametrosCont {$$ = mknode(ListaParametrosCont3,yylineno,$1,$4,NULL,NULL);}
                    | Tipo ID EBRACK DBRACK VIRGULA ListaParametrosCont {$$ = mknode(ListaParametrosCont4,yylineno,$1,$6,NULL,NULL);}
                    ;

Bloco : EBRACE ListaDeclVar ListaComando DBRACE {$$ = mknode(Bloco1,yylineno,$2,$3,NULL,NULL);}
      | EBRACE ListaDeclVar DBRACE {$$ = $2;}
      ;

ListaDeclVar : {$$ = NULL;}
             | Tipo ID DeclVar SEMI ListaDeclVar {$$ = mknode(ListaDeclVar2,yylineno,$1,$3,$5,NULL);}
             | Tipo ID EBRACK INTCONST DBRACK DeclVar SEMI ListaDeclVar {$$ = mknode(ListaDeclVar3,yylineno,$1,$6,$8,NULL);}
             ;

Tipo : DECLARACAO_INT {$$ = mknode(Tipo,yylineno,NULL,NULL,NULL,"int");}
     | DECLARACAO_CAR {$$ = mknode(Tipo,yylineno,NULL,NULL,NULL,"car");}
     ;

ListaComando : Comando {$$ = $1;}
             | Comando ListaComando {$$ = mknode(ListaComando2,yylineno,$1,$2,NULL,NULL);}
             ;

Comando : 
	SEMI {$$ = NULL;}
        | Expr SEMI {$$ = $1;}
        | RETORNE Expr SEMI {$$ = mknode(Retorne,yylineno,$2,NULL,NULL,NULL);}
        | LEIA LValueExpr SEMI {$$ = mknode(Leia,yylineno,$2,NULL,NULL,NULL);}
        | ESCREVA Expr SEMI {$$ = mknode(Escreva,yylineno,$2,NULL,NULL,NULL);}
        | ESCREVA STRING SEMI {$$ = mknode(EscrevaString,yylineno,NULL,NULL,NULL,NULL);}
        | NOVALINHA SEMI {$$ = mknode(Novalinha,yylineno,NULL,NULL,NULL,NULL);}
        | SE EPAREN Expr DPAREN ENTAO Comando {$$ = mknode(Se,yylineno,$3,$6,NULL,NULL);}
        | SE EPAREN Expr DPAREN ENTAO Comando SENAO Comando {$$ = mknode(SeSenao,yylineno,$3,$6,$8,NULL);}
        | ENQUANTO EPAREN Expr DPAREN EXECUTE Comando {$$ = mknode(Enquanto,yylineno,$3,$6,NULL,NULL);}
        | Bloco {$$ = $1;}
        ;

Expr : AssignExpr {$$ = $1;}
     ;
AssignExpr : CondExpr {$$ = $1;}
           | LValueExpr ATRIB AssignExpr {$$ = mknode(Atribuir,yylineno,$1,$3,NULL,NULL);}
           ;

CondExpr : OrExpr {$$ = $1;}
         | OrExpr INTERROG Expr DOISPONT CondExpr {$$ = mknode(SeTernario,yylineno,$1,$3,$5,NULL);}
         ;


OrExpr : OrExpr OUEXPR AndExpr {$$ = mknode(Or,yylineno,$1,$3,NULL,NULL);}
       | AndExpr {$$ = $1;}
       ;

AndExpr : AndExpr EEXPR EqExpr {$$ = mknode(And,yylineno,$1,$3,NULL,NULL);}
        | EqExpr {$$ = $1;}
        ;

EqExpr : EqExpr DBIGUAL DesigExpr {$$ = mknode(IgualIgual,yylineno,$1,$3,NULL,NULL);}
       | EqExpr DIFF DesigExpr {$$ = mknode(Diferente,yylineno,$1,$3,NULL,NULL);}
       | DesigExpr {$$ = $1;}
       ;

DesigExpr : DesigExpr MENORQ AddExpr {$$ = mknode(Menor,yylineno,$1,$3,NULL,NULL);}
          | DesigExpr MAIORQ AddExpr {$$ = mknode(Maior,yylineno,$1,$3,NULL,NULL);}
          | DesigExpr MENORIGQ AddExpr {$$ = mknode(MenorIg,yylineno,$1,$3,NULL,NULL);}
          | DesigExpr MAIORIGQ AddExpr {$$ = mknode(MaiorIg,yylineno,$1,$3,NULL,NULL);}
          | AddExpr {$$ = $1;}
          ;

AddExpr : AddExpr MAIS MulExpr {$$ = mknode(Mais,yylineno,$1,$3,NULL,NULL);}
        | AddExpr MENOS MulExpr {$$ = mknode(Menos,yylineno,$1,$3,NULL,NULL);}
        | MulExpr {$$ = $1;}
        ;

MulExpr : MulExpr VEZES UnExpr {$$ = mknode(Vezes,yylineno,$1,$3,NULL,NULL);}
        | MulExpr DIV UnExpr {$$ = mknode(Divisao,yylineno,$1,$3,NULL,NULL);}
        | MulExpr RESTO UnExpr {$$ = mknode(Resto,yylineno,$1,$3,NULL,NULL);}
        | UnExpr {$$ = $1;}
        ;

UnExpr : MENOS PrimExpr {$$ = mknode(Negativo,yylineno,$2,NULL,NULL,NULL);}
       | ANULEXPR PrimExpr {$$ = mknode(Negacao,yylineno,$2,NULL,NULL,NULL);}
       | PrimExpr {$$ = $1;}
       ;

LValueExpr : ID EBRACK Expr DBRACK {$$ = mknode(IdentificadorBEB,yylineno,$3,NULL,NULL,NULL);}
           | ID {$$ = mknode(Identificador,yylineno,NULL,NULL,NULL,NULL);}
           ;

PrimExpr : ID EPAREN ListExpr DPAREN {$$ = mknode(IdentificadorLista,yylineno,$3,NULL,NULL,NULL);}
         | ID EPAREN DPAREN {$$ = mknode(Identificador,yylineno,NULL,NULL,NULL,NULL);}
         | ID EBRACK Expr DBRACK {$$ = mknode(IdentificadorBEB,yylineno,$3,NULL,NULL,NULL);}
         | ID {$$ = mknode(Identificador,yylineno,NULL,NULL,NULL,yyval.string);}
         | CARCONST {$$ = mknode(Carconst,yylineno,NULL,NULL,NULL,yyval.string);}
         | INTCONST {$$ = mknode(Intconst,yylineno,NULL,NULL,NULL,convert2Str(yyval.string));}
         | EPAREN Expr DPAREN {$$ = $2;}
         ;

ListExpr : AssignExpr {$$ = $1;}
         | ListExpr VIRGULA AssignExpr {$$ = mknode(Virgula, yylineno,$1, $3, NULL, yyval.string);}
         ;
%%

yywrap(){
	return 1;
}

main(){
        #ifdef YYDEBUG
                yydebug = 1;
        #endif
	yyparse();
        printtree(tree);
        
}

node *mknode(Operator type, int line, node *first, node *second, node *third, char *token){
        //printf("MAKE NEW NODE");
        //printf("TRYING TO SAVE: %s %d\n", enumStrings[(int)type],line);
        node *newnode = (node *)malloc(sizeof(node));
        if(newnode == NULL) return NULL;
        newnode->type = type;
        newnode->line = line;
        newnode->first = first;
        newnode->second = second;
        newnode->third = third;
        //printf("TRYING TO SAVE: %s %d\n", enumStrings[(int)type],line);
        //if(!token) printf("TOKEN NULL\n");
        if(token != NULL){
               newnode->token = (char *)malloc(sizeof(char)*(strlen(token)+1));
               strcpy(newnode->token,token); 
        }
        else newnode->token = NULL;
        //printf("WILL RETURN NOW\n");
        return newnode;
}
void printtree(node *tree) {
        //printf("PRINTING TREE\n");
        if(tree == NULL) return;
        //switch operator
        switch(tree->type){
          case programa:
                printf("programa ");
                break;
          case DeclFuncVar1:
                printf("DeclFuncVar1 ");
                break;
          case DeclFuncVar2:
                printf("DeclFuncVar2 ");
                break;
          case DeclFuncVar3:
                printf("DeclFuncVar3 ");
                break;
          case DeclFunc:
                printf("DeclFunc ");
                break;
          case ListaParametrosCont3:
                printf("ListaParametrosCont3 ");
                break;
          case ListaParametrosCont4:
                printf("ListaParametrosCont4 ");
                break;
          case Bloco1:
                printf("Bloco1 ");
                break;
          case ListaDeclVar2:
                printf("ListaDeclVar2 ");
                break;
          case ListaDeclVar3:
                printf("ListaDeclVar3 ");
                break;
          case Tipo:
                printf("Tipo %s ", tree->token);
                break;
          case ListaComando2:
                printf("ListaComando2 ");
                break;
          case Retorne:
                printf("Retorne ");
                break;
          case Leia:
                printf("Leia ");
                break;
          case Escreva:
                printf("Escreva ");
                break;
          case EscrevaString:
                printf("EscrevaString ");
                break;
          case Novalinha:
                printf("Novalinha ");
                break;
          case Se:
                printf("Se ");
                break;
          case SeSenao:
                printf("SeSenao ");
                break;
          case Enquanto:
                printf("Enquanto ");
                break;
          case Atribuir:
                printf("= ");
                break;
          case SeTernario:
                printf("SeTernario ");
                break;
          case Or:
                printf("OU ");
                break;
          case And:
                printf("E ");
                break;
          case IgualIgual:
                printf("== ");
                break;
          case Diferente:
                printf("!= ");
                break;
          case Menor:
                printf("< ");
                break;
          case Maior:
                printf("> ");
                break;
          case MenorIg:
                printf("<= ");
                break;
          case MaiorIg:
                printf(">= ");
                break;
          case Mais:
                printf("+ ");
                break;
          case Menos:
                printf("- ");
                break;
          case Vezes:
                printf("* ");
                break;
          case Divisao:
                printf("/ ");
                break;
          case Resto:
                printf("% ");
                break;
          case Negativo:
                printf("- Un ");
                break;
          case Negacao:
                printf("! ");
                break;
          case IdentificadorBEB:
                printf("Identificador[] ");
                break;
          case Identificador:
                printf("Identificador ");
                break;
          case IdentificadorLista:
                printf("Identificador() ");
                break;
          case Carconst:
                printf("Carconst %s ", tree->token);
                break;
          case Intconst:
                printf("Intconst %s ", tree->token);
                break;
          case Virgula:
                printf(", ");
                break;
        }
        printf(" - Line: %d\n", tree->line);
        
        //
        printtree(tree->first);
        printtree(tree->second);
        printtree(tree->third);
 }

 char *convert2Str(int x){
        int length = snprintf( NULL, 0, "%d", x );
        char* str = malloc( length + 1 );
        snprintf( str, length + 1, "%d", x );
        return str;
}