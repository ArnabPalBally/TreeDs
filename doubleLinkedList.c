#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *head,*ptr,*tail; 
struct node *getNode(int x)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        return NULL;
    }
    newNode->data=x;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void insertBeg()
{
    int x;
    struct node *newNode;
    printf("Enter data:");
    scanf("%d",&x);
    newNode=getNode(x);
    if(newNode==NULL)
    {
        printf("Overflow\n");
    }
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        newNode->right=head;
        head->left=newNode;
        head=newNode;
    }
}
void insertafterData()
{
    int x,y;
    struct node *newNode;
    printf("Enter the specific data for after insertion:");
    scanf("%d",&x);
    if(head==NULL)
    {
        insertBeg();
    }
    else
    {
        ptr=head;
        while(ptr->data!=x && ptr->right!=NULL)
        {
            ptr=ptr->right;
        }
        if(ptr->data==x)
        {
            printf("Enter data for insertion:");
            scanf("%d",&y);
            newNode=getNode(y);
            newNode->left=ptr;
            newNode->right=ptr->right;
            ptr->right->left=newNode;
            ptr->right=newNode;
        }
    }
}
void insertatEnd()
{
    int y;
    if(head==NULL)
    {
        insertBeg();
    }
    else
    {
        ptr=head;
        while(ptr->right!=NULL)
        {
            ptr=ptr->right;
        }
        struct node *newNode;
        printf("Enter data for insertion:");
        scanf("%d",&y);
        newNode=getNode(y);
        newNode->left=ptr;
        ptr->right=newNode;
    }
}
void deleteBeg()
{
    ptr=head;
    printf("Deleted value is %d\n",ptr->data);
    head=ptr->right;
    free(ptr);
}
void deleteEnd()
{
    ptr=head;
    if(ptr->right==NULL)
    {
        deleteBeg();
    }
    else
    {
        while(ptr->right!=NULL)
        {
            ptr=ptr->right;
        }
        printf("Deleted Item is:%d",ptr->data);
        ptr->left->right=NULL;
        free(ptr);
    }
}
void deleteAtData()
{
    int x;
    printf("Enter data to be deleted:\n");
    scanf("%d",&x);
    ptr=head;
    while(ptr->data!=x && ptr->right!=NULL)
    {
        ptr=ptr->right;
    }
    if(ptr->right==NULL)
    {
        printf("Elements not found\n");
    }
    else
    {
        ptr->left->right=ptr->right;
        free(ptr);
    }
}
void display()
{
    ptr=head;
    while(ptr)
    {
        printf("%d ",ptr->data);
        ptr=ptr->right;
    }
    printf("\n");
}

int main()
{
    int choice;
    printf("1 for insert at begining:\n");
    printf("2 for insert after data:\n");
    printf("3 for insert at end:\n");
    printf("4 for delete begining\n");
    printf("5 for delete at end\n");
    printf("6 for delete data\n");
    printf("7 for display\n");
    printf("8 for exit\n");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertBeg();
                break;
            case 2:
                insertafterData();
                break;
            case 3:
                insertatEnd();
                break;
            case 4:
                deleteBeg();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                deleteAtData();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(1);
            default:
                printf("Invalid Choices\n");
        }
    }
}