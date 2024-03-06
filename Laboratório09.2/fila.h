#ifndef PILHA_H
#define PILHA_H

typedef struct {
  char nome[50];
  char isbn[20];
} Livro;

typedef struct No {
  Livro livro;
  struct No *prox;
} No;

typedef struct {
  No *topo;
} Pilha;

void inicializarPilha(Pilha *pilha);
int pilhaVazia(Pilha *pilha);
void empilharLivro(Pilha *pilha, Livro livro);
void desempilharLivro(Pilha *pilha);
void mostrarTopoPilha(Pilha *pilha);

#endif
