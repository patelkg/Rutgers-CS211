#include <stdio.h>
#include <stdlib.h>
double ** multiply(double **,double **, int,int,int,int);
double ** inverse(double **,int,int);
double ** transpose (double **,int,int);
void print(double **,int,int);
 
     int main (int argc , char ** argv){
int n; // rows
int k;
int i;
int j;
int r;
int c;
int testN;
double ** trainX;
double ** trainY;
double ** matrixW;
double **matrixX;
double **matrixY;


       FILE * train = fopen(argv[1],"r");

	fscanf(train,"%d\n",&k); // original columns have to do k+1 still as both a and y matrix 
	fscanf(train,"%d\n",&n); // rows 
	
	//printf("%d rows\n",n);
	//printf("%d columns not by 1\n",k);
	//k++;
       //	printf("%d columns  by 1",k);
	 int newK = k+1; // columns 
   
 trainX=malloc(n*sizeof(double*));
 trainY=malloc(n*sizeof(double*));

for(i=0; i<n;i++){
     trainX[i]=malloc(newK*sizeof(double));
  }
for(j=0;j<n;j++){
	trainY[j]= malloc(sizeof(double));
	}


	for(i=0;i<n;i++){
	  trainX[i][0]=1;
	 for (j=1;j<newK;j++){
		  fscanf(train,"%lf,",&trainX[i][j]);
			

		 }
		fscanf(train,"%lf,",&trainY[i][0]);
	}		

   // print(trainX,n,newK);
 // the swapped rows and columns for the transposed matrix
    r=newK;
      c=n;
    double ** transX=transpose(trainX,n,newK);
   // // have newK be rows and n be columns 
   double **matrixMult=multiply(transX,trainX,r,c,n,newK);
//   i=n;
 //  j=c;
 //  printf("\n");
  //  print(trainY,n,1);
 // print(matrixMult,r,newK);
    double **inverseTX = inverse(matrixMult,r,newK);
 //print(inverseTX,r,newK);

  double ** temp =multiply(inverseTX,transX,r,newK,r,c);
	//print(temp,r,c);
  matrixW=multiply(temp,trainY,r,c,n,1);
	// have k+1 by 1 dimensions

 //print(matrixW,r,1);

 
    FILE * test=fopen(argv[2],"r");
      fscanf(test,"%d",&testN);
         
	

//printf("%d new n value is  ",testN);


matrixX=malloc(testN*sizeof(double*));
for(i=0;i<testN;i++){
  matrixX[i]=malloc(newK*sizeof(double));
}


	for(i=0;i<testN;i++){
	  matrixX[i][0]=1;
	 for (j=1;j<newK;j++){
		  fscanf(test,"%lf,",&matrixX[i][j]);
			

		 }
	}	




//print(matrixX,testN,newK);

matrixY=multiply(matrixX,matrixW,testN,newK,r,1);

print(matrixY,testN,1);



 return 0;
 }

void print(double ** table, int row, int col){
int i,j;
for(i=0;i<row;i++){ 
 for(j=0;j<col;j++){
  printf("%0.0lf ",table[i][j]);
	}
  printf("\n");

  }
  
}

double ** transpose(double** table,int row,int col){
 int i,j;

 double **matrix = malloc(col*sizeof(double*));

for(i=0;i<col;i++){
   matrix[i]=malloc(row*sizeof(double));
}

for(i=0;i<row;i++){
 for(j=0;j<col;j++){
   matrix[j][i]=table[i][j];
	}

 
 }

return matrix;


}

double **multiply (double **matrixA , double **matrixB,int r1,int c1,int r2, int c2){
double ** matrix;
int i,j,k;
if(c1!=r2){
return;
 } else {
matrix = malloc(r1*sizeof(double*));

for(i=0;i<r1;i++){
  matrix[i]=malloc(c2*sizeof(double));
   }

 for(i=0;i<r1;i++){
  for(j=0;j<c2;j++){
       for(k=0;k<r2;k++){
	 matrix[i][j]+=matrixA[i][k]*matrixB[k][j];

      }

   
        }    
 
    }


}


return matrix;

}


double ** inverse(double ** matrix ,int row,int col){
double **temp; // is identity matrix whatever is done to original will be done to temp 
 int i,j;
int a,b;
int k,l;


 temp=malloc(row*sizeof(double*));
 for(i=0;i<row;i++){
  temp[i]=malloc(col*sizeof(double));

 }


 for(i=0;i<row;i++){
    for(j=0;j<col;j++){
    if(i==j){
      temp[i][j]=1.0;
      }else {
       temp[i][j]=0.0;
      }
   } 
    } 






// first divide by constants to make the diagonals of original matrix to 1
 for (i=0;i<row;i++){
	 double con=matrix[i][i];
// divides the whole matricies by the constatnt so the pivots are 1
   for(j=0;j<col;j++){          
      matrix[i][j]=matrix[i][j]/con;
	//printf("%lf ",con);
  	 temp[i][j]=temp[i][j]/con;
	}
       

       for(a=0;a<col;a++){
    if(matrix[i][a]!=1 && a!=i){
          double  num=matrix[a][i]/matrix[i][i];
	  for(b=0;b<col;b++){      
        matrix[a][b]=matrix[a][b]-(num*matrix[i][b]);
        temp[a][b]=temp[a][b]-(num*temp[i][b]);
       }

           }

      }

/*
  for(a=0;a<col;a++){
    if(matrix[i][a]!=0 && a!=i){
           double num=matrix[i][a];
	  for(b=0;b<col;b++){      
        matrix[b][a]=matrix[b][a]-(num*matrix[b][i]);
        temp[b][a]=temp[b][a]-(num*temp[b][i]);
       }

           }

      }

      */




     }


return temp;
}





