#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct para representar uma Sala (nó da árvore binária)
typedef struct Sala Sala;
struct Sala {
    char nome[50];          // Nome do cômodo
    Sala *esquerda;         // Caminho esquerdo
    Sala *direita;          // Caminho direito
};

// Protótipos das funções
Sala* criarSala(char *nome);
void explorarSalas(Sala *atual);
void limparBuffer(void);

/*
 * Função: criarSala
 * Descrição: Cria  uma nova sala com o nome fornecido.
 * Inicializa ponteiros esquerda/direita como NULL (folha por padrão).
 * Parâmetros: nome - string com o nome da sala.
 * Retorno: Ponteiro para a nova Sala alocada.
 */
Sala* criarSala(char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("[ERRO] Falha na alocação de memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

/*
 * Função: explorarSalas
 * Descrição: Função recursiva principal para exploração interativa da mansão.
 * Exibe sala atual, verifica se é folha, e oferece menu de escolhas.
 * Permite backtracking (volta após explorar subárvore) e saída manual.
 * Parâmetros: atual - ponteiro para a sala atual.
 */
void explorarSalas(Sala *atual) {
    printf("\n=== %s ===\n", atual->nome);

    // Verifica se é uma folha (sem caminhos)
    if (atual->esquerda == NULL && atual->direita == NULL) {
        printf("Este cômodo não possui mais saídas.\n");
        printf("Você encontrou o fim desta ala da mansão!\n");
        printf("Pressione Enter para voltar...\n");
        getchar();  // Aguarda confirmação
        return;
    }

    // Menu interativo para não-folhas
    char escolha;
    while (1) {
        printf("\nCaminhos disponíveis:\n");
        if (atual->esquerda != NULL) {
            printf("  e - Ir para a esquerda\n");
        }
        if (atual->direita != NULL) {
            printf("  d - Ir para a direita\n");
        }
        printf("  s - Sair da mansão\n");
        printf("Sua escolha: ");
        
        scanf(" %c", &escolha);
        limparBuffer();
        escolha = tolower(escolha);  // Insensível a maiúsculas

        if (escolha == 's') {
            printf("\nVocê decidiu sair da mansão...\n");
            return;
        } else if (escolha == 'e') {
            if (atual->esquerda != NULL) {
                explorarSalas(atual->esquerda);  // Recursão: explora subárvore esquerda
                // Após retornar, continua no loop para novas escolhas
            } else {
                printf("  [ERRO] Caminho esquerdo não existe!\n");
            }
        } else if (escolha == 'd') {
            if (atual->direita != NULL) {
                explorarSalas(atual->direita);  // Recursão: explora subárvore direita
            } else {
                printf("  [ERRO] Caminho direito inexistente!\n");
            }
        } else {
            printf("  [ERRO] Escolha inválida! Tente novamente.\n");
        }
    }
}

/*
 * Função: limparBuffer
 * Descrição: Limpa o buffer de entrada após scanf para evitar leituras incorretas.
 */
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
 * Função principal: monta o mapa e inicia a exploração
 */
int main(void) {
    // Construção da árvore da mansão
    Sala *hall = criarSala("Hall de Entrada");

    // Esquerda: Sala de Estar
    hall->esquerda = criarSala("Sala de Estar");
    hall->esquerda->esquerda = criarSala("Cozinha");
    hall->esquerda->esquerda->esquerda = criarSala("Despensa");
    hall->esquerda->esquerda->direita = criarSala("Sala de Jantar");
    hall->esquerda->direita = criarSala("Biblioteca");
    hall->esquerda->direita->esquerda = criarSala("Escritorio");
    hall->esquerda->direita->direita = criarSala("Corredor Superior");

    // Direita: Corredor Inferior
    hall->direita = criarSala("Corredor Inferior");
    hall->direita->esquerda = criarSala("Quarto de Hospedes");
    hall->direita->direita = criarSala("Banheiro");
    hall->direita->direita->esquerda = criarSala("Lavanderia");
    hall->direita->direita->direita = criarSala("Jardim");

    // Início do jogo
    printf("Bem-vindo a Detective Quest!\n");
    printf("Explore a mansão em busca de pistas.\n");
    printf("Use 'e' para esquerda, 'd' para direita, 's' para sair.\n\n");

    // Inicia exploração a partir do Hall
    explorarSalas(hall);

    printf("\nFim da investigacao!\n");

    // Nota: Em produção, implementar free recursivo para liberar memória
    return 0;
}
