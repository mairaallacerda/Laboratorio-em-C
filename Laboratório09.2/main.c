#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Pilha pilha;
  inicializarPilha(&pilha);

  int opcao;
  char nome[50];
  char isbn[20];
  Livro livro;

  do {
    printf("\n---- Menu ----\n");
    printf("1. Inserir livro na pilha\n");
    printf("2. Retirar livro da pilha\n");
    printf("3. Mostrar livro do topo da pilha\n");
    printf("4. Verificar se a pilha esta vazia\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");

    switch (opcao) {
    case 1:
      printf("Digite o nome do livro: ");
      scanf(" %[^\n]s", nome);
      strcpy(livro.nome, nome);
      printf("Digite o ISBN do livro: ");
      scanf(" %[^\n]s", isbn);
      strcpy(livro.isbn, isbn);
      empilharLivro(&pilha, livro);
      break;
    case 2:
      desempilharLivro(&pilha);
      break;
    case 3:
      mostrarTopoPilha(&pilha);
      break;
    case 4:
      if (pilhaVazia(&pilha)) {
        printf("Pilha vazia.\n");
      } else {
        printf("Pilha nao esta vazia.\n");
      }
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
