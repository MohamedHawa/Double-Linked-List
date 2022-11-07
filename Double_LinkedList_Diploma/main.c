#include <stdio.h>
#include <stdlib.h>
////////////////////////////////////
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;

} node_t;
node_t init;
//init->prev=NULL;
//init->next=NULL;

node_t *head=NULL;
////////////////////////////////
void InsertNode(int value);
void InsertAnyPositions(int value,int pos);
void DeleteNodeFirst(void);
void DeleteNodeLast(void);
void DeleteNodeAnyPositions(int pos);
int ElementsCounts(void);
int Display(void);


int main()
{
    InsertNode(10);
    InsertNode(20);
    InsertNode(30);
    InsertNode(40);
    InsertNode(50);
    InsertAnyPositions(1000,2);
    DeleteNodeFirst();
    DeleteNodeLast();
    DeleteNodeAnyPositions(3);


    Display();


    return 0;
}
/////////////////////////////////////////////////////
/*this function insert node in last or insert linked list is empty */
void InsertNode(int value)
{
    node_t *temp=head;
    node_t *newnode=NULL;
    newnode=(node_t*)malloc(sizeof(node_t));
    if(NULL==head)
    {

        if(NULL==newnode)
        {
            printf("SORY NULL POINTER\N");
        }
        else
        {
            newnode->data=value;
            newnode->next=NULL;
            newnode->prev=NULL;
            head=newnode;



        }
    }

    else
    {

        if(NULL==newnode)
        {
            printf("SORY NULL POINTER\N");
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            newnode->data=value;
            newnode->next=NULL;
            temp->next=newnode;
            newnode->prev=temp;



        }

    }



}
////////////////////////////////////////////////
/*this function insert node at any postion*/
void InsertAnyPositions(int value,int pos)
{
    int i=0;
    node_t *newnode=NULL;
    node_t *temp=head;
    newnode=(node_t*)malloc(sizeof(node_t));

    if(NULL==newnode)
    {
        printf("SORY NULL POINTER\N");
    }
    else
    {
        if(pos==0)
        {
            newnode->data=value;
            newnode->next=head;
            newnode->prev=NULL;
            head=newnode;
        }
        else if(pos==ElementsCounts())
        {
            InsertNode(value);
        }
        else
        {
            for(i=0; i<pos; i++) // 0<=2 1<=2 2<=2
            {
                temp=temp->next;

            }

            newnode->data=value;
            newnode->prev=temp->prev;
            temp->prev->next=newnode;
            temp->prev=newnode;
            newnode->next=temp;



        }




    }

}
//////////////////////////////////////////////////////////
int ElementsCounts(void)
{
    int counter=0;
    node_t *temp=head;

    while(temp!=NULL)
    {
        counter++;
        temp=temp->next;
    }
    return counter;

}
int Display(void)
{
    node_t *temp=head;
    if(NULL==head)
    {
        printf("SORRY  linked list is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%i\t",temp->data);
            temp=temp->next;
        }
        printf("\n");

    }


}
///////////////////////////////////////////////
void DeleteNodeFirst(void)
{
    node_t *delet_temp=head;

    if(NULL==head)
    {
        printf("linked list is empty\N");
    }
    else
    {
        head=head->next;
        free(delet_temp);


    }


}
////////////////////////////////////////////////////
void DeleteNodeLast(void)
{
    node_t *delet_temp=head;

    if(NULL==head)
    {
        printf("linked list is empty\N");
    }
    else
    {
        while(delet_temp->next!=NULL)
        {
            delet_temp=delet_temp->next;
        }
        delet_temp->prev->next=NULL;
        free(delet_temp);


    }


}
//////////////////////////////////////////////
void DeleteNodeAnyPositions(int pos)
{

    int i=0;
    node_t *delet_temp=head;

    if(head==NULL)
    {
        printf("linked list is empty\N");
    }
    else
    {
        if(pos==0)
        {
            DeleteNodeFirst();
        }
        else if(pos==ElementsCounts())
        {
            DeleteNodeLast();
        }
        else
        {
            for(i=0; i<pos; i++) // 0<=2 1<=2 2<=2
            {
                delet_temp=delet_temp->next;

            }
            delet_temp->prev->next=delet_temp->next;
            free(delet_temp);




        }

    }

}
///////////////////////////////////////////////////
