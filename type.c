#include "type.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        if(strcmp(it->token,token)){
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
    newnode->childs = NULL;
    newnode->table = NULL;
    return newnode;
}

symbolTree *searchScope(symbolTree *tree, char *scope){
    if(tree == NULL) return NULL;
    int i;
    symbolTree *it, *ret;
    ret = NULL;
    for(i = 0; i < tree->nChild; i++){
        it = &tree->childs[i];
        if(strcmp(it->scope,scope)){
            ret = it;
        }
    }
    if(ret != NULL) return ret;
    for(i = 0; i < tree->nChild; i++){
        ret = searchScope(&tree->childs[i],scope);
    }
    return ret;
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

