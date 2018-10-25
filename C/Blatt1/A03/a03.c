#include <stdio.h>

int main(void){
	int userinput, i;
	printf("Bitte zahl Eingeben:\n");
	scanf("%d", &userinput);
	printf("Die Zahl in Römisch:");
	for(i=0; i<(userinput/100);i++){
		printf("C");
	}
	userinput= userinput%100;

	for(i=0; i<(userinput/50);i++){
		printf("L");
	}
	userinput = userinput % 50;

	for(i=0; i<(userinput/10);i++){
		printf("X");
	}
	userinput = userinput % 10;
	for(i=0; i<(userinput/5);i++){
		printf("V");
	}
	userinput = userinput % 5;
	for(i=0; i<(userinput/1);i++){
		printf("I");
	}

	printf("\n");


	return 0;
}
