#include <stdio.h>
#include <ctype.h>

/* Function to create soundex code from given input*/
void soundex(const char s[], char res[]){
	int i=1,j;
	char curr;
	const char *inputptr = s;
	char *soundexptr;
	char *soundex[] = {"BFPV",
				  "CGJKQSXZ",
				  "DT",
				  "L",
				  "MN",
				  "R"
	};
	res[0] = toupper(s[0]);
	while(*inputptr++){
		curr = toupper(*inputptr);
		for(j=0;j<6;j++){
			soundexptr = soundex[j];
			while(*soundexptr){
				if(curr == *soundexptr && (res[i-1]!=(j+1)+'0')){
					res[i]=j+1 + '0';
					i++;
					j=6;
					break;
				}
				soundexptr++;
			}
		}
		if(i==6){
			break;
		}
	}
	if(i<6){
		for(;i<6;i++){
			res[i]='0';
		}
	}
	res[i+1]='\0';
	printf("%s",res);

}

int main(void){
	char input[100], res[100];
	while(fgets(input,100,stdin)!=NULL){	
		soundex(input,res);
		printf("\n");
	}
	return 0;
}
