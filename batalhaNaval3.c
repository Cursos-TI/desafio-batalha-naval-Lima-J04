#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define TAM_HAB 5  // Tamanho das matrizes de habilidade (5x5)
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Imprime o tabuleiro
void imprimir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Posiciona navio no tabuleiro
void posicionar_navio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < 3; i++) {
        int l = linha, c = coluna;
        if (diagonal == 0) {
            if (direcao == 0) l += i;       // vertical
            else c += i;                    // horizontal
        } else {
            if (direcao == 0) { l += i; c += i; }       // diagonal principal
            else { l += i; c -= i; }                    // diagonal secundária (inversa)
        }

        if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO) {
            tabuleiro[l][c] = NAVIO;
        }
    }
}

// Inicializa matriz 2D com zeros
void inicializar_matriz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Cria matriz de habilidade em forma de cone
void criar_cone(int matriz[TAM_HAB][TAM_HAB]) {
    inicializar_matriz(matriz);
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Cria matriz de habilidade em forma de cruz
void criar_cruz(int matriz[TAM_HAB][TAM_HAB]) {
    inicializar_matriz(matriz);
    int meio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        matriz[meio][i] = 1;
        matriz[i][meio] = 1;
    }
}

// Cria matriz de habilidade em forma de octaedro (losango)
void criar_octaedro(int matriz[TAM_HAB][TAM_HAB]) {
    inicializar_matriz(matriz);
    int meio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Aplica a matriz de habilidade ao tabuleiro
void aplicar_habilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HAB][TAM_HAB], int origem_l, int origem_c) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int l = origem_l + i - offset;
                int c = origem_c + j - offset;
                if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    // Posiciona navios (com coordenadas válidas)
    posicionar_navio(tabuleiro, 0, 0, 1, 0);  // horizontal
    posicionar_navio(tabuleiro, 2, 2, 0, 0);  // vertical
    posicionar_navio(tabuleiro, 5, 4, 1, 1);  // diagonal inversa (ajustada)
    posicionar_navio(tabuleiro, 6, 6, 0, 1);  // diagonal principal

    // Cria as habilidades
    criar_cone(cone);
    criar_cruz(cruz);
    criar_octaedro(octaedro);

    // Aplica as habilidades em pontos fixos
    aplicar_habilidade(tabuleiro, cone, 2, 5);      // cone centrado em (2,5)
    aplicar_habilidade(tabuleiro, cruz, 7, 2);      // cruz centrada em (7,2)
    aplicar_habilidade(tabuleiro, octaedro, 5, 5);  // octaedro centrado em (5,5)

    // Imprime o tabuleiro final
    imprimir_tabuleiro(tabuleiro);

    return 0;
}
