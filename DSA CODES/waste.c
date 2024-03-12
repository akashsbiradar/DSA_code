 #include<stdio.h>
 #define size 30
 struct patient
 {
     char name[30];
     int id,a;
 };
 main()
 {
     struct patient h;
     int f,r,ch;
     struct patient q[size];
     f=-1;
     r=-1;
     int insert(struct patient q[],int f,int r,struct patient h);
     int delete(struct patient q[],int f,int r);
     void display(struct patient q[],int f,int r);
     void avg(struct patient q[],int f,int r);
     void young(struct patient q[],int f,int r);
     do
     {
         printf("1--insert the patient\n");
         printf("2--delete the patient\n");
         printf("3--display the patient\n");
         printf("4--average age of the patient\n");
         printf("5--young patient in queue\n");
         printf("6--exit\n");

         printf("enter your choice\n");
         scanf("%d",&ch);

         switch(ch)
         {
             case 1:if(r==size-1)
                     printf("Q is full\n");
                     else
                     {
                         printf("enter the name id age of patient\n");
                         scanf("%s%d%d",&h.name,&h.id,&h.a);
                     if(f==-1 && r==-1)
                      {
                        f++;
                        r++;
                        strcpy(q[r].name,h.name);
                        q[r].id=h.id;
                        q[r].a=h.a;
                      }
                      else
                      {
                          r=insert(q,f,r,h);
                      }
                     }
                     break;
             case 2:if(f==-1 && r==-1)
                        printf("Q is empty\n");
                        else if(f==r)
                        {
                            printf("patient deleted is\n name=%s\t id=%d\t age=%d\n",q[f].name,q[f].id,q[f].a);
                            f=-1;
                            r=-1;
                        }
                        else
                        {
                            f=delete(q,f,r);
                        }
                        break;
              case 3:  if(f==-1 && r==-1)
                        printf("Q is empty\n");
                        else
                        {
                            display(q,f,r);
                        }
                        break;
              case 4: if(f==-1 && r==-1)
                        printf("Q is empty\n");
                        else
                        {
                            avg(q,f,r);
                        }
                        break;
              case 5:  if(f==-1 && r==-1)
                        printf("Q is empty\n");
                        else
                        {
                            young(q,f,r);

                        }
                        break;
               case 6: exit(0);
                       break;
                       default:printf("Invalid choice\n");
                                  break;
         }

     }while(ch!=6);

 }

int insert(struct patient q[],int f,int r,struct patient h)
{
    r++;
    strcpy(q[r].name,h.name);
    q[r].id=h.id;
    q[r].a=h.a;
    return(r);
}

int delete(struct patient q[],int f,int r)
{
     printf("patient deleted is\n name=%s\t id=%d\t age=%d\n",q[f].name,q[f].id,q[f].a);
      f++;
    return(f);
}
void display(struct patient q[],int f,int r)
{
    int i;
    for(i=f;i<=r;i++)
    {
        printf("name=%s\t id=%d\t age=%d\n",q[i].name,q[i].id,q[i].a);
    }
}

void avg(struct patient q[],int f,int r)
{
    int tot=0,c=0,i;
    float ag;
    for(i=f;i<=r;i++)
    {
        tot=tot+q[i].a;
        c++;
    }
    ag=(float)tot/c;
    printf("average age of Q=%f\n",ag);
}
void young(struct patient q[],int f,int r)
{
    int min,i,y;
    min=q[f].a;

    for(i=f; i<=r; i++)
    {
        if(q[i].a < min)
        {
            y=i;
            min=q[i].a;
        }
    }

    printf("Younger patient in Queue is:\n");
    printf("Name:%s\tID:%d\tAge:%d\n",q[y].name,q[y].id,q[y].a);
}
