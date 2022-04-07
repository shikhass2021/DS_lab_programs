#include <stdio.h>  
#include <stdlib.h>  
struct node{  
 int val;  
 struct node *next;  
};  
struct Head  
{  
 int size;  
 int maxSize;  
 struct node *front;  
 struct node *rear;  
};  
//Function declareations  
void enqueue(int val, struct Head *head);  
struct node *dequeue(struct Head *head);  
void menu();  
void sumAvg(struct Head *head);  
//Initializing head of queue; head contains pointers to front, rear, max size of queue, current size of queue  
struct Head head = {0, 0,NULL, NULL};  
int main(int argc, char const *argv[])  
{  
 //initialize max size of queue  
 printf("\nEnter size of queue : ");  
 scanf("%d", &head.maxSize);  
 menu();  
 return 0;  
}  
void menu(){  
 // Prints the menu, waits for input  
 system("cls");  
 printf("\n[1] : Enqueue");  
 printf("\n[2] : Dequeue");  
 printf("\n[3] : Find sum and average");  
 printf("\n[>] : ");  
 int choice, val;  
 struct node * ret;
 scanf("%d", &choice);  
 switch(choice){  
 case 1 :  
 printf("\nEnter value to queue : ");  
 int val;  
 scanf("%d", &val);  
 enqueue(val, &head);  
 printf("\nValue put in queue...!!");  
 break;  
 case 2 :  
  ret = dequeue(&head);  
 if(ret != NULL){  
 printf("\nDequeued value : %d", ret->val);  
 free(ret);  
 }  
 else printf("\nDequeue Failed.");  
 break;  
 case 3:  
 sumAvg(&head);  
 break;  
 default:  
 printf("\nInvalid choice");  
 break;  
 }  
 printf("\n Press any key to continue");  
 getch(); 
 menu();  
}  
void enqueue(int val, struct Head *head){  
 if(head->size >= head->maxSize){  
 printf("\nQueue is Full..!!");  
 }  
 else{  
 struct node *newNode = malloc(sizeof(struct node)); 
  newNode->val = val;  
 if(head->rear == NULL) {  
 head->rear = newNode;  
head->front = newNode; 
head->size += 1;  
 }  
 else{  
 head->rear->next = newNode;  
  head->rear = newNode;   
  head->size += 1;  
 }  
 }  
}  
struct node *dequeue(struct Head *head){  
 if(head->size > 0){  
 //int val;  
 struct node *temp = head->front;
 head->front = temp->next;  
 head->size -= 1;  
 if(head->size == 0) {  
 head->front = NULL;
 head->rear = NULL;
 head->size = 0;
 }
 return temp;
 }  
 if(head->size == 0) {  
 head->front = NULL;
 head->rear = NULL;
 head->size = 0;
 return NULL;  
 }  
}  
void sumAvg(struct Head *head){  
 int size = head->size;  
 int i;
 int sum = 0;
 for(i = 0 ; i < size; i += 1){  
 struct node *temp = dequeue(head);
 int val= temp->val;
 sum += val;
 
 enqueue(val, head);
}
if(size !=0){
	float avg =(float) ((float)sum/(float)size);
	printf("Sum = %d\nAverage = %.3f",sum, avg);
}
else 
printf("queue is empty" );
}  

