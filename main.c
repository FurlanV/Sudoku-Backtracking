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
    
   
    Sudoku sudoku;
    
    preencheTabuleiro(&sudoku);
    printf("Tabuleiro Inicial:\n");
    imprimeTabuleiro(sudoku);
    
    if(resolveSudoku(&sudoku)){
        printf("Resolvido !\n");
        imprimeTabuleiro(sudoku);
    }
    else
        printf("O tabuleiro nao possui solucao !\n");
   
    return (EXIT_SUCCESS);
}

