#include <stdio.h>

enum{MAX_SQUARE_SIZE = 9};

void printsquare(int vec[MAX_SQUARE_SIZE][MAX_SQUARE_SIZE]){
	int i, j;
	for(i=0;i<MAX_SQUARE_SIZE;i++){
		for(j=0;j<MAX_SQUARE_SIZE;j++){
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
		printsquare(magicSquare);	
	}
	else{
		printf("Ungueltige Eingabe\n");
		return 1;
	}	
	return 0;

}
