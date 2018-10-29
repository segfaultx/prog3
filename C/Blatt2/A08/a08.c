#include <stdio.h>

enum {MAXNUMBERS=20};


int main(void){
	int v[MAXNUMBERS]={0}, i=0,j, arraysize, swap;
	while(scanf("%d",&v[i])!=EOF){
	i++;
	}
	arraysize=i;
	for(i=0;i<arraysize;i++){
		for(j=i+1;j<arraysize;j++){
			if(v[j]<v[i]){
				swap=v[i];
				v[i]=v[j];
				v[j]=swap;
				swap=0;
			}
		}

	}

	for(j=0; j<i;j++){
		printf("%06d\n",v[j]);
	}
	return 0;
}
