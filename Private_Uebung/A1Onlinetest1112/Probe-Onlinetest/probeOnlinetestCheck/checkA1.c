/* (c) 2011 Alexander Baumgärtner */
/* Testwerte (c) Barth */

#include<stdio.h>
#include<stdlib.h>
#include "a1.h"
#include"a1.c"

int testNr=0;
int gesamtOk=0;

int testStep(int input,int resQ,int resK, int res4){

  int resQtest=quadrat(input);
  int resKtest=kubik(input);
  int res4test=hoch4(input);
  
  printf("Aufruf: quadrat(\t%i), kubik(\t%i), hoch4(\t%i)\n",input,input,input);
  printf("Erwarte: \t\t%i  \t\t%i  \t\t%i\n",resQ, resK, res4);
  printf("Erhalten: \t\t%i  \t\t%i  \t\t%i\n",resQtest, resKtest, res4test);
  
  if (resQ!=resQtest || resK!=resKtest || res4!=res4test)
    return 0;
  else
    return 1;
}


int test(int testwerte[][4], int testAnzahl){
  int testOk;
  int i;

  testNr+=1;
  testOk=1;
  printf("\nTest Nr. %i\n",testNr);

  for(i=0;i<testAnzahl;i+=1){
    if(testStep(testwerte[i][0],testwerte[i][1],testwerte[i][2],testwerte[i][3])!=1){
      testOk=0;
    }
  }

 if (testOk){
    printf("Test %i bestanden.\n",testNr);
    return 1;
  }
 else{
    printf("Test %i nicht bestanden.\n",testNr);
    return 0;}
}

int main (void){
  int res;

  int iA1[][4]={{1,1,1,1}};
  int iA2[][4]={{2,4,8,16},{3,9,27,81},{4,16,64,256}};
  int iA3[][4]={ {0,0,0,0},{1,1,1,1} };
  int iA4[][4]={ {-1,1,-1,1} };
  int iA5[][4]={ {-1,1,-1,1},{0,0,0,0},{1,1,1,1} };
  int iA6[][4]={ {2,4,8,16},{4,16,64,256},{9,81,729,6561},{16,256,4096,65536},{25,625,15625,390625}  };
int iA7[][4]={ {36,1296,46656,1679616},{37,1369,50653,1874161},{38,1444,54872,2085136},{39,1521,59319,2313441},{40,1600,64000,2560000},{41,1681,68921,2825761},{42,1764,74088,3111696},{50,2500,125000,6250000} };

  gesamtOk+=test(iA1,1);
  gesamtOk+=test(iA2,3);
  gesamtOk+=test(iA3,2);
  gesamtOk+=test(iA4,1);
  gesamtOk+=test(iA5,3);
  gesamtOk+=test(iA6,5);
  gesamtOk+=test(iA7,8);



  res=(gesamtOk*100)/testNr;
  printf("\n%i von %i Tests bestanden. Das sind %i Prozent.\n\n",gesamtOk,testNr,res);

  return 0;
}
