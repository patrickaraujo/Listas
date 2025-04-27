// ===== Arquivo: ListaSequencial.h =====
#ifndef LISTASEQUENCIAL_H_INCLUDED
#define LISTASEQUENCIAL_H_INCLUDED

#define MAX 100

// Estrutura do aluno
struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

// Tipo lista (ponteiro para elemento)
typedef struct lista Lista;

// Criação e liberação
Lista* cria_lista();
void libera_lista(Lista* li);

// Informações sobre a lista
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);

// Inserções
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);

// Remoções
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int remove_lista(Lista* li, int mat);
int remove_lista_otimizado(Lista* li, int mat);

// Buscas
int busca_lista_pos(Lista* li, int pos, struct aluno *al);
int busca_lista_mat(Lista* li, int mat, struct aluno *al);

#endif // LISTASEQUENCIAL_H_INCLUDED
