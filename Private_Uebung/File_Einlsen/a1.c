#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *f;
	char satz[100];
	f = fopen("saetze.txt","r");
	while(fgets(satz,100,f) != NULL){
		printf("%s\n",satz);
	}
	fclose(f);
	return 0;
}
