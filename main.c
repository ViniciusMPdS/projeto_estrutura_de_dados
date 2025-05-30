//
// Created by Vinicius on 21/05/2025.
//

#include <stdio.h>
#include <string.h>
#include "ListaDuplamenteLigada.h"
#include "ArvoreBinaria.h"
#include "ListaDinamica.h"

// Constantes
enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_ALTERAR,
    OP_EXCLUIR,
    OP_PROCURAR,
    OP_RELATORIO,
    OP_SAIR
};


// Protótipos
int menu();
bool validarCPF(const char *cpf);

int main(void) {
    char cpf[12];
    char nome[50];
    char endereco[50];
    char telefone[20];
    char email[50];
    int opcao = OP_NAO_SELECIONADA;

    ll_inicializar();
    ld_init();

    while (opcao != OP_SAIR) {
        opcao = menu();
        switch (opcao) {
            case OP_ADICIONAR:
                printf("Digite um CPF valido: ");
                scanf(" %s", cpf);
                if (!validarCPF(cpf)) {
                    printf("CPF invalido!\n");
                } else {
                    if (ab_localizar(cpf, ab_inicio)) {
                        printf("CPF ja cadastrado!\n");
                    } else {
                        printf("Digite o nome: ");
                        scanf(" %[^\n]", nome);
                        printf("Digite o endereco: ");
                        scanf(" %[^\n]", endereco);
                        printf("Digite o telefone: ");
                        scanf(" %[^\n]", telefone);
                        printf("Digite a email: ");
                        scanf(" %[^\n]", email);
                        ll_adicionar(nome, ld_posicao);
                        ab_adicionar(ab_novoNo(cpf, ld_posicao), ab_inicio);
                        ld_add(cpf, nome, endereco, telefone, email);
                        printf("Registro adicionado!\n");
                    }
                }
                break;
            case OP_ALTERAR:
                printf("Digite um CPF valido: ");
                scanf(" %s", cpf);
                if (!validarCPF(cpf)) {
                    printf("CPF invalido!\n");
                } else {
                    if (!ab_localizar(cpf, ab_inicio)) {
                        printf("CPF nao cadastrado!\n");
                    } else {
                        printf("Digite o nome: ");
                        scanf(" %[^\n]", nome);
                        printf("Digite o endereco: ");
                        scanf(" %[^\n]", endereco);
                        printf("Digite o telefone: ");
                        scanf(" %[^\n]", telefone);
                        printf("Digite a email: ");
                        scanf(" %[^\n]", email);

                        ld_alterar(cpf, nome, endereco, telefone, email);

                        struct ll_no *nome_encontrado = ll_searchByIndex(ab_localizar(cpf, ab_inicio)->indice);
                        if (_stricmp(nome_encontrado->nome, nome) != 0) {
                            ll_excluir(nome_encontrado->nome);
                            ll_adicionar(nome, ab_localizar(cpf, ab_inicio)->indice);
                        }
                        printf("Registro alterado!\n");
                    }
                }
                break;
            case OP_EXCLUIR:
                printf("Digite um CPF valido: ");
                scanf(" %s", cpf);
                if (!validarCPF(cpf)) {
                    printf("CPF invalido!\n");
                } else {
                    if (!ab_localizar(cpf, ab_inicio)) {
                        printf("CPF nao cadastrado!\n");
                    } else {
                        ll_excluir(ll_searchByIndex(ab_localizar(cpf, ab_inicio)->indice)->nome);
                        ab_excluir(cpf);
                        printf("Registro excluido!\n");
                    }
                }
                break;
            case OP_PROCURAR:
                printf("Digite um CPF valido: ");
                scanf(" %s", cpf);
                if (!validarCPF(cpf)) {
                    printf("CPF invalido!\n");
                } else {
                    if (!ab_localizar(cpf, ab_inicio)) {
                        printf("CPF nao cadastrado!\n");
                    } else {
                        struct ld_registro *registro = ld_lista[ab_localizar(cpf, ab_inicio)->indice];
                        printf("======DADOS======\n");
                        printf("CPF: %s\n", registro->cpf);
                        printf("Nome: %s\n", registro->nome);
                        printf("Endereco: %s\n", registro->endereco);
                        printf("Telefone: %s\n", registro->telefone);
                        printf("Email: %s\n", registro->email);
                        printf("\n");
                    }
                }
                break;
            case OP_RELATORIO:
                if (ll_inicio == NULL) {
                    printf("Lista Vazia!\n");
                } else {
                    ll_paraInicio();
                    printf("======Relatorio======\n");
                    while (ll_noAtual() != NULL) {
                        struct ld_registro *registro = ld_lista[ll_noAtual()->indice];
                        printf("Nome: %s\n", registro->nome);
                        printf("CPF: %s\n", registro->cpf);
                        printf("Endereco: %s\n", registro->endereco);
                        printf("Telefone: %s\n", registro->telefone);
                        printf("Email: %s\n", registro->email);
                        printf("----------------------");
                        printf("\n");
                        ll_paraOProximo();
                    }
                    printf("\n");
                }
                break;
            case OP_SAIR:
                printf("Finalizando...");
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    }
    return 0;
}

int menu() {
    int op = OP_NAO_SELECIONADA;
    printf("======MENU======\n");
    printf("%d - Adicionar\n", OP_ADICIONAR);
    printf("%d - Alterar\n", OP_ALTERAR);
    printf("%d - Excluir\n", OP_EXCLUIR);
    printf("%d - Procurar\n", OP_PROCURAR);
    printf("%d - Relatorio\n", OP_RELATORIO);
    printf("%d - Sair\n", OP_SAIR);
    scanf("%d", &op);
    return op;
}

bool validarCPF(const char *cpf) {
    int i, j, digito1 = 0, digito2 = 0;

    // CPF deve ter 11 caracteres numéricos
    if (strlen(cpf) != 11) return false;

    // Verifica se todos os dígitos sao iguais (ex: 111.111.111-11)
    for (i = 1; i < 11; i++) {
        if (cpf[i] != cpf[0]) break;
        if (i == 10) return false;
    }

    // Calculo do primeiro dígito
    for (i = 0, j = 10; i < 9; i++, j--)
        digito1 += (cpf[i] - '0') * j;
    digito1 = 11 - (digito1 % 11);
    if (digito1 >= 10) digito1 = 0;

    // Calculo do segundo dígito
    for (i = 0, j = 11; i < 10; i++, j--)
        digito2 += (cpf[i] - '0') * j;
    digito2 = 11 - (digito2 % 11);
    if (digito2 >= 10) digito2 = 0;

    return (digito1 == (cpf[9] - '0') && digito2 == (cpf[10] - '0'));
}
