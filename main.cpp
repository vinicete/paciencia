#include <stdio.h>
#include <stdlib.h> 
#include <conio2.h>
#include <time.h> // usado para "randomizar" o embaralhamento;
#include <ctype.h> // usado apenas para toupper() e tolower();
#include <windows.h> // foi usado apenas para o Sleep();
#include "scr/tad.h" // onde fica o tipo abstrado de dado do tipo Fila
#include "scr/desenhos.h" // header de layouts das paginas e exibe as cartas;
#include "scr/menus.h" // header de menus do jogo;
#include "scr/game.h" // header com as funcoes que possibilitem jogar;

int main(){
	struct deck deck;
	struct deck auxdeck;
    struct deck ord[NUM_ORDEM];
    struct deck tab[NUM_TABULEIRO];
    int op,opp,cont=0;
	
	
	inicio(); // Exibe regras
	
	startFunctionGame(tab,deck,ord,auxdeck); // Parametros inciais para possibiliar o inicio do jogo
	conferePraCima(tab);
	desenhaTab(deck,tab,ord);
	gotoxy(2,14);
	
	do{
		
		op = Menu();
		switch(op){
			LimpaTela(3, 23, 99, 24);
			case 'A':
				LimpaTela(3,23,99,24);
				do{
					
					opp = MenuJogo();
					switch(opp){
					case 'A':
						LimpaTela(3,23,99,24);
						SelecionarTopos(tab,deck,ord);

						break;
					case 'B':
							if(cont==0){
								LimpaTela(3,23,99,24);
								desenhaCartaTOPO(93,3,deck);
								gotoxy(88,6);
								printf("Reserva: %d ",deck.TOPO+1);
								gotoxy(3,22);
								cont++;
							}
							else{
								LimpaTela(3,23,99,24);
								ProximaReserva(deck,auxdeck);
							}
							break;
					}
					LimpaTela(3,23,99,24);
					
				}while(opp!=27);
				
				break;
				
			case 'B':
				LimpaTela(3, 23, 99, 24);
				Creditos();

				getch();
				break;
				
			case 'C':
				LimpaTela(3, 23, 99, 24);
				Ordem();
				getch();
				break;
			
		}
	}while(op!=27);
}
