#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
	int main (int argc , char** argv){ 
	int i; 
        char *string;	
        int length;
	
     for (i=1; i<argc ;i++){
         string = argv[i];
	length = strlen(string)-1;
 
	  printf("%c" ,string [length]);  
	  
        
  } 
    
  return 0;	
	}
