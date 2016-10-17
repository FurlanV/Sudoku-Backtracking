/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vinicius
 *
 * Created on October 01, 2016, 4:20 AM
 */

#include "Sudoku.h"

/*
 * 
 */
int main(int argc, char** argv) {

    int arq = 1;
    char nomeArquivo[30];
    Sudoku sudoku;

    while (arq) {
        
        printf("Digite o nome do arquivo: ");
        scanf("%s",nomeArquivo);
        getchar();
        
        preencheTabuleiro(&sudoku, nomeArquivo);
        printf("Tabuleiro Inicial:\n");
        imprimeTabuleiro(sudoku);

        if (resolveSudoku(&sudoku)) {
            printf("Resolvido !\n");
            imprimeTabuleiro(sudoku);
            printf("Foram feitas %d tentativas\n",sudoku.nTentativas);
        } else
            printf("O tabuleiro nao possui solucao !\n");
        
        printf("Deseja carregar um novo tabuleiro ?\n0- Nao | 1- Sim\n");
        scanf("%d",&arq);
        
        if(arq == 1){
            zeraTabuleiro(&sudoku);
            getchar();
        }
    }


    return (EXIT_SUCCESS);
}

