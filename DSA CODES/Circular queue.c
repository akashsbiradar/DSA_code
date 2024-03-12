#include<stdio.h>
#define size 5

main()
{
int q[size];
int f,r;
int ch,ele;
     f=-1;
   r=-1;
int insert(int q[],int f,int r,int ele);
int delete(int q[],int f,int r);
void display(int q[],int f,int r);

  do
   {
   printf("1---insert\n");
   printf("2---delete\n");
   printf("3---display\n");
   printf("4----exit\n");

   printf("enter your choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
      case 1: if((r+1)%size==f)
                    {
                          printf("Q is full\n");
                    }
                    else if(f==-1 && r==-1)
                       {
                        printf("enter the element to insert\n");
                          scanf("%d",&ele);
                         f=(f+1)%size;
                        r=(r+1)%size;
                         q[r]=ele;
                       }
                    else
                    {
                          printf("enter the element to insert\n");
                          scanf("%d",&ele);
                          r=insert(q,f,r,ele);
                    }
                    break;
     case 2: if(f==-1 && r==-1)
                    {
                        printf("Q is empty\n");
                    }
                    else if(f==r)
                    {
                        printf("element deleted=%d\n",q[f]);
                        f=-1;
                        r=-1;
                    }
                    else
                    {
                        f=delete(q,f,r);

                    }
                    break;
    case 3: display(q,f,r);
                    break;
    case 4: exit(0);break;
    default: printf("Invalid choice\n");break;
   }
}while(ch!=4);
}

int insert(int q[],int f,int r,int ele)
{
         r=(r+1)%size;
        q[r]=ele;
        return(r);
}

int delete(int q[],int f,int r)
{

        printf("element deleted=%d\n",q[f]);
        f =(f+1)%size;
        return(f);

}

void display(int q[],int f,int r)
{
    if(f==-1 && r==-1)
        printf("Q is empty\n");
    else
    {
        int i;
        printf("Q elemets are\n");
        for(i=f;i!=r;i=(i+1)%size)
        {
            printf("%d\t",q[i]);

        }
        printf("%d\t",q[i]);
        printf("\n");
    }
}
