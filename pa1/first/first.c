#include<stdio.h>
#include<stdlib.h>
	int isPrime(int);
	int isTrunctPrime(int);

	int main(int argc , char** argv){
	  

  if (argc < 1 ){
    printf("insufficient arguments\n");
    exit(0);
  }
  FILE* fp = fopen(argv[1], "r");
  if(fp == NULL){
    printf("file does not exist\n");
    exit(0);
  }

  int num = 0;
  /* Now read the first line in the file */
  if(fscanf(fp, "%d\n", &num) == EOF){
    printf("empty file\n");
    exit(0);
  }
  
int temp;
int i;
  for( i = 0; i< num; i++){
    
    fscanf(fp, "%d\n", &temp);
  

	if(isPrime(temp)==1){
 	    if (isTrunctPrime(temp)==1){
		printf("yes\n");
  		} else {
		printf("no\n");
			
		  }  

	} else {
	printf("no\n");
}
 }
fclose(fp);
return 0;
}

int isPrime(int num){
  if (num==0){
return 0;
} 

 if (num==1){
return 0;
}

int i;
 for(i=2; i<num;i++){

if (num%i==0){ 
   return 0;
  } 
  
 }
return 1;
}


int isTrunctPrime(int num){
 if (num<10){

return isPrime(num);
}   

while (num>=10){
  if (isPrime(num)==1){
 	num=num/10;
     } 
   if (isPrime(num)==0){
       return 0; 
	break; 
   }
}

}
 
