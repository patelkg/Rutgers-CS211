#include <stdio.h>
#include <stdlib.h>
int checkSame(int[],int);
int isMaigc(int **,int ,int);

	int main (int argc,char **argv){
            int i;
	    int j;
	    int **matrix;
	    int row;
	    int number; // desiserd magic number
	FILE *fp =fopen(argv[1],"r");
	fscanf(fp,"%d",&row);
     	
        matrix=malloc(row*sizeof(int*));
	for (i=0;i<row;i++){
	matrix[i]=malloc(row*sizeof(int*));
          }

	for(i=0;i<row;i++){
	  for(j=0;j<row;j++){
	fscanf(fp,"%d",&matrix[i][j]);

      }
 }
		

	for(i=0;i<row;i++){
	number+=matrix[i][i]; // will give diagonal sum 
	}

//	printf("Mnumber is %d\n",number);
   		 
        int row2 = row*row;
	int array[row2];
        int counter=0;

for(i=0;i<row;i<i++){
   for(j=0;j<row;j++){
	array[counter]=matrix[i][j];
	 counter++;
   }
} 
 


 // will first check if there are any duplicates in the matrix 
if (checkSame(array,row2)==1){
	printf("not-magic\n");

} else if (checkSame(array,row2)==0){

 // will run the is magic test cases 

 if (isMagic(matrix,row,number)==1){
	printf("magic\n");

}  else {
	printf("not-magic\n");
}

 
  }  

	return 0;
	}

int checkSame(int array[],int n2){
 int j;
 int i;
//int length =sizeof(array)/sizeof(int);

	for (i=0;i<n2;i++){
	   for (j=i+1;j<n2;j++){
		if (array[i]==array[j]){	
			return 1;
	            }
		}
	}

	return 0;
  }


// n is the number of rows and columns 
int isMagic(int **matrix,int n,int magicNum){
int dSum=0;
 int rSum=0;;
int colSum=0;
int i;
int j;
// other diagonal 
//printf("dSum is %d\n",dSum);
 for (i=0;i<n;i++){
  dSum = dSum+matrix[i][n-1-i];
//printf("Numbers %d\n",dSum);
}

//printf("Sum diagonal 2 is %d\n",dSum);

if(magicNum!=dSum){
  return 0;

}    
 //printf("rSum %d\n",rSum);
for (i=0;i<n;i++){
      rSum=0;
	for(j=0;j<n;j++){
	rSum = rSum+matrix[i][j];
	
        }
    }

//printf("rSum %d\n",rSum);

if(magicNum!=rSum){
  return 0;

} 

for (i=0;i<n;i++){
colSum=0;
	for(j=0;j<n;j++){
	colSum = colSum+matrix[j][i];
	
        }
    }

if(magicNum!=colSum){
  return 0;

} 


return 1;


 }



