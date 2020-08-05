#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};
struct node * newNode(int);
void insert_hash(struct node **,int); // creates node and inserts into hash uusing mod 1000
int search(struct node**,int);
int code(int data);

struct node *hash[1000];



	int main (int argc , char** argv){
	;
//	struct node* head =NULL;
	char letter;
	int num;
	FILE *fp = fopen(argv[1],"r");
	if (fp==NULL){
	   printf("error\n");
	   exit(0);
		}


	while (fscanf(fp,"%c%d\n",&letter,&num)!=EOF){

		if(letter=='i'){
			if (search(hash,num)==0){
			  insert_hash(hash,num);

			  printf("inserted\n");

			      }else {
				printf("duplicate\n");
                              }
			}
	
		if(letter=='s'){
		   if(search(hash,num)==1){
			printf("present\n");
                       } else {
			printf("absent\n");
                       }


		}

	}

	

	return 0;
	}

struct node *newNode(int data){
	struct node*temp =malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;
 }

void insert_hash(struct node** table ,int data){
  struct node *temp = newNode(data);
  int index = code(data);

    if (table[index]==NULL){
	table[index]=temp;
	}
    else if(table[index]!=NULL){
	struct node *chain =table[index];
	while (chain->next!=NULL){
	 chain = chain->next;
		}
	chain->next=temp;
      } 
	  
}
// the hash key 
int code(int data){

 int num = abs(data);
  num = num%1000;
	//printf("%d\n",num);
   return num;

 } 

int search(struct node**table,int data){
int key = code(data);
struct node *chain ;

	if (table[key]==NULL){
		return 0;
	  } 

       if (table[key]!=NULL){
	    chain =table[key];
	// printf("%d\n",chain->data);
	while(chain!=NULL){
		//printf("%d\t",chain->data);
	  if(chain->data==data){
		return 1;
              }
	   chain = chain->next;
	   }
 } 
 
return 0;
 }


