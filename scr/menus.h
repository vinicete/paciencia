char Menu();
char MenuJogo();
void LimpaTela(int CI, int LI, int CF, int LF);
void Creditos();
void explicarRegras();
void Loading(int tempo_de_espera);
void inicio();

void Loading(int tempo_de_espera){
	clrscr();
	gotoxy(45,10);
	printf("LOADING");
	gotoxy(37,11);
	printf("[                     ]");
	gotoxy(38,11);
	for(int i=0;i<20;i++){
		printf("=");
		Sleep(tempo_de_espera);
	}
}

void inicio(){
	clrscr();
	gotoxy(38,10);
	printf("BEM VINDO AO JOGO PACIENCIA");
	gotoxy(35,12);
	printf("Pressione qualquer tecla para jogar");
	getch();
	Loading(50);
	explicarRegras();
}

char Menu(){
	LimpaTela(3,23,99,24);
	int op;
	gotoxy(3,23);
	printf("[A] - INICIAR\t[B] - CREDITOS\t[C] - REGRAS");
	op = toupper(getch());
	
}

char MenuJogo(){
	int op;
	gotoxy(3,23);
	printf("[A] - MOVER\t[B] - BARALHO");
	
	op = toupper(getch());
}

char MenuTopoSequencia(){
	int op;
	gotoxy(3,23);
	printf("[A] - TOPO\t[B] - SEQUENCIA");
	
	op = toupper(getch());
}

void LimpaTela(int CI, int LI, int CF, int LF){
	
	int i=0,j=0;
	
	for(i=CI;i<CF;i++){
		for (j=LI;j<LF;j++){
			gotoxy(i,j);
			printf(" ");
		}
	}
}

void Creditos(){
	gotoxy(3,23);
	printf("1 - CAIO COLLETE SILVA\t2 - JOAO RICARDO LESCOVAR\t3 - VINICIUS ARAUJO MESSIAS");
}

void Ordem(){
	gotoxy(3,23);
    printf("\tOrdem das cartas:\t");
    printf("K-Rei, Q-Dama, J-Valete, 10,9,8,7,6,5,4,3,2, A(As)");
}

void explicarRegras() {
	system("cls");
	gotoxy(1,1);
    printf("Bem-vindo ao jogo de Paciencia!");
    gotoxy(1,3);
    printf("Objetivo do jogo:");
    gotoxy(1,4);
    printf("O objetivo do jogo e mover todas as cartas para as pilhas de fundacao, organizando-as em ordem crescente de naipes.");
    gotoxy(1,6);
    printf("Como jogar:");
    gotoxy(1,7);
    printf("1. O tabuleiro e composto por sete pilhas de cartas, com a carta do topo de cada pilha virada para cima.");
    gotoxy(1,8);
    printf("2. As pilhas de fundação, localizadas no topo da tela, são inicialmente vazias.");
    gotoxy(1,9);
    printf("3. O jogador pode mover cartas entre as pilhas do tabuleiro e para as pilhas de fundação de acordo com as seguintes");
    gotoxy(1,10);
    printf("regras:");
    gotoxy(1,11);
    printf("   a. Cartas podem ser movidas para as pilhas de fundação se forem do mesmo naipe e tiverem uma posição de rank maior do");
    gotoxy(1,12);
    printf("que a carta no topo da pilha de fundação correspondente.");
    gotoxy(1,13);
    printf("   b. Cartas podem ser movidas entre as pilhas do tabuleiro se forem de cores diferentes e a carta a ser movida for de");
    gotoxy(1,14);
    printf("rank menor do que a carta no topo da pilha de destino e uma quantidade específica de cartas é selecionada.");
    gotoxy(1,15);
    printf("   c. Cartas podem ser movidas do estoque (reserva) para as pilhas do tabuleiro ou pilhas de fundação, seguindo as");
    gotoxy(1,16);
    printf("regras acima.");
    gotoxy(1,17);
    printf("4. O jogador pode clicar no estoque para revelar uma nova carta, que pode ser movida conforme as regras acima.");
    gotoxy(1,18);
    printf("5. O jogo termina quando todas as cartas forem movidas para as pilhas de fundação, indicando uma vitoria, ");
    gotoxy(1,19);
    printf("ou quando não houver mais movimentos possíveis, indicando uma derrota.");
    gotoxy(1,21);
    printf("Pressione qualquer tecla para começar o jogo...");
    gotoxy(1,22);
   // printf("   b. Cartas podem ser movidas entre as pilhas do tabuleiro se forem de cores diferentes e a carta a ser movida for de rank menor do que a carta no topo da pilha de destino e uma quantidade específica de cartas é selecionada.");
    getch();
    LimpaTela(1,1,100,25);
    LimpaTela(1,1,100,25);
    
    //ARRUMAR ISSO NO FINAL, NAO PODE USAR \n COM GOTOXY
}
