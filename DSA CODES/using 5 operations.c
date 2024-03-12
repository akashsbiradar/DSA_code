#include<stdio.h>
#define NULL 0
struct book
{
    char name[30];
    char author[30];
    float price;
    struct book *link;
};
struct book *start,*cur;
main()
{
    struct book *head,*ptr;
    int ch,pos;
    head=NULL;
    struct book* insert_front(struct book*head,struct book*ptr);
    struct book* insert_end(struct book*head,struct book*ptr);
    struct book* delete_front(struct book*head);
    struct book* delete_end(struct book*head);
    void display(struct book*head);
    int count_node(struct book*head);
    struct book* insert_pos(struct book* head,struct book *ptr);
    do
    {
        printf("1.INSERT NODE AT FRONT\n");
        printf("2.INSERT NODE AT END\n");
        printf("3.DELETE NODE AT FRONT\n");
        printf("4.DELETE NODE AT FRONT\n");
        printf("5.DISPLAY THE NODES\n");
        printf("6.COUNT A NUMBER OF NODES\n");
        printf("7.INSERT A NODE AT GIVEN POSITION\n");
        printf("8.EXIT\n");

        printf("enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: ptr=(struct book*)malloc(sizeof(struct book));
             printf("enter the details of book\n");
             scanf("%s%s%f",&ptr->name,&ptr->author,&ptr->price);
             head=insert_front(head,ptr);
             break;

             case 2: ptr=(struct book*)malloc(sizeof(struct book));
             printf("enter the details of book\n");
             scanf("%s%s%f",&ptr->name,&ptr->author,&ptr->price);
             head=insert_end(head,ptr);
             break;

             case 3:
            if(head==NULL)
             {
                printf("CSLL is empty\n");
             }
             else
             {
                 head=delete_front(head);
             }
             break;
             case 4:
                if(head==NULL)
                {
                    printf("CSLL is empty\n");
                }
                else
                {
                    head=delete_end(head);
                }
                break;
             case 5:
                if(head==NULL)
                {
                    printf("CSLL is empty\n");
                }
                else
                {
                   display(head);
                }
                break;

             case 6: if(head==NULL)
                     {
                         printf("CSLL is empty\n");
                     }
                     else
                     {
                         c=count_node(head);
                         printf("total number of nodes=%d\n",c);
                     }
                     break;
              case 7: printf("enter the position\n");
                 scanf("%d",&pos);
                 if(pos<1 || pos>count_node(head)+1)
                 {
                     printf("Invalid position\n");
                 }

                 else
                 {
                     ptr=(struct book*)malloc(sizeof(struct bok));
                   printf("enter the details of book\n");
                   scanf("%s%s%f",&ptr->name,&ptr->author,&ptr->price);
                   if(pos==1)
                   {
                       head=insert_at_front(head,ptr);
                   }
                   else if(pos==count_node(head)+1)
                   {
                       head=insert_at_end(head,ptr);
                   }
                   else
                   {

                   }
                }

             case 8: exit(0);
             break;

        }
    }while(ch!=8);
}

    struct book* insert_front(struct book*head,struct book*ptr)
    {
        if(head==NULL)
        {
          head=ptr;
          head->link=head;
        }

        else
        {
            start=head;
            while(start->link!=head)
            {
                start=start->link;
            }
            start->link=ptr;
            ptr->link=head;
            head=ptr;
        }
        return(head);
    };

        struct book* insert_end(struct book*head,struct book*ptr)
        {
            if(head==NULL)
            {
                head=ptr;
                head->link=head;
            }
            else
            {
              start=head;
              while(start->link!=head)
              {
                  start=start->link;
              }
              start->link=ptr;
              ptr->link=head;
            }
            return(head);
        };

     struct book* delete_front(struct book*head)
     {
         if(head->link==head)
         {
             printf("node deleted\n");
             printf("name=%s\t author=%s\t price=%f\n",head->name,head->author,head->price);
             free(head);
             head=NULL;
         }
         else
         {
           start=head;
           cur=head;
           while(start->link!=head)
           {
               start=start->link;
           }
           start->link=head->link;
           head=head->link;
           printf("node deleted is\n");
           printf("name=%s\t author=%s\t price=%f\n",cur->name,cur->author,cur->price);
           free(cur);
         }
         return(head);
     };
      struct book* delete_end(struct book*head)
      {
          if(head->link==head)
          {
             printf("node deleted\n");
             printf("name=%s\t author=%s\t price=%f\n",head->name,head->author,head->price);
             free(head);
             head=NULL;
          }
          else
          {
              start=head;
              while(start->link!=NULL)
              {
                  cur=start;
                  start=start->link;
              }
              cur->link=head;
              printf("node deleted\n");
             printf("name=%s\t author=%s\t price=%f\n",start->name,start->author,start->price);
             free(start);

          }
          return(head);
      };

        void display(struct book*head)
        {
            start=head;
            while(start->link!=head)
            {
              printf("name=%s\t author=%s\t price=%f\n",start->name,start->author,start->price);
              start=start->link;
            }
            printf("name=%s\t author=%s\t price=%f\n",start->name,start->author,start->price);
        };


        int count_node(struct book *head)
        {
            int count=0;
            start=head;
            while(start->link!=head)
            {
                count++;
                start=start->link;
            }
            count++;
            return(count);
        };
