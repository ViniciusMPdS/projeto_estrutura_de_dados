# Estrutura de Dados: Projeto Árvores Binárias

[cite\_start]Este projeto, de autoria do Prof. Marcos Nava [cite: 5][cite\_start], é um sistema de gerenciamento de dados que utiliza diferentes estruturas de dados para simular um banco de dados em disco[cite: 8].

## Descrição

O sistema utiliza as seguintes estruturas:

  * [cite\_start]**Lista Dinâmica:** Simula um banco de dados em disco[cite: 8]. [cite\_start]Armazena os dados completos, incluindo CPF, nome, endereço, telefone e email[cite: 10, 11, 12, 13, 14, 15, 24].
  * [cite\_start]**Lista Duplamente Ligada:** Atua como um índice de ordenação de dados[cite: 8]. [cite\_start]Armazena o nome e o número de registro[cite: 26].
  * [cite\_start]**Árvore Binária:** Funciona como um índice de chave primária[cite: 8]. [cite\_start]Armazena o CPF e o número de registro[cite: 20].

Os dados a serem adicionados incluem:

  * [cite\_start]**CPF** (chave primária) [cite: 11]
  * [cite\_start]**Nome** (índice de ordenação) [cite: 12]
  * [cite\_start]**Endereço** [cite: 13]
  * [cite\_start]**Telefone** [cite: 14]
  * [cite\_start]**Email** [cite: 15]

## Como Executar o Projeto

Para compilar e executar o projeto, siga os passos abaixo:

1.  **Clone o repositório:**

    ```bash
    git clone https://github.com/ViniciusMPdS/projeto_estrutura_de_dados.git
    cd projeto_estrutura_de_dados
    ```

2.  **Compile o código usando um compilador C (como GCC):**

    ```bash
    gcc -o projeto_final main.c ListaDinamica.c ListaDuplamenteLigada.c ArvoreBinaria.c
    ```

3.  **Execute o programa:**

    ```bash
    ./projeto_final
    ```

## Estrutura de Arquivos

  * `main.c`: Contém a lógica principal do programa, o menu de opções e as chamadas para as funções das estruturas de dados.
  * `ListaDinamica.h`: Cabeçalho com a definição da estrutura e protótipos das funções da Lista Dinâmica.
  * `ListaDinamica.c`: Implementação da Lista Dinâmica.
  * `ListaDuplamenteLigada.h`: Cabeçalho com a definição da estrutura e protótipos das funções da Lista Duplamente Ligada.
  * `ListaDuplamenteLigada.c`: Implementação da Lista Duplamente Ligada.
  * `ArvoreBinaria.h`: Cabeçalho com a definição da estrutura e protótipos das funções da Árvore Binária.
  * `ArvoreBinaria.c`: Implementação da Árvore Binária.
