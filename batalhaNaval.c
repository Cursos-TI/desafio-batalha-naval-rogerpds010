#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define tamanho 10
#define navio 3

void imprimirTabuleiro(char tabuleiro[tamanho][tamanho]) {
    printf("   A B C D E F G H I J\n"); // Cabeçalho das colunas
    for (int i = 0; i < tamanho; i++) {
        printf("%2d ", i + 1); // Índice das linhas
        for (int j = 0; j < tamanho; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    printf(" Tabuleiro Batalha naval \n");


    char tabuleiro[tamanho][tamanho];
    
    // Inicializa o tabuleiro com água ('~')
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = '~';
        }
    }
    // Declaração e posicionamento dos navios
    int navio1_x = 3, navio1_y = 4; // Navio horizontal começando em (4,5)
    int navio2_x = 5, navio2_y = 6; // Navio vertical começando em (6,7)
    int navio3_x = 0, navio3_y = 0; // Navio diagonal começando em (1,1) 
    int navio4_x = 9, navio4_y = 5; // Navio diagonal começando em (10,6)
    // Posiciona o navio horizontalmente
    for (int i = 0; i < navio; i++) {
        tabuleiro[navio1_x][navio1_y + i] = '3';
    }
    
    // Posiciona o navio verticalmente
    for (int i = 0; i < navio; i++) {
        tabuleiro[navio2_x + i][navio2_y] = '3';
    }
    // Posiciona o navio diagonalmente
    for (int i = 0; i < navio; i++) {
        tabuleiro[navio3_x + i][navio3_y + i] = '3';
    }
    // Posiciona o navio diagonalmente
    for (int i = 0; i < navio; i++) {
        tabuleiro[navio4_x - i][navio4_y - i] = '3';
    // o - faz com que o navio esteja de costas
    }
    imprimirTabuleiro(tabuleiro);



    return 0;
}
