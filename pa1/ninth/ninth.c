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
struct BSTnode * delete(int data, struct BSTnode*);
struct BSTnode * min(struct BSTnode*);
struct BSTnode * max(struct BSTnode*);

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
                      }
                   } 
		if (letter=='s'){
                   if (search(num,root)==1){
                      printf("present %d\n",node_height(num,root));
                } else {
                   printf("absent\n");
                   }
	 
      } 

		if (letter=='d'){
		    if (search(num,root)==1){
			root=delete(num,root);
			printf("success\n");	
			}else {
			printf("fail\n");
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

struct BSTnode *delete(int data, struct BSTnode*head){

	/* if the data is found it will do either 3 options 
	1. if the node deleted is a leaf node 
	2. if the node is a root but has only 1 child 
	3. if the node is a root and has 2 chilren , will find min in right
	subtree make that new "root"	 
    */
	if (head ==NULL){
		return head;
	} 
    if(head->data >data){
	  head->left=delete(data,head->left);
	 } else if(head->data<data){
		head->right=delete(data,head->right);
	 }

			
	 else {
		if (head->left ==NULL && head->right==NULL){
		    free(head); // deletes node 
		    head =NULL; //new value of head 
		    
	           } 

		else if (head->left==NULL){
			struct BSTnode *oldHead =head;
			head = head ->right;
			free(oldHead);
	              
			} 

		else if (head->right==NULL){	
			struct BSTnode *oldHead =head;
			head =head->left;
			free(oldHead);
			
			}
		else if (head->left!=NULL && head->right!=NULL){
			struct BSTnode *oldHead=min(head->right);
		     head->data=oldHead->data;
			head->right=delete(oldHead->data,head->right);
			return head;
			}

                } 
    
	return head;


 } 
 struct BSTnode *min(struct BSTnode* head){
	while (head->left!=NULL)
       {  
         head = head ->left;
	  } 
	return head; 
	}

struct BSTnode * max(struct BSTnode* head){
	while(head->right!=NULL){
	    head = head ->right;
	}
	return head; 
	}
