#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum{programa,DeclFuncVar1,DeclFuncVar2,DeclFuncVar3,DeclFunc,ListaParametrosCont3,
ListaParametrosCont4,Bloco1,ListaDeclVar2,ListaDeclVar3,Tipo,ListaComando2,Retorne,Leia,Escreva,
EscrevaString,Novalinha,Se,SeSenao,Enquanto,Atribuir,SeTernario,Or,And,IgualIgual,Diferente,Menor,
Maior,MenorIg,MaiorIg,Mais,Menos,Vezes,Divisao,Resto,Negativo,Negacao,IdentificadorBEB,Identificador,
IdentificadorLista,Carconst,Intconst,Virgula,Main,DeclVar1,DeclVar2,ListaParametrosCont1,ListaParametrosCont2,ListaParametros2}Operator;

//definicao de um no da arvore de sintaxe abstrata
typedef struct node{ 
        Operator type;
        int line;
        struct node *first;
        struct node *second;
        struct node *third;
        char *token;
}node;

//IDEA: Cada nó de uma árvore de escopos armazena uma tabela de símbolos representando aquele escopo.
typedef struct symbolTable{
    char *token;
    int line; //talvez
    char *type;
    int decl;
    struct node *astPointer;
}symbolTable;
typedef struct symbolTree{
    char* scope;
    char*type;
    int nChild, nTable;
    node *astPointer;
    struct symbolTree **childs;
    struct symbolTable **table;
}symbolTree;

/*symbolTable Operations
symbolTable *initTable(char *token, int line, char *type, node *astPointer);
void insertSymbol(symbolTable *table, char *token, int line, char *type, node *astPointer);
int searchSymbol(symbolTable *table, char *token);
//symbolTree operations
symbolTree *createScope(char *scope);
symbolTree *searchScope(symbolTree *tree, char *scope);
void insertOnScope(symbolTree *tree,char *scope,char *token, int line, char *type, node *astPointer);
*/