#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
main()
{
    struct node *head,*new;
    struct node* insert_end(struct node *head, struct node *new);
    struct node* insert_front(struct node *head, struct node *new);
    struct node* delete_front(struct node *head,struct node *new);
    struct node* delete_end(struct node *head);
    void display(struct node *head);
    head=NULL;
    int n,i;
    printf("enter the number\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d",&new->data);
        head=insert_end(head,new);
    }
    head=delete_end(head);
    //count(head);
    display(head);

}
struct node* insert_end(struct node *head, struct node *new)
{
    struct node *temp;
    if(head==NULL)
    {
        head=new;
        new->next=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=NULL;
    }

}
struct node* insert_front(struct node *head, struct node *new)
{
    if(head==NULL)
    {
        head=new;
        new->next=NULL;
    }
    else
    {
        new->next=head;
        head=new;
    }
}
 struct node* delete_front(struct node *head,struct node *new)
 {
   struct node* temp;
    if(head==NULL)
  {
      printf("sll is empty");
  }


          else if(head->next!=NULL)
          {
              printf("node delete\n");
              printf("%d",&head->data);
              free(head);
              head=NULL;
          }
          else
          {
            temp=head;
            head=head->next;
            printf("node delete");
            printf("%d\n",&temp->data);
            free(head);
          }


      }
 struct node* delete_end(struct node *head)
 {
    struct node* cur,*temp;
    if(head==NULL)
    {
        printf("sll is empty\n");
    }
    else if(head->next==NULL)
    {
        printf("node detele\n");
        printf("%d\n",head->data);
        free(head);
    }
    else
    {
        temp=head;
        while(temp->next=NULL)
        {
            cur=temp;
            temp=temp->next;
        }
        cur->next=NULL;
        printf("node delete");
        printf("%d\n",temp->data);
        free(temp);
    }
}
void display(struct node *head)
{
        struct node *temp;
    temp=head;
    while(temp->next=NULL)
    {
        printf("node=%d\n",temp->data);

        temp=temp->next;
    }
    printf("node=%d\n",temp->data);
}
