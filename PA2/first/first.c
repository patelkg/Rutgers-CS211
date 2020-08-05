#include <stdio.h>
#include <stdlib.h>
void printHexadoku(char **);
int isValid(char **,int ,int ,char);
int isValidRow(char**,int,char);
int isValidCol(char**,int,char);
int isValidMini(char **,int ,int);
int solve(char **);
int isValidMin(char** ,int,int,char);
int isRowGood(char**,int);
int isColGood(char ** ,int);
int isValidBefore(char **);
int isValidSub(char **);

	int main(int argc, char** argv){
	
	char **table;
	int rows=16;
	int i;
	char val;
	int j;

	table=malloc(rows*sizeof(char*));
	  
	for(i=0;i<rows;i++){
	table[i]=malloc(rows);
	   }

     FILE * f = fopen(argv[1],"r");

	for(i=0;i<rows;i++){
	  for (j=0;j<rows;j++){
		fscanf(f,"%c\t",&table[i][j]);
			}	
		}
	

	
	//  printHexadoku(table);
	 //    printf("%d ",isValidMini(table,1,1));
		


     if(isValidBefore(table)==1 && isValidSub(table)==1 ){
	   if(solve(table)==1){
		printHexadoku(table);
		//printf("Hello");
	   
       }  else if(solve(table)==0){
                 printf("no-solution\n");
		}
} else {
	printf("no-solution\n");
	
  } 

    
/*
	
*/
     

return 0;
 }

void printHexadoku(char **table){
	int i,j;
	
for(i=0;i<16;i++){
 for(j=0;j<16;j++){
printf("%c",table[i][j]);
printf(" ");
    }
printf("\n");

}

} 
// checks the uniqueness of the rows 
int isValidRow(char ** table,int rowNum,char c){
  int i,j,counter;
    for(i=0;i<16;i++){
	if(table[rowNum][i]==c)
	  return 0;
    }
 
  return 1;  
 }

int isValidCol(char **table,int colNum,char c){
  int i,j,counter;
 

  for(i=0;i<16;i++){
  if(table[i][colNum]==c){
	return 0;
         }      
}

return 1;
 }




isValid(char ** table,int row,int col,char c){

if(isValidRow(table,row,c)==1 && isValidCol(table,col,c)==1 && isValidMin(table,row,col,c)==1){
        return 1;
	} else {
	return 0;
      } 
	



} 



int solve(char** table){
 char bank[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int row,col,k;
//int ctr =0;
int kr;
//printf("*\n");

    for(row=0;row<16;row++){
	for(col=0;col<16;col++){
		if(table[row][col]=='-'){
			 for(k=0;k<16;k++){
			if(isValid(table,row,col,bank[k])==1){
			   table[row][col]=bank[k];

			   if(solve(table)==1){
				return 1;
				}else {
				table[row][col]='-';
				} 
			   }
			}
			
			return 0;

		}

	}

  }


return 1;
} 





int isValidMini(char **table, int row, int column){
   int i,j; 
  int ii = ((row/4)*4) +4;
  int jj=((column/4)*4) +4;
  int num=0;
   int counter =0;
	//printf(":njsnjn\n");
for( i=(row/4)*4;i<ii;i++){
	for(j=(column/4)*4;j<jj;j++){
         if(table[i][j]!='-'){
             counter++;
	 } 

    }
 }
//printf("%d\n",counter);
   char * temp;
	temp=malloc(counter*sizeof(char));
    
	
	for(i=((row/4)*4);i<ii;i++){
	for(j=((column/4)*4);j<jj;j++){
         if(table[i][j]!='-'){
       		temp[num]=table[i][j];
		num++;
	 } 

    }
	}
               
    //  for(i=0;i<counter;i++){
	//  printf("%c ",temp[i]);
		//}               
	//printf("\n");


             for(i=0;i<counter;i++){
		for(j=i+1;j<counter;j++){
		   if(temp[i]==temp[j]){
			return 0;
		    } 

			}
		
     

 }

 return 1;
  }

  

int isValidMin(char **table, int row, int column,char c){
   int i,j; 
  int ii = ((row/4)*4) +4;
  int jj=((column/4)*4) +4;
  //int num=0;
   int counter =0;
	//printf(":njsnjn\n");
for( i=(row/4)*4;i<ii;i++){
	for(j=(column/4)*4;j<jj;j++){
         if(table[i][j]==c){
             return 0;
	 } 

    }
 }

 //if(counter>0){
//	return 0;
  //  }


 return 1;
  }


int isRowGood(char ** table, int rowNum){
 int i,j,counter;
   int num=0;
	counter =0;

      for(i=0;i<16;i++){
  	 if(table[rowNum][i]!='-'){
	   counter++;
	 }
     }
	if(counter==0){
	  return 1;
      }	
	
   char temp[counter];

	 for(i=0;i<16;i++){
	    if(table[rowNum][i]!='-'){
	       temp[num]=table[rowNum][i];
		num++;
		}
	}
           if(num==1){
	      return 1;
            }

	for(i=0;i<counter;i++){
		for(j=i+1;j<counter;j++){
		   if(temp[i]==temp[j]){
			return 0;
		    } 

			}
}

return 1;

 }

int isColGood(char ** table,int colNum){

int i,j,counter;
   int num=0;
	counter =0;

  for(i=0;i<16;i++){
  	 if(table[i][colNum]!='-'){
	   counter++;
	 }
     }
	// there is an empty column
	if(counter==0){
	 return 1;
      }

   char temp[counter];


	 for(i=0;i<16;i++){
	    if(table[i][colNum]!='-'){
	       temp[num]=table[i][colNum];
		num++;
		}
	}
      // if there is only 1 filled in number or there is an empty row
	if(num==1){
          return 1;
        }

	for(i=0;i<counter;i++){
		for(j=i+1;j<counter;j++){
		   if(temp[i]==temp[j]){
			return 0;
		    } 

			}
}

return 1;
 }

isValidBefore(char ** table){
int i;
for (i=0;i<16;i++){
  
  if(isRowGood(table,i)==0 || isColGood(table,i)==0){
		return 0;
		} 

    }	


return 1;


}


int isValidSub(char ** table){
int i,j,counter; 
   
for(i=0;i<16;i++){
	for(j=0;j<16;j++){
     if(isValidMini(table,i,j)==0){
	 return 0;
		}
		
	}

 }

return 1;


} 














