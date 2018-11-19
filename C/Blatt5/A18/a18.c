#include <stdio.h>
#include <string.h>

#ifndef SIZE
	#define SIZE 10
#endif

void printstars(char *sentence){
	int i,j;
	/* ROWS */
	for(i=0; i<=((2* SIZE) + 1); i++){
		/* LINES */
		for(j=0;j<((2*SIZE)+strlen(sentence));j++){
			if(i==0|| i==(2*SIZE-1)){
				printf("*");
			}else{
				if(j==0) printf("*");
				if(j==((2*SIZE))+strlen(sentence)-1) printf("*\n");
				if(i==SIZE){
					printf("%*s%s",SIZE,"",sentence);
					break;
				}
				else{
					printf(" ");
				}
			}

		}	
	}
}

int main(void){
	#ifdef  DE
		printstars("Ohne Hörgerät höre ich nichts\n");
	#endif
	#ifdef NL
		printf("Zonder gehoorapparaat hoor ik niets\n");
	#endif
	#ifdef FI
		printf("Ilman kuuloleitta en kuula mittään\n");
	#endif
	#ifdef SE
		printf("Jag hör ingenting utan hörselapparat\n");
	#endif
	#ifdef IT
		printf("Senza l'apparecchio d'autito non sento niente\n");
	#endif
	#ifdef CN
		printf("mei zhu ting qi jiu tingbujian\n");
	#endif	
	return 0;
}
