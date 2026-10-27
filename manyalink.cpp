#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *ptr;
};
typedef struct node node;
node *head;

void ins_beg()
{
    int x;
    node *new_node;
    new_node=(node*)malloc(sizeof(node));
    printf("Enter num");
    scanf("%d",&x);
    new_node->data=x;
    new_node->ptr=head;
    head=new_node;
}

void ins_any()
{
	node *new_node, *t1, *t2;
	int i=0,pos,x;
	t1=head;
	new_node=(node*)malloc(sizeof(node));
	
	printf("Enter position:");
	scanf("%d",&pos);
	
    printf("Enter num:");
    scanf("%d",&x);
    
    while(i<pos)
    {
    	t2=t1;
    	t1=t1->ptr;
    	i++;
	}
	
	new_node->data=x;
	new_node->ptr=t1;
	t2->ptr=new_node;
    
}


void ins_end()
{
	int x;
    node *new_node, *t;
    t=head;
    
    new_node=(node*)malloc(sizeof(node));
    printf("Enter num:");
    scanf("%d",&x);
    while(t->ptr!=NULL)
    {
    	t=t->ptr;
	}
    new_node->data=x;
    new_node->ptr=NULL;
    t->ptr=new_node;
    
}

void del_beg()
{
	node *t1,*t1;
	t1=head;
	t2=head;
	t2=t2->ptr;
	head=t2;
	free(t1);
}

void del_end()
{
	node *t1, t2;
	t1=head;
	while(t1->ptr!=NULL)
	{
		t2=t1;
		t1=t1->ptr;
	}
	t2->ptr=NULL;
	free(t1);
	
}

void del_any(item)
{
	node *t1,*t2;
	t2=head;
	while(t2->num!=item)
	{
		t1=t2;
		t2=t2->ptr;
	}
	t1->ptr=t2->ptr;
	free(t2);
}


void display()
{
    node *t;
    t=head;
    while(t!=NULL){
        printf("%d\t",t->data);
        t=t->ptr;
    }
}

void cnode()
{
	node *t;
	t=head;
	int c=0;
	while(t!=NULL){
		t=t->ptr;
		c++;
	}
	printf("num of node: %d", c);
}

int main()
{
    head=(node*)malloc(sizeof(node));
    head->data=1000;
    head->ptr=NULL;
    //printf("%d", head->data);


    int n,ch,i=1;

    while(i==1)
    {
        printf("\nEnter 1 to insert at begging\n 2 to insert anywhere\n 3 to insert at the end\n 4 to display\n 5 to count node\n 6 to delete from beginning \n 7 to delete from end \n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                ins_beg();
                break;
            case 2:
            	ins_any();
            	break;
            case 3:
            	ins_end();
            	break;
            case 4:
                display();
                break;
            case 5:
            	cnode();
            	break;
            case 6:
            	del_beg();
            	break;
            case 7:
            	int item;
            	printf("enter value to delete");
            	scanf("%d",&item)
				del_end(item);
            	break;
            default:
                printf("\nthanks.");
                break;
        }

        printf("\nEnter 1 to run again");
        scanf("%d", &n);
        if(n!=1){
            break;
        }
    }
    return 0;
}
