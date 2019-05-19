#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//Declaração de Funções
int pMatriz(int aux[5][5]);
int verificar(int aux[5][5]);

int main() {
	setlocale(LC_ALL, "Portuguese");
	int Matriz[5][5];
	int nJogos, i, k, j, result;
	
	printf("Digite os numeros de jogos: ");
	scanf("%i", &nJogos);
	
	//For para numero de jogos	
	for(i=1; i <= nJogos; i++){
		printf("O numero de jogos é %i , jogo atual é %i\n\n", nJogos, i);
		// K = linhas , J = colunas
		for(k=0; k<5; k++){
			for(j=0; j<5; j++){
				printf("[Célula %i,%i]Digite 0 ou 1: ",k,j);
				scanf("%i", &Matriz[k][j]);	
			}
			
		}
		printf("\nA matriz digitada é: \n");
		pMatriz(Matriz);
		result = verificar(Matriz);

	}
	return 0;
}

//Função para printar a matriz
int pMatriz(int aux[5][5]){
	int k, j;
	
		for(k=0; k<5; k++){
			for(j=0; j<5; j++){
				printf("%i", aux[k][j]);
				if(j==4){
					printf("\n");
				}
				else{
					printf(" ");
				}	
			}
		}
}

//Função retorna 1 se os ROBBERS ganharam, retorna 0 se os COPS ganharam.
int verificar(int aux[5][5]){
	int i, j, k;
	k=0;
	j=0;
	//K - linha , J - coluna
	//Verifica se a primeira celula está fechada
	if(aux[k][j]==1){
		printf("\nROBBERS\n\n");
		return 1;
	}
	else{
		//Laço para percorrer a matriz
		for(i=0; i<=8; i++){
			//Verifica se os  COPs chegaram ao final da matriz
			if(k==4 && j==4){
				printf("\nCOPS\n\n");
				return 0;
			}
			else{
				//Verifica se o maximo de linhas ja foi alcançado
				if(k == 4){
					j++;
						//Caso a proxima coluna for igual a 1 COPs vencem
						if(aux[k][j]==1){
							printf("\nROBBERS\n\n");
							return 1;
						}
						//Caso contrario Continua a execursão
						else{
							continue;
						}
				}
				else{	
				
				k++;
					//Caso a proxima verificação de linha aponte 1 ele retorna uma linha para verificar a proxima coluna
					if(aux[k][j]==1){
						k--;
						j++;
						if(aux[k][j]==1){
							printf("\nROBBERS\n\n");
							return 1;
						}
						else{
							continue;
						}
					}
					else{
						continue;
					}
				}
			}
		}
	}
}
