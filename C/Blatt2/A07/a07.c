#include <stdio.h>

void schreibbit(unsigned z){
	int i;
	for(i=15; i>=0; i--){
		printf("%d", (z & 1<<i) !=0);	
	}
	printf("\n");
}
unsigned liesbit(void){
	unsigned int usrinput, intrep=0;
	int i;
	scanf("%u", &usrinput);
	for(i=0;i<=15; i++){
		if((usrinput%10)!=0){
		intrep = intrep | 1<<i;
		}
		usrinput = usrinput/10;
	}
	return intrep;
}



int main(void){
	unsigned int input1, input2;
	printf("Bitte Zahl 1 eingeben:\n");
	input1 = liesbit();
	printf("Bitte Zahl 2 eingeben:\n");
	input2 = liesbit();
	printf("a & b: ");
	schreibbit(input1&input2);
	printf("a | b: ");
	schreibbit(input1|input2);
	printf("a ^ b: ");
	schreibbit(input1^input2);
	return 0;

}
