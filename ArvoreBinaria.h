//
// Created by Vinicius on 21/05/2025.
//

#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

// Estruturas
struct ab_no {
    char cpf[12];
    int indice;
    struct ab_no *esquerda, *direita;
};

// Variáveis
extern struct ab_no *ab_inicio;
extern struct ab_no *ab_anterior;

// Protótipos
struct ab_no *ab_novoNo(char *cpf, int indice);
void ab_adicionar(struct ab_no *quem, struct ab_no *aonde);
void ab_finalizar(struct ab_no *quem);
struct ab_no *ab_localizar(char *cpf, struct ab_no *aonde);
void ab_excluir(char *cpf);

#endif //ARVOREBINARIA_H
