//
// Created by Vinicius on 21/05/2025.
//

#include "ListaDuplamenteLigada.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// variáveis
struct ll_no *ll_inicio = NULL;
struct ll_no *ll_novo = NULL;
struct ll_no *anterior = NULL;
struct ll_no *proximo = NULL;
struct ll_no *ll_aux = NULL;
struct ll_no *cursor = NULL;

// funções
void ll_inicializar() {
    ll_inicio = NULL;
    cursor = NULL;
}

void ll_finalizar(struct ll_no *quem) {
    if (ll_inicio == NULL) {
        return;
    }
    if (quem->proximo != NULL) {
        ll_finalizar(quem->proximo);
    }
    printf("Excluindo %s...\n", quem->nome);
    free(quem);
}

struct ll_no * ll_novoNo(char *nome, int indice) {
    struct ll_no *p = malloc(sizeof(struct ll_no));
    if (!p) {
        printf("Erro de alocacao de memoria!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(p->nome, nome);
    p->indice = indice;
    p->proximo = NULL;
    p->anterior = NULL;

    return p;
}

void ll_adicionar(char *nome, int indice) {
    ll_novo = ll_novoNo(nome, indice);

    if (ll_inicio == NULL) {
        ll_inicio = ll_novo;
    } else {
        if (_stricmp(ll_novo->nome, ll_inicio->nome) < 0) {
            ll_adicionarNoInicio();
        } else {
            ll_aux = ll_inicio;
            while (_stricmp(ll_aux->nome, ll_novo->nome) <= 0 &&
                   ll_aux->proximo != NULL) {
                ll_aux = ll_aux->proximo;
            }
            if (_stricmp(ll_novo->nome, ll_aux->nome) >= 0) {
                ll_adicionarNoFinal();
            } else {
                ll_adicionarNoMeio();
            }
        }
    }
}

void ll_adicionarNoInicio() {
    ll_novo->proximo = ll_inicio;
    ll_inicio->anterior = ll_novo;
    ll_inicio = ll_novo;
}

void ll_adicionarNoFinal() {
    ll_aux->proximo = ll_novo;
    ll_novo->anterior = ll_aux;
}

void ll_adicionarNoMeio() {
    anterior = ll_aux->anterior;

    ll_novo->proximo = ll_aux;
    ll_novo->anterior = anterior;
    anterior->proximo = ll_novo;
    ll_aux->anterior = ll_novo;
}

void ll_excluir(char *nome) {
    if (ll_inicio == NULL) {
        printf("Lista vazia!\n");
    } else {
        if (_stricmp(nome, ll_inicio->nome) == 0) {
            ll_excluirNoInicio();
        } else {
            ll_aux = ll_inicio;
            while (_stricmp(ll_aux->nome, nome) != 0 && ll_aux->proximo != NULL) {
                ll_aux = ll_aux->proximo;
            }
            if (_stricmp(ll_aux->nome, nome) == 0) {
                if (ll_aux->proximo == NULL) {
                    ll_excluirNoFinal();
                } else {
                    ll_excluirNoMeio();
                }
            } else {
                printf("Nao encontrado!\n");
            }
        }
    }
}

void ll_excluirNoInicio() {
    if (ll_inicio->proximo == NULL) {
        free(ll_inicio);
        ll_inicio = NULL;
    } else {
        ll_aux = ll_inicio;
        ll_inicio = ll_inicio->proximo;
        ll_inicio->anterior = NULL;
        free(ll_aux);
    }
}

void ll_excluirNoFinal() {
    anterior = ll_aux->anterior;
    anterior->proximo = NULL;
    free(ll_aux);
}

void ll_excluirNoMeio() {
    anterior = ll_aux->anterior;
    proximo = ll_aux->proximo;

    anterior->proximo = proximo;
    proximo->anterior = anterior;
    free(ll_aux);
}

void ll_paraInicio() {
    cursor = ll_inicio;
}

void ll_paraOProximo() {
    if (cursor != NULL) {
        cursor = cursor->proximo;
    }
}

void ll_paraOAnterior() {
    if (cursor != NULL) {
        cursor = cursor->anterior;
    }
}

struct ll_no * ll_noAtual() {
    return cursor;
}

struct ll_no * ll_searchByIndex(int indice) {
    struct ll_no *aux = ll_inicio;
    while (aux != NULL) {
        if (aux->indice == indice) {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}