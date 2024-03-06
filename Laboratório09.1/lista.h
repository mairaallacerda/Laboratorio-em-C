#ifndef LISTA_H
#define LISTA_H

typedef struct {
  char nome[50];
  char cpf[12];
} Pessoa;

typedef struct No {
  Pessoa pessoa;
  struct No *prox;
} No;

typedef struct {
  No *inicio;
  No *fim;
} Lista;

void inicializarLista(Lista *lista);
int listaVazia(Lista *lista);
void inserirPessoa(Lista *lista, Pessoa pessoa);
void retirarPessoa(Lista *lista);
void imprimirLista(Lista *lista);
void atendimentoPrioritario(Lista *lista);

#endif
