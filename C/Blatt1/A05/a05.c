#include <stdio.h>

int main(void){
	char input;
	while(scanf("%c", &input) != EOF){
		if(input <='Z' && input >='A'){
			printf("%c",(((input+13)-'A')%26)+'A');
		}else{
		 	if(input>='a' && input <='z'){
                        	printf("%c",(((input+13)-'a')%26)+'a');
			}
               		 else{
				printf("%c", input);
			}	
		}		
	}
	return 0;
}
