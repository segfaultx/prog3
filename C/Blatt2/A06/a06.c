#include <stdio.h>

int main(void){
	double input, rest,new;
	printf("Bitte Zahl eingeben:\n");
	scanf("%lg",&input);
	rest = (1+input)/2;
	do{
		new = (rest+(input/rest))/2;

		if((rest-new)<1e-7){
			printf("Wurzel: %-10.2f\n",new);
			break;
		}else{
			rest= new;
		}
	}while(1);
	return 0;
}
