#include <stdio.h>

#define TAMANHO 10
#define AGUA 0
#define NAVIO 3
#define TAMANHO_NAVIO 3

// Função para verificar se é possível posicionar o navio
int pode_posicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (diagonal == 0) { // horizontal ou vertical
            if (direcao == 0) l += i;       // vertical
            else if (direcao == 1) c += i;  // horizontal
        } else { // diagonal
            if (direcao == 0) { l += i; c += i; }        // diagonal principal
            else if (direcao == 1) { l += i; c -= i; }   // diagonal secundária
        }

        // Verifica se está dentro dos limites
        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO) return 0;
        // Verifica se há sobreposição
        if (tabuleiro[l][c] != AGUA) return 0;
    }
    return 1;
}

// Função para posicionar o navio
void posicionar_navio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (diagonal == 0) {
            if (direcao == 0) l += i;       // vertical
            else if (direcao == 1) c += i;  // horizontal
        } else {
            if (direcao == 0) { l += i; c += i; }        // diagonal principal
            else if (direcao == 1) { l += i; c -= i; }   // diagonal secundária
        }

        tabuleiro[l][c] = NAVIO;
    }
}

// Função para imprimir o tabuleiro
void imprimir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa o tabuleiro com água (0)

    // Tentativas de posicionamento com coordenadas fixas
    if (pode_posicionar(tabuleiro, 0, 0, 1, 0))  // horizontal
        posicionar_navio(tabuleiro, 0, 0, 1, 0);

    if (pode_posicionar(tabuleiro, 2, 2, 0, 0))  // vertical
        posicionar_navio(tabuleiro, 2, 2, 0, 0);

    if (pode_posicionar(tabuleiro, 5, 0, 0, 1))  // diagonal secundária
        posicionar_navio(tabuleiro, 5, 2, 1, 1);

    if (pode_posicionar(tabuleiro, 6, 6, 0, 1))  // diagonal principal
        posicionar_navio(tabuleiro, 6, 6, 0, 1);

    imprimir_tabuleiro(tabuleiro);

    return 0;
}