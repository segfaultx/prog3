#include <stdio.h>


int str_del_lowervowels(char *s){
	char *lowerVowels ="aeiou";
	char *v;
	char *res, *cpyhlpr;
	int amount = 0;
	res = s;
	while(*s){
		v = lowerVowels;
		while(*v){
			if(*s == *v){
				res++;
				cpyhlpr = s;
				amount+=1;
				do{
					*cpyhlpr++=*res++;
				}while(*res);
				*cpyhlpr='\0';
				res = s;
				v = lowerVowels;
				continue;
			}
			v++;
		}
		s++;
		res++;
	}
	return amount;
}

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


int main(int argc, char **argv){
	char words[200] = "heute ist ein schoener tag";
	printf("%d\n",str_del_lowervowels(words));
	printf("%s\n",words);
	return 0;
}
