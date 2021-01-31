#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <stdio.h>

#define ROWS 4                               // Numero di righe della matrice
#define COLUMNS 4                            // Numero di colonne della matrice
#define TRUE 1                               // TRUE -> 1
#define FALSE 0                              // FALSE -> 0
#define MAX_NUMBER_OF_CHANCES 50             // Numero massimo di tenativi

/**
 * Indice che indica la riga contenente lo spazio vuoto
 */
extern int blankSpaceRow;

/**
 * Indice che indica la colonna contenente lo spazio vuoto
 */
extern int blankSpaceColumn;

/**
 * Matrice ROWS x COLUMNS che rappresenterà la tavola di gioco
 */
extern int gameBoard[ROWS][COLUMNS];

/**
 * Matrice ROWS x COLUMNS che contiene la sequenza necessaria per vincere il gioco
 */
extern int completedGameBoardSample[ROWS][COLUMNS];

/**
 * Vettore monodimensionale che indica il percorso sull'asse delle x dello spazio bianco (destra o sinistra). 
 * L'asse delle x indica le colonne
 */
extern int xAxis[];

/**
 * Vettore monodimensionale che indica il percorso sull'asse delle y dello spazio bianco (sopra o sotto). 
 * L'asse delle x indica le righe
 */
extern int yAxis[];

/**
 * Enumerazione utilizzata per gestire la posizione del numero adiacente allo spazio vuoto
 */
enum MoveNumber{
    MOVE_NUMBER_UP = 0,    // Il numero si muove verso l'alto
    MOVE_NUMBER_DOWN = 1,  // Il numero si muove verso il basso
    MOVE_NUMBER_LEFT = 2,  // Il numero si muove verso la sinistra
    MOVE_NUMBER_RIGHT = 3  // Il numero si muove verso la destra
};

/**
 * Funzione che stampa la tavola di gioco
 */
void printGameBoard();

/**
 * Funzione che permette di impostare la tavola di gioco mischiando gli elementi pre-impostati
 */
void shuffleGameBoard();

/**
 * Funzione che permette di aggiornare lo stato della tavola di gioco
 * 
 * @param[in] moveNumberCommand -> Il comando che si riferisce al dove spostare il numero
 */
void updateGameBoard(enum MoveNumber moveNumberCommand);

/**
 * Funzione che scambia la posizione di due elementi
 * 
 * @param[in/out] x -> Il primo elemento
 * @param[in/out] y -> Il secondo elemento
 */
void swap(int *x, int *y);

/**
 * Funzione che controlla se il giocatore ha piazzato i numeri correttamente
 * 
 * @param[out] TRUE/FALSE -> TRUE se il gioco è finito, FALSE altrimenti
 */
int isFinalSequenceFound();

/**
 * Funzione che ritorna il codice associato allo spostamento che il numero deve compiere
 */
enum MoveNumber moveNumber();

#endif