#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Lista lista;
  inicializarLista(&lista);

  int opcao;
  char nome[50];
  char cpf[12];
  Pessoa pessoa;

  do {
    printf("\n---------- Menu ----------\n");
    printf("1. Inserir pessoa na lista\n");
    printf("2. Retirar pessoa da lista\n");
    printf("3. Imprimir pessoas da lista\n");
    printf("4. Verificar se a lista esta vazia\n");
    printf("5. Atendimento prioritario\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");

    switch (opcao) {
    case 1:
      printf("Digite o nome da pessoa: ");
      scanf(" %[^\n]s", nome);
      strcpy(pessoa.nome, nome);
      printf("Digite o CPF da pessoa: ");
      scanf(" %[^\n]s", cpf);
      strcpy(pessoa.cpf, cpf);
      inserirPessoa(&lista, pessoa);
      break;
    case 2:
      retirarPessoa(&lista);
      break;
    case 3:
      imprimirLista(&lista);
      break;
    case 4:
      if (listaVazia(&lista)) {
        printf("Lista vazia.\n");
      } else {
        printf("Lista não esta vazia.\n");
      }
      break;
    case 5:
      atendimentoPrioritario(&lista);
      break;
    case 0:
      printf("Saindo do programa.\n");
      break;
    default:
      printf("Opcao invalida.\n");
    }
  } while (opcao != 0);

  return 0;
}
