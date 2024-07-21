// se o cara escolher BARALHO, exibir a 89,2;

void Moldura(int CI, int LI, int CF, int LF);
void desenhaTab(struct deck bar,struct deck tab[],struct deck ord[]);
void exibeCarta(deck deck);
void desenhaCarta(int x, int y, deck bar);
void desenhaCarta2(int x, int y, deck bar);
void desenhaCartaTOPO(int x,int y,deck bar);
void desenhaVirada(int x, int y);


void Moldura(int CI, int LI, int CF, int LF)
{
	int i;
	gotoxy(CI, LI);
	printf("%c", 201);
	gotoxy(CI, LF);
	printf("%c", 200);
	gotoxy(CF, LI);
	printf("%c", 187);
	gotoxy(CF, LF);
	printf("%c", 188);
	for (i = CI + 1; i < CF; i++)
	{
		gotoxy(i, LI);
		printf("%c", 205);
		gotoxy(i, LF);
		printf("%c", 205);
	}
	for (i = LI + 1; i < LF; i++)
	{
		gotoxy(CI, i);
		printf("%c", 186);
		gotoxy(CF, i);
		printf("%c", 186);
	}
}


void desenhaTab(struct deck bar,struct deck tab[],struct deck ord[]){
	clrscr(); 
	Moldura(1, 1, 100, 25);
	Moldura(2, 22, 99, 24);
	
	// DESENHAS NAIPES
	gotoxy(3,2);
	printf("E-8");
	if(!PilhaVazia(ord[0].TOPO)) desenhaCartaTOPO(2,3,ord[0]);
	gotoxy(9,2);
	printf("P-9");
	if(!PilhaVazia(ord[1].TOPO))desenhaCartaTOPO(9,3,ord[1]);
	gotoxy(15,2);
	printf("C-10");
	if(!PilhaVazia(ord[2].TOPO))desenhaCartaTOPO(15,3,ord[2]);
	gotoxy(21,2);
	printf("O-11");
	if(!PilhaVazia(ord[3].TOPO))desenhaCartaTOPO(21,3,ord[3]);	
	
	//gotoxy(17,7);
	//if(!PilhaVazia(tab[6].TOPO)) desenhaCarta2(16,8,tab[6]);
	// DESENHA TABULEIRO
	gotoxy(25,7);
	printf("0");
	if(!PilhaVazia(tab[0].TOPO)) desenhaCarta2(24,8,tab[0]);
	
	gotoxy(33,7);
	printf("1");
	if(!PilhaVazia(tab[1].TOPO))desenhaCarta2(32,8,tab[1]);	
	
	gotoxy(41,7);
	printf("2");
	if(!PilhaVazia(tab[2].TOPO))desenhaCarta2(40,8,tab[2]);
	
	gotoxy(49,7);
	printf("3");
	if(!PilhaVazia(tab[3].TOPO))desenhaCarta2(48,8,tab[3]);
	
	gotoxy(57,7);
	printf("4");
	if(!PilhaVazia(tab[4].TOPO))desenhaCarta2(56,8,tab[4]);	
	
	gotoxy(65,7);
	printf("5");
	if(!PilhaVazia(tab[5].TOPO))desenhaCarta2(64,8,tab[5]);
	
	gotoxy(73,7);
	printf("6");
	if(!PilhaVazia(tab[6].TOPO))desenhaCarta2(72,8,tab[6]);
	
	// DESENHA DESCARTE
	gotoxy(94,2);
	printf("12");
	if(!PilhaVazia(bar.TOPO))desenhaVirada(93,3);
	else{ 
		gotoxy(94,4);
		printf("NULL");
	}
	
	
}

void exibeCarta(deck deck){
	 carta carta = ElementoTopo(deck);
	
	switch(carta.rank){
		case 0: printf("A");break;
		case 10: printf("J");break;
		case 11: printf("Q");break;
		case 12: printf("K");break;
		default: printf("%d",carta.rank+1);
	}

	switch(carta.naipe){
		case 0: textcolor(BLACK);printf("E");break; //espada
		case 1: textcolor(BLACK);printf("P");break; //paus
		case 2: textcolor(RED);printf("C");break; //copas
		case 3: textcolor(RED);printf("O");break; //ouro
	}
	textcolor(BLACK);
}

void desenhaVirada(int x, int y){
	
	textbackground(RED);
	textcolor(WHITE);
	gotoxy(x,y);
	printf("%c%c%c%c",218,196,196,191);
	y++;
	gotoxy(x,y);
	printf("|"); printf("  "); printf("|");
	y++;
	gotoxy(x,y);
	printf("%c%c%c%c",192,196,196,217);
	
	textbackground(BLACK);
	textcolor(WHITE);
	
}

void desenhaCarta(int x, int y, deck bar){
	carta carta = ElementoTopo(bar);
	
	int i;
	for(i=0;i<bar.TOPO;i++){
		textbackground(RED);
		textcolor(WHITE);
		gotoxy(x,y);
		printf("|...|");
		y++;
	}
	
	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(x,y);
	printf("%c%c%c%c%c",218,196,196,196,191);
	y++;
	gotoxy(x,y);
	printf("|"); exibeCarta(bar); if(carta.rank==9) printf("|"); else printf(" |");
	y++;
	gotoxy(x,y);
	printf("%c%c%c%c%c",192,196,196,196,217);
	
	textbackground(BLACK);
	textcolor(WHITE);
}

void desenhaCarta2(int x, int y, deck bar){
	carta carta = bar.cartas[bar.TOPO];
	
	int i;
	for(i=0;i<bar.TOPO;i++){
		carta = bar.cartas[i];
		
		if(carta.pracima == 0){
			textbackground(RED);
			textcolor(WHITE);
			gotoxy(x,y);
			printf("|...|");
			y++;
		}
		else if(carta.pracima == 1){
			textbackground(WHITE);
			textcolor(BLACK);
			gotoxy(x,y);
			//printf("|...|");
			printf("|"); 
			//exibeCarta(bar); // é uma parte do exibeCarta(bar)
			switch(carta.rank){
				case 0: printf("A");break;
				case 10: printf("J");break;
				case 11: printf("Q");break;
				case 12: printf("K");break;
				default: printf("%d",carta.rank+1);
			}
		
			switch(carta.naipe){
				case 0: textcolor(BLACK);printf("E");break; //espada
				case 1: textcolor(BLACK);printf("P");break; //paus
				case 2: textcolor(RED);printf("C");break; //copas
				case 3: textcolor(RED);printf("O");break; //ouro
			}
			if(carta.rank==9) 
				printf("|"); 
			else 
				printf(" |");
			y++;
		}
		
	}
	
	//bar.cartas[bar.TOPO].pracima = 1;
	carta = ElementoTopo(bar);
	
	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(x,y);
	printf("%c%c%c%c%c",218,196,196,196,191);
	y++;
	gotoxy(x,y);
	printf("|"); exibeCarta(bar); if(carta.rank==9) printf("|"); else printf(" |");
	y++;
	gotoxy(x,y);
	printf("%c%c%c%c%c",192,196,196,196,217);
	
	textbackground(BLACK);
	textcolor(WHITE);
}

void exibeCarta2(deck deck){
	 carta carta = ElementoTopo(deck);
	
	switch(carta.rank){
		case 0: printf("A");break;
		case 10: printf("J");break;
		case 11: printf("Q");break;
		case 12: printf("K");break;
		default: printf("%d",carta.rank+1);
	}

	switch(carta.naipe){
		case 0: textcolor(BLACK);printf("E");break; //espada
		case 1: textcolor(BLACK);printf("P");break; //paus
		case 2: textcolor(RED);printf("C");break; //copas
		case 3: textcolor(RED);printf("O");break; //ouro
	}
	textcolor(BLACK);
}

void desenhaCartaTOPO(int x,int y,deck bar){
	carta carta = ElementoTopo(bar);
	
	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(x,y);
	printf("%c%c%c%c%c",218,196,196,196,191);
	y++;
	gotoxy(x,y);
	printf("|"); exibeCarta(bar); if(carta.rank==9) printf("|"); else printf(" |");
	y++;
	gotoxy(x,y);
	printf("%c%c%c%c%c",192,196,196,196,217);
	
	textbackground(BLACK);
	textcolor(WHITE);
}
