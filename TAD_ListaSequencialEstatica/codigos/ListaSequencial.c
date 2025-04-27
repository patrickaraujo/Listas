// ===== Arquivo: ListaSequencial.c =====
#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"	//	inclui os protótipos

// Definição do tipo lista
struct lista {
    int qtd;
    struct aluno dados[MAX];
};

// Cria uma nova lista
Lista* cria_lista() {
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

// Libera a memória da lista
// Destroi uma lista
void libera_lista(Lista* li) {
    free(li);
}

// Retorna o tamanho da lista
int tamanho_lista(Lista* li) {
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

// Verifica se a lista está cheia
int lista_cheia(Lista* li) {
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

// Verifica se a lista está vazia
int lista_vazia(Lista* li) {
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

// Insere elemento no início da lista
int insere_lista_inicio(Lista* li, struct aluno al) {
    if(li == NULL || li->qtd == MAX)
        return 0;
    int i;
    for(i = li->qtd - 1; i >= 0; i--)
        li->dados[i + 1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

// Insere elemento no final da lista
int insere_lista_final(Lista* li, struct aluno al) {
    if(li == NULL || li->qtd == MAX)
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

// Insere elemento de forma ordenada pela matrícula
int insere_lista_ordenada(Lista* li, struct aluno al) {
    if(li == NULL || li->qtd == MAX)
        return 0;
    int i, k;
    for(i = 0; i < li->qtd && li->dados[i].matricula < al.matricula; i++);

    for(k = li->qtd - 1; k >= i; k--)
        li->dados[k + 1] = li->dados[k];
    li->dados[i] = al;
    li->qtd++;
    return 1;
}

// Remove elemento do início da lista
int remove_lista_inicio(Lista* li) {
    if(li == NULL || li->qtd == 0)
        return 0;
    for(int k = 0; k < li->qtd - 1; k++)
        li->dados[k] = li->dados[k + 1];
    li->qtd--;
    return 1;
}

// Remove elemento do final da lista
int remove_lista_final(Lista* li) {
    if(li == NULL || li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

// Remove um elemento específico da lista
// Remove elemento por matrícula
int remove_lista(Lista* li, int mat) {
    if(li == NULL || li->qtd == 0)
        return 0;
    int i, k;
    for(i = 0; i < li->qtd && li->dados[i].matricula != mat; i++);

    if(i == li->qtd)
        return 0;
    for(k = i; k < li->qtd - 1; k++)
        li->dados[k] = li->dados[k + 1];
    li->qtd--;
    return 1;
}

// Remove um elemento específico da lista
// Remove elemento por matrícula (otimizado)
int remove_lista_otimizado(Lista* li, int mat) {
    if(li == NULL || li->qtd == 0)
        return 0;
    int i;
    for(i = 0; i < li->qtd && li->dados[i].matricula != mat; i++);

    if(i == li->qtd)
        return 0;
    li->qtd--;
    li->dados[i] = li->dados[li->qtd];
    return 1;
}

// Busca elemento por posição
int busca_lista_pos(Lista* li, int pos, struct aluno *al) {
    if(li == NULL || pos <= 0 || pos > li->qtd)
        return 0;
    *al = li->dados[pos - 1];
    return 1;
}

// Busca elemento por matrícula (conteúdo)
int busca_lista_mat(Lista* li, int mat, struct aluno *al) {
    if(li == NULL)
        return 0;
    int i;
    for(i = 0; (i < li->qtd) && (li->dados[i].matricula != mat); i++);

    if(i == li->qtd)
        return 0;
    *al = li->dados[i];
    return 1;
}
