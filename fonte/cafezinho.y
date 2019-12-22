%{
      #include "type.h"
	#include <stdio.h>
      #include <string.h>
      #include <ctype.h>
      static char* enumStrings[] = {"programa","DeclFuncVar1","DeclFuncVar2","DeclFuncVar3","DeclFunc","ListaParametrosCont3",
"ListaParametrosCont4","Bloco1","ListaDeclVar2","ListaDeclVar3","Tipo","ListaComando2","Retorne","Leia","Escreva",
"EscrevaString","Novalinha","Se","SeSenao","Enquanto","Atribuir","SeTernario","Or","And","IgualIgual","Diferente","Menor",
"Maior","MenorIg","MaiorIg","Mais","Menos","Vezes","Divisao","Resto","Negativo","Negacao","IdentificadorBEB","Identificador",
"IdentificadorLista","Carconst","Intconst","Virgula","Main"};
      extern int yylineno;
      node *mknode(Operator type, int line, node *first, node *second, node *third, char *token);
      void printtree(node *tree);
      char *convert2Str(int x);
      void createSymbolTree(node *tree);
      char *newName(char *token);
      void createScopeTree(node *tree, char escopoAtual[100], symbolTree *noAtual);
      void insertChild(symbolTree *tree, symbolTree *newNode);
      symbolTable *initTable(char *token, int line, char *type, node *astPointer);
      void insertSymbol(symbolTable *table, char *token, int line, char *type, node *astPointer);
      int searchSymbol(symbolTable *table, char *token);
      //symbolTree operations
      symbolTree *createScope(char *scope);
      symbolTree *searchScope(symbolTree *tree, char *scope);
      void insertOnScope(symbolTree *tree,char *scope,char *token, int line, char *type, node *astPointer);
      symbolTree *scopeTree;
      node *tree;
      char escopo[100] = "global";
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
	PROGRAMA Bloco {$$ = mknode(Main,yylineno,$2,NULL,NULL,NULL);}
         ;

DeclVar : VIRGULA ID DeclVar {$$ = $3;}
        | VIRGULA ID EBRACK INTCONST DBRACK DeclVar {$$ = $6;}
        | {$$ = NULL;}
        ;

DeclFunc : EPAREN ListaParametros DPAREN Bloco {$$ = mknode(DeclFunc,yylineno,$2,$4,NULL,newName(yyval.string));}
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

LValueExpr : ID EBRACK Expr DBRACK {$$ = mknode(IdentificadorBEB,yylineno,$3,NULL,NULL,newName(yyval.string));}
           | ID {$$ = mknode(Identificador,yylineno,NULL,NULL,NULL,newName(yyval.string));}
           ;

PrimExpr : ID EPAREN ListExpr DPAREN {$$ = mknode(IdentificadorLista,yylineno,$3,NULL,NULL,newName(yyval.string));}
         | ID EPAREN DPAREN {$$ = mknode(Identificador,yylineno,NULL,NULL,NULL,newName(yyval.string));}
         | ID EBRACK Expr DBRACK {$$ = mknode(IdentificadorBEB,yylineno,$3,NULL,NULL,newName(yyval.string));}
         | ID {$$ = mknode(Identificador,yylineno,NULL,NULL,NULL,newName(yyval.string));}
         | CARCONST {$$ = mknode(Carconst,yylineno,NULL,NULL,NULL,newName(yyval.string));}
         | INTCONST {$$ = mknode(Intconst,yylineno,NULL,NULL,NULL,convert2Str(yyval.string));}
         | EPAREN Expr DPAREN {$$ = $2;}
         ;

ListExpr : AssignExpr {$$ = $1;}
         | ListExpr VIRGULA AssignExpr {$$ = mknode(Virgula, yylineno,$1, $3, NULL, NULL);}
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
      //printtree(tree);
      scopeTree = createScope("programa");
      createScopeTree(tree, "programa", scopeTree);
      printScopeTree(scopeTree);       
}

node *mknode(Operator type, int line, node *first, node *second, node *third, char *token){
       // printf("MAKE NEW NODE");
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
        //switch 
        printf("(");
        switch(tree->type){
            case Main:
                  printf("PROGRAMA ");
                  break;
          case programa:
                printf("programa %s", tree->token);
                break;
          case DeclFuncVar1:
                printf("DeclFuncVar1 %s", tree->token);
                break;
          case DeclFuncVar2:
                printf("DeclFuncVar2 %s", tree->token);
                break;
          case DeclFuncVar3:
                printf("DeclFuncVar3 %s", tree->token);
                break;
          case DeclFunc:
                printf("ListaParametrosCont3 %s", tree->token);
                break;
          case ListaParametrosCont4:
                printf("ListaParametrosCont4 %s", tree->token);
                break;
          case Bloco1:
                printf("Bloco1 %s", tree->token);
                break;
          case ListaDeclVar2:
                printf("ListaDeclVar2 %s", tree->token);
                break;
          case ListaDeclVar3:
                printf("ListaDeclVar3 %s", tree->token);
                break;
          case Tipo:
                printf("Tipo %s ", tree->token);
                break;
          case ListaComando2:
                printf("ListaComando2 ");
                printf("DeclFunc %s", tree->token);
                break;
          case ListaParametrosCont3:
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
                printf("EscrevaString %s ", tree->token);
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
                printf("Identificador[] %s", tree->token);
                break;
          case Identificador:
                printf("Identificador %s", tree->token);
                break;
          case IdentificadorLista:
                printf("Identificador() %s", tree->token);
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
        //printf(" - Line: %d", tree->line);
        
        //
        printtree(tree->first);
        printtree(tree->second);
        printtree(tree->third);
        printf(")");
 }

void printScopeTree(symbolTree *tree){
      if(tree == NULL){
            printf("ERROR: SymbolTree NULL\n");
            return;
      }
      printf("ESCOPO %s NumChild %d;", tree->scope, tree->nChild);
      if(!tree->nChild) return;
      int i;
      printf("(");
      for(i = 0; i < tree->nChild; i++) printScopeTree(tree->childs[i]);
      printf(")");
}

void insertChild(symbolTree *tree, symbolTree *newNode){
      if(tree == NULL) return;
      printf("got here %s\n", newNode->scope);
      //if(tree->childs == NULL) tree->childs = (symbolTree **)malloc(sizeof(symbolTree *));
      //tree->childs[tree->nChild] = (symbolTree *)malloc(sizeof(symbolTree));
      tree->childs[tree->nChild] = newNode;
      tree->nChild++;
      printf("%s %d\n",tree->childs[tree->nChild-1]->scope,tree->childs[tree->nChild-1]->nChild);
      return; 
}
void createScopeTree(node *tree, char escopoAtual[100], symbolTree *noAtual) {
        //printf("Creating Tree....\n");
        symbolTree *nodeAux, *newNode;
        if(tree == NULL){
            //printf("ERROR: NULL AST\n");
            return;
        }
        //switch operator
        switch(tree->type){
            
            case programa:
                  printf("Atualizando escopo para programa\n");
                  escopoAtual = "programa"; 
                  break;
            case DeclFunc:
                  nodeAux = searchScope(scopeTree,tree->token);
                  if(nodeAux == NULL){
                        printf("Criando escopo %s como subescopo de %s\n", tree->token,escopoAtual);
                        //newNode = searchScope(scopeTree,escopoAtual);
                        newNode = createScope(tree->token);
                        if(newNode != NULL) insertChild(noAtual,newNode);
                        else printf("newNode NULL\n");
                  }
                  escopoAtual=tree->token;
                  noAtual = newNode;
                  printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
            case Main:
                  nodeAux = searchScope(scopeTree,"PROGRAMA");
                  if(nodeAux == NULL){
                        printf("Criando escopo PROGRAMA como subescopo de programa\n");
                        noAtual = searchScope(scopeTree,"programa");
                        newNode = createScope("PROGRAMA");
                        if(newNode != NULL) insertChild(noAtual,newNode);
                  }
                  escopoAtual="PROGRAMA";
                  noAtual = newNode;
                  printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
            case Se:
                  printf("Criando escopo Se como subescopo de %s\n",escopoAtual);
                  newNode = createScope("Se");
                  if(newNode != NULL) insertChild(noAtual,newNode);
                  escopoAtual="Se";
                  noAtual = newNode;
                  printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
            case SeSenao:
                  printf("Criando escopo SeSenao como subescopo de %s\n",escopoAtual);
                  newNode = createScope("SeSenao");
                  if(newNode != NULL) insertChild(noAtual,newNode);
                  escopoAtual="SeSenao";
                  noAtual = newNode;
                  printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
            case Enquanto:
                  printf("Criando escopo Enquanto como subescopo de %s\n",escopoAtual);
                  newNode = createScope("Enquanto");
                  if(newNode != NULL) insertChild(noAtual,newNode);
                  noAtual = newNode;
                  escopoAtual="Enquanto";
                  printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
        }
          
        createScopeTree(tree->first,escopoAtual,noAtual);
        createScopeTree(tree->second,escopoAtual,noAtual);
        createScopeTree(tree->third,escopoAtual,noAtual);
 }

 char *convert2Str(int x){
        int length = snprintf( NULL, 0, "%d", x );
        char* str = malloc( length + 1 );
        snprintf( str, length + 1, "%d", x );
        return str;
}

char *newName(char *token){
      if(token == NULL) return NULL;
      //printf("NEWNAME ");
      int it, token_size,pos;
      token_size = strlen(token);
     // printf("NEWNAME2 ");
      pos = 0;
      char *aux = (char *)malloc(sizeof(char)*(strlen(token)+1));
      //printf("NEWNAME3 ");
      for(it = 0; it < token_size;it++){
            if(!isalnum(token[(int)it])){
                  //printf("NEWNAME4 ");
                  pos = it;
                  break;
            }
      }
      if(pos != 0){
            for(it = 0; it < pos; it++){
                  aux[it] = token[it];
            }
            return aux;
      }
      return token;
}
symbolTable *initTable(char *token, int line, char *type, node *astPointer){
    symbolTable *newnode = (symbolTable *)malloc(sizeof(symbolTable));
    newnode->token = (char *)malloc(sizeof(char)*(strlen(token)+1));
    strcpy(newnode->token,token);
    newnode->line = line;
    newnode->type = (char *)malloc(sizeof(char)*(strlen(type)+1));
    strcpy(newnode->type,type);
    newnode->astPointer = astPointer;
    newnode->next = NULL;
    return newnode;
}

void insertSymbol(symbolTable *table, char *token, int line, char *type, node *astPointer){
    if(table == NULL){
        table = initTable(token,line,type,astPointer);
        return;
    }
    symbolTable *aux, *auxNext = table;
    while(auxNext != NULL){
        aux = auxNext;
        auxNext = auxNext->next;
        if(auxNext == NULL) break;
    }
    if(aux == NULL) { printf("ERRO: INSERCAO FALIDA\n"); return;}
    symbolTable *newnode = (symbolTable *)malloc(sizeof(symbolTable));
    newnode->token = (char *)malloc(sizeof(char)*(strlen(token)+1));
    strcpy(newnode->token,token);
    newnode->line = line;
    newnode->type = (char *)malloc(sizeof(char)*(strlen(type)+1));
    strcpy(newnode->type,type);
    newnode->astPointer = astPointer;
    newnode->next = NULL;
    aux->next = newnode;
    return;
}

int searchSymbol(symbolTable *table, char *token){
    if(table == NULL) return 0;
    symbolTable *it,*aux;
    while(it != NULL){
        if(it == NULL) break;
        if(strcmp(it->token,token)==0){
            return 1;
            break;
        }
        it = it->next;
    }
    return 0;
}

//symbolTable operations end

//symbolTree operations

symbolTree *createScope(char *scope){
    symbolTree *newnode = (symbolTree *)malloc(sizeof(symbolTree));
    newnode->nChild = 0;
    newnode->childs = (symbolTree **)malloc(sizeof(symbolTree *));
    newnode->table = NULL;
    newnode->scope = (char *)malloc(sizeof(char)*(strlen(scope)+1));
    //printf("scope be4 %s", scope);
    strcpy(newnode->scope,scope);
    //printf("scope after %s", newnode->scope);
    return newnode;
}

symbolTree *searchScope(symbolTree *tree, char *scope){
      if(tree == NULL) return NULL;
      if(strcmp(tree->scope,scope) == 0) return tree;
      if(tree->nChild == 0) return NULL;
      int i;
      symbolTree *retorn;
      for(i = 0; i < tree->nChild; i++) 
            retorn = searchScope(tree->childs[i],scope);
      return retorn;
}

void insertOnScope(symbolTree *tree,char *scope,char *token, int line, char *type, node *astPointer){
    if(tree == NULL){
        tree = createScope(scope);
        if(token != NULL) insertSymbol(tree->table,token,line,type,astPointer);
        return;
    }
    symbolTree *node = searchScope(tree,scope);
    if(node != NULL) insertSymbol(node->table,token,line,type,astPointer);
    else{
        tree->nChild++;
        insertOnScope(&tree->childs[tree->nChild-1],scope,token,line,type,astPointer);
    }
    return;
}

