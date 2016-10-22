#include "Sudoku.h"

int preencheTabuleiro(Sudoku *sudoku, char *nomeArquivo) //constroi o tabuleiro 9x9 apartir de um arquivo
{
    int i = 0;
    int j = 0;
    int n;
    FILE *file;

    file = fopen(nomeArquivo, "r");

    if (file) {
        sudoku->nTentativas = 0;
        while (!feof(file)) {

            fscanf(file, "%d ", &n);
            
            sudoku->tabuleiro[i][j] = n;

            if (j >= 0 && j < 8) //0 - 8
                j++;
            else if (j == 8) {
                i++;
                j = 0;
            }

        }
        
        return 1;
        
    } else {
        printf("Não foi possivel encontrar o arquivo\n");
        return 0;
    }
}

void zeraTabuleiro(Sudoku *sudoku) {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            sudoku->tabuleiro[i][j] = 0;
        }
    }
}

void imprimeTabuleiro(Sudoku sudoku) {
    int i, j, k;

    for (i = 0; i < 9; i++) {

        if (i % 3 == 0) {
            for (k = 0; k < 8; k++)
                printf("+--");
        }
        printf("\n");

        for (j = 0; j < 9; j++) {

            if (j == 0 || j % 3 == 0)
                printf("%s", "|");

            printf("%d ", sudoku.tabuleiro[i][j]);

            if (j == 8)
                printf("%s", "|");
        }
        printf("\n");

        if (i == 8) {
            for (k = 0; k < 8; k++) {
                printf("+--");
            }
            printf("\n");
        }
    }
}

int procuraPosicaoVazia(Sudoku sudoku, int *linha, int *coluna) {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (sudoku.tabuleiro[i][j] == 0) {
                *coluna = j;
                *linha = i;
                return 1;
            }
        }
    }

    return 0;
}

int isPosicaoSegura(Sudoku *sudoku, int linha, int coluna, int numero) {

    int i, j;
    int linhaInicialGrid, colunaInicialGrid;

    for (i = 0; i < 9; i++) { //verifica se o numero ja existe na linha
        if (sudoku->tabuleiro[linha][i] == numero)
            return 0;
    }

    for (i = 0; i < 9; i++) { //verifica se o numero ja existe na coluna
        if (sudoku->tabuleiro[i][coluna] == numero)
            return 0;
    }

    linhaInicialGrid = (linha - (linha % 3)); //Marca a posição inicial do grid atual 
    colunaInicialGrid = (coluna - (coluna % 3)); //Marca a coluna inicial do grid atual

    for (i = 0; i < 3; i++) { //percorre o grid e verifica se o numero ja foi utilizado neste grid
        for (j = 0; j < 3; j++) {
            if (sudoku->tabuleiro[i + linhaInicialGrid][j + colunaInicialGrid] == numero)
                return 0;
        }
    }

    return 1;
}

int resolveSudoku(Sudoku *sudoku) {

    int i;
    int linhaVazia, colunaVazia;

    if (procuraPosicaoVazia(*sudoku, &linhaVazia, &colunaVazia) == 0) //se não houver posições vazias sudoku resolvido
        return 1;

    for (i = 1; i <= 9; i++) {
        if (isPosicaoSegura(sudoku, linhaVazia, colunaVazia, i)) {
            sudoku->nTentativas++;
            sudoku->tabuleiro[linhaVazia][colunaVazia] = i;

            if (resolveSudoku(sudoku))
                return 1;

            sudoku->tabuleiro[linhaVazia][colunaVazia] = 0;
        }
    }
    return 0;
}