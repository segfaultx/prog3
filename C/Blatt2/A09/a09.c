#include <stdio.h>

enum{MAX_SQUARE_SIZE = 9};

void printsquare(int vec[MAX_SQUARE_SIZE][MAX_SQUARE_SIZE], int size){
	int i, j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("%3d", vec[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int magicSquare[MAX_SQUARE_SIZE][MAX_SQUARE_SIZE]={{0}}, usrinput;
	printf("Groeße fuer das tolle Ettikett eingeben: \n");
	scanf("%d",&usrinput);
	if((usrinput<=9)&& (usrinput%2)!=0){
		printsquare(magicSquare, usrinput);	
	}
	else{
		printf("Ungueltige Eingabe\n");
		return 1;
	}	
	return 0;

}
