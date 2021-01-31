#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "declarations.h"

int main(){
    // Contatore delle possibilità di gioco rimaste
    unsigned short chancesCounter = 0;
    
    // Richiamo questa funzione per impostare la tavola di gioco principale
    shuffleGameBoard();

    // Richiamo questa funzione per stampare la tavola di gioco
    printGameBoard();

    // Continuo ad aggiornare la tavola di gioco e a stamparla finché non si è raggiunto il numero di tentativi massimi
    while(!isFinalSequenceFound() && chancesCounter < MAX_NUMBER_OF_CHANCES){
        int command = moveNumber();
        updateGameBoard(command);
        printGameBoard();
        chancesCounter++;
    }

    // Se il numero di tentativi equivale al numero massimo di tentativi disponibili, il gioco termina
    if(chancesCounter == MAX_NUMBER_OF_CHANCES){
        printf("\nHai terminato i tentativi disponibili.\n");
        return 0;
    }

    // Messaggio che compare quando il giocatore vince
    printf("\nComplimenti! Hai vinto il gioco del 15.\n");

    return 0;
}