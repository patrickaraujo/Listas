// ===== Arquivo: main.c =====
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "ListaSequencial.h"

// Função que realiza a busca e imprime o resultado
void buscar_aluno_por_matricula(Lista* li, int matricula_busca) {
    struct aluno resultado;

    if (busca_lista_mat(li, matricula_busca, &resultado)) {
        printf("Aluno encontrado:\n");
        printf("Matrícula: %d\n", resultado.matricula);
        printf("Nome: %s\n", resultado.nome);
        printf("Notas: %.2f, %.2f, %.2f\n", resultado.n1, resultado.n2, resultado.n3);
    } else {
        printf("Aluno com matrícula %d não encontrado.\n", matricula_busca);
    }
}

// Função para imprimir a lista
void imprime_lista(Lista* li) {
    int tam = tamanho_lista(li);
    struct aluno al;
    for (int i = 1; i <= tam; i++) {
        if (busca_lista_pos(li, i, &al)) {
            printf("Matrícula: %d\n", al.matricula);
            printf("Nome: %s\n", al.nome);
            printf("Notas: %.2f, %.2f, %.2f\n", al.n1, al.n2, al.n3);
            printf("--------------------------\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    Lista* minha_lista = cria_lista();

    struct aluno a1 = {123, "Ana", 8.0, 7.5, 9.0};
    struct aluno a2 = {456, "Bruno", 6.0, 6.5, 7.0};
    struct aluno a3 = {789, "Carlos", 9.0, 8.5, 9.5};

    // Inserindo elementos
    printf("Inserindo os alunos...\n\n");

    insere_lista_final(minha_lista, a1);
    insere_lista_inicio(minha_lista, a2);
    insere_lista_ordenada(minha_lista, a3);

    // Imprimindo a lista
    printf("Imprimindo lista atual:\n");
    imprime_lista(minha_lista);

    // Retornando o tamanho da lista
    printf("\nTamanho da lista: %d\n", tamanho_lista(minha_lista));

    // Fazendo a busca com a nova função
    printf("\nFazendo a busca (matrícula 789):\n");
    buscar_aluno_por_matricula(minha_lista, 789);

    // Removendo da lista
    printf("\nRemovendo Bruno (matricula 456)...\n\n");
    remove_lista(minha_lista, 456);

    // Imprimindo a lista novamente
    printf("Imprimindo lista após remoção:\n");
    imprime_lista(minha_lista);

    // Retornando o tamanho da lista
    printf("\nTamanho da lista: %d\n", tamanho_lista(minha_lista));

    // Fazendo a busca com a nova função
    printf("\nFazendo a busca (matrícula 117):\n");
    buscar_aluno_por_matricula(minha_lista, 117);

    // Destruindo a lista
    libera_lista(minha_lista);
    return 0;
}
