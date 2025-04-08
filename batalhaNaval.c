#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define tamanho 10
#define navio 3

void imprimirtabuleiro(char tabuleiro[tamanho][tamanho]) {
    printf("   A B C D E F G H I J\n"); // Cabeçalho das colunas
    for (int i = 0; i < tamanho; i++) {
        printf("%2d ", i + 1 ); // Índice das linhas
        for (int j = 0; j < tamanho; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
void aplicarhabilidadeCone(char tabuleiro[tamanho][tamanho], int linhainicio, int colunacentro, int alturacone) {
    for (int i = 0; i < alturacone; i++) {
        int linhaAtual = linhainicio + i;
        if (linhaAtual >= tamanho) break; // Evita sair do tabuleiro

        for (int j = colunacentro - i; j <= colunacentro + i; j++) {
            if (j >= 0 && j < tamanho) {
                tabuleiro[linhaAtual][j] = '5';
            }
        }
    }
}
void aplicarhabilidadeOctaedro(char tabuleiro[tamanho][tamanho], int linhacentro, int colunacentro) {
    int dlinhas[] = {0, -1, 1, 0, 0};     // centro, cima, baixo, nada, nada
    int dcolunas[] = {0, 0, 0, -1, 1};    // centro, nada, nada, esquerda, direita

    for (int i = 0; i < 5; i++) {
        int linha = linhacentro + dlinhas[i];
        int coluna = colunacentro + dcolunas[i];

        if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho) {
            tabuleiro[linha][coluna] = '5';
        }
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
    int navio1_x = 4, navio1_y = 4; // Navio horizontal começando em (5,5)
    int navio2_x = 2, navio2_y = 8; // Navio vertical começando em (3,9)
    int navio3_x = 0, navio3_y = 4; // Navio diagonal começando em (1,5) 
    int navio4_x = 9, navio4_y = 4; // Navio diagonal começando em (10,5)
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




    //ativar habilidade cruz
    int linhaverticalx1 = 7 ,linhahoeizontalx1 = 3;
    int linhaverticalx2 = 6 , linhahoeizontalx2 = 5; 
       // Posiciona a linha horizontalmente
       for (int i = 0; i < 5; i++) {
        tabuleiro[linhaverticalx1][linhahoeizontalx1 + i] = '5';
        // Posiciona a linha verticalmente
        for (int j = 0; j < 3; j++) {
            tabuleiro[linhaverticalx2 + j][linhahoeizontalx2] = '5';
        }
    }

    // Aplica o cone a partir da linha 0, coluna 4 (coluna 'E'), com 3 linhas de altura
    aplicarhabilidadeCone(tabuleiro, 0, 2, 3);
  
    // Aplica o octaedro no centro da posição [6][1] (linha 6, coluna 'B')
    aplicarhabilidadeOctaedro(tabuleiro, 6, 1);


    imprimirtabuleiro(tabuleiro);

   
    return 0;
}
