#include<stdio.h>

//prototipos das funcoes
void exibirTabuleiro();
int posicionarBarco(int posicaoArtefato, int lin, int col);
int posicionarSubmarino(int posicaoArtefato, int lin, int col);
int posicionarNavio(int posicaoArtefato, int lin, int col);
int posicionarPortaAviao(int posicaoArtefato, int lin, int col);
int lancarMissel();
int verificarAfundou(int artefato);
void exibirPosicao();
void iniciarTabuleiroJogador();
void exibirTabuleiroJogador();
void linha();

//variaveis globais
int tabuleiro[10][10];
int posicao[3][2];
int tabuleiroJogador[10][10];
int cont = 0;
int artefatosAfundados[4];

main() {
	printf("-----INICIANDO BATALHA NAVAL-----\n\n");
	printf("        Item        Qtd Pecas    \n");
	printf("     ------------------------    \n");
	printf("        Barco           2        \n");
	printf("        Navio           6        \n");
	printf("      Porta Aviao       5        \n");
	printf("       Submarino        4        \n\n");
	
	
		
	int artefato, posicao, lin, col;
	for(int i = 0; i<=3; i++) {
	
		printf("Qual artefato deseja adicionar: "); scanf("%i", &artefato);
		printf("Qual posicao voce quer que ele fique: "); scanf("%i", &posicao);
		printf("Em qual linha deseja adicionar o artefato: "); scanf("%i", &lin);
		printf("Em qual colouna deseja posicionar o artefato: "); scanf("%i", &col);
		
		switch(artefato){
			case 1:
				posicionarBarco(posicao, lin, col);
				break;
			case 2:
				posicionarSubmarino(posicao, lin, col);
				break;
			case 3:
				posicionarNavio(posicao, lin, col);
				break;
			case 4:
				posicionarPortaAviao(posicao, lin, col);
				break;
		}
	}
	iniciarTabuleiroJogador();
	exibirTabuleiroJogador();
	int resp;
	linha();
	while (true) {
		resp = lancarMissel();
		cont++;
		linha();
		exibirTabuleiroJogador();

		if(artefatosAfundados[0] != 1) {
			verificarAfundou(1);
		}
		if(artefatosAfundados[1] != 2) {
			verificarAfundou(2);
		}
		if(artefatosAfundados[2] != 3) {
			verificarAfundou(3);
		}
		if(artefatosAfundados[3] != 4) {
			verificarAfundou(4);
		}
		linha();
		for(int i = 0; i <= 3; i++) {
			if(artefatosAfundados[i] != 0) {
				if(i == 0) {
					printf("Barco Afundado!\n");
				}
				if(i == 1) {
					printf("Submarino Afundado!\n");
				}
				if(i == 2) {
					printf("Navio Afundado!\n");
				}
				if(i == 3) {
					printf("Porta Aviao Afundado!\n");
				}
			}
		}
		printf("\n\n");
		if(artefatosAfundados[0] == 1 && artefatosAfundados[1] == 2 && artefatosAfundados[2] == 3 && artefatosAfundados[3] == 4) {
			printf("PARABENS! Voce ganhou!\n");
			printf("Voce usou %i Misseis", cont);
			break;
		}
	}
	linha();
	
}
void linha() {
	printf("\n");
}
void iniciarTabuleiroJogador() {

	for(int lin = 0; lin <= 9; lin++) {
		for(int col = 0; col <= 9; col++) {
			tabuleiroJogador[lin][col] = 45;
		}
	}
}

void exibirTabuleiroJogador() {
	printf("    ");
	for(int c = 0; c <= 9; c++) {
		printf(" %i ", c);
	}
	printf("\n");
	printf("   ------------------------------");
	printf("\n");
	for(int lin = 0; lin <= 9; lin++) {
		printf(" %i |", lin);
		for(int col = 0; col <= 9; col++) {
			if(tabuleiroJogador[lin][col] == 45) {
				printf(" %c ", tabuleiroJogador[lin][col]);
			} else {
				printf(" %i ", tabuleiroJogador[lin][col]);
			}
		}
		printf("\n");
	}
}

void exibirTabuleiro() {
	printf("   ");
	for(int cont = 0; cont <= 9; cont++) {
		printf(" %d ", cont);
	}
	printf("\n");
	printf("  ------------------------------");
	printf("\n");
	for(int lin = 0; lin <= 9; lin++) {
		printf("%d |", lin);
		for(int col = 0; col <= 9; col++) {
			printf(" %d ", tabuleiro[lin][col]);
		}
		printf("\n");
	}
}

int posicionarBarco(int posicaoArtefato, int lin, int col) {
	int aux;
	aux=1;
	posicao[aux][0]=lin;
	posicao[aux][1]=col;
	switch(posicaoArtefato) {
		case 1: //posicionando artefato a direita
			if (col <= 8 && col >= 0 && lin >= 0 && lin <= 9) {
				tabuleiro[lin][col]=1;
				tabuleiro[lin][col+1]=1;
				return 1;
			}
			else {
				return 0;
			}
			break;
		case 2: //posicionando artefato a esquerda
			if(col <= 9 && col >= 1 && lin <= 9 && lin >= 0) {
				tabuleiro[lin][col]=1;
				tabuleiro[lin][col-1]=1;
				return 1;
			}
			else {
				return 0;
			}
		case 3: //posicionando artefato para baixo
			if(col <= 9 && col >= 0 && lin <= 9 && lin >= 1) {
				tabuleiro[lin][col]=1;
				tabuleiro[lin+1][col]=1;
				return 1;
			}
			else {
				return 0;
			}
		case 4: //posicionando artefato para cima
			if(col <= 9 && col >= 0 && lin <= 8 && lin >= 0) {
				tabuleiro[lin][col]=1;
				tabuleiro[lin-1][col]=1;
				return 1;
			}
			else {
				return 0;
			}
	}
}

int posicionarSubmarino(int posicaoArtefato, int lin, int col) {
	int aux;
	aux=2;
	posicao[aux][0]=lin;
	posicao[aux][1]=col;
	switch(posicaoArtefato) {
		case 1: //posicionando artefato para direita
			if(col <= 7 && col >= 0 && lin <= 8 && lin >= 1) {
				tabuleiro[lin][col]=2;
				tabuleiro[lin-1][col]=2;
				tabuleiro[lin][col+1]=2;
				tabuleiro[lin][col+2]=2;
				return 1;
			}
			else {
				return 0;
			}
			break;
		case 2: //posicionando artefato a esquerda
			if(col >= 2 && col <= 9 && lin >= 1 && lin <= 9) {
				tabuleiro[lin][col]=2;
				tabuleiro[lin+1][col]=2;
				tabuleiro[lin][col-1]=2;
				tabuleiro[lin][col-2]=2;
				return 1;
			}
			else {
				return 0;
			}
			break;
		case 3: //posicionando artefato para baixo
			if(col >= 0 && col <= 8 && lin >= 0 && lin <= 7) {
				tabuleiro[lin][col]=2;
				tabuleiro[lin][col+1]=2;
				tabuleiro[lin+1][col]=2;
				tabuleiro[lin+2][col]=2;
				return 1;
			}
			else {
				return 0;
			}
			break;
		case 4: //posicionando artefato para cima
			if(col >= 1 && col <= 9 && lin >= 2 && lin <= 9) {
				tabuleiro[lin][col]=2;
				tabuleiro[lin][col-1]=2;
				tabuleiro[lin-1][col]=2;
				tabuleiro[lin-2][col]=2;
				return 1; 
			}
			else {
				return 0;
			}
			break;
	}
}

int posicionarNavio(int posicaoArtefato, int lin, int col) {
	int aux;
	aux=3;
	posicao[aux][0]=lin;
	posicao[aux][1]=col;
	switch(posicaoArtefato) {
		case 1: //posicionando navio a direita
			if(col <= 6 && col >= 0 && lin >= 1 && lin <= 9) {
				tabuleiro[lin][col]=3;
				tabuleiro[lin][col+1]=3;
				tabuleiro[lin-1][col+1]=3;
				tabuleiro[lin][col+2]=3;
				tabuleiro[lin-1][col+2]=3;
				tabuleiro[lin][col+3]=3;
				return 1;
			}
			else {
				return 0;
			}
			break;
		case 2: //posicionando artefato a esquerda
			if(col >= 3 && col <= 9 && lin >= 1 && lin <= 9 ) {
				tabuleiro[lin][col]=3;
				tabuleiro[lin][col-1]=3;
				tabuleiro[lin+1][col-1]=3;
				tabuleiro[lin][col-2]=3;
				tabuleiro[lin+1][col-2]=3;
				tabuleiro[lin][col-3]=3;
				return 1;
			}
			else {
				return 0;
			}
			break;
		case 3: //posicionando artefato para baixo
			if(col >= 0 && col <= 8 && lin >= 0 && lin <= 6 ) {
				tabuleiro[lin][col]=3;
				tabuleiro[lin+1][col]=3;
				tabuleiro[lin+1][col+1]=3;
				tabuleiro[lin+2][col]=3;
				tabuleiro[lin+2][col+1]=3;
				tabuleiro[lin+3][col]=3;
				return 1;
			}
			else {
				return 0;
			}
			break;
		case 4: //posicionando artefato para cima
			if(col > 0 && col <= 9 && lin >= 3 && lin <= 9) {
				tabuleiro[lin][col]=3;
				tabuleiro[lin-1][col]=3;
				tabuleiro[lin-1][col-1]=3;
				tabuleiro[lin-2][col]=3;
				tabuleiro[lin-2][col-1]=3;
				tabuleiro[lin-3][col]=3;
				return 1;
			}
			else {
				return 0;
			}
			break;
	}
}

int posicionarPortaAviao(int posicaoArtefato, int lin, int col) {
	int aux;
	aux=4;
	posicao[aux][0]=lin;
	posicao[aux][1]=col;
	switch(posicaoArtefato) {
		case 1: //posicionando artefato a direita
			if(col >= 0 && col <= 5 && lin >= 0 && lin <= 9) {
				tabuleiro[lin][col]=4;
				tabuleiro[lin][col+1]=4;
				tabuleiro[lin][col+2]=4;
				tabuleiro[lin][col+3]=4;
				tabuleiro[lin][col+4]=4;
				return 1;
			}
			else {
				return 0;
			}
			break;
		case 2: // posisionando artefato a esquerda
			if(col >= 4 && col <= 9 && lin >= 0 && lin <= 9) {
				tabuleiro[lin][col]=4;
				tabuleiro[lin][col-1]=4;
				tabuleiro[lin][col-2]=4;
				tabuleiro[lin][col-3]=4;
				tabuleiro[lin][col-4]=4;
				return 1;
			}
			else {
				return 0;
			}
			break;
		case 3: // posicionando artefato para baixo
			if(col >= 0 && col <= 9 && lin >= 0 && lin <= 5) {
				tabuleiro[lin][col]=4;
				tabuleiro[lin+1][col]=4;
				tabuleiro[lin+2][col]=4;
				tabuleiro[lin+3][col]=4;
				tabuleiro[lin+4][col]=4;
				return 1;
			}
			else {
				return 0;
			}
			break;
		case 4: // posicionando artefato para cima
			if(col >= 0 && col <= 9 && lin >= 4 && lin <= 9) {
				tabuleiro[lin][col]=4;
				tabuleiro[lin-1][col]=4;
				tabuleiro[lin-2][col]=4;
				tabuleiro[lin-3][col]=4;
				tabuleiro[lin-4][col]=4;
				return 1;
			}
			else {
				return 0;
			}
			break;
	}
}

int lancarMissel() {
	int lin, col;
	while(true) {
		printf("Linha: ");
		scanf("%i", &lin);
		if(lin > 9) {
			printf("Escolha uma linha entre 0 e 9! Tente novamente!\n");
		} else {
			break;
		}
	}
	while(true) {
		printf("Coluna: ");
		scanf("%i", &col);
		if(col > 9) {
			printf("Escolha uma coluna entre 0 e 9! Tente novamente!\n");
		} else {
			break;
		}
	}
	if(tabuleiro[lin][col] != 0) {
		tabuleiroJogador[lin][col] = 9;
	} else {
		tabuleiroJogador[lin][col] = 0;
	}
}

int verificarAfundou(int artefato) {
	switch(artefato) {
		case 1 :
			if(tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1]] == 9 && tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1]+1] == 9) {
				artefatosAfundados[0] = 1;
				return 1;
			} else {
				return 0;
			}
			break;
		case 2:
			if(tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1]] == 9 &&  tabuleiroJogador[posicao[artefato][0]-1][posicao[artefato][1]] == 9 &&
			        tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1]+1] == 9 && tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1]+2] == 9) {
				artefatosAfundados[1] = 2;
				return 1;
			} else {
				return 0;
			}
			break;
		case 3:
			if(tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1]] == 9 && tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1] + 1] == 9 &&
			        tabuleiroJogador[posicao[artefato][0] - 1][posicao[artefato][1] + 1] == 9 && tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1] + 2] == 9 &&
			        tabuleiroJogador[posicao[artefato][0] - 1][posicao[artefato][1] + 2] == 9 && tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1] + 3] ==  9) {
				artefatosAfundados[2] = 3;
				return 1;
			} else {
				return 0;
			}
			break;
		case 4:
			if(tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1]] == 9 && tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1] + 1] == 9 &&
			        tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1] + 2] == 9 && tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1] + 3] == 9 &&
			        tabuleiroJogador[posicao[artefato][0]][posicao[artefato][1] + 4] == 9) {
				artefatosAfundados[3] = 4;
				return 1;
			} else {
				return 0;
			}
			break;
	}
}

void exibirPosicao() {
	for(int lin=0; lin<=4; lin++) {
		for(int col=0; col<=1; col++) {
			printf(" %i", posicao[lin][col]);
		}
		printf("\n");
	}
	printf("\n\n");
}


