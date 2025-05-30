//
// Created by Vinicius on 21/05/2025.
//

#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

#include <stdbool.h>

// Estrutura de registro
struct ld_registro {
    char cpf[12];
    char nome[50];
    char endereco[50];
    char telefone[20];
    char email[50];
};

// Variáveis globais
extern int ld_posicao;
extern int ld_tamanho;
extern struct ld_registro **ld_lista;

// Protótipos
void ld_init();
struct ld_registro *ld_novoNo(char *cpf, char *nome, char *endereco, char *telefone, char *email);
void ld_add(char *cpf, char *nome, char *endereco, char *telefone, char *email);
int ld_size();
struct ld_registro *ld_searchByCpf(char *cpf);
void ld_delete(char *cpf);
void ld_expand();
void ld_destroy();
void ld_alterar(char *cpf, char *nome, char *endereco, char *telefone, char *email);

#endif // LISTADINAMICA_H
