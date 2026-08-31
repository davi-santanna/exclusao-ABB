#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;



TNoA *exclui(TNoA *raiz, int chave) {

    if(!raiz) return NULL;
    else if(raiz->chave < chave){
        raiz->dir = exclui(raiz->dir, chave);
        return raiz;}
    else if(raiz->chave > chave){
        raiz->esq = exclui(raiz->esq, chave);
        return raiz;
   }
    TNoA*temp = raiz;
    if(!raiz->dir&&!raiz->esq){
        raiz = NULL;
        free(temp);
    }
    else if(!raiz->dir){
        raiz = raiz->esq;
        free(temp);
    }
    else if(!raiz->esq){
        raiz = raiz->dir;
        free(temp);
    }
    else{
        TNoA* f= raiz->esq;
        while(f->dir) f=f->dir;
        raiz->chave = f->chave;
        raiz->esq = exclui(raiz->esq, f->chave);
    }

    return raiz;
}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *insere(TNoA *no, int chave) {
    if (no == NULL) {
        no = (TNoA *) malloc(sizeof(TNoA));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave)) {
        no->dir = insere(no->dir, chave);
    } else {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}

int main(void) {

    /* A função main lê os dados de entrada, cria a árvore e chama a função solicitada no problema
     * depois imprime o resultado solicitado
     * ELA NÃO DEVE SER MODIFICADA
     * */
    TNoA *raiz;
    raiz = NULL;

    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int valor;

    /* lê valores para criar a arvore
     * valores devem ser informados separados por traço
     * exemplo: 1-3-5-2-7-9-21-6 */
    scanf("%s", l);
    //quebra a string de entrada
    ptr = strtok(l, delimitador);
    while(ptr != NULL) {
        valor = atoi(ptr);
        raiz = insere(raiz, valor);
        ptr = strtok(NULL, delimitador);
    }

    //le valor a ser excluido
    scanf("%d", &valor);
    //Chama função
    raiz = exclui(raiz, valor);
    imprime(raiz, 0);
};