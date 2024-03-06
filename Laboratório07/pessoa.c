#include <stdio.h>
#include <string.h>
#include "pessoa.h"

void cadastrarPessoa(Pessoa pessoas[]) {
    int i;
    for (i = 0; i < MAX_PESSOAS; i++) {
        if (pessoas[i].cpf == 0) {
            printf("\n--- Cadastro de Pessoa ---\n");
            printf("Nome: ");
            scanf(" %[^\n]s", pessoas[i].nome);
            printf("Endereco: ");
            scanf(" %[^\n]s", pessoas[i].endereco);
            printf("Telefone: ");
            scanf(" %[^\n]s", pessoas[i].telefone);
            printf("Idade: ");
            scanf("%d", &pessoas[i].idade);
            printf("CPF: ");
            scanf("%lld", &pessoas[i].cpf);
            printf("Pessoa cadastrada com sucesso!\n");
            break;
        }
    }
    if (i == MAX_PESSOAS) {
        printf("Limite de pessoas cadastradas atingido.\n");
    }
}

void exibirPessoas(Pessoa pessoas[]) {
    int i;
    printf("\n--- Pessoas Cadastradas ---\n");
    for (i = 0; i < MAX_PESSOAS; i++) {
        if (pessoas[i].cpf != 0) {
            printf("Nome: %s\n", pessoas[i].nome);
            printf("Endereco: %s\n", pessoas[i].endereco);
            printf("Telefone: %s\n", pessoas[i].telefone);
            printf("Idade: %d\n", pessoas[i].idade);
            printf("CPF: %lld\n", pessoas[i].cpf);
            printf("--------------------------\n");
        }
    }
}

void excluirPessoa(Pessoa pessoas[]) {
    long long cpf;
    int i;
    printf("\n--- Excluir Pessoa ---\n");
    printf("CPF: ");
    scanf("%lld", &cpf);
    for (i = 0; i < MAX_PESSOAS; i++) {
        if (pessoas[i].cpf == cpf) {
            pessoas[i].cpf = 0;
            printf("Pessoa excluida com sucesso!\n");
            return;
        }
    }
    printf("Pessoa nao encontrada.\n");
}

void alterarPessoa(Pessoa pessoas[]) {
    long long cpf;
    int i;
    printf("\n--- Alterar Pessoa ---\n");
    printf("CPF: ");
    scanf("%lld", &cpf);
    for (i = 0; i < MAX_PESSOAS; i++) {
        if (pessoas[i].cpf == cpf) {
            printf("Nome: ");
            scanf(" %[^\n]s", pessoas[i].nome);
            printf("Endereco: ");
            scanf(" %[^\n]s", pessoas[i].endereco);
            printf("Telefone: ");
            scanf(" %[^\n]s", pessoas[i].telefone);
            printf("Idade: ");
            scanf("%d", &pessoas[i].idade);
            printf("Dados da pessoa alterados com sucesso!\n");
            return;
        }
    }
    printf("Pessoa nao encontrada.\n");
}

void salvarDados(Pessoa pessoas[]) {
    FILE *arquivo;
    arquivo = fopen(FILENAME, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fwrite(pessoas, sizeof(Pessoa), MAX_PESSOAS, arquivo);
    fclose(arquivo);
    printf("Dados salvos com sucesso.\n");
}

void carregarDados(Pessoa pessoas[]) {
    FILE *arquivo;
    arquivo = fopen(FILENAME, "rb");
    if (arquivo == NULL) {
        printf("Arquivo nao encontrado.\n");
        return;
    }
    fread(pessoas, sizeof(Pessoa), MAX_PESSOAS, arquivo);
    fclose(arquivo);
    printf("Dados carregados com sucesso.\n");
}
