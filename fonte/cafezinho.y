%{
      #include "type.h"
	#include <stdio.h>
      #include <string.h>
      #include <ctype.h>
      static char* enumStrings[] = {"programa","DeclFuncVar1","DeclFuncVar2","DeclFuncVar3","DeclFunc","ListaParametrosCont3",
"ListaParametrosCont4","Bloco1","ListaDeclVar2","ListaDeclVar3","Tipo","ListaComando2","Retorne","Leia","Escreva",
"EscrevaString","Novalinha","Se","SeSenao","Enquanto","Atribuir","SeTernario","Or","And","IgualIgual","Diferente","Menor",
"Maior","MenorIg","MaiorIg","Mais","Menos","Vezes","Divisao","Resto","Negativo","Negacao","IdentificadorBEB","Identificador",
"IdentificadorLista","Carconst","Intconst","Virgula","Main","DeclVar1","DeclVar2","ListaParametrosCont1", "ListaParametrosCont2","ListaParametros2"};
      extern int yylineno;
      char *alphaNum(char *token);
      node *mknode(Operator type, int line, node *first, node *second, node *third, char *token);
      void printtree(node *tree);
      void printTable(symbolTable **table, int t_size);
      char *convert2Str(int x);
      void createSymbolTree(node *tree);
      symbolTable *createSymbolNode(char *token,int *line,char *type,node *astPointer,int decl);
      char *newName(char *token);
      void createScopeTree(node *tree, char escopoAtual[100], symbolTree *noAtual, char tipoAtual[100]);
      void insertChild(symbolTree *tree, symbolTree *newNode);
      void insertSymbol(symbolTree *tree, symbolTable *newNode);
      symbolTable *searchSymbol(symbolTable **table, int t_size, char *token, char *type);
      //symbolTree operations
      symbolTree *createScope(char *scope, char *type, node *astPointer);
      symbolTree *searchScope(symbolTree *tree, char *scope);
      void insertOnScope(symbolTree *tree,char *scope,char *token, int line, char *type, node *astPointer);
      void propagarType(symbolTree *tree);
      void assignTypes(symbolTree *tree, symbolTable *symbol);
      void procurarDeclaracoes(symbolTree *tree);
      void BuscaEmProfundidade(symbolTree *tree, symbolTable *symbol);
      void getReturnNode(node *tree, char *funcReturn);
      void checkReturn(symbolTree *tree);
      void BuscaChamadas(symbolTree *tree, symbolTree *unalteredTree);
      void PercorreSubArvore(node *tree, param *Vars);
      symbolTable *lookForSymbol(symbolTree *tree,char *scope,char *token);
      symbolTree *scopeTree;
      node *tree;
      char StringAux[100];
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
%token INTCONST CARCONST STRING
%token <string> ID

%%
programa : DeclFuncVar DeclProg {tree = mknode(programa,yylineno,$1,$2,NULL,NULL);}
         ;

DeclFuncVar : Tipo ID DeclVar SEMI DeclFuncVar {$$ = mknode(DeclFuncVar1,yylineno,$1,$3,$5,newName($2));}
            | Tipo ID EBRACK INTCONST DBRACK DeclVar SEMI DeclFuncVar {$$ = mknode(DeclFuncVar2,yylineno,$1,$6,$8,newName($2));}
            | Tipo ID DeclFunc DeclFuncVar {$$ = mknode(DeclFuncVar3,yylineno,$1,$3,$4,newName($2));}
            | {$$ = NULL;}
            ;

DeclProg : 
	PROGRAMA Bloco {$$ = mknode(Main,yylineno,$2,NULL,NULL,NULL);}
         ;

DeclVar : VIRGULA ID DeclVar {$$ = mknode(DeclVar1,yylineno,$3,NULL,NULL,newName($2));}
        | VIRGULA ID EBRACK INTCONST DBRACK DeclVar {$$ = mknode(DeclVar2,yylineno,$6,NULL,NULL,newName($2));}
        | {$$ = NULL;}
        ;

DeclFunc : EPAREN ListaParametros DPAREN Bloco {$$ = mknode(DeclFunc,yylineno,$2,$4,NULL,newName(yyval.string));}
         ;

ListaParametros : {$$ = NULL;}
                | ListaParametrosCont {$$ = mknode(ListaParametros2,yylineno,$1,NULL,NULL,NULL);}
                ;

ListaParametrosCont : Tipo ID {$$ = mknode(ListaParametrosCont1,yylineno,$1,NULL,NULL,newName($2));}
                    | Tipo ID EBRACK DBRACK {$$ = mknode(ListaParametrosCont2,yylineno,$1,NULL,NULL,newName($2));}
                    | Tipo ID VIRGULA ListaParametrosCont {$$ = mknode(ListaParametrosCont3,yylineno,$1,$4,NULL,newName($2));}
                    | Tipo ID EBRACK DBRACK VIRGULA ListaParametrosCont {$$ = mknode(ListaParametrosCont4,yylineno,$1,$6,NULL,newName($2));}
                    ;

Bloco : EBRACE ListaDeclVar ListaComando DBRACE {$$ = mknode(Bloco1,yylineno,$2,$3,NULL,NULL);}
      | EBRACE ListaDeclVar DBRACE {$$ = $2;}
      ;

ListaDeclVar : {$$ = NULL;}
             | Tipo ID DeclVar SEMI ListaDeclVar {$$ = mknode(ListaDeclVar2,yylineno,$1,$3,$5,newName($2));}
             | Tipo ID EBRACK INTCONST DBRACK DeclVar SEMI ListaDeclVar {$$ = mknode(ListaDeclVar3,yylineno,$1,$6,$8,newName($2));}
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
      //printtree(tree); //funcao para imprimir a arvore de sintaxe abstrata
      //printScopeTree(scopeTree); //funcao para imprimir arvore de scopos
      fflush(stdin); 
      /*
            Criacao da arovre de escopos
      */
      scopeTree = createScope("programa",NULL,tree); //
      createScopeTree(tree, "programa", scopeTree, "NOTYPE");
      /* ******************************************** */

      /*
            Análise semântica
      */
      propagarType(scopeTree); //propaga para os nós filhos o tipo de uma variável declarada      
      procurarDeclaracoes(scopeTree); //procura por declaracoes de nome igual a algum parametro do mesmo escopo
      checkReturn(scopeTree); //compara o retorno da funcao com uma chamada de retorno interna
      BuscaChamadas(scopeTree, scopeTree); //procura chamadas de função e faz tratamento de erros
      /* ******************************************** */     
}
/*
      Criacao de um nó da AST
*/
node *mknode(Operator type, int line, node *first, node *second, node *third, char *token){
        node *newnode = (node *)malloc(sizeof(node));
        if(newnode == NULL) return NULL;
        newnode->type = type;
        newnode->line = line;
        newnode->first = first;
        newnode->second = second;
        newnode->third = third;
        if(token != NULL){
               newnode->token = (char *)malloc(sizeof(char)*(strlen(token)+1));
               strcpy(newnode->token,token); 
        }
        else newnode->token = NULL;
        return newnode;
}
/*
      Impressao da AST
*/
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
      case DeclVar1:
            printf("DeclVar1 %s", tree->token);
            break;
      case DeclVar2:
            printf("DeclVar2 %s", tree->token);
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
            printf("DeclFunc %s", tree->token);
            break;
      case ListaParametros2:
            printf("ListaParametros2 %s", tree->token);
            break;
      case ListaParametrosCont1:
            printf("ListaParametrosCont1 %s", tree->token);
            break;
      case ListaParametrosCont2:
            printf("ListaParametrosCont2 %s", tree->token);
            break;
      case ListaParametrosCont3:
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

/*
      Impressao de uma tabela de símbolos
*/
 void printTable(symbolTable **table, int t_size){
      if(table == NULL) return;
      int i;
      for(i = 1; i <= t_size; i++){
            printf("%s %s decl:%d;", table[i]->token, table[i]->type, table[i]->decl);
      }
 }

/*
/*
      Impressao da arvore de escopos
*/
void printScopeTree(symbolTree *tree){
      if(tree == NULL){
            printf("ERROR: SymbolTree NULL\n");
            return;
      }
      int i;
      printf("ESCOPO %s NumChild %d; Tipo: %s ;Tabela:", tree->scope, tree->nChild, tree->type);
      printTable(tree->table,tree->nTable);
      printf("numParams: %d; ", tree->nParams);
      for(i = 1; i <= tree->nParams;i++){
            printf("%s;", tree->params[i]);
      }
      if(!tree->nChild) return;
      printf("(");
      for(i = 0; i < tree->nChild; i++) printScopeTree(tree->childs[i]);
      printf(")");
}

/*
      Insercao de um nó filho em um escopo
*/
void insertChild(symbolTree *tree, symbolTree *newNode){
      if(tree == NULL) return;
      //printf("got here %s\n", newNode->scope);
      //if(tree->childs == NULL) tree->childs = (symbolTree **)malloc(sizeof(symbolTree *));
      //tree->childs[tree->nChild] = (symbolTree *)malloc(sizeof(symbolTree));
      tree->childs[tree->nChild] = newNode;
      tree->nChild++;
      //printf("%s %d\n",tree->childs[tree->nChild-1]->scope,tree->childs[tree->nChild-1]->nChild);
      return; 
}

/*
      createScopeTree percorre a AST construindo uma árvore de escopos baseado nas funções
      e declaração de programa; em seguida, são construídas as tabelas de símbolo de cada escopo
*/
void createScopeTree(node *tree, char escopoAtual[100], symbolTree *noAtual,char tipoAtual[100]) {
        //printf("Creating Tree....\n");
        symbolTree *nodeAux, *newNode;
        if(tree == NULL){
            //printf("ERROR: NULL AST\n");
            return;
        }
        //switch operator to create scope
        switch(tree->type){
            
            case programa:
                  //printf("Atualizando escopo para programa\n");
                  escopoAtual = "programa"; 
                  break;
            //case DeclFuncVar1:
            //case DeclFuncVar2:
            case DeclFuncVar3:
                  nodeAux = searchScope(scopeTree,tree->token);
                  if(nodeAux == NULL){
                        //printf("Criando escopo %s como subescopo de %s\n", tree->token,escopoAtual);
                        //newNode = searchScope(scopeTree,escopoAtual);
                        //printf("DeclFuncVar3 tipo da funcao %s",tree->first->token);
                        newNode = createScope(tree->token,tree->first->token,tree);
                        if(newNode != NULL) insertChild(noAtual,newNode);
                        else printf("newNode NULL\n");
                  }
                  escopoAtual=tree->token;
                  noAtual = newNode;
                  //printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
            case Main:
                  nodeAux = searchScope(scopeTree,"PROGRAMA");
                  if(nodeAux == NULL){
                        //printf("Criando escopo PROGRAMA como subescopo de programa\n");
                        noAtual = searchScope(scopeTree,"programa");
                        newNode = createScope("PROGRAMA",NULL,tree);
                        if(newNode != NULL) insertChild(noAtual,newNode);
                  }
                  escopoAtual="PROGRAMA";
                  noAtual = newNode;
                  //printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
            case Se:
                  //printf("Criando escopo Se como subescopo de %s\n",escopoAtual);
                  newNode = createScope("Se",NULL,tree);
                  if(newNode != NULL) insertChild(noAtual,newNode);
                  escopoAtual="Se";
                  noAtual = newNode;
                  //printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
            case SeSenao:
                  //printf("Criando escopo SeSenao como subescopo de %s\n",escopoAtual);
                  newNode = createScope("SeSenao",NULL,tree);
                  if(newNode != NULL) insertChild(noAtual,newNode);
                  escopoAtual="SeSenao";
                  noAtual = newNode;
                  //printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
            case Enquanto:
                  //printf("Criando escopo Enquanto como subescopo de %s\n",escopoAtual);
                  newNode = createScope("Enquanto",NULL,tree);
                  if(newNode != NULL) insertChild(noAtual,newNode);
                  noAtual = newNode;
                  escopoAtual="Enquanto";
                  //printf("Atualizando escopo para %s\n",escopoAtual);
                  break;
        }

      symbolTable *novoNode;
      switch(tree->type){
            case DeclFuncVar1:
            case DeclFuncVar2:
            case ListaDeclVar2:
            case ListaDeclVar3:
                  tipoAtual = tree->first->token;
                  //printf("ListaDeclVar2ou3 %s\n",tipoAtual);
                  if(searchSymbol(noAtual->table,noAtual->nTable,tree->token,tipoAtual)==NULL){
                        novoNode = createSymbolNode(tree->token,tree->line,tipoAtual,tree,1);
                        noAtual->nTable++;
                        noAtual->table[noAtual->nTable] = novoNode;
                        //printf("TOKEN %s SIZE TABLE %d\n", noAtual->table[noAtual->nTable]->token,noAtual->nTable);
                        
                  }
                  else{
                        printf("ERRO SEMANTICO: VARIAVEL %s DECLARADA NO ESCOPO DO PARAMETRO DE MESMO NOME LINHA %d\n", tree->token,tree->line-1);
                        exit(1);       
                  }
                  break;
            case DeclVar1: 
            case DeclVar2:
                  if(searchSymbol(noAtual->table,noAtual->nTable,tree->token,tipoAtual)==NULL){
                        novoNode = createSymbolNode(tree->token,tree->line,tipoAtual,tree,1);
                        noAtual->nTable++;
                        noAtual->table[noAtual->nTable] = novoNode;
                        //printf("TOKEN %s SIZE TABLE %d\n", noAtual->table[noAtual->nTable]->token,noAtual->nTable);
                  }
                  else{
                        printf("ERRO SEMANTICO: VARIAVEL %s DECLARADA NO ESCOPO DO PARAMETRO DE MESMO NOME LINHA %d\n", tree->token,tree->line-1);
                        exit(1);    
                  }
                  break;
            case ListaParametrosCont1:
            case ListaParametrosCont2:
            case ListaParametrosCont3:
            case ListaParametrosCont4:
                  tipoAtual = tree->first->token;
                  if(searchSymbol(noAtual->table,noAtual->nTable,tree->token,tipoAtual)==NULL){
                        novoNode = createSymbolNode(tree->token,tree->line,tipoAtual,tree,1);
                        int i,j;
                        int pos=0;
                        for(i = 0; i < strlen(novoNode->token); i++){
                              if(!isalnum(novoNode->token[i])){
                                    pos = i;
                                    break;
                              }
                        }
                        if(pos){
                              //printf("ENTEI");
                              strcpy(StringAux,novoNode->type);
                              strcpy(StringAux,alphaNum(StringAux));
                              if(novoNode->token[pos] == '['){
                                    strcat(StringAux,"[]");
                                    //printf("%s\n",symbol->type);
                                    strcpy(novoNode->type,StringAux);
                              }
                        }
                        strcpy(novoNode->token, alphaNum(novoNode->token));      
                        noAtual->nParams++;
                        noAtual->params[noAtual->nParams] = (char *)malloc(sizeof(char)*(strlen(novoNode->type)+1));
                        strcpy(noAtual->params[noAtual->nParams],novoNode->type);
                        
                        noAtual->nTable++;
                        noAtual->table[noAtual->nTable] = novoNode;
                        //("TOKEN %s SIZE TABLE %d\n", noAtual->table[noAtual->nTable]->token,noAtual->nTable);
                        
                  }
                  break;
            case IdentificadorBEB:
                  if(searchSymbol(noAtual->table,noAtual->nTable,tree->token,"[]")==NULL){
                              novoNode = createSymbolNode(tree->token,tree->line,"[]",tree,0);
                              noAtual->nTable++;
                              noAtual->table[noAtual->nTable] = novoNode;
                              //printf("TOKEN %s SIZE TABLE %d\n", noAtual->table[noAtual->nTable]->token,noAtual->nTable);
                  }
                  break;
            case Identificador:
                  if(searchSymbol(noAtual->table,noAtual->nTable,tree->token,"var")==NULL){
                              novoNode = createSymbolNode(tree->token,tree->line,"var",tree,0);
                              noAtual->nTable++;
                              noAtual->table[noAtual->nTable] = novoNode;
                              //printf("TOKEN %s SIZE TABLE %d\n", noAtual->table[noAtual->nTable]->token,noAtual->nTable);
                  }
                  break;
            case IdentificadorLista:
            if(searchSymbol(noAtual->table,noAtual->nTable,tree->token,"func()")==NULL){
                  novoNode = createSymbolNode(tree->token,tree->line,"()",tree,0);
                  noAtual->nTable++;
                  noAtual->table[noAtual->nTable] = novoNode;
                  //printf("TOKEN %s SIZE TABLE %d\n", noAtual->table[noAtual->nTable]->token,noAtual->nTable);
            }
            break;
      }
      createScopeTree(tree->first,escopoAtual,noAtual,tipoAtual);
      createScopeTree(tree->second,escopoAtual,noAtual,tipoAtual);
      createScopeTree(tree->third,escopoAtual,noAtual,tipoAtual);
 }

/*
      função auxiliar para converter um int para string
*/
 char *convert2Str(int x){
        int length = snprintf( NULL, 0, "%d", x );
        char* str = malloc( length + 1 );
        snprintf( str, length + 1, "%d", x );
        return str;
}
/*
      newName e alphaNum fazem correções nos nomes dos tokens de acordo com a necessidade,
      para armazenar os tipos de váriáveis car[] e int[]
*/
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
                  pos = it;
                  if(token[pos] == '['){
                         while(token[pos] != ']') pos++;
                        pos++;
                  }
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

char *alphaNum(char *token){
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
                  pos = it;
                  break;
            }
      }
      if(pos){
            for(it = 0; it < pos; it++){
                  aux[it] = token[it];
            }
            return aux;
      }
      return token;
}

/*
      criação de um nó da árvore de escopos
*/
symbolTree *createScope(char *scope, char *type, node *astPointer){
    symbolTree *newnode = (symbolTree *)malloc(sizeof(symbolTree));
    newnode->nChild = 0;
    newnode->nTable = 0;
    newnode->childs = (symbolTree **)malloc(sizeof(symbolTree *));
    newnode->scope = (char *)malloc(sizeof(char)*(strlen(scope)+1));
    strcpy(newnode->scope,scope);
    newnode->table = (symbolTable **)malloc(sizeof(symbolTable *)*2);
    newnode->table[0] = (symbolTable *)malloc(sizeof(symbolTable));
    newnode->table[1] = (symbolTable *)malloc(sizeof(symbolTable));
    if(type != NULL){
      newnode->type = (char *)malloc(sizeof(char)*(strlen(type)+1));
      strcpy(newnode->type,type);
    }
    newnode->nParams = 0;
    newnode->params = (char **)malloc(sizeof(char *)*2);
    newnode->astPointer = astPointer;
    //printf("scope after %s", newnode->scope);
    return newnode;
}

/*
      criação de um nó da árvore de símbolos
*/
symbolTable *createSymbolNode(char *token,int *line,char *type,node *astPointer,int decl){
      symbolTable *newnode = (symbolTable *)malloc(sizeof(symbolTable));
      newnode->token = (char *)malloc(sizeof(char)*(strlen(token)+1));
      strcpy(newnode->token,token);
      newnode->type = (char *)malloc(sizeof(char)*(strlen(type)+1));
      strcpy(newnode->type,type);
      newnode->line = line;
      newnode->astPointer = astPointer;
      newnode->decl = decl;
      return newnode;   
}
/*
      Busca um símbolo em uma tabela de símbolos
*/
symbolTable *searchSymbol(symbolTable **table, int t_size, char *token,char *type){
      if(table == NULL) return NULL;
      int i;
      for(i = 1; i <= t_size;i++){
            if(strcmp(table[i]->token,token) == 0 && strcmp(table[i]->type,type)==0) return table[i];
      }
      return NULL;
}
/*
      Busca um escopo baseado em seu identificador
*/
symbolTree *searchScope(symbolTree *tree, char *scope){
      if(tree == NULL){ return NULL;}
      if(strcmp(tree->scope,scope) == 0) {return tree;}
      if(tree->nChild == 0) {return NULL;}
      int i;
      for(i = 0; i < tree->nChild; i++) 
            return searchScope(tree->childs[i],scope);
}

/*
      Propagar tipos de variáveis declaradas para os nós filhos
*/

void propagarType(symbolTree *tree){
      if(tree == NULL) return;
      int i;
      for(i = 1; i <= tree->nTable; i++){
            assignTypes(tree,tree->table[i]);
      }
      for(i = 0; i < tree->nChild; i++){
            propagarType(tree->childs[i]);
      }
}

/*
     Altera os tipos das variáveis para seus tipos apropriados a partir da propagação dos tipos
*/
void assignTypes(symbolTree *tree, symbolTable *symbol){
      if(tree == NULL) return;
      /* casos: []
      *         ()
      *         var
      */ 
      int i,j;
      int pos=0;
      for(i = 0; i < strlen(symbol->token); i++){
            if(!isalnum(symbol->token[i])){
                  pos = i;
                  break;
            }
      }
      if(pos){
            //printf("ENTEI");
            strcpy(StringAux,symbol->type);
            strcpy(StringAux,alphaNum(StringAux));
            if(symbol->token[pos] == '['){
                  strcat(StringAux,"[]");
                  //printf("%s\n",symbol->type);
                  strcpy(symbol->type,StringAux);
            }
      }
      for(i = 1; i <= tree->nTable;i++){
            if(strcmp(alphaNum(symbol->token),alphaNum(tree->table[i]->token))==0){
                  strcpy(StringAux, symbol->type);
                  if(strcmp(tree->table[i]->type,"[]")==0){
                        strcpy(tree->table[i]->token, alphaNum(tree->table[i]->token));
                        //printf("AQUI1 %s\n\n", tree->table[i]->token);
                        //strcat(StringAux,"[]");
                        strcpy(tree->table[i]->type,StringAux); 
                  }
                  else if(strcmp(tree->table[i]->type,"var")==0){
                        //printf("AQUI3");
                        strcpy(tree->table[i]->type,StringAux);
                  }
                  else{
                        if(strcmp(tree->table[i]->type,symbol->type)!=0)
                              printf("ERRO SEMANTICO: VARIAVEIS DE TIPOS DISTINTOS COM MESMO NOME LINHA %d",tree->table[i]->line);
                  }
            }
      }
      strcpy(symbol->token, alphaNum(symbol->token));


      for(i = 0; i < tree->nChild; i++){
            assignTypes(tree->childs[i],symbol);
      }
}

/*
      Procura por declarações de variável com o mesmo nome de parâmetros de função do mesmo escopo
*/
void procurarDeclaracoes(symbolTree *tree){
      if(tree == NULL) return;
      int i;
      for(i = 1; i <= tree->nTable; i++){
            BuscaEmProfundidade(tree,tree->table[i]);
      }
      for(i = 0; i < tree->nChild; i++){
            procurarDeclaracoes(tree->childs[i]);
      }
}

/*
      Percorre a árvore de escopos em profundidade e detecta erros semânticos de variáveis não declaradas
*/
void BuscaEmProfundidade(symbolTree *tree, symbolTable *symbol){
      if(tree == NULL) return;
      /* casos: []
      *         ()
      *         var
      */ 
      int i,j;
      
      for(i = 1; i <= tree->nTable;i++){
            if(strcmp(alphaNum(symbol->token),alphaNum(tree->table[i]->token))==0){
                  if(strcmp(tree->table[i]->type,"[]")==0 ||strcmp(tree->table[i]->type,"var")==0){
                        printf("ERRO SEMANTICO: VARIAVEL %s NAO DECLARADA LINHA %d\n", tree->table[i]->token,tree->table[i]->line);
                        exit(1);
                  }
                  //printf("%d %p\t%d %p\n", symbol->decl,symbol->astPointer,tree->table[i]->decl,tree->table[i]->astPointer);
            }
      }


      for(i = 0; i < tree->nChild; i++){
            BuscaEmProfundidade(tree->childs[i],symbol);
      }
}

/*
      Compara o tipo do retorno com a variável retornada, lançando um erro semântico em caso de divergência
*/

void getReturnNode(node *tree, char *funcReturn){
      if(tree == NULL) return; 
      switch(tree->type){
            case Retorne:
                  //printf("Retorne %s", enumStrings[(int)tree->first->type]);
                  switch(tree->first->type){
                        case Mais:
                        case Menos:
                        case Vezes:
                        case Divisao:
                        case Resto:
                        case Negativo:
                        case Intconst:
                              if(strcmp(funcReturn,"int")!=0){
                                    printf("ERRO SEMANTICO: EXPRESSAO TEM TIPO INCOMPATIVEL COM RETORNO DA FUNCAO NA LINHA %d\n", tree->line);
                                    exit(1);
                              }
                              break;
                        case Carconst:
                              if(strcmp(funcReturn,"car")!=0){
                                    printf("ERRO SEMANTICO: EXPRESSAO TEM TIPO INCOMPATIVEL COM RETORNO DA FUNCAO NA LINHA %d\n", tree->line);
                                    exit(1);
                              }
                              break;

                  }
                  break;
            default:      
                  break;
      }
      getReturnNode(tree->first,funcReturn);
      getReturnNode(tree->second,funcReturn);
      getReturnNode(tree->third,funcReturn);
}

/*
      auxilia a função getReturnNode 
*/
void checkReturn(symbolTree *tree){
      if(tree == NULL) return;
      node *returnNode;
      if(tree->type != NULL){
            //printf("tipo funcao %s\n", tree->type);
            getReturnNode(tree->astPointer,tree->type);
      }
      int i;
      for(i = 0; i < tree->nChild;i++){
            checkReturn(tree->childs[i]);
      }

}
/*
      Percorre uma subárvore da AST para contar a quantidade de parâmetros e retornar seus tipos
*/
void PercorreSubArvore(node *tree, param *Vars){
      if(tree == NULL) return;
      int bb = 0; 
      switch(tree->type){
            case Mais:
            case Menos:
            case Vezes:
            case Divisao:
            case Resto:
            case Negativo:
                  bb = 1;
                  Vars->t_size++;
                  Vars->variables[Vars->t_size] = (char *)malloc(sizeof(char)*(strlen(enumStrings[(int)tree->type]+1)));
                  strcpy(Vars->variables[Vars->t_size],"Intconst");
                  break;
            case Intconst:
                  Vars->t_size++;
                  Vars->variables[Vars->t_size] = (char *)malloc(sizeof(char)*(strlen(enumStrings[(int)tree->type]+1)));
                  strcpy(Vars->variables[Vars->t_size],"Intconst");
                  break;
            case Carconst:
                  Vars->t_size++;
                  Vars->variables[Vars->t_size] = (char *)malloc(sizeof(char)*(strlen(enumStrings[(int)tree->type]+1)));
                  strcpy(Vars->variables[Vars->t_size],"Carconst");
                  break;
            case Identificador:
                  Vars->t_size++;
                  Vars->variables[Vars->t_size] = (char *)malloc(sizeof(char)*(strlen(tree->token)+1));
                  strcpy(Vars->variables[Vars->t_size],tree->token);
                  break;
      }
      if(!bb) PercorreSubArvore(tree->first,Vars);
      if(!bb) PercorreSubArvore(tree->second,Vars);
      if(!bb) PercorreSubArvore(tree->third,Vars);
}
/*
     Busca um tipo em um determinado escopo
*/
symbolTable *lookForSymbol(symbolTree *tree,char *scope,char *token){
      if(tree == NULL) return NULL;
      symbolTree *node = (symbolTree *)malloc(sizeof(symbolTree));
      node = searchScope(tree,scope);
      int i;
      printf("SCOPE %s %s\n", node->scope, scope);
      for(i = 1; i <= tree->nTable; i++){
            if(strcmp(node->table[i]->token,token)==0)
                  return node->table[i];
      }
}
/*
      Compara os tipos das variáveis de uma chamada de função com a declaração da função,
      além de conferir se a chamada tem a quantidade corretas de argumentos.
*/
void BuscaChamadas(symbolTree *tree, symbolTree *unalteredTree){
      if(tree == NULL) return;
      int i,j;
      
      for(i = 1; i <= tree->nTable;i++){
            //printf("TOK: %s TYPE: %s\n", tree->table[i]->token, tree->table[i]->type);
            if(strcmp(tree->table[i]->type,"()")==0){
                  //printf("Entrei aqui\n");
                  param *Vars = (param *)malloc(sizeof(param));
                  Vars->t_size = 0;
                  Vars->variables = (char **)malloc(sizeof(char *)*2);
                  Vars->variables[0] = (char *)malloc(sizeof(char));     
                  PercorreSubArvore(tree->table[i]->astPointer,Vars);
                  symbolTree *acScope = (symbolTree *)malloc(sizeof(symbolTree));
                  symbolTree *auxNode = (symbolTree *)malloc(sizeof(symbolTree));
                  acScope = searchScope(unalteredTree,tree->table[i]->token); 
                  if(acScope == NULL) return;
                  if(acScope->nParams != Vars->t_size){
                        printf("ERRO SEMANTICO: QUANTIDADE DE PARAMETROS INCORRETA, ESPERA-SE %d, FOI PASSADO %d NA LINHA %d\n", acScope->nParams,Vars->t_size, tree->table[i]->line);
                        exit(1);
                  }
                  int k;
                  //printf("Size: %d\n", Vars->t_size);
                  for(j = 1; j <= Vars->t_size;j++){
                        strcpy(StringAux,Vars->variables[j]);
                        for(k = 1; k <= tree->nTable;k++){
                              if(strcmp(tree->table[k]->token,Vars->variables[j])==0)
                                    strcpy(StringAux,tree->table[k]->type);
                        }
                        //printf("VARS %s\n", StringAux);
                        //printf("TOK::: %s :::: %s\n", StringAux, acScope->params[j]);
                        if(strcmp(acScope->params[j],StringAux) != 0){
                              if(strcmp(acScope->params[j], "car")==0 && strcmp(StringAux,"Carconst") !=0){
                                    printf("ERRO SEMANTICO: TIPO DE PARAMETRO INCORRETO NA LINHA %d\n", tree->table[i]->line);
                                    exit(1); 
                              }
                              else if(strcmp(acScope->params[j], "int")==0 && strcmp(StringAux,"Intconst") !=0){
                                    printf("ERRO SEMANTICO: TIPO DE PARAMETRO INCORRETO NA LINHA %d\n", tree->table[i]->line);
                                    exit(1); 
                              
                              }
                              else if(strcmp(acScope->params[j], "car[]")==0 && strcmp(StringAux,"car[]") !=0){
                                    printf("ERRO SEMANTICO: TIPO DE PARAMETRO INCORRETO NA LINHA %d\n", tree->table[i]->line);
                                    exit(1); 
                              }
                              else if(strcmp(acScope->params[j], "int[]")==0 && strcmp(StringAux,"int[]") !=0){
                                    printf("ERRO SEMANTICO: TIPO DE PARAMETRO INCORRETO NA LINHA %d\n", tree->table[i]->line);
                                    exit(1); 
                              }
                        }
                        
                  }
                  //printf("\n");
            }
      }
      for(i = 0; i < tree->nChild; i++){
            BuscaChamadas(tree->childs[i], unalteredTree);
      }
}