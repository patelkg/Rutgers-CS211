#include <stdio.h>
#include <stdlib.h>	
	int main(int argc, char** argv){

	int ** matrixA;  
	int ** matrixB;
	int ** matrixC;

	int r1;
	int r2;
	int col1;
	int col2;
        int i;
	int j;

	FILE * fp = fopen(argv[1],"r");

	fscanf(fp,"%d",&r1);
	fscanf(fp,"%d",&col1);

	matrixA=malloc(r1*sizeof(int*));
	
	for( i=0; i<r1;i++){
	matrixA[i]=malloc(col1*sizeof(int*));

       } 

       for(i=0;i<r1;i++){
	for(j=0;j<col1;j++){
	
        fscanf(fp,"%d",&matrixA[i][j]);

	}
	
     }





      
        fscanf(fp,"%d",&r2);
	fscanf(fp,"%d",&col2); 
 	
	
       matrixB=malloc(r2*sizeof(int*));
	
	for(i=0; i<r2;i++){
	matrixB[i]=malloc(col2*sizeof(int*));

       } 

       for(i=0;i<r2;i++){
	for(j=0;j<col2;j++){
	
        fscanf(fp,"%d",&matrixB[i][j]);

	}
	
     }

	// will then check to see if col1==r2 if yes then it can preform matrix multiplication

	if(col1!=r2){
	printf("bad-matrices\n");
	 }

       else if (col1==r2){
	// matrix c will have rows of r1 and columns of col2
	matrixC=malloc(r1*sizeof(int*));

	for (i=0;i<r1;i++){
	matrixC[i]=malloc(col2*sizeof(int*));
	}

     int a;
     int result; 
	for(i=0;i<r1;i++){

           for(j=0;j<col2;j++){
	//matrixC[i][j]=0;           
       for (a=0; a<r2;a++){
       	matrixC[i][j]+=matrixA[i][a]*matrixB[a][j];
 
      }   
          
	//matrixC[i][j]=result;
	       }
	
           }



	
for (i=0;i<r1;i++){
	for(j=0;j<col2;j++){

	printf("%d\t",matrixC[i][j]);
       }
	printf("\n");
   }
	
		
	
       } 




		return 0;
	}
