/* (c) 2011 Alexander Baumgärtner */
/* Testwerte (c) Barth */

#include<string.h>
#include<stdio.h>
#include"a2.h"
#include"a2.c"

int anzahlTests=0, anzahlTestsOk=0,testOk;

void check(char *word, char *correct, int delVowCorrect){

  int delVowels=0;
  anzahlTests+=1;
  testOk=1;
  printf("Aufruf:str_del_vowels(\t %s\n",word);

  delVowels=str_del_vowels(word);

  printf("Erwarte: \t\t%s\n",correct);
  printf("Erhalten: \t\t%s\n",word);
  if (strcmp(word,correct)==0){
    printf("Vergleich OK.\n");
  }
  else{
    printf("Vergleich nicht OK.\n");
    testOk=0;
  }

  if (delVowCorrect==delVowels){
    printf("Rückgabewert %i OK.\n\n",delVowels);
  }
  else{
    printf("Rückgabewert %i nicht OK. Richtig wäre %i\n\n",delVowels,delVowCorrect);
    testOk=0;
  }
  if (testOk)
    anzahlTestsOk+=1;
}


void checkUpp(char *word, char *correct, int delVowCorrect){

  int delVowels=0;
  anzahlTests+=1;
  testOk=1;
  printf("Aufruf:str_del_uppervowels(\t %s\n",word);

  delVowels=str_del_uppervowels(word);

  printf("Erwarte: \t\t%s\n",correct);
  printf("Erhalten: \t\t%s\n",word);
  if (strcmp(word,correct)==0){
    printf("Vergleich OK.\n");
  }
  else{
    printf("Vergleich nicht OK.\n");
    testOk=0;
  }

  if (delVowCorrect==delVowels){
    printf("Rückgabewert %i OK.\n\n",delVowels);
  }
  else{
    printf("Rückgabewert %i nicht OK. Richtig wäre %i\n\n",delVowels,delVowCorrect);
    testOk=0;
  }
  if (testOk)
    anzahlTestsOk+=1;
}


void checkLow(char *word, char *correct, int delVowCorrect){
   
  int delVowels=0;
  anzahlTests+=1;
  testOk=1;
  printf("Aufruf:str_del_lowervowels(\t %s\n",word);

  delVowels=str_del_lowervowels(word);

  printf("Erwarte: \t\t%s\n",correct);
  printf("Erhalten: \t\t%s\n",word);
  if (strcmp(word,correct)==0){
    printf("Vergleich OK.\n");
  }
  else{
    printf("Vergleich nicht OK.\n");
    testOk=0;
  }

  if (delVowCorrect==delVowels){
    printf("Rückgabewert %i OK.\n\n",delVowels);
  }
  else{
    printf("Rückgabewert %i nicht OK. Richtig wäre %i\n\n\n",delVowels,delVowCorrect);
testOk=0;
  }
  if (testOk)
    anzahlTestsOk+=1;
}



int main(void){

  int res;
  char word1[]="bcdxdfgkl", correct1[]="bcdxdfgkl";
  char word2[]="abAcde", correct2[]="bAcd";
  char word3[]="", correct3[]="";
  char word4[]="", correct4[]="";
  char word5[]="AeIxoU", correct5[]="exo";
  char word6[]="AeIxoU", correct6[]="x";
  char word7[]="", correct7[]="";
  char word8[]="fghEbcdXUEIOfdgHG", correct8[]="fghEbcdXUEIOfdgHG";


  putchar('\n');
  

  check(word1,correct1,0);
  checkLow(word2,correct2,2);
  checkLow(word3,correct3,0);
  check(word4,correct4,0);
  checkUpp(word5,correct5,3);
  check(word6,correct6,5);
  check(word7,correct7,0);
  checkLow(word8,correct8,0);

  res=anzahlTestsOk*100/anzahlTests;

  printf("%i von %i Tests erfolgreich. Das sind %i Prozent.\n\n",anzahlTestsOk,anzahlTests,res);

  return 0;
}
