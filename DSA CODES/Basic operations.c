#include<stdio.h>
#define size 5
main()
{
    int queue[size];
    int f=-1,r=-1,ch,ele;
    int insert(int queue[],int f,int r,int ele);
    int delete(int queue[],int f,int r);
    void display(int queue[],int f,int r);
    do
    {
        printf("1--insert a element in queue\n");
        printf("2--delete a element in queue\n");
        printf("3--display a elements in queue\n");
        printf("4--exit\n");

        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:if(r==size-1)
               {
                printf("queue is full\n");
               }
               else
               {
                printf("enter the element\n");
                    scanf("%d",&ele);
                    r=insert(queue,f,r,ele);
               }
               break;
           case 2:if(f==-1 && r==-1)
                    printf("queue is empty\n");
                   else if(f==r)
    {
        printf("elemet deleted is=%d\n",queue[f]);
        f=-1;
        r=-1;
    }
                    else
                    {
                        f=delete(queue,f,r);
                    }
                    break;

           case 3: if(f==-1 && r==-1)
                    printf("queue is empty\n");
                    else
                    {
                        display(queue,f,r);
                    }
                    break;
            case 4:exit(0);break;
            default:printf("invalid choice\n");break;
        }

    }while(ch!=4);

}

int insert(int queue[],int f,int r,int ele)
{
    if(f==-1 && r==-1)
    {
        f++;
        r++;
        queue[r]=ele;
    }
    else
    {
        r++;
        queue[r]=ele;
    }
    return(r);
    return(f);
}
int delete(int queue[],int f,int r)
{



         printf("elemet deleted is=%d\n",queue[f]);
        f++;

    return(f);
    //return(r);
}
void display(int queue[],int f,int r)
{
    int i;
    i=f;
    printf("elements in queue are\n");
    while(i!=r+1)
    {
        printf("%d\n",queue[i]);
        i++;
    }
}
