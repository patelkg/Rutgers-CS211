#include <stdio.h>
#include <stdlib.h>
	struct BSTnode{
	    int data;
	    struct BSTnode *left;
	    struct BSTnode *right;
	 };
 struct BSTnode * insert(int data, struct BSTnode*); //rec. creating "new node " as well as inserting
 int search(int data,struct BSTnode*); // traversal 
 int node_height(int data,struct BSTnode*); // traversal and counts the height of node
struct BSTnode *create_node(int data); 
void free_tree(struct BSTnode*);
struct BSTnode * create_node(int data);

      int main (int argc , char ** argv){
        struct BSTnode *root =NULL;
	char letter;
	int num;
	
 

	FILE * fp = fopen(argv[1],"r");
	 if (fp==NULL){
	    printf("error\n");
	    exit(0);
	} 	
  while (fscanf(fp, "%c\t%d\n",&letter,&num)!=EOF){
               
               if (letter=='i'){
		 if (search(num,root)==0){
		root=insert(num,root);
		 printf("inserted %d\n",node_height(num,root));
                      }else{
			printf("duplicate\n");
		     }
                   } 
		if (letter=='s'){
                   if (search(num,root)==1){
                      printf("present %d\n",node_height(num,root));
                } else {
                   printf("absent\n");
                   }  

      } 
 }
  fclose(fp);
	return 0;
  }

    
 struct BSTnode* create_node(int data){
      struct BSTnode *temp =malloc(sizeof(struct BSTnode));
	temp->data = data;
	temp->left =NULL;
	temp->right =NULL;
	return temp;
 } 

  struct BSTnode* insert(int data , struct BSTnode* temp){ 
      if (temp==NULL){
	 temp= create_node(data);
	} 
      if(temp->data > data){
 	temp->left = insert(data,temp->left); 
	} 
     if (temp->data < data){ 
	 temp->right=insert(data, temp->right);
     } 
   return temp;
 }  
  
int search(int data , struct BSTnode *temp){
 	if (temp!=NULL && temp->data==data){
		return 1;
	}
  if (temp==NULL){
	return 0;
 	}
          if (temp->data >data){
	     return search(data,temp->left);
		}
        if (temp->data <data){
	     return search(data,temp->right);
             } 
}
  
  int node_height(int data, struct BSTnode *head){
	int counter = 0;
	if (head->data ==data){ 
	counter++;
	return counter; 
        } 
		counter++; 
 
		if (head->data >data){
		    return counter +node_height(data,head->left);
                    } 
     
               if (head->data < data){
                  return counter + node_height(data,head->right);
                } 

  
      }    
   

 


