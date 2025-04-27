# Lista Sequencial Estática – Estrutura de Dados em _C_

Este projeto tem como objetivo ensinar e demonstrar, de forma prática, a implementação de uma **Lista Sequencial Estática** em linguagem _C_.

---

## 🧱 Lista Sequencial Estática

Implementada com base em um _array_. Cada novo elemento é inserido em uma posição contígua da memória.

### Estrutura Base

```c
// Define a capacidade máxima da lista sequencial.
// A lista poderá armazenar até 100 elementos do tipo struct aluno.
#define MAX 100

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
```

Além do _array_, utiliza-se um campo `qtd` que indica quantas posições estão ocupadas.

### ✅ Vantagens

- Acesso direto via índice.
- Tempo constante para acessar posições.
- Facilidade para modificação de dados.

### ❌ Desvantagens

- Tamanho fixo.
- Inserções e remoções internas exigem deslocamento de elementos.

### 📌 Quando Utilizar

- Listas pequenas.
- Inserções e remoções no final.
- Tamanho máximo conhecido.
- Quando busca é a operação mais frequente.

---

## Referências
### Referência Básica:
- Backes, Andre Ricardo. Algoritmos E Estruturas De Dados Em Linguagem C. Ltc - Livros Tecnicos E Cientificos Editora Lda, 2022.
- Ascencio, Ana Fernanda Gomes. Análise de Algoritmos e Estrutura de Dados. Prentice Hall/Sp, 2010.
### Referência Complementar:
- Estruturas de Dados e Seus Algoritmos. Ltc - Livros Tecnicos E Cientificos Editora Lda, 2009.
- Tenenbaum, Aaron M., et al. Estruturas de dados usando C. Pearson Makron Books, 1995.

---

Este material foi elaborado como parte de uma aula prática de estruturas de dados em _C_.

# TAD_ListaSequencialEstatica
Implementação do TAD Lista Sequencial Estática em Linguagem _C_
