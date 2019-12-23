#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum{programa,DeclFuncVar1,DeclFuncVar2,DeclFuncVar3,DeclFunc,ListaParametrosCont3,
ListaParametrosCont4,Bloco1,ListaDeclVar2,ListaDeclVar3,Tipo,ListaComando2,Retorne,Leia,Escreva,
EscrevaString,Novalinha,Se,SeSenao,Enquanto,Atribuir,SeTernario,Or,And,IgualIgual,Diferente,Menor,
Maior,MenorIg,MaiorIg,Mais,Menos,Vezes,Divisao,Resto,Negativo,Negacao,IdentificadorBEB,Identificador,
IdentificadorLista,Carconst,Intconst,Virgula,Main,DeclVar1,DeclVar2,ListaParametrosCont1,ListaParametrosCont2,ListaParametros2}Operator;

/*
      * Estrutura param utilizada para armazenar os parâmetros encontrados em uma chamada de função
      * e compará-los com o protótipo da função para análise semântica.
*/
typedef struct param{
    int t_size;
    char **variables;
}param;
//definicao de um no da arvore de sintaxe abstrata ternária
typedef struct node{ 
        Operator type;
        int line;
        struct node *first;
        struct node *second;
        struct node *third;
        char *token;
}node;
/*
      * tabela de símbolos symbolTable, cada posição da tabela contém o token de um símbolo,
      * sua linha, seu tipo, se corresponde à uma declaração ou não e um ponteiro para seu nó na AST
*/
typedef struct symbolTable{
    char *token;
    int line; //talvez
    char *type;
    int decl;
    struct node *astPointer;
}symbolTable;
/*
      * arvore de escopos symbolTree, cada nó da árvore tem um escopo atribuído, portanto, os nós filhos
      * são os escopos aninhados à um escopo. Além disso, cada escopo contém uma tabela de símbolos, symbolTable
      * que contém os respectivos símbolos de um escopo.
*/
      
typedef struct symbolTree{
    char* scope;
    char*type;
    char **params;
    int nChild, nTable,nParams;
    node *astPointer;
    struct symbolTree **childs;
    struct symbolTable **table;
}symbolTree;