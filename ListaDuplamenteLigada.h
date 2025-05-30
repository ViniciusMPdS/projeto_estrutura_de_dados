//
// Created by Vinicius on 21/05/2025.
//

#ifndef LISTADUPLAMENTELIGADA_H
#define LISTADUPLAMENTELIGADA_H

// Estrutura
struct ll_no {
    char nome[50];
    int indice;
    struct ll_no *anterior, *proximo;
};

// Variáveis
extern struct ll_no *ll_inicio;
extern struct ll_no *ll_novo;
extern struct ll_no *anterior;
extern struct ll_no *proximo;
extern struct ll_no *ll_aux;

// Protótipos
void ll_inicializar();
void ll_finalizar(struct ll_no *quem);
struct ll_no *ll_novoNo(char*nome, int indice);
void ll_adicionar(char*nome, int indice);
void ll_adicionarNoInicio();
void ll_adicionarNoFinal();
void ll_adicionarNoMeio();
void ll_excluir(char*nome);
void ll_excluirNoInicio();
void ll_excluirNoFinal();
void ll_excluirNoMeio();

void ll_paraInicio();
void ll_paraOProximo();
void ll_paraOAnterior();
struct ll_no *ll_noAtual();
struct ll_no *ll_searchByIndex(int indice);

#endif //LISTADUPLAMENTELIGADA_H