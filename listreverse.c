/*
Given any positive integer k(>0) and a linklist, reverse elements in each block/segment of length k in that linklist,starting from head node.
If last block has l(l<k) elements than for that block, reverse l elements.

N is the number of elements in linklist
Required Space complexity: O(N)	
Required Time Complexity: O(N)

Example:
INPUT:
k=3
linklist: 
1-->2-->3-->4-->5-->6-->7-->8-->9-->10-->11-->NULL

OUTPUT:
3-->2-->1-->6-->5-->4-->9-->8-->7-->11-->10-->NULL


INPUT FORMAT
<k> <Number of elements in linklist> <Elements of linklist seperated with blankspace>

OUTPUT FORMAT
<Elements of linklist seperated with blankspace>

Test Cases:
------------------------------------
Input:
10 1 2 3 4 5 6 7 8 9 10
1 
Output:
1 2 3 4 5 6 7 8 9 10
------------------------------------
Input:
10 1 1 1 1 1 1 1 1 1 2
2 
Output:
1 1 1 1 1 1 1 1 2 1
------------------------------------
Input:
4 1 2 3 4
5 
Output:
4 3 2 1
------------------------------------
Input:
10 1 2 3 4 5 6 7 8 9 10
2 
Output:
2 1 4 3 6 5 8 7 10 9
------------------------------------
Input:
10 1 2 3 4 5 6 7 8 9 10
4 
Output:
4 3 2 1 8 7 6 5 10 9
------------------------------------

Following metrics are used for comparing different algorithms:
1)Number of assignments
2)Number of comparisions
3)Time taken
4)Space taken


*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//structure of a node
typedef struct node
{
	int data;
	struct node *next;
}node;

node *head=NULL;

//append new node at the end of the linklist 
void insert_at_end(node **head, int d)
{
	node *new,*temp;
	new=(node *)malloc(sizeof(node));
	
	if(!new)
	{
		printf("Error in memory");
		exit(0);
	}
	
	temp=*head;
	if(temp==NULL)
	{
		new->data=d;
		new->next=NULL;
		*head=new;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}

		new->data=d;
		new->next=NULL;
		temp->next=new;
	}
		
	return;
}

//display the linklist
void display(node *head)
{
	node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("List is Empty...:(");
		return;
	}	
	printf("\n\n");
	while(temp!=NULL)
	{
	
		printf("%d ",temp->data);
		temp=temp->next;
	}
	return;
}

//store starting address of the next block in start
void head_nextblock(node **start,int k)
{
	node *temp;
	temp=*start;
	int x=k;
	while(x>0)
	{
		temp=temp->next;
		x--;
	}
	*start=temp;
	return;
}

//reverse elements of the block of k nodes with first node as head
void reverse_knodes(node **head,int k)
{
	node *temp,*p=NULL,*q,*r;
	temp=*head;
	q=*head;
	head_nextblock(&q,k);	
	
	if(temp==NULL)
	{
		printf("\nlist is empty..;(");
		return;
	}
	
	while(temp!=NULL && k>0)
	{
		k--;
		p=temp->next;
		temp->next=q;
		q=temp;
		temp=p;
	}
	*head=q;
	return;
}

//return 1 if the given block,with starting node as head,contains k nodes 
int has_knodes(node *head,int k)
{
	node *temp;
	temp=head;
	while(temp!=NULL && k>0)
	{
		k--;
		temp=temp->next;
	}
	if(k==0)
		return 1;
	else
		return 0;
}

int main(int argc,char *argv[])
{
	int k,flag,i,n,data,less_data=0;
	node *nextblock,*prevblock,*temp;

	//getting input from the input.in file
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		insert_at_end(&head,data);
	}
	scanf("%d",&k);
	//check if the given linklist has k nodes 
	flag=has_knodes(head,k);
	nextblock=head;
	prevblock=NULL;

	//if the list has k or more than k nodes
	if(flag==1)
	{
		less_data=1;
      		//reverse first block which is having head node
		reverse_knodes(&head,k);
		i=k-1;
		nextblock=head;
		prevblock=head;
		while(i>0)
		{
			prevblock=prevblock->next;
			i--;
		}
		head_nextblock(&nextblock,k);

		//reverse remaining blocks
		while(nextblock!=NULL && (flag=has_knodes(nextblock,k))==1)
		{
			reverse_knodes(&nextblock,k);
			prevblock->next=nextblock;
			i=k;
			while(i>0)
			{
				prevblock=prevblock->next;
				i--;
			}
			head_nextblock(&nextblock,k);
		}	
	}
	//if last block is having less than k elements
		if(nextblock!=NULL && (flag=has_knodes(nextblock,k))==0)
		{
			temp=nextblock;
			k=1;
			while(temp->next!=NULL)	
			{	
				k++;
				temp=temp->next;
			}
			reverse_knodes(&nextblock,k);

			//case when the first block itself is having less than k elements
			if(less_data==0)
                         {
				head=nextblock;
				display(head);
				return 1;
                         }
			prevblock->next=nextblock;
			i=k;
			while(i>0)
			{
				prevblock=prevblock->next;
				i--;
			}
			head_nextblock(&nextblock,k);
		}
	//display the list
   	display(head);

	return 1;
}
