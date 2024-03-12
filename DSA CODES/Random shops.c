#include<stdio.h>
#define NULL 0
struct shop
{
    char name[30];
    float p;
    struct shop *link;
};
typedef struct shop s;
s *head,*start,*temp,*cur,*ptr;
main()
{
    head=NULL;
    int n,i;
    printf("enter the number of customers\n");
    scanf("%d",&n);
    s* insert(s *head,s *ptr);
    void display(s *head);
    void disc(s *head);
    void max(s *head);
    for(i=0;i<n;i++)
    {
       ptr=(s*)malloc(sizeof(s));
        printf("enter the details of customer %d\n",i+1);
        scanf("%s%f",&ptr->name,&ptr->p);
        head=insert(head,ptr);
    }
    display(head);
    disc(head);
    max(head);
}

s* insert(s *head,s *ptr)
{
    if(head==NULL)
    {
        head=ptr;
        head->link=NULL;
    }
    else
    {
        start=head;
        while(start->link!=NULL)
        {
            start=start->link;
        }
        start->link=ptr;
        ptr->link=NULL;
    }
    return(head);
}

void display(s *head)
{
    start=head;
    float tot=0;
    printf("customer details present in shop\n");
    while(start!=NULL)
    {
        printf("name =%s\t price=%f\n",start->name,start->p);
         tot=tot+start->p;
        start=start->link;
    }
  printf("total purcahse amount=%f\n",tot);
}
void disc(s *head)
{
    start=head;
    int c=0;

    while(start!=NULL)
    {
        if(start->p>10000)
        {
            c++;

        }
        start=start->link;
    }
    printf("total number of customer got discount=%d\n",c);

}

void max(s *head)
{
    start=head;
    float max;
    max=head->p;
    while(start!=NULL)
    {
        if(start->p>max)
        {
            max=start->p;
            temp=start;
        }
        start=start->link;
    }
    printf("food coupon got for :\n");
    printf("name =%s\t price=%f\n",temp->name,temp->p);
}
