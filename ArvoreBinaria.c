//
// Created by Vinicius on 21/05/2025.
//

#include "ArvoreBinaria.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variáveis
struct ab_no *ab_inicio = NULL;
struct ab_no *ab_anterior = NULL;

// Funções
struct ab_no * ab_novoNo(char *cpf, int indice) {
    struct ab_no *p = malloc(sizeof(struct ab_no));
    if (!p) {
        printf("Erro de alocação de memória!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(p->cpf, cpf);
    p->esquerda = NULL;
    p->direita = NULL;
    p->indice = indice;


    return p;
}

void ab_adicionar(struct ab_no *quem, struct ab_no *aonde) {
    if (ab_inicio == NULL) {
        ab_inicio = quem;
    } else {
        if (strcmp(quem->cpf, aonde->cpf) > 0) {
            // direita
            if (aonde->direita == NULL) {
                aonde->direita = quem;
            } else {
                ab_adicionar(quem, aonde->direita);
            }
        } else {
            // esquerda
            if (aonde->esquerda == NULL) {
                aonde->esquerda = quem;
            } else {
                ab_adicionar(quem, aonde->esquerda);

            }
        }
    }
}

void ab_finalizar(struct ab_no *quem) {
    if (ab_inicio == NULL) {
        return;
    }
    if (quem->esquerda != NULL) {
        ab_finalizar(quem->esquerda);
    }
    if (quem->direita != NULL) {
        ab_finalizar(quem->direita);
    }
    free(quem);
}

struct ab_no * ab_localizar(char *cpf, struct ab_no *aonde) {
    if (ab_inicio == NULL || aonde == NULL) {
        return NULL;
    } else {
        if (aonde == ab_inicio) {
            ab_anterior = ab_inicio;
        }
        if (strcmp(cpf, aonde->cpf) == 0) {
            return aonde;
        } else {
            ab_anterior = aonde;
            if (strcmp(cpf, aonde->cpf) > 0) {
                // direita
                if (aonde->direita == NULL) {
                    return NULL;
                } else {
                    return ab_localizar(cpf, aonde->direita);
                }
            } else {
                // esquerda
                if (aonde->esquerda == NULL) {
                    return NULL;
                } else {
                    return ab_localizar(cpf, aonde->esquerda);
                }
            }
        }
    }
}

void ab_excluir(char *cpf) {
    struct ab_no *aux = ab_localizar(cpf, ab_inicio);
    if (aux != NULL) {
        if (aux == ab_inicio) {
            ab_inicio = NULL;
        } else {
            if (strcmp(aux->cpf, ab_anterior->cpf) > 0) {
                ab_anterior->direita = NULL;
            } else {
                ab_anterior->esquerda = NULL;
            }
        }
        if (aux->esquerda != NULL) {
            ab_adicionar(aux->esquerda, ab_inicio);
        }
        if (aux->direita != NULL) {
            ab_adicionar(aux->direita, ab_inicio);
        }
        printf("Excluindo %s\n", aux->cpf);
        free(aux);
    }
}
