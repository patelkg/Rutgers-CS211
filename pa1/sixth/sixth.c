#include <stdio.h>
#include <stdlib.h>
#include <string.h>
   
int is_vowel(char); 
	
	int main (int argc , char **argv){
	 
    
	int index;
	 int num = argc;
	int i;
	int j;
        int startvowel;
 	int startconst; 
	char *string; 
	for (i=1;i<num;i++){		
              string = argv[i];

	    for (j=0;j<strlen(string);j++){

		  if(is_vowel(string[j])==1){
			index =j;  
			break;
	}
 
      }

if (index==0){
for (startvowel=index;startvowel<strlen(string);startvowel++)
		printf("%c",string[startvowel]);
                printf("yay");

 } 

if (index>0){

      // vowel 
	for (startvowel=index;startvowel<strlen(string);startvowel++)
		printf("%c",string[startvowel]);

	
  // adding the non starting vowel letters 
	for (startconst = 0; startconst<index;startconst++){
		printf("%c",string[startconst]);
		} 
	           printf("ay");	 
	  
	}

	printf(" ");
     }	
printf("\n");
		return 0;
		} 





int is_vowel(char chr){
if( chr == 'a' || chr == 'A' || chr == 'e' || chr == 'E' || chr == 'i' || chr == 'I' || chr =='o' || chr=='O' || chr == 'u' || chr == 'U'){

	return 1;

  } else {

    return 0;
 
     } 
 
  } 
