#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *insertEmpty(struct node *start,int data){
	struct node *temp;
	temp= (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	start = temp;
	return start;
}
struct node *insertEnd(struct node *start,int data){
	struct node *temp,*temp1;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;

	temp1 = start;
	while(temp1->link!=NULL){
		temp1 = temp1->link;
	}
	temp1->link = temp;
	return start;
}
void display(struct node *start){
	struct node *p;
	if(start==NULL){
		printf("\nList is empty");
	}
	else{
		p = start;
		printf("\nList is : ");
		while(p!=NULL){
			printf("%d ",p->data);
			p=p->link;
		}
		printf("\n");	
	}
	
}
struct node *insertBegin(struct node *start,int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = start;
	start = temp;
	return start; 
}
struct node *insertAfter(struct node *start,int data,int item){
	struct node *temp,*p;
	p=start;
	while(p!=NULL){
		if(p->data == item){
			temp = (struct node*) malloc(sizeof(struct node*));
			temp->data = data;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p=p->link;
	}
	printf("\n%d is not present in the list",item);
	return start;
}
struct node *insertBefore(struct node *start,int data,int item){
	struct node *temp,*p;
	p=start;
	if(p->data ==item){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;	
		temp->link =start;
		start = temp;
		return start;
	}	
	else{
		while(p->link!=NULL){
			if(p->link->data == item){
				temp = (struct node*)malloc(sizeof(struct node*));
				temp->data = data;
				temp->link = p->link;
				p->link =temp;
				return start;
			}
			p=p->link;
		}
	}
	printf("\n%d is not preset in the list",item);
	return start;
}
struct node *deleteEnd(struct node *start){
	struct node *temp;
	temp = start;
	if(temp==NULL){
		printf("List is empty");
		return start;
	}
	else if(temp->link==NULL){
		printf("\nDeleted data is : %d",temp->data);
		start = NULL;
		free(temp);
		return start;
	}
	else{
		while(temp->link->link!=NULL){
			temp=temp->link;
		}
		printf("\nDeleted data is : %d",temp->link->data);
		temp->link = NULL;
		free(temp->link);
		return start;
	}
}
struct node *deleteBegin(struct node *start){
	struct node *temp;
	temp = start;
	if(temp==NULL){
		printf("\nList is empty");
		return start;
	}
	else{
		printf("\nDeleted data is :  %d",temp->data);
		start = temp->link;
		free(temp);
		return start;
	}
}
struct node *deleteAfter(struct node *start,int item){
	struct node *temp,*p;
	p = start;
	while(p!=NULL){
		if(p->data == item){
			temp = p->link;
			if(temp==NULL){
				printf("\nThere is no node after %d",item);
				return start;
			}
			printf("\nDeleted data is : %d",temp->data);
			p->link = temp->link;
			free(temp);
			return start;
		}
		p=p->link;
	}
	printf("\n%d is not present in the list",item);
	return start;
}
struct node *deleteBefore(struct node *start,int item){
	struct node *temp,*p;
	p = start;
	if(p->data == item){
		printf("\nThere is no node before %d",item);
		return start;
	}
	else if(p->link->data == item){
		printf("\nDeleted data is : %d",p->data);
		start = p->link;
		free(p);
		return start;
	}
	while(p->link!=NULL){
		if(p->link->link->data==item){
			temp = p->link;
			printf("\nDeleted data is : %d",temp->data);
			p->link = temp->link;
			free(temp);
			return start;
		}
		p=p->link;
	}
	printf("\n%d is not found in the List",item);
	return start;
}
int main(){
	int choice,data,item;
	struct node *start;
	start = NULL; 
	while(1){
		printf("\n\n1=display\n2=insertEmpty\n3=insertend\n4=insertBegin");
		printf("\n5=insertAfter\n6=insertBefore");
		printf("\n7=deleteEnd\n8=deleteBegin\n9=DeleteAffter\n10=Deletebefore\n11=exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				display(start);
				break;
			case 2:
				printf("\nEnter data : ");
				scanf("%d",&data);
				start = insertEmpty(start,data);
				break;
			case 3:
				printf("\nEnter data : ");
				scanf("%d",&data);
				start=insertEnd(start,data);
				break;
			case 4:
				printf("\nEnter data : ");
				scanf("%d",&data);
				start = insertBegin(start,data);
				break;
			case 5:
				printf("\nEnter item after which you want to insert a new node : ");
				scanf("%d",&item);
				printf("\nEnter data : ");
				scanf("%d",&data);
				start = insertAfter(start,data,item);
				break;
			case 6:
				printf("\nEnter item before which you want to insert a new node : ");
				scanf("%d",&item);
				printf("\nEnter data : ");
				scanf("%d",&data);
				start = insertBefore(start,data,item);
				break;
			case 7:
				start = deleteEnd(start);
				break;
			case 8:
				start = deleteBegin(start);
				break;	
			case 9:
				printf("\nEnter item after which node you want to delete : ");
				scanf("%d",&item);
				start = deleteAfter(start,item);
				break;
			case 10:
				printf("\nEnter item before which node you want to delete : ");
				scanf("%d",&item);
				start = deleteBefore(start,item);
				break;
			case 11:
				printf("\nExit\n");
				exit(0);
			default:
				printf("\nInvalid choice");
		}
	}
	return 0;
}