#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum{programa,DeclFuncVar1,DeclFuncVar2,DeclFuncVar3,DeclFunc,ListaParametrosCont3,
ListaParametrosCont4,Bloco1,ListaDeclVar2,ListaDeclVar3,Tipo,ListaComando2,Retorne,Leia,Escreva,
EscrevaString,Novalinha,Se,SeSenao,Enquanto,Atribuir,SeTernario,Or,And,IgualIgual,Diferente,Menor,
Maior,MenorIg,MaiorIg,Mais,Menos,Vezes,Divisao,Resto,Negativo,Negacao,IdentificadorBEB,Identificador,
IdentificadorLista,Carconst,Intconst,Virgula,Main,DeclVar1,DeclVar2,ListaParametrosCont1,ListaParametrosCont2,ListaParametros2}Operator;

typedef struct param{
    int t_size;
    char **variables;
}param;
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
    char **params;
    int nChild, nTable,nParams;
    node *astPointer;
    struct symbolTree **childs;
    struct symbolTable **table;
}symbolTree;