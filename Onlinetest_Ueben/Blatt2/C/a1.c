#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void schwabify(char *input, char output[]){
	int i = 0;
	char swap[2] = {'\0','\0'};
	while(*input){
		if(*input == '.'){
			strcat(output, ", woisch?");
			i+=strlen(", woisch?");
			input++;
			continue;
		}
		if(strncmp(input,"halt",strlen("halt")) == 0){
			strcat(output, "heb");
			i+=strlen("heb");
			input+=strlen("halt");
			continue;
		}
		if(strncmp(input,"ist",strlen("ist")) == 0){
			strcat(output, "isch");
			i+=strlen("isch");
			input+=strlen("ist");
			continue;
		}
		else{
			swap[0] = *input;
			strcat(output,swap);
		}
		input++;
	}
	printf("%s\n",output);
}


int main(int argc, char **argv){
	char *output;
	output = malloc(sizeof(char)*(100*5));
	schwabify("Das ist interessant.",output);
	schwabify("Mit		diesem Kleber	sollte es halten, oder?", output);
	schwabify("haltisthalt. isthaltist . . .", output);
	free(output);
	return 0;
}
