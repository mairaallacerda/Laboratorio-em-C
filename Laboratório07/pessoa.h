#ifndef PESSOA_H
#define PESSOA_H

#define MAX_PESSOAS 100
#define FILENAME "pessoa.dat"

typedef struct {
    char nome[50];
    char endereco[100];
    char telefone[15];
    int idade;
    long long cpf;
} Pessoa;

void cadastrarPessoa(Pessoa pessoas[]);
void exibirPessoas(Pessoa pessoas[]);
void excluirPessoa(Pessoa pessoas[]);
void alterarPessoa(Pessoa pessoas[]);
void salvarDados(Pessoa pessoas[]);
void carregarDados(Pessoa pessoas[]);

#endif
