#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarLista(Lista *lista) {
  lista->inicio = NULL;
  lista->fim = NULL;
}

int listaVazia(Lista *lista) { return lista->inicio == NULL; }

void inserirPessoa(Lista *lista, Pessoa pessoa) {
  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->pessoa = pessoa;
  novoNo->prox = NULL;

  if (listaVazia(lista)) {
    lista->inicio = novoNo;
    lista->fim = novoNo;
  } else {
    lista->fim->prox = novoNo;
    lista->fim = novoNo;
  }

  printf("Pessoa inserida: %s\n", pessoa.nome);

  int posicao = 1;
  No *atual = lista->inicio;
  while (atual != novoNo) {
    posicao++;
    atual = atual->prox;
  }

  printf("Posicao na fila: %d\n", posicao);
}

void retirarPessoa(Lista *lista) {
  if (listaVazia(lista)) {
    printf("Lista vazia.\n");
    return;
  }

  No *noRemovido = lista->inicio;
  lista->inicio = lista->inicio->prox;

  printf("Pessoa retirada: %s\n", noRemovido->pessoa.nome);

  free(noRemovido);

  if (listaVazia(lista)) {
    lista->fim = NULL;
  }
}

void imprimirLista(Lista *lista) {
  if (listaVazia(lista)) {
    printf("Lista vazia.\n");
    return;
  }

  printf("Pessoas na lista:\n");

  No *atual = lista->inicio;
  int posicao = 1;

  while (atual != NULL) {
    printf("Posicao %d: %s\n", posicao, atual->pessoa.nome);
    posicao++;
    atual = atual->prox;
  }
}
//tem algum erro
void atendimentoPrioritario(Lista *lista) {
  if (listaVazia(lista)) {
    printf("Lista vazia.\n");
    return;
  }

  No *noPrioritario = lista->inicio;
  lista->inicio = lista->inicio->prox;

  printf("Atendimento prioritario: %s\n", noPrioritario->pessoa.nome);

  free(noPrioritario);

  if (listaVazia(lista)) {
    lista->fim = NULL;
  }
}
