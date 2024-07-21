void SelecionarTopos(struct deck tab[],struct deck &deck, struct deck ord[]);
void ProximaReserva(struct deck &bar,struct deck &auxdeck);
void embaralhar(deck &deck);
void distribuirCartas(struct deck &deck,struct deck tab[]);
void inicializaPilhas(deck tab[],deck ord[]);
void inicializarBaralho(deck &deck);
void startFunctionGame();
void conferePraCima(deck tab[]);
void Sequencia(deck tab[],int op1,int op2);

void Sequencia(deck tab[],int op1,int op2){
	deck aux;
	inicializar(aux);
	
	int i=tab[op1].TOPO;
	while(tab[op1].cartas[i].pracima==1) // PARA ACHAR A POSICAO QUE DEVE CONFERIR SE PODE FAZER A MUDANCA
		i--;
		
	if(PilhaVazia(tab[op2].TOPO)){
		if(tab[op1].cartas[i+1].rank == 12){
			for(int j=tab[op1].TOPO;j>i;j--){
				PUSH(aux,POP(tab[op1]));
			}
			while(!PilhaVazia(aux.TOPO)){
				PUSH(tab[op2],POP(aux));
			}
			
		}
		else{
			gotoxy(3,23); 
			printf("Essa mudanca nao pode ser feita");
			getch(); 
		}
	}
	else if(tab[op1].cartas[i+1].rank==tab[op2].cartas[tab[op2].TOPO].rank-1 && tab[op1].cartas[i+1].cor != tab[op2].cartas[tab[op2].TOPO].cor){ 
		for(int j=tab[op1].TOPO;j>i;j--){
			PUSH(aux,POP(tab[op1]));
		}
		while(!PilhaVazia(aux.TOPO)){
			PUSH(tab[op2],POP(aux));
		}
	}
	else{
		gotoxy(3,23); 
		printf("Essa mudanca nao pode ser feita"); 
		getch(); 
	} 
	
}

void startFunctionGame(struct deck tab[],struct deck &deck, struct deck ord[], struct deck &auxdeck){
	inicializaPilhas(tab,ord);
	inicializarBaralho(deck);
	inicializar(auxdeck);
	embaralhar(deck);
	distribuirCartas(deck,tab);
}

void inicializarBaralho(deck &deck){
	//INICIALIZA BARALHO, COLOCA AS 52 CARTAS NO BARALHO
	int i=0,n,r;
	
	for(n=0;n<NUM_NAIPES;n++){
		for(r=0;r<NUM_RANKS;r++){
			deck.cartas[i].rank=r;
			deck.cartas[i].naipe=n;
			// declaracao de cor
			if(n<2) deck.cartas[i].cor = 0; 
			else deck.cartas[i].cor = 1;
			i++;
			
			deck.cartas[i].pracima = 0;
		}
	}
	deck.TOPO = NUM_CARDS-1;
}

void inicializaPilhas(deck tab[],deck ord[]){
	int i;
	for(i=0;i<NUM_TABULEIRO;i++){
  	  inicializar(tab[i]);
	}
    
    for(i=0;i<NUM_ORDEM;i++){
    	inicializar(ord[i]);
    }
}

void embaralhar(deck &deck){
	// EMBARALHA DE FORMA ALEATORIO O BARALHO
	carta temp;
	int j;
	
	srand(time(0));
	for(int i=0;i<NUM_CARDS;i++){
		j = rand() % NUM_CARDS;
		temp = deck.cartas[i];
		deck.cartas[i] = deck.cartas[j];
		deck.cartas[j] = temp;
	}
}

void distribuirCartas(struct deck &deck,struct deck tab[]) {
	// DISTRIBUI AS CARTAS NAS 7 PILHAS DO TABULEIRO
    int i = 0;
    for (int t = 0; t < NUM_TABULEIRO; t++) {
        for (int j = 0; j <= t; j++) {
        	//if(j==t){
        //	}
            PUSH(tab[t],POP(deck));
        }
    }
}

void ProximaReserva(struct deck &bar,struct deck &auxdeck){
	

	
	if(!PilhaVazia(bar.TOPO)){
		PUSH(auxdeck,POP(bar));
	}
	
	if(PilhaVazia(bar.TOPO)){
		while(!PilhaVazia(auxdeck.TOPO)){
			PUSH(bar,POP(auxdeck));
		}
		//desenhaVirada(93,3);
	}
	
	desenhaCartaTOPO(93,3,bar);
	gotoxy(88,6);
	printf("Reserva: %d ",bar.TOPO+1);
	// verifica onde usuario quer alocar a carta e etc....
}

void conferePraCima(deck tab[]){
	
	
	for(int i=0; i<NUM_TABULEIRO; i++){
		tab[i].cartas[tab[i].TOPO].pracima = 1;
	}
}
void SelecionarTopos(struct deck tab[],struct deck &deck, struct deck ord[]){
	
	int op1,op2,opcao;
	carta card,card2;
	gotoxy(3,23);
	printf(" - SELECIONE O BARALHO p/ Retirar: ");
	scanf("%d",&op1);
	
	

	while(op1!=99){
		
		if(op1<7 || op1==12){
			LimpaTela(3,23,99,24);
			gotoxy(3,23);
			printf("BARALHO p/ RECEBER: ");
			scanf("%d",&op2);
			LimpaTela(3,23,99,24);
			gotoxy(3,23);
			if(op1==12){ // se a OP1 for BARALHO(estoque)
				if(op2<7){ // se o destino for o tabuleiro
					if(PilhaVazia(tab[op2].TOPO)){
						if(deck.cartas[deck.TOPO].rank == 12)
							PUSH(tab[op2],POP(deck));
						else{
							gotoxy(3,23); 
							printf("Essa mudanca nao pode ser feita");
							getch(); 
						} 
					}
					else if(deck.cartas[deck.TOPO].rank==tab[op2].cartas[tab[op2].TOPO].rank-1 && deck.cartas[deck.TOPO].cor != tab[op2].cartas[tab[op2].TOPO].cor){
						PUSH(tab[op2],POP(deck));
					}
				}
				if(op2>7){ // se o destino for para algum dos A`s (fundacao)
					switch(op2){
						case 8:	// espada
							if(PilhaVazia(ord[0].TOPO) && deck.cartas[deck.TOPO].naipe == 0){
								PUSH(ord[0],POP(deck)); 
							} 
							if(ord[0].cartas[ord[0].TOPO].rank+1==deck.cartas[deck.TOPO].rank && deck.cartas[deck.TOPO].naipe == 0){
								PUSH(ord[0],POP(deck)); 
							}
							
							break;
							
						case 9: // paus
							if(PilhaVazia(ord[1].TOPO) && deck.cartas[deck.TOPO].naipe == 1){
								PUSH(ord[1],POP(deck)); 
							}
							if(ord[1].cartas[ord[1].TOPO].rank+1==deck.cartas[deck.TOPO].rank && deck.cartas[deck.TOPO].naipe == 1){
								PUSH(ord[1],POP(deck)); 
							}
							break;
							
						case 10: // copas
							if(PilhaVazia(ord[2].TOPO)&& deck.cartas[deck.TOPO].naipe == 2){
								PUSH(ord[2],POP(deck));
							} 
							if(ord[2].cartas[ord[2].TOPO].rank+1==deck.cartas[deck.TOPO].rank || PilhaVazia(ord[2].TOPO)&& deck.cartas[deck.TOPO].naipe == 2){
								PUSH(ord[2],POP(deck));
							} 
							
							break;
							
						case 11: // ouros
							if(PilhaVazia(ord[3].TOPO)&& deck.cartas[deck.TOPO].naipe == 3){
								PUSH(ord[3],POP(deck));
							} 
							if(ord[3].cartas[ord[3].TOPO].rank+1==deck.cartas[deck.TOPO].rank && deck.cartas[deck.TOPO].naipe == 3){
								PUSH(ord[3],POP(deck));
							} 
							break;
							
						default: 
							gotoxy(3,23); 
							printf("Entrada invalida"); 
							getch(); 
					}
				}
			}
			else{// se nao for igual a 12, estamos falando de tab para tab ou para A`s
			
				opcao = MenuTopoSequencia();// pra selecionar se vai ser apenas a carta do topo ou uma sequencia de cartas
				switch(opcao){
					
					case 'A':
						if(op2>7){ // se a OP2 for para algum dos A`s
						
							switch(op2){ 
								case 8:
									if(tab[op1].cartas[tab[op1].TOPO].naipe == 0){
										if(PilhaVazia(ord[0].TOPO)){
											if(tab[op1].cartas[tab[op1].TOPO].rank == 0)
												PUSH(ord[0],POP(tab[op1]));
											else{
												gotoxy(3,23); 
												printf("Essa mudanca nao pode ser feita"); 
												getch(); 
											} 
										}
										else if(ord[0].cartas[ord[0].TOPO].rank+1==tab[op1].cartas[tab[op1].TOPO].rank) 
											PUSH(ord[0],POP(tab[op1]));
										else{
											gotoxy(3,23); 
											printf("Essa mudanca nao pode ser feita"); 
											getch(); 
										}  break;
									}
									
								case 9:	
									if(tab[op1].cartas[tab[op1].TOPO].naipe == 1){
										if(PilhaVazia(ord[1].TOPO)){
											if(tab[op1].cartas[tab[op1].TOPO].rank == 0)
												PUSH(ord[1],POP(tab[op1]));
											else{
												gotoxy(3,23); 
												printf("Essa mudanca nao pode ser feita"); 
												getch(); 
											} 
										}
										else if(ord[1].cartas[ord[1].TOPO].rank+1==tab[op1].cartas[tab[op1].TOPO].rank)
											PUSH(ord[1],POP(tab[op1]));
											else{
												gotoxy(3,23); 
												printf("Essa mudanca nao pode ser feita"); 
												getch(); 
											} 
											break;
									}
									
								case 10: 
									if(tab[op1].cartas[tab[op1].TOPO].naipe == 2){
										if(PilhaVazia(ord[2].TOPO)){
											if(tab[op1].cartas[tab[op1].TOPO].rank == 0)
												PUSH(ord[2],POP(tab[op1]));
											else{
												gotoxy(3,23); 
												printf("Essa mudanca nao pode ser feita");
												getch(); 
											} 
										}
										else if(ord[2].cartas[ord[2].TOPO].rank+1==tab[op1].cartas[tab[op1].TOPO].rank) 
											PUSH(ord[2],POP(tab[op1])); 
										else{
											gotoxy(3,23); 
											printf("Essa mudanca nao pode ser feita"); 
											getch(); 
										}
										break;
									}
									
								case 11: 
									if(tab[op1].cartas[tab[op1].TOPO].naipe == 3){
										if(PilhaVazia(ord[3].TOPO)){
											if(tab[op1].cartas[tab[op1].TOPO].rank == 0)
												PUSH(ord[3],POP(tab[op1]));
											else{
												gotoxy(3,23); 
												printf("Essa mudanca nao pode ser feita");
												getch(); 
											} 
										}
										else if(ord[3].cartas[ord[3].TOPO].rank+1==tab[op1].cartas[tab[op1].TOPO].rank) 
											PUSH(ord[3],POP(tab[op1]));
										else{
											gotoxy(3,23); 
											printf("Essa mudanca nao pode ser feita"); 
											getch(); 
										} break;
									}
									
								default: 
									gotoxy(3,23); 
									printf("Entrada invalida");
									getch(); 
							}
						}
						if(op2<7){ // se for de tabuleiro para tabuleiro
							
							if(PilhaVazia(tab[op2].TOPO)){
								if(tab[op1].cartas[tab[op1].TOPO].rank == 12)
									PUSH(tab[op2],POP(tab[op1]));
								else{
									gotoxy(3,23); 
									printf("Essa mudanca nao pode ser feita");
									getch(); 
								} 
							}
							else if(tab[op1].cartas[tab[op1].TOPO].rank==tab[op2].cartas[tab[op2].TOPO].rank-1 && tab[op1].cartas[tab[op1].TOPO].cor != tab[op2].cartas[tab[op2].TOPO].cor){ 
								PUSH(tab[op2],POP(tab[op1]));
							}
							else{
								gotoxy(3,23); 
								printf("Essa mudanca nao pode ser feita"); 
								getch(); 
							} 
						}
						break;
						
					case 'B': Sequencia(tab,op1,op2);// so vai de tab pra tab					
						break;
				}
				 
				
			}			
			
		}
		else{
			gotoxy(3,23);
			printf("Voce nao pode mexer no baralho de Fundacao");
		}
			
		conferePraCima(tab);
		desenhaTab(deck,tab,ord);
		
		LimpaTela(3,23,99,24);
		gotoxy(3,23);
		printf(" - SELECIONE O BARALHO p/ Retirar: (99 - sair) ");
		scanf("%d",&op1);
	}
}

