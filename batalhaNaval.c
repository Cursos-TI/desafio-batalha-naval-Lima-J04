#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO 10

// Tamanho dos navios
#define TAMANHO_NAVIO 3

// Valor que representa um navio no tabuleiro
#define NAVIO 3

int main() {
    // Declaração e inicialização do tabuleiro com 0 (água)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Coordenadas iniciais do navio horizontal (linha, coluna)
    int linha_h = 2;
    int coluna_h = 4;

    // Coordenadas iniciais do navio vertical (linha, coluna)
    int linha_v = 5;
    int coluna_v = 7;

    // Verifica se o navio horizontal está dentro dos limites
    if (coluna_h + TAMANHO_NAVIO <= TAMANHO) {
        // Verifica se há sobreposição antes de posicionar
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio horizontal
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_h][coluna_h + i] = NAVIO;
            }
        } else {
            printf("Erro: Sobreposição detectada ao posicionar o navio horizontal.\n");
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
    }

    // Verifica se o navio vertical está dentro dos limites
    if (linha_v + TAMANHO_NAVIO <= TAMANHO) {
        // Verifica se há sobreposição antes de posicionar
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio vertical
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_v + i][coluna_v] = NAVIO;
            }
        } else {
            printf("Erro: Sobreposição detectada ao posicionar o navio vertical.\n");
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

