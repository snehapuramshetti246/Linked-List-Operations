#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *next;
};
typedef struct node Node;
//Printing the elements of the linked list
void displayList(Node *head){
Node *ptr = head;
if(ptr == NULL)
 printf("List is Empty\n");
else{
while(ptr != NULL){
printf("%d->",ptr->data);
ptr = ptr->next;
}
printf("NULL\n");
}
}
//Searching
int search(Node *head , int key){
Node *ptr = head;
if(ptr==NULL){
       printf("list is empty");
  return 0;
    }
else{
while(ptr!=NULL){
if(ptr->data == key){
return 1;
}
ptr = ptr->next;

}
}
return 0;
}

//Creation of Node
Node *createNode(int value){
Node *newNode;
newNode = (Node *)malloc(sizeof(Node));
newNode->data= value;
newNode->next = NULL;
return newNode;
}

//Insertion at the end
Node *insertatEnd(Node *head,int value){
Node *n = createNode(value);
if(head==NULL)
 head = n;
else{
Node *lastNode = head;
while(lastNode->next!=NULL)
 lastNode = lastNode->next;
lastNode->next = n;
}
return head;
}

//length of the list
int length(Node *head){
Node *ptr = head;
int count = 0;
while(ptr!=NULL){
count++;
ptr=ptr->next;
}
return count;
}

//Insertion at the beginning
Node *insertatBegin(Node *head,int value){
Node *n = createNode(value);
n->next = head;
head = n;
return head;
}

//Insertion at a position
Node *insertatPosition(Node *head,int value,int pos){
int len = length(head);
Node *ptr = head;
if(pos>len){
head = insertatEnd(head,value);
}
else if(len==1||ptr==NULL){
head = insertatBegin(head,value);
}
else{
Node *n=createNode(value);
Node *ptr = head;
int i;
for(i=1;i<pos-1;i++){
   ptr= ptr->next;
}
n->next = ptr->next;
ptr->next=n;
return head;
}
return head;
}

//Delete at the beginning
Node *deleteatBegin(Node *head){
if(head!=NULL){
Node *ptr = head;
   head = ptr->next;
   ptr->next = NULL;
   free(ptr->next);
   return head;
}
else{
printf("List is empty.Element cannot be deleted\n");
}

}

//Delete at the end
Node *deleteatEnd(Node *head){
Node *ptr = head;
if(ptr!=NULL){
int len = length(head);
if(len ==1){
free(ptr);
head = NULL;
}
else{
	int i;
for(i = 1;i<len-1;i++){
ptr = ptr->next;
}
free(ptr->next);
ptr->next = NULL;
}

}
else{
printf("List is empty.Element cannot be deleted\n");
}
return head;
}

//Delete at a position
Node *deleteatPosition(Node *head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    int len = length(head);

    if (pos > len || pos < 1) {
        printf("Invalid position\n");
        return head;
    }

    if (pos == 1) {
        return deleteatBegin(head);
    }

    Node *ptr = head;
    int i;
    for (i = 1; i < pos - 1; i++) {
        ptr = ptr->next;
    }
    Node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    return head;
}

//middle element
int middleElement(Node *head){
int len = length(head);
int mid = (1+len)/2;
Node *ptr = head;
int i; 
for(i =1;i<mid;i++){
ptr = ptr->next;
}
return ptr->data;
}


int main(){
Node *head = NULL;
int choice,value,key,pos,len;
do{
printf("1-Insert at the end\n");
   printf("2-Searching an element\n");
   printf("3-printing the elements\n");
   printf("4-Insert at beginning\n");
   printf("5-Insert at a specified position\n");
   printf("6-Delete an element at the beginning\n");
   printf("7-delete an element at the end\n");
   printf("8-delete an element at specific position\n");
   printf("9-prints the length of the list\n");
   printf("10-prints the middle element\n");
   printf("11-Exit\n");
   printf("Select your choice:\n");
   scanf("%d",&choice);
   switch(choice){
   case 1:
  printf("Enter an element:\n");
  scanf("%d",&value);
  head = insertatEnd(head,value);
  displayList(head);
  break;
   case 2:
  printf("Enter an element to search: \n");
  scanf("%d",&key);
      if (search(head, key))
                  printf("Element %d found in the list.\n", key);
               else
                  printf("Element %d not found in the list.\n", key);
                break;
   case 3:
   displayList(head);
   break;
case 4:
printf("Enter an element:\n");
   scanf("%d",&value);
   head = insertatBegin(head,value);
   displayList(head);
   break;
case 5:
printf("Enter an element:\n");
   scanf("%d",&value);
   printf("Enter the position to insert:\n");
   scanf("%d",&pos);
head = insertatPosition(head,value,pos);
   displayList(head);
   break;
case 6:
head = deleteatBegin(head);
displayList(head);
break;
case 7:
head = deleteatEnd(head);
displayList(head);
break;
case 8:
printf("enter the position number to delete an element:\n");
scanf("%d",&pos);
head = deleteatPosition(head,pos);
displayList(head);
break;
case 9:
len =length(head);
printf("The length of the linked list is:%d",len);
break;
case 10:
//int middleelement = middleElement(head);
printf("The middle element of the array is:%d\n",middleElement(head));
break;
   case 11:
  printf("Exiting..\n");
  break;
   default:
  printf("Invalid choice.Please try again\n");
}
   
} while (choice!=11);
return 0;
}
