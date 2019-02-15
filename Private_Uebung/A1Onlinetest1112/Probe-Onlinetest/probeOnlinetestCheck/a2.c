int str_del_lowervowels(char *s){
   char *read=s,*write=s;
   int counter=0;
   int dowrite;
   
   while(read!='\0'){
  
   if (*read=='a' || *read=='e' || *read=='i' || *read=='o' || *read=='u'){
      counter+=1;
	  dowrite=0;   
   }
   else{
      dowrite=1;}
	  
	if (*read=='\0')
	   break;
	   
	if (dowrite){
	   *write=*read;
	   write+=1;}
	read+=1;
	
   }
   *write='\0';
   return counter;
}


int str_del_uppervowels(char *s){
   char *read=s,*write=s;
   int counter=0;
   int dowrite;
   
   while(read!='\0'){
  
   if (*read=='A' || *read=='E' || *read=='I' || *read=='O' || *read=='U'){
      counter+=1;
	  dowrite=0;   
   }
   else{
      dowrite=1;}
	  
	if (*read=='\0')
	   break;
	   
	if (dowrite){
	   *write=*read;
	   write+=1;}
	read+=1;
	
   }
   *write='\0';
   return counter;
}



int str_del_vowels(char *s){
   char *read=s,*write=s;
   int counter=0;
   int dowrite;
   
   while(read!='\0'){
  
   if (*read=='a' || *read=='e' || *read=='i' || *read=='o' || *read=='u' || *read=='A' || *read=='E' || *read=='I' || *read=='O' || *read=='U'){
      counter+=1;
	  dowrite=0;   
   }
   else{
      dowrite=1;}
	  
	if (*read=='\0')
	   break;
	   
	if (dowrite){
	   *write=*read;
	   write+=1;}
	read+=1;
	
   }
   *write='\0';
   return counter;
}
