#include <stdlib.h>
#include <stdio.h>
int intvgl(const void *p1, const void *p2){
	return *(int*) p1 - *(int*) p2;
}
int main(void){
	int vek[9] = {9,7,1,5,3,6,2,8,4}, i;
	qsort(vek,9,sizeof(int),intvgl);
	for(i = 0; i<9; i++){
		printf("%d\n",vek[i]);
	}
	return 0;
}
