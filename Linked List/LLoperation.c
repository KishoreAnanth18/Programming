/*Linked list
---------------
Insertion at begin
Insertion at end
Delete at begin
Delete at end
Insert on sort
*/


#include <stdio.h>
#include <stdlib.h>
//Node structure
struct node{
  int data;
  struct node* next;
};
typedef struct node Node;

//Create node function
Node* createNode(int input){
  Node* newNode;
  newNode = (Node*)malloc(sizeof(Node));
  newNode->data = input;
  newNode->next = NULL;
  return newNode;
}

//Function to add node at beginning
void insert_at_begin(int input,Node* * start_ptr){
  Node* newNode = createNode(input);
  newNode->next = *start_ptr;
  *start_ptr = newNode;
}

//Function to add node at end
void insert_at_end(int input, Node* * start_ptr){
  Node* newNode = createNode(input);    
  if(*start_ptr == NULL){
    *start_ptr = newNode;
  }else{
    Node* ptr;
    for(ptr=*start_ptr; ptr->next!=NULL; ptr=ptr->next);
    ptr->next = newNode;      
  }
}

//Function to delete at begin
void delete_at_begin(Node* * start_ptr){
  if(*start_ptr == NULL) printf("Linked List is empty");
  else{
    Node* to_free;
    to_free = *start_ptr;
    *start_ptr = (*start_ptr)->next;
    free(to_free);
  }
}

//Function to delete at end
void delete_at_end(Node* * start_ptr){
  if(*start_ptr == NULL) printf("Linked List is empty");
  else{
    Node* ptr;
    Node* shadow=NULL;
    for(ptr = *start_ptr; ptr->next != NULL; ptr=ptr->next){
      shadow = ptr;  
    }
    shadow->next = NULL;
    free(ptr);
  }
}

//Function to add elements in sorting order
void insert_on_sort(int input, Node* * start_ptr){
  Node* newNode = createNode(input);
  if(*start_ptr == NULL){
    *start_ptr = newNode;
    return;
  }
  Node* ptr;
  Node* shadow = NULL;
  for(ptr = *start_ptr; ptr!=NULL; shadow = ptr,ptr = ptr->next){
    if((ptr->data) > input){
      break;
    }
  }
  if(ptr==*start_ptr){
    *start_ptr = newNode;
    newNode->next = ptr;
  }else{
    shadow->next = newNode;
    newNode->next = ptr;  
  }
}

//Function to print the data in the linked list
void display_LL(Node* start){
  for(Node* ptr=start; ptr!=NULL; ptr=ptr->next){
    printf("%d ",ptr->data);
  }
}

//Main function
int main(){
  int input;
  Node* start = NULL;
  while(1){
    scanf("%d",&input);
    if(input == -1) break;
    insert_on_sort(input,&start);
  }
  display_LL(start);
  return 0;
}
