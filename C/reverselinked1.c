#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *next;    
}*head=NULL;
typedef struct Node node;
void create(int data)
{
    node *temp,*p;
    temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
            temp->data=data;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
}

int check_Empty()
{
    if(head==NULL)
    return 1;
    else
    return 0;
}

void display()
{
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void add_at_begin(int data)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=head;
    head=temp;
}
int get_pos(int data)
{
    node *temp;
    temp=head;
    int c=0,c1=0;
    while(temp!=NULL)
    {
        c++;
        if(temp->data==data)
        {
            c1++;
            break;
        }
        temp=temp->next;
    }
    if(c1==0)
    {
        return -1;
    }
    return c;
}
 void add_at_position(int data,int pos)
 {
     node *temp,*posi;
      temp=(node*)malloc(sizeof(node));
     int c=1;
     
    temp->data=data;
    posi=head;
     while(c!=pos)
     {
         posi=posi->next;
         c++;
    }
    temp->next=posi->next;
    posi->next=temp;
 }
 
int length()
{
    node *p;
    p=head;
    int count=0;
    while(p!=NULL)
    {
        p=p->next;
        count++;
    }
    return count;
}

void delete_at_last()
{
    node *temp,*p;
    temp=head;
    p=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
        
    }

    p=temp->next;
    printf("%d",p->data);
    temp->next=NULL;
    free(p);
    
        
}

void delete_at_location(int pos)
{
    node *temp,*prev;
    temp=head;
    if(pos==1)
    {
        head=head->next;
        free(temp);
    }
    else{
    int c=1;
    while(c!=pos)
    {
        prev=temp;
        temp=temp->next;
        c++;
    }
    prev->next=temp->next;
    free(temp);
}
}

void reverse()
{
    node *temp,*temp1;
    temp=NULL,temp1=NULL;
    while(head!=NULL)
    {
        temp1=head->next;
        head->next=temp;
        temp=head;
        head=temp1;
        
    }
    head=temp;
}

int main()
{
    int choice;
    int x,y;
    int q;
    int po;
    scanf("%d",&q);
   
    while(q--)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                {    
                    scanf("%d",&x);
                    create(x);
                    display();
                    break;
                }
            case 2:
                scanf("%d",&x);
                add_at_begin(x);
                display();
                break;
            case 3:
                scanf("%d%d",&x,&y);
                po=get_pos(x);
                if(po==-1)
                {
                    create(y);
                }
                else{
                add_at_position(y,po);
                }    
                display();
                break;
            case 4:
                scanf("%d%d",&x,&y);
                po=get_pos(x);
                if(po==-1)
                {
                    add_at_begin(y);
                }
                else{
                add_at_position(y,po-1);
                }    
                display();
                
                break;
            case 5:
                scanf("%d",&x);
                po=get_pos(x);
                delete_at_location(po);
                display();
                break;
            case 6:
                    scanf("%d",&x);
                    printf("%d\n",get_pos(x));
                break;
            case 7:
                {
                    reverse();
                    display();
                    break;
                }
            

        }
    }
    return 0;
}
