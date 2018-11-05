#include <stdio.h>
#include <string.h>

char alphabet[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char encryptionTable[]={'w','g','s','n','q','c','d','v','m','e','y','l','u','z','o','a','b','h','r','j','f','k','x','i','p','t'};


/*
 * Method to encrypt single letters;
 * Iterates over alphabet and replaces with encryption table character at same index
 */
char encrypt(char to_encrypt){
	int i;
	char * alphabetptr = alphabet;
	for(i=0; *alphabetptr++; i++){
		if(to_encrypt == alphabet[i]){
			return encryptionTable[i];
		}
	}
	return to_encrypt;
}

/**
 * Method to decrypt single letters;
 * Replaces encrypted letters with correct letters from alphabet
 */
char decrypt(char to_decrypt){
	int i;
	char *encryptionptr = encryptionTable;
	for(i = 0; *encryptionptr++; i++){
		if(to_decrypt == encryptionTable[i]){
			return alphabet[i];
		}
	}
	return to_decrypt;
}


int main(int argc, char *argv[]){
	int i;
	char usrinput[100];
	char *usrinputptr;
	/* If no arguments given return error
	 */
	if(argc <=1){
		return 1;
	}
	/* Check if userinput calls encrypt
	 */
	if(strcmp("encrypt",argv[1])==0){
		/* Read userinput and set pointer
		 */
		fgets(usrinput,100,stdin);
		usrinputptr=usrinput;
		/*Call encryption function for every letter in sentence
		 */
		for(i=0; *usrinputptr++; i++){
			printf("%c",encrypt(usrinput[i]));
		}
		printf("\n");
		return 0;
	}
	/* Check if userinput calls decrypt
	 */
	if(strcmp("decrypt",argv[1])==0){
		fgets(usrinput,100,stdin);
		usrinputptr=usrinput;
		for(i=0; *usrinputptr++;i++){
			printf("%c", decrypt(usrinput[i]));
		}
		printf("\n");
		return 0;
	}
	/* Default return
	 */
	return 0;
}
