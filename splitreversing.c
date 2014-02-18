#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node * inputList(){
	int size=0;
	int ch;
	struct node *head;
	struct node *ptr;
	struct node *temp;
	head = malloc( sizeof(struct node) );
	//printf("Enter size of llist");
	scanf("%d",&size);
	//printf("Enter element\n");
	scanf("%*c%d",&ch);
	head->data = ch;
	ptr = head;
	int i=0;
	for(i=0;i<size-1;i++)
	{	
		temp = malloc(sizeof(struct node));
		//printf("Enter element\n");
		ptr->next = temp;
		ptr = ptr->next;
		scanf("%*c%d",&ch);
		ptr->data = ch;
		
	} 
	ptr->next = NULL;
	//ptr = head;
	return head;
}

void order(struct node *head, int blockSize){
	struct node *ptr;
	struct node *nextHead;
	struct node *tail;
	int tempData;
	ptr = head;
	int i = 0, j = 0, c = 0, k = 0, flag = 0;
	for(k=0;;k++){
		if(flag==1)
			break;
		c=0;
		for(j=0;j<blockSize/2;j++){

			for(i = 0;i < blockSize-1-c;i++){
				if(ptr->next == NULL){
					flag = 1;
					break;
					}
				ptr = ptr->next;
			}
			if(j==0)
				nextHead = ptr->next;
			if(nextHead==NULL)
				flag = 1;
			tempData = head->data;
			head->data = ptr->data;
			ptr->data = tempData;
			ptr = head->next;
			c = c + 2;
			head = head->next;
		}
	if(flag==1)
		break;
	ptr = nextHead;head = nextHead;
	}
}

int main(){
	struct node *head1;
	struct node *ptr;
	head1 = inputList();
	int blockSize = 0;
	ptr = head1;
	scanf("%d",&blockSize);
	order(head1, blockSize);
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}

}
