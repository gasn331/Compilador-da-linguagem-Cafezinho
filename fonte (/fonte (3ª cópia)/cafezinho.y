%{
	#include <stdio.h>
        #include <string.h>
        typedef struct node{ //definicao de um no da arvore de sintaxe abstrata
                struct node *left;
                struct node *right;
                char *token;
        }node;
        node *mknode(node *left, node *right, char *token);
        void printtree(node *tree); 
        #define YYSTYPE struct node *
	yydebug=1;
%}
%start programa

%token PROGRAMA DECLARACAO_INT DECLARACAO_CAR 
%token RETORNE LEIA ESCREVA NOVALINHA
%token SE ENTAO SENAO ENQUANTO EXECUTE
%token MAIS MENOS VEZES DIV RESTO OUEXPR EEXPR ANULEXPR DBIGUAL DIFF
%token MAIORQ MENORQ MAIORIGQ MENORIGQ INTERROG DOISPONT
%token EPAREN DPAREN DBRACK EBRACK EBRACE DBRACE SEMI VIRGULA ATRIB
%token ID INTCONST CARCONST STRING

%%
programa : DeclFuncVar DeclProg   {$$ = mknode($1, $2, "programa"); printtree($1); printf("\n"); }
         ;

DeclFuncVar : Tipo ID DeclVar SEMI DeclFuncVar {$$ = mknode(mknode(NULL,$2,"Tipo"), mknode($4, NULL,"DeclFuncVar"), "DeclVar");}
            | Tipo ID EBRACK INTCONST DBRACK DeclVar SEMI DeclFuncVar   {$$ = mknode(mknode($1,mknode($3,$5,"INTCONST"),"ID"),mknode($7,NULL,"DeclFuncVar"), "DeclVar");}
            | Tipo ID DeclFunc DeclFuncVar      {$$ = mknode(mknode(NULL,$2,"Tipo"), $4, "DeclFunc");}
            | /* empty */
            ;

DeclProg : 
	PROGRAMA Bloco  {$$ = mknode($1,NULL,"Bloco");}          
         ;

DeclVar : VIRGULA ID DeclVar    {$$ = mknode($1, $3, "ID");}
        | VIRGULA ID EBRACK INTCONST DBRACK DeclVar {$$ = mknode($1,mknode(mknode($3,$5,"INTCONST"),NULL,"DeclVar"),"ID");}
        | /* empty */
        ;

DeclFunc : EPAREN ListaParametros DPAREN Bloco {$$ = mknode($1,mknode(NULL,$4,"DPAREN"),"ListaParametros");}
         ;

ListaParametros : /* empty */
                | ListaParametrosCont {$$ = $1;}
                ;

ListaParametrosCont : Tipo ID   {$$ = mknode(NULL,$2,"Tipo");}
                    | Tipo ID EBRACK DBRACK {$$ = mknode(NULL,mknode($2,$4,"EBRACK"),"Tipo");}
                    | Tipo ID VIRGULA ListaParametrosCont {$$ = mknode(mknode(NULL,$2,"Tipo"),$4,"VIRGULA");}
                    | Tipo ID EBRACK DBRACK VIRGULA ListaParametrosCont {$$ = mknode(mknode(NULL,mknode($2,$4,"EBRACK"),$1),$6,"VIRGULA");}
                    ;

Bloco : EBRACE ListaDeclVar ListaComando DBRACE { $$ = mknode(mknode($1,NULL,"ListaDeclVar"),$4,"ListaComando");}
      | EBRACE ListaDeclVar DBRACE {$$ = mknode($1,$3,"ListaDeclVar");}
      ;

ListaDeclVar : /* empty */
             | Tipo ID DeclVar SEMI ListaDeclVar {$$ = mknode(mknode(NULL,$2,"Tipo"),mknode($4,NULL,"ListaDeclVar"),"DeclVar");}
             | Tipo ID EBRACK INTCONST DBRACK DeclVar SEMI ListaDeclVar {$$ = mknode(mknode($1,mknode($3,$5,"INTCONST"),"ID"),mknode($7,NULL,"ListaDeclVar"),"DeclVar");}
             ;

Tipo : DECLARACAO_INT   {$$ = mknode(NULL,NULL,"DECLARACAO_INT");}
     | DECLARACAO_CAR   {$$ = mknode(NULL,NULL,"DECLARACAO_CAR");}
     ;

ListaComando : Comando  {$$ = $1;}
             | Comando ListaComando {$$ = mknode(NULL,$2,"Comando");}
             ;

Comando : 
	SEMI    {$$ = mknode(NULL, NULL, "SEMI");}
        | Expr SEMI     {$$ = mknode($1, NULL, "SEMI");}
        | RETORNE Expr SEMI     {$$ = mknode($1, $3, "Expr");}
        | LEIA LValueExpr SEMI  {$$ = mknode($1, $3, "LValueExpr");}
        | ESCREVA Expr SEMI     {$$ = mknode($1, $3, "Expr");}
        | ESCREVA STRING SEMI   {$$ = mknode($1, $3, "STRING");}
        | NOVALINHA SEMI        {$$ = mknode(NULL, $2, "NOVALINHA");}
        | SE EPAREN Expr DPAREN ENTAO Comando {$$ = mknode(mknode($1,NULL,"EPAREN"),mknode($4,$6,"ENTAO"),"Expr");}
        | SE EPAREN Expr DPAREN ENTAO Comando SENAO Comando {$$ = mknode(mknode($1,NULL,"EPAREN"),mknode($4,mknode($6,$8,"SENAO"),"ENTAO"),"Expr");}
        | ENQUANTO EPAREN Expr DPAREN EXECUTE Comando {$$ = mknode(mknode($1,NULL,"EPAREN"),mknode($4,$6,"EXECUTE"),"Expr");}
        | Bloco         {$$ = $1;}
        ;

Expr : AssignExpr       {$$ = $1;}
     ;

AssignExpr : CondExpr {$$ = $1;}
           | LValueExpr ATRIB AssignExpr {$$ = mknode($1,$3,"ATRIB");}
           ;

CondExpr : OrExpr {$$ = $1;}
         | OrExpr INTERROG Expr DOISPONT CondExpr {$$ = mknode(mknode($1,NULL,"INTERROG"),mknode($4,NULL,"CondExpr"),"Expr");}
         ;

OrExpr : OrExpr OUEXPR AndExpr  {$$ = mknode($1,$3,"OUEXPR");}
       | AndExpr        {$$ = $1;}
       ;

AndExpr : AndExpr EEXPR EqExpr          {$$ = mknode($1,$3,"EEXPR");}
        | EqExpr        {$$ = $1;}
        ;

EqExpr : EqExpr DBIGUAL DesigExpr       {$$ = mknode($1,$3,"DBIGUAL");}
       | EqExpr DIFF DesigExpr          {$$ = mknode($1,$3,"DIFF");}
       | DesigExpr      {$$ = $1;}
       ;

DesigExpr : DesigExpr MENORQ AddExpr    {$$ = mknode($1,$3,"MENORQ");}
          | DesigExpr MAIORQ AddExpr    {$$ = mknode($1,$3,"MAIORQ");}  
          | DesigExpr MENORIGQ AddExpr  {$$ = mknode($1,$3,"MENORIGQ");}
          | DesigExpr MAIORIGQ AddExpr  {$$ = mknode($1,$3,"MAIORIGQ");}
          | AddExpr     {$$ = $1;}
          ;

AddExpr : AddExpr MAIS MulExpr  {$$ = mknode($1,$3,"MAIS");}
        | AddExpr MENOS MulExpr {$$ = mknode($1,$3,"MENOS");}
        | MulExpr       {$$ = $1;}
        ;

MulExpr : MulExpr VEZES UnExpr  {$$ = mknode($1,$3,"VEZES");}
        | MulExpr DIV UnExpr    {$$ = mknode($1,$3,"DIV");}
        | MulExpr RESTO UnExpr  {$$ = mknode($1,$3,"RESTO");}
        | UnExpr        {$$ = $1;}
        ;       

UnExpr : MENOS PrimExpr {$$ = mknode(NULL,$2,"MENOS");}
       | ANULEXPR PrimExpr      {$$ = mknode(NULL,$2,"ANULEXPR");}      
       | PrimExpr       {$$ = $1;}
       ;

LValueExpr : ID EBRACK Expr DBRACK      {$$ = mknode(mknode($1,NULL,"EBRACK"),$4,"Expr");}
           | ID {$$ = mknode(NULL,NULL,"ID");}
           ;

PrimExpr : ID EPAREN ListExpr DPAREN    {$$ = mknode(mknode($1,NULL,"EPAREN"),$4,"ListExpr");}
         | ID EPAREN DPAREN     {$$ = mknode($1,$3,"EPAREN");}
         | ID EBRACK Expr DBRACK        {$$ = mknode(mknode($1,NULL,"EBRACK"),$4,"Expr");}
         | ID           {$$ = mknode(NULL,NULL,"ID");}
         | CARCONST     {$$ = mknode(NULL,NULL,"CARCONST");}
         | INTCONST     {$$ = mknode(NULL,NULL,"INTCONST");}
         | EPAREN Expr DPAREN   {$$ = mknode($1,$3,"Expr");}
         ;

ListExpr : AssignExpr   {$$ = $1;}
         | ListExpr VIRGULA AssignExpr {$$ = mknode($1, $3, "VIRGULA");}
         ;
%%

yywrap(){
	return 1;
}

main(){
	yyparse();
        
}

node *mknode(node *left, node *right, char *token){
        /*printf("PRINTING TOKEN %s\n", token);
        if(left == NULL) printf("leftNNULL\n");
        if(right == NULL) printf("RightNULL\n");*/
        if(token == NULL) return NULL;
        node *newnode = (node *)malloc(sizeof(node));
        newnode->token = (char *)malloc(sizeof(strlen(token)+1));
        newnode->left = left;
        newnode->right = right;
        strcpy(newnode->token,token);
        //if(newnode->token) printf("TOK: %s ",newnode->token); 
        //if(newnode->left) printf("LFT: %s ",newnode->left->token); else printf("\n");
        //if(newnode->right) printf("RGH: %s\n",newnode->right->token); else printf("\n");
        //printtree(newnode); printf("\n");
        return newnode;
}
void printtree(node *tree) {
        if(tree == NULL) return;
        if(tree->left) printtree(tree->left);
        printf("%s ", tree->token);
        if(tree->right) printtree(tree->right);
 }