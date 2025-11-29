#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Capacidade da fila (exemplo: 5 peças)
#define CAPACIDADE 5

// Struct que representa uma peça do Tetris
typedef struct {
    char nome;  // Tipo da peça: 'I', 'O', 'T', 'L'
    int id;     // Identificador único sequencial
} Peca;

// Vetor para a fila circular
Peca fila[CAPACIDADE];

// Variáveis controle da fila circular
int frente = -1;    // Índice da frente da fila
int tras = -1;      // Índice do final da fila
int proximo_id = 0; // Contador global para IDs únicos das peças

// Protótipos das funções
Peca gerarPeca(void);
int vazia(void);
int cheia(void);
void enfileirar(Peca p);
void desenfileirar(void);
void exibirFila(void);
void limparBuffer(void);

/*
 * Função: gerarPeca
 * Descrição: Gera uma nova peça com tipo aleatório ('I','O','T','L')
 *e ID único incremental.
 * Retorno: Struct Peca pronta para enfileirar.
 */
Peca gerarPeca(void) {
    Peca p;
    char tipos[] = {'I', 'O', 'T', 'L'};
    p.nome = tipos[rand() % 4];
    p.id = proximo_id++;
    return p;
}

/*
 * Função: vazia
 * Descrição: Verifica se a fila está vazia.
 * Retorno: 1 se vazia, 0 caso contrário.
 */
int vazia(void) {
    return frente == -1;
}

/*
 * Função: cheia
 * Descrição: Verifica se a fila está cheia (capacidade máxima atingida).
 * Retorno: 1 se cheia, 0 caso contrário.
 */
int cheia(void) {
    return (tras + 1) % CAPACIDADE == frente;
}

/*
 * Função: enfileirar
 * Descrição: Adiciona uma peça ao final da fila
 *Ignora se cheia. Trata caso especial de primeira inserção.
 */
void enfileirar(Peca p) {
    if (cheia()) {
        return;
    }
    if (vazia()) {
        // Primeira peça: inicializa frente e tras
        frente = tras = 0;
    } else {
        // Avança o tras circularmente
        tras = (tras + 1) % CAPACIDADE;
    }
    fila[tras] = p;
}

/*
 * Função: desenfileirar
 * Descrição: Remove a peça da frente da fila
 *Ignora se vazia. Trata caso especial de última peça.
 */
void desenfileirar(void) {
    if (vazia()) {
        return;
    }
    if (frente == tras) {
        // Última peça: esvazia a fila
        frente = tras = -1;
    } else {
        // Avança a frente circularmente
        frente = (frente + 1) % CAPACIDADE;
    }
}

/*
 * Função: exibirFila
 * Descrição: Exibe o estado atual da fila de forma clara, respeitando a circularidade.
 *            Formato: [T 0] [O 1] ...
 */
void exibirFila(void) {
    printf("\nFila de peças\n");
    if (vazia()) {
        printf("  [Vazia]\n");
        return;
    }
    printf("  ");
    int i = frente;
    int prox = (tras + 1) % CAPACIDADE;
    do {
        printf("[%c %d] ", fila[i].nome, fila[i].id);
        i = (i + 1) % CAPACIDADE;
    } while (i != prox);
    printf("\n");
}

/*
 * Função: limparBuffer
 * Descrição: Limpa o buffer de entrada após scanf para evitar problemas com \n residual.
 */
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
 * Função principal
 */
int main(void) {
    int opcao;

    printf("Tetris Stack - Fila de Peças Futuras\n");
    printf("=====================================\n\n");

    // Inicialização: semente randômica e preenche fila com 5 peças
    srand(time(NULL));
    for (int i = 0; i < CAPACIDADE; i++) {
        enfileirar(gerarPeca());
    }

    // Loop principal do menu
    do {
        // Exibe estado atual antes da ação
        exibirFila();

        printf("\nOpções de ação:\n");
        printf("  1 - Jogar peça (dequeue)\n");
        printf("  2 - Inserir nova peça (enqueue)\n");
        printf("  0 - Sair\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);
        limparBuffer();

        if (opcao == 0) {
            printf("\nObrigado por jogar Tetris Stack!\n");
            break;
        }

        if (opcao == 1) {
            if (!vazia()) {
                Peca jogada = fila[frente];
                printf("\n  Jogando peça da frente...\n");
                printf("  Peça jogada: [%c %d]\n", jogada.nome, jogada.id);
                desenfileirar();
                // Exibe fila atualizada após a ação
                exibirFila();
            } else {
                printf("\n  [ERRO] Fila vazia! Não há peças para jogar.\n");
            }
        } else if (opcao == 2) {
            if (!cheia()) {
                Peca nova = gerarPeca();
                enfileirar(nova);
                printf("\n  Nova peça gerada e enfileirada.\n");
                printf("  Peça inserida: [%c %d]\n", nova.nome, nova.id);
                // Exibe fila atualizada após a ação
                exibirFila();
            } else {
                printf("\n  [ERRO] Fila cheia! Capacidade máxima atingida (%d peças).\n", CAPACIDADE);
            }
        } else {
            printf("\n  [ERRO] Opção inválida! Tente novamente.\n");
        }

        printf("\n");
    } while (1);

    return 0;
}
