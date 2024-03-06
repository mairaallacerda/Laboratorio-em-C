#include <stdio.h>
#include "pessoa.h"

int main() {
    int opcao;
    Pessoa pessoas[MAX_PESSOAS];

    carregarDados(pessoas);

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar pessoa\n");
        printf("2. Exibir todas as pessoas cadastradas\n");
        printf("3. Excluir pessoa\n");
        printf("4. Alterar pessoa\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarPessoa(pessoas);
                break;
            case 2:
                exibirPessoas(pessoas);
                break;
            case 3:
                excluirPessoa(pessoas);
                break;
            case 4:
                alterarPessoa(pessoas);
                break;
            case 5:
                salvarDados(pessoas);
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
