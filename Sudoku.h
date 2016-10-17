/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sudoku.h
 * Author: vinicius
 *
 * Created on October 15, 2016, 1:56 PM
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#ifndef SUDOKU_H
#define SUDOKU_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        int tabuleiro[9][9];
    } Sudoku;

    int procuraPosicaoVazia(Sudoku sudoku, int *linha, int *coluna) ;
    void preencheTabuleiro(Sudoku *sudoku);
    void imprimeTabuleiro(Sudoku sudoku);
    int resolveSudoku(Sudoku *sudoku);

#ifdef __cplusplus
}
#endif

#endif /* SUDOKU_H */

