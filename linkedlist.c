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

void display()
{
    node *t;
    t=head;
    while(t!=NULL){
        printf("%d\t",t->data);
        t=t->ptr;
    }
}

int main()
{
    head=(node*)malloc(sizeof(node));
    head->data=1000;
    head->ptr=NULL;
    //printf("%d", head->data);


    int n,ch;

    while(int i=1)
    {
        printf("\nEnter 1 to insert\n 2 to display");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                ins_beg();
                break;
            case 2:
                display();
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