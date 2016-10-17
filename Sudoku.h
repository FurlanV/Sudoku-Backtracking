/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sudoku.h
 * Author: vinicius
 *
 * Created on October 01, 2016, 4:20 AM
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
        int nTentativas;
    } Sudoku;

    int procuraPosicaoVazia(Sudoku sudoku, int *linha, int *coluna) ;
    void preencheTabuleiro(Sudoku *sudoku, char *nomeArquivo);
    void imprimeTabuleiro(Sudoku sudoku);
    void zeraTabuleiro(Sudoku *sudoku);
    int resolveSudoku(Sudoku *sudoku);

#ifdef __cplusplus
}
#endif

#endif /* SUDOKU_H */

