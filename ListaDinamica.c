//
// Created by Vinicius on 21/05/2025.
//

#include "ListaDinamica.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Variáveis
int ld_posicao = 0;
int ld_tamanho = 5;
struct ld_registro **ld_lista = NULL;

// Funções

void ld_init() {
    ld_lista = malloc(sizeof(struct ld_registro *) * ld_tamanho);
    if (!ld_lista) {
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }
}

struct ld_registro *ld_novoNo(char *cpf, char *nome, char *endereco, char *telefone, char *email) {
    struct ld_registro *p = malloc(sizeof(struct ld_registro));
    if (!p) {
        printf("Erro de alocacao de memoria!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(p->cpf, cpf);
    strcpy(p->nome, nome);
    strcpy(p->endereco, endereco);
    strcpy(p->telefone, telefone);
    strcpy(p->email, email);

    return p;
}

void ld_add(char *cpf, char *nome, char *endereco, char *telefone, char *email) {
    if (ld_posicao == ld_tamanho) {
        ld_expand();
    }
    ld_lista[ld_posicao++] = ld_novoNo(cpf, nome, endereco, telefone, email);
}

int ld_size() {
    return ld_posicao;
}

struct ld_registro *ld_searchByCpf(char *cpf) {
    for (int i = 0; i < ld_posicao; i++) {
        if (_stricmp(ld_lista[i]->cpf, cpf) == 0) {
            return ld_lista[i];
        }
    }
    return NULL;
}

void ld_delete(char *cpf) {
    int i;
    for (i = 0; i < ld_posicao; i++) {
        if (strcmp(ld_lista[i]->cpf, cpf) == 0) {
            free(ld_lista[i]);
            break;
        }
    }

    if (i == ld_posicao) return;  // Não encontrou

    for (; i < ld_posicao - 1; i++) {
        ld_lista[i] = ld_lista[i + 1];
    }
    ld_posicao--;
}

void ld_expand() {
    int novoTamanho = ld_tamanho + 5;
    struct ld_registro **aux = malloc(sizeof(struct ld_registro *) * novoTamanho);
    if (!aux) {
        printf("Erro ao alocar memoria!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ld_posicao; i++) {
        aux[i] = ld_lista[i];
    }

    free(ld_lista);
    ld_lista = aux;
    ld_tamanho = novoTamanho;
}

void ld_destroy() {
    for (int i = 0; i < ld_posicao; i++) {
        free(ld_lista[i]);
    }
    free(ld_lista);
}

void ld_alterar(char *cpf, char *nome, char *endereco, char *telefone, char *email) {
    struct ld_registro *ld_registroParaAlterar = ld_searchByCpf(cpf);
    strcpy(ld_registroParaAlterar->nome, nome);
    strcpy(ld_registroParaAlterar->endereco, endereco);
    strcpy(ld_registroParaAlterar->telefone, telefone);
    strcpy(ld_registroParaAlterar->email, email);
}