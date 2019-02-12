#include <stdio.h>

int checklowerVowel(char n){
	switch(n){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': return 1;
	}
	return 0;
}

int str_del_lowervowels(char *s){
	char *res;
	int amount = 0;
	res = s;
	while(*s){
		if(!checklowerVowel(*res)){
			*s++=*res++;
		}else{
			amount+=1;
			res++;
		}
	}
	return amount;
}




int main(int argc, char **argv){
	char words[200] = "heute ist ein schoener tag";
	printf("%d\n",str_del_lowervowels(words));
	printf("%s\n",words);
	return 0;
}
