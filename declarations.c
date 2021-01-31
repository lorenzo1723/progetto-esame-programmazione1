#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "declarations.h"

/**
 * Indice che indica la riga contenente lo spazio vuoto
 */
int blankSpaceRow = ROWS - 1; // L'ultima riga

/**
 * Indice che indica la colonna contenente lo spazio vuoto
 */
int blankSpaceColumn = COLUMNS - 1; // L'ultima colonna

/**
 * Matrice ROWS x COLUMNS che rappresenterà la tavola di gioco
 */
int gameBoard[ROWS][COLUMNS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}
};

/**
 * Matrice ROWS x COLUMNS che contiene la sequenza necessaria per vincere il gioco
 */
int completedGameBoardSample[ROWS][COLUMNS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}
};

/**
 * Vettore monodimensionale che indica il percorso sull'asse delle x dello spazio bianco (destra o sinistra). 
 * L'asse delle x indica le colonne
 */
int xAxis[] = {0, 0, -1, 1};

/**
 * Vettore monodimensionale che indica il percorso sull'asse delle y dello spazio bianco (sopra o sotto). 
 * L'asse delle y indica le righe
 */
int yAxis[] = {-1, 1, 0, 0};

/**
 * Funzione che stampa la tavola di gioco
 */
void printGameBoard(){
    for(size_t i = 0; i < ROWS; ++i){
        for(size_t j = 0; j < COLUMNS; ++j){
            // Se l'elemento [i][j] è maggiore di 0, viene stampato
            if(gameBoard[i][j]){
                (j != COLUMNS - 1) ? printf("%2d ", gameBoard[i][j]) : printf("%2d \n", gameBoard[i][j]);
            }
            // Se l'elemento [i][j] equivale a 0, viene stampato uno spazio vuoto 
            else{
                (j != COLUMNS - 1) ? printf("%2s ", "") : printf("%2s \n", "");
            }
        }
    }
}

/**
 * Funzione che permette di impostare la tavola di gioco mischiando gli elementi pre-impostati
 */
void shuffleGameBoard(){
    srand(time(NULL));

    // Mischio gli elementi della tavola
    for(size_t i = 0; i < ROWS; ++i){
        for(size_t j = 0; j < COLUMNS; ++j){
            // Considero solo gli elementi maggiori di 0
            if(gameBoard[i][j]){
                int x = rand() % 4;
                int y = rand() % 4;

                // Mischio ogni elemento tranne l'ultimo poiché è di default lo spazio vuoto
                if(x != 3 && y != 3)
                    swap(&gameBoard[i][j], &gameBoard[x][y]);
            }
        }
    }
}

/**
 * Funzione che permette di aggiornare lo stato della tavola di gioco
 * 
 * @param[in] moveNumberCommand -> Il comando che si riferisce al dove spostare il numero
 */
void updateGameBoard(enum MoveNumber moveNumberCommand){
    // Contenitore della riga indice dello spazio vuoto
    size_t i = blankSpaceRow + yAxis[moveNumberCommand];
    
    // Contenitore della colonna indice dello spazio vuoto
    size_t j = blankSpaceColumn + xAxis[moveNumberCommand];

    if(i >= 0 && i < ROWS && j >= 0 && j < COLUMNS){
        // Sposto lo spazio bianco
        gameBoard[blankSpaceRow][blankSpaceColumn] = gameBoard[i][j];
        gameBoard[i][j] = 0;

        // Assegno il nuovo indice di riga e di colonna dello spazio bianco
        blankSpaceRow = i;
        blankSpaceColumn = j;
    }
}

/**
 * Funzione che scambia la posizione di due elementi
 * 
 * @param[in/out] x -> Il primo elemento
 * @param[in/out] y -> Il secondo elemento
 */
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Funzione che controlla se il giocatore ha piazzato i numeri correttamente
 * 
 * @param[out] TRUE/FALSE -> TRUE se il gioco è finito, FALSE altrimenti
 */
int isFinalSequenceFound(){
    for(size_t i = 0; i < ROWS; ++i){
        for(size_t j = 0; j < COLUMNS; ++j){
            if(gameBoard[i][j] != completedGameBoardSample[i][j]){
                return FALSE;
            }
        }
    }

    return TRUE;
}

/**
 * Funzione che ritorna il codice associato allo spostamento che il numero deve compiere
 */
enum MoveNumber moveNumber(){
    // Codice inserito dall'utente per spostare i numeri
    int characterInput;

    while(TRUE){
        printf("Inserisci u/U per spostare il numero sopra\n");
        printf("Inserisci d/D per spostare il numero sotto\n");
        printf("Inserisci l/L per spostare il numero a sinistra\n");
        printf("Inserisci r/R per spostare il numero a destra\n\n");
        printf("Inserisci q/Q per terminare l'esecuzione\n\n");

        characterInput = getchar();
        while(getchar() != '\n');

            /**
             * NOTA: Quando viene richiamato, ad esempio, il comando 'D' (DOWN), viene ritornato come valore il comando UP 
             *       perché ho deciso di spostare lo spazio al posto del numero
             */

            switch(characterInput){
                case 'd': 
                case 'D':
                    return MOVE_NUMBER_UP;

                case 'u': 
                case 'U':
                    return MOVE_NUMBER_DOWN;

                case 'r': 
                case 'R':
                    return MOVE_NUMBER_LEFT;

                case 'l': 
                case 'L':
                    return MOVE_NUMBER_RIGHT;

                case 'q':
                case 'Q':    
                    exit(TRUE);
            }
    }
}