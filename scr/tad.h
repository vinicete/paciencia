#define MAXPILHA 10
#define NUM_NAIPES 4
#define NUM_RANKS 13
#define NUM_CARDS 52 // MAXPILHA
#define NUM_ORDEM 4
#define NUM_TABULEIRO 7

struct carta{
	int rank;
	int naipe;
	int cor; // { 0 - preto / 1 - vermelho }
	int pracima;
};

struct deck{
	carta cartas[NUM_CARDS]; // pilha
	int TOPO; // topo
};


void inicializar(deck &Pilha){
	Pilha.TOPO=-1;
}

void PUSH(deck &Pilha, carta Elemento){
	Pilha.cartas[++Pilha.TOPO] = Elemento;
}

carta POP(deck &Pilha){
	return Pilha.cartas[Pilha.TOPO--];
}

carta ElementoTopo(deck Pilha){
	return Pilha.cartas[Pilha.TOPO];
}

int PilhaCheia(int topo){
	return topo==NUM_CARDS-1;
}

int PilhaVazia(int topo){
	return topo==-1;
}

void ExibirPilha(deck Pilha){
	
	while(!PilhaVazia(Pilha.TOPO)){
		printf("\n%c",POP(Pilha));
	}
	
}

