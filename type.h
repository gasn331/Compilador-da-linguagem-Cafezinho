
typedef enum{programa,DeclFuncVar1,DeclFuncVar2,DeclFuncVar3,DeclFunc,ListaParametrosCont3,
ListaParametrosCont4,Bloco1,ListaDeclVar2,ListaDeclVar3,Tipo,ListaComando2,Retorne,Leia,Escreva,
EscrevaString,Novalinha,Se,SeSenao,Enquanto,Atribuir,SeTernario,Or,And,IgualIgual,Diferente,Menor,
Maior,MenorIg,MaiorIg,Mais,Menos,Vezes,Divisao,Resto,Negativo,Negacao,IdentificadorBEB,Identificador,
IdentificadorLista,Carconst,Intconst,Virgula}Operator;

//definicao de um no da arvore de sintaxe abstrata
typedef struct node{ 
        Operator type;
        int line;
        struct node *first;
        struct node *second;
        struct node *third;
        char *token;
}node;
