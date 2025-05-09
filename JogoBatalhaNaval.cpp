#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // ---------------- MOVIMENtA AS PEÇAS DE XADREZ ----------------

    // Simula o movimento da Torre usando estrutura 'for'
    int movimentoTorre = 5;
    printf("Movimento da Torre:\n");
    for (int i = 0; i < movimentoTorre; i++) {
        printf("Direita\n");
    }

    printf("\n");

    // Simula o movimento do Bispo usando estrutura 'while'
    int movimentoBispo = 5;
    int contadorBispo = 0;
    printf("Movimento do Bispo:\n");
    while (contadorBispo < movimentoBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    printf("\n");

    // Simula o movimento da Rainha usando estrutura 'do-while'
    int movimentoRainha = 8;
    int contadorRainha = 0;
    printf("Movimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < movimentoRainha);

    printf("\n");

    // ---------------- BATALHA NAVAL - POSICIONA OS NAVIOS ----------------

    // Inicializa o tabuleiro com água (valor 0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // Definine dois navios como vetores de tamanho 3
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 5;
    int colunaVertical = 1;

    // Validação simplificada: Faz com que navios caibam no tabuleiro
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Posiciona o navio na horizontal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se a posição já está ocupada
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] == AGUA) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
            }
        }

        // Posiciona o navio na vertical
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se a posição já está ocupada
            if (tabuleiro[linhaVertical + i][colunaVertical] == AGUA) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }
        }

        // Exibe o tabuleiro completo
        printf("Tabuleiro de Batalha Naval:\n");
        for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
            for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
                printf("%d ", tabuleiro[linha][coluna]);
            }
            printf("\n");
        }
    } else {
        printf("Erro: Coordenadas dos navios fora do limite do tabuleiro.\n");
    }

    return 0;
}

