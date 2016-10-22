/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vinicius
 *
 * Created on October 15, 2016, 1:55 PM
 */

#include "Sudoku.h"

/*
 * 
 */
int main(int argc, char** argv) {

    int arq = 1, opc;
    char nomeArquivo[30];
    Sudoku sudoku;

    while (arq) {


        printf("Digite o nome do arquivo: ");
        scanf("%s", nomeArquivo);
        getchar();
        if (preencheTabuleiro(&sudoku, nomeArquivo)) {

            printf("1- Resolver Sudoku | 2- Resolver Sudoku em modo análise\n");
            scanf("%d", &opc);

            while (opc < 1 || opc > 2) {
                printf("1- Resolver Sudoku | 2- Resolver Sudoku em modo análise\n");
                scanf("%d", &opc);
            }

            switch (opc) {
                case 1:
                    printf("Tabuleiro Inicial:\n");
                    imprimeTabuleiro(sudoku);

                    if (resolveSudoku(&sudoku)) {
                        printf("Resolvido !\n");
                        imprimeTabuleiro(sudoku);
                    } else
                        printf("O tabuleiro nao possui solucao !\n");
                    break;
                case 2:
                    printf("Tabuleiro Inicial:\n");
                    imprimeTabuleiro(sudoku);

                    if (resolveSudoku(&sudoku)) {
                        printf("Resolvido !\n");
                        imprimeTabuleiro(sudoku);
                        printf("\nForam feitas %d tentativas\n\n", sudoku.nTentativas);
                    } else
                        printf("O tabuleiro nao possui solucao !\n");
                    break;
                default:
                    printf("Opção inexistente !\n");
                    break;
            }

            printf("Deseja carregar um novo tabuleiro ?\n0- Nao | 1- Sim\n");
            scanf("%d", &arq);

            if (arq == 1) {
                zeraTabuleiro(&sudoku);
                getchar();
            }
        } else {
            printf("ERRO !\n");
        }
    }


    return (EXIT_SUCCESS);
}

