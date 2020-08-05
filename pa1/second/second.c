#include <stdio.h>
#include <stdlib.h>

	struct node{
		int data; 
		struct node* next;
	};

int duplicate(int);
void insert(int);
void delete(int);
void print_list();
void free_list();
int count_nodes();
void sort();

struct node *head =NULL;

	int main(int argc , char** argv){
	int num;
	int count;

	char c;

 
 FILE * fp=fopen(argv[1],"r");

if(fp==NULL){
  printf("error\n");
  return 0;
}



  while(fscanf(fp,"%c%d\n",&c,&num)!=EOF){


   if(c=='i'){
	if (duplicate(num)==0){
 	insert(num);
        }

}
   if(c=='d'){
	if (duplicate(num)==1){
 	delete(num);
     }
          }
     }
	fclose(fp);
sort();
count=count_nodes();
printf("%d\n",count); 
print_list();
free_list();


	return 0;
	}


void insert(int data){
 struct node* temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next=head;
	head = temp;
}


void print_list(){
struct node *temp = head;
	while(temp!=NULL){
	printf("%d\t", temp->data);
	temp=temp->next;
      }
 }

int duplicate(int data){
    struct node * temp = head;
    while (temp!=NULL){
	if(temp->data==data){
	  return 1;
	}
	temp= temp->next;
	}
   return 0;
	} 

void delete(int data){
     struct node *temp = head->next;
     struct node *prev=head;
	if(prev->data==data){ // if deleted node is the 1st node 
	  head = prev->next;
	
	 }

	while (temp!=NULL){
	if(temp->data==data){
	 prev->next=temp->next;
	 }  
	prev=temp;
	   temp = temp->next;
	    }
	}

void sort() {   
// sorting uses bubble sort to switch the data in the node 
   struct node* temp;
   struct node* temp1; 
   int switchData;	
	 for (temp=head;temp!=NULL;temp=temp->next){
		for(temp1=temp; temp1!=NULL;temp1=temp1->next){
			if (temp->data>temp1->data){
			  switchData = temp->data; 
			  temp->data = temp1->data; 
			  temp1->data = switchData;
				}
			}
		}
	}

int count_nodes(){
 struct node* temp = head;
 int counter=0;
	while(temp!=NULL){
	 counter++;
	temp = temp->next;
	} 
     return counter;
 } 

void free_list(){
    struct node* temp= head;
	while (temp!=NULL){
	 struct node* temp1 =temp;
	 temp = temp->next;
	 free(temp1);
   } 
 }


