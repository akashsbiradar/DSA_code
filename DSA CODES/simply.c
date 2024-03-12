#include<stdio.h>
struct phone
{
    char name[30];
    char tid[30];
    int uid;
    int bid;
    float amount;
    char date[30];
    char time[30];
};

struct phone *ptr;
int i;
main()
{
    int n;
    printf("enter the number of transactions\n");
    scanf("%d",&n);
    ptr=(struct phone*)malloc(n*sizeof(struct phone));
    void r(struct phone *ptr,int n);
    void d(struct phone *ptr,int n);
    void search_id(struct phone *ptr,int n);
    if(n<0)
    {
        printf("invalid transactions\n");
    }
    else
    {
        r(ptr,n);
        d(ptr,n);
        search_id(ptr,n);
    }
}
void r(struct phone *ptr,int n)
{

    printf("enter the details of transaction\n");
    for(i=0;i<n;i++)
    {
        scanf("%s%s%d%d%f%s%s",&ptr->name,&ptr->tid,&ptr->uid,&ptr->bid,&ptr->date,&ptr->time);
        ptr++;
    }
}

void d(struct phone *ptr,int n)
{
    int i;
    printf(" details of transaction\n");
    for(i=0;i<n;i++)
    {
        printf("name=%s\t transaction id=%s\t user id=%d\t benifitiary id=%d\t amount=%f\t date=%s\t time=%s\n",ptr->name,ptr->tid,ptr->uid,ptr->bid,ptr->date,ptr->time);
        ptr++;
    }
}
void search_id(struct phone *ptr,int n)
{
    char aid[30];
    printf("enter the required id details\n");
    scanf("%s",&aid);
    for(i=0; i<n; i++)
    {
        if(strcmp(ptr->tid,aid)==0)
        {
            printf("name=%s\t transaction id=%s\t user id=%d\t benifitiary id=%d\t amount=%f\t date=%s\t time=%s\n",ptr->name,ptr->tid,ptr->uid,ptr->bid,ptr->date,ptr->time);
        }
        ptr++;
    }
}

