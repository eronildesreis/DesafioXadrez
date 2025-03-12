#include <stdio.h>

#define N 8 // Tamanho do tabuleiro de xadrez (8x8)

// Função para exibir o tabuleiro de xadrez
void exibirTabuleiro(char tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Movimentos da Torre (horizontal e vertical)
void moverTorre(int x, int y, char tabuleiro[N][N]) {
    // Movimento na vertical (cima e baixo)
    for (int i = 0; i < N; i++) {
        if (i != x) {
            tabuleiro[i][y] = 'T'; // Marca as casas onde a torre pode se mover
        }
    }

    // Movimento na horizontal (esquerda e direita)
    for (int j = 0; j < N; j++) {
        if (j != y) {
            tabuleiro[x][j] = 'T'; // Marca as casas onde a torre pode se mover
        }
    }
}

// Movimentos do Bispo (diagonais)
void moverBispo(int x, int y, char tabuleiro[N][N]) {
    // Diagonal para cima à esquerda
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        tabuleiro[i][j] = 'B';
    }

    // Diagonal para cima à direita
    for (int i = x, j = y; i >= 0 && j < N; i--, j++) {
        tabuleiro[i][j] = 'B';
    }

    // Diagonal para baixo à esquerda
    for (int i = x, j = y; i < N && j >= 0; i++, j--) {
        tabuleiro[i][j] = 'B';
    }

    // Diagonal para baixo à direita
    for (int i = x, j = y; i < N && j < N; i++, j++) {
        tabuleiro[i][j] = 'B';
    }
}

// Movimentos da Rainha (combina movimentos da Torre e do Bispo)
void moverRainha(int x, int y, char tabuleiro[N][N]) {
    moverTorre(x, y, tabuleiro);  // Movimentos horizontais e verticais
    moverBispo(x, y, tabuleiro);  // Movimentos diagonais
}

// Movimentos do Cavalo (movimento em "L")
void moverCavalo(int x, int y, char tabuleiro[N][N]) {
    // As 8 possibilidades de movimento do Cavalo
    int movimentos[8][2] = {
        {-2, -1}, {-2, 1}, {2, -1}, {2, 1},   // Movimentos para cima
        {-1, -2}, {-1, 2}, {1, -2}, {1, 2}     // Movimentos para baixo
    };

    // Loop para aplicar cada movimento possível
    for (int i = 0; i < 8; i++) {
        int novaX = x + movimentos[i][0];
        int novaY = y + movimentos[i][1];

        if (novaX >= 0 && novaX < N && novaY >= 0 && novaY < N) {
            tabuleiro[novaX][novaY] = 'C'; // Marca as casas onde o cavalo pode se mover
        }
    }
}

// Função recursiva para simular o movimento avançado de uma peça
void moverRecursivamente(int x, int y, char tabuleiro[N][N], int direcaoX, int direcaoY, char simbolo) {
    if (x >= 0 && x < N && y >= 0 && y < N) {
        tabuleiro[x][y] = simbolo; // Marca a posição
        moverRecursivamente(x + direcaoX, y + direcaoY, tabuleiro, direcaoX, direcaoY, simbolo);
    }
}

// Função para simular o movimento avançado (como a Torre ou Rainha) com recursividade
void moverAvancado(int x, int y, char tabuleiro[N][N], int direcaoX, int direcaoY, char simbolo) {
    // Movimento recursivo (continua enquanto não ultrapassar os limites do tabuleiro)
    while (x >= 0 && x < N && y >= 0 && y < N) {
        tabuleiro[x][y] = simbolo; // Marca a posição atual
        x += direcaoX;
        y += direcaoY;
    }
}

// Função principal
int main() {
    // Inicializa o tabuleiro de xadrez
    char tabuleiro[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tabuleiro[i][j] = '.'; // Representação de uma casa vazia
        }
    }

    // Posições iniciais para as peças (exemplo)
    int x = 3, y = 3;

    // Movimentação da Torre
    printf("Movimento da Torre:\n");
    moverTorre(x, y, tabuleiro);
    exibirTabuleiro(tabuleiro);

    // Limpa o tabuleiro para o próximo movimento
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    // Movimentação do Bispo
    printf("\nMovimento do Bispo:\n");
    moverBispo(x, y, tabuleiro);
    exibirTabuleiro(tabuleiro);

    // Limpa o tabuleiro para o próximo movimento
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    // Movimentação da Rainha
    printf("\nMovimento da Rainha:\n");
    moverRainha(x, y, tabuleiro);
    exibirTabuleiro(tabuleiro);

    // Limpa o tabuleiro para o próximo movimento
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    // Movimentação do Cavalo
    printf("\nMovimento do Cavalo:\n");
    moverCavalo(x, y, tabuleiro);
    exibirTabuleiro(tabuleiro);

    return 0;
}
