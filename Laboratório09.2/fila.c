#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarPilha(Pilha *pilha) { pilha->topo = NULL; }

int pilhaVazia(Pilha *pilha) { return pilha->topo == NULL; }

void empilharLivro(Pilha *pilha, Livro livro) {
  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->livro = livro;
  novoNo->prox = pilha->topo;
  pilha->topo = novoNo;

  printf("Livro inserido: %s\n", livro.nome);

  int quantidade = 0;
  No *atual = pilha->topo;
  while (atual != NULL) {
    quantidade++;
    atual = atual->prox;
  }

  printf("Quantidade de livros na pilha: %d\n", quantidade);
}

void desempilharLivro(Pilha *pilha) {
  if (pilhaVazia(pilha)) {
    printf("Pilha vazia.\n");
    return;
  }

  No *noRemovido = pilha->topo;
  pilha->topo = pilha->topo->prox;

  printf("Livro retirado: %s\n", noRemovido->livro.nome);

  free(noRemovido);
}

void mostrarTopoPilha(Pilha *pilha) {
  if (pilhaVazia(pilha)) {
    printf("Pilha vazia.\n");
    return;
  }

  printf("Livro do topo da pilha: %s\n", pilha->topo->livro.nome);
}
