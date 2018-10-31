#include <stdio.h>

enum {MAXNUMBERS=20};


int main(void){
	int v[MAXNUMBERS]={0}, i=0,j, arraysize;
	while(scanf("%d",&v[i])!=EOF){
		if(i==MAXNUMBERS-1){
			break;
		}
		i++;
	}
	arraysize=i;
	for(i=0;i<arraysize;i++){
		for(j=i+1;j<arraysize;j++){
			if(v[j]<v[i]){
				v[i]+=v[j];
				v[j]=v[i]-v[j];
				v[i]=v[i]-v[j];
			}
		}

	}

	for(j=0; j<i;j++){
		printf("%06d\n",v[j]);
	}
	return 0;
}
