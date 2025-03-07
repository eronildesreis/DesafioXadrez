#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Estrutura para a peça de xadrez
typedef struct {
    char type;   // Tipo da peça: 'P' para peão, 'R' para torre, 'N' para cavalo, 'B' para bispo, 'Q' para rainha, 'K' para rei
    char color;  // Cor da peça: 'B' para preto, 'W' para branco
} ChessPiece;

// Função para inicializar o tabuleiro
void initBoard(ChessPiece board[BOARD_SIZE][BOARD_SIZE]) {
    // Inicializar as peças brancas
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i].type = 'P';  // Peões brancos na segunda linha
        board[1][i].color = 'W';

        // Torres brancas
        board[0][0].type = board[0][7].type = 'R';
        board[0][0].color = board[0][7].color = 'W';

        // Cavalos brancos
        board[0][1].type = board[0][6].type = 'N';
        board[0][1].color = board[0][6].color = 'W';

        // Bispos brancos
        board[0][2].type = board[0][5].type = 'B';
        board[0][2].color = board[0][5].color = 'W';

        // Rainha branca
        board[0][3].type = 'Q';
        board[0][3].color = 'W';

        // Rei branco
        board[0][4].type = 'K';
        board[0][4].color = 'W';
    }

    // Inicializar as peças pretas
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[6][i].type = 'P';  // Peões pretos na penúltima linha
        board[6][i].color = 'B';

        // Torres pretas
        board[7][0].type = board[7][7].type = 'R';
        board[7][0].color = board[7][7].color = 'B';

        // Cavalos pretos
        board[7][1].type = board[7][6].type = 'N';
        board[7][1].color = board[7][6].color = 'B';

        // Bispos pretos
        board[7][2].type = board[7][5].type = 'B';
        board[7][2].color = board[7][5].color = 'B';

        // Rainha preta
        board[7][3].type = 'Q';
        board[7][3].color = 'B';

        // Rei preto
        board[7][4].type = 'K';
        board[7][4].color = 'B';
    }

    // Inicializar as casas vazias
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].type = ' ';
            board[i][j].color = ' ';
        }
    }
}

// Função para exibir o tabuleiro
void printBoard(ChessPiece board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == ' ') {
                printf(". ");  // Casas vazias
            } else {
                printf("%c ", board[i][j].type);  // Exibe a peça
            }
        }
        printf("\n");
    }
}

// Função para mover uma peça
int movePiece(ChessPiece board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY) {
    // Verificar se a posição inicial e final estão dentro dos limites do tabuleiro
    if (startX < 0 || startX >= BOARD_SIZE || startY < 0 || startY >= BOARD_SIZE ||
        endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        printf("Movimento inválido! As coordenadas estão fora do tabuleiro.\n");
        return 0;
    }

    // Verificar se há uma peça na posição inicial
    if (board[startX][startY].type == ' ') {
        printf("Não há peça na posição inicial!\n");
        return 0;
    }

    // Verificar se a peça na posição inicial pertence ao jogador
    // Para simplicidade, consideraremos que o jogador da vez move a peça.
    // (Este código não lida com a alternância de jogadores, mas isso pode ser facilmente adicionado.)
    printf("Movendo a peça de (%d,%d) para (%d,%d)...\n", startX, startY, endX, endY);

    // Mover a peça para a nova posição
    board[endX][endY] = board[startX][startY];
    board[startX][startY].type = ' ';
    board[startX][startY].color = ' ';

    return 1;
}

int main() {
    ChessPiece board[BOARD_SIZE][BOARD_SIZE];
    initBoard(board);  // Inicializa o tabuleiro

    // Exibe o tabuleiro
    printBoard(board);

    // Movendo uma peça (exemplo: mover o peão branco de (1,0) para (3,0))
    if (movePiece(board, 1, 0, 3, 0)) {
        printf("Tabuleiro após o movimento:\n");
        printBoard(board);
    }

    return 0;
}