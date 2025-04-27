# Lista Sequencial Estática (ListaSequencialEstatica) em _C_

Este projeto implementa uma estrutura de **lista sequencial estática** para armazenar registros de alunos, utilizando a linguagem _C_. A lista possui um número fixo máximo de elementos, definido por `MAX`.

## Estrutura de Dados

A estrutura principal está dividida em dois arquivos, sendo a estrutura principal:

### `ListaSequencial.h`
```c
// ===== Arquivo: ListaSequencial.h =====
struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
```

A lista é definida como um _array_ fixo de `struct aluno`.

### `ListaSequencial.h`
```c
// ===== Arquivo: ListaSequencial.c =====
// Definição do tipo lista
struct lista {
    int qtd;
    struct aluno dados[MAX];
};
```

---

## Funções Disponíveis

### Criação e Liberação
- `Lista* cria_lista()`: Aloca e inicializa uma nova lista.
- `void libera_lista(Lista* li)`: Libera a memória ocupada pela lista.

### Verificação
- `int tamanho_lista(Lista* li)`: Retorna o número de elementos da lista.
- `int lista_cheia(Lista* li)`: Retorna 1 se a lista estiver cheia.
- `int lista_vazia(Lista* li)`: Retorna 1 se a lista estiver vazia.

### Inserção
- `int insere_lista_inicio(Lista* li, struct aluno al)`: Insere um aluno no início da lista.
- `int insere_lista_final(Lista* li, struct aluno al)`: Insere um aluno no final da lista.
- `int insere_lista_ordenada(Lista* li, struct aluno al)`: Insere um aluno mantendo a ordem crescente da matrícula.

### Remoção
- `int remove_lista_inicio(Lista* li)`: Remove o primeiro aluno da lista.
- `int remove_lista_final(Lista* li)`: Remove o último aluno da lista.
- `int remove_lista(Lista* li, int mat)`: Remove um aluno com matrícula específica (manutenção da ordem).
- `int remove_lista_otimizado(Lista* li, int mat)`: Remove um aluno substituindo pelo último elemento (sem preservar ordem).

### Busca
- `int busca_lista_pos(Lista* li, int pos, struct aluno *al)`: Retorna o aluno da posição `pos`.
- `int busca_lista_mat(Lista* li, int mat, struct aluno *al)`: Retorna o aluno com matrícula igual a `mat`.

---

## Compilação e Execução

Para compilar o projeto, use o seguinte comando no terminal:

```bash
gcc main.c ListaSequencial.c -o programa
```

Para executar:

```bash
./programa
```

---

## Exemplo de Saída

```
Inserindo os alunos...

Imprimindo lista atual:
Matrícula: 456
Nome: Bruno
Notas: 6,00, 6,50, 7,00
--------------------------
Matrícula: 123
Nome: Ana
Notas: 8,00, 7,50, 9,00
--------------------------
Matrícula: 789
Nome: Carlos
Notas: 9,00, 8,50, 9,50
--------------------------

Tamanho da lista: 3

Fazendo a busca (matrícula 789):
Aluno encontrado:
Matrícula: 789
Nome: Carlos
Notas: 9,00, 8,50, 9,50

Removendo Bruno (matricula 456)...

Imprimindo lista após remoção:
Matrícula: 123
Nome: Ana
Notas: 8,00, 7,50, 9,00
--------------------------
Matrícula: 789
Nome: Carlos
Notas: 9,00, 8,50, 9,50
--------------------------

Tamanho da lista: 2

Fazendo a busca (matrícula 117):
Aluno com matrícula 117 não encontrado.
```

---

## Autor

Este projeto é uma implementação didática de uma lista sequencial estática em _C_, útil para fins de aprendizado de estruturas de dados.
