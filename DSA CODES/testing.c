  #include<stdio.h>
  #define NULL 0
  struct library
  {
      int token;
      struct library *link;
  };
  typedef struct library s;
   s *head,*ptr,*start,*temp,*cur;
   int n;
 s* insert_end(s *head,s *ptr);
       void count(s *head);
       s* delete(s *head);
       void display(s *head);
   main()
   {
       head=NULL;
       int i;

       printf("enter the number of students\n");
       scanf("%d",&n);
       if(n>0)
       {
       for(i=0;i<n;i++)
       {
           ptr=(s*)malloc(sizeof(s));
           printf("enter the token number of student %d\n",i+1);
           scanf("%d",&ptr->token);
          if(ptr->token==1||ptr->token==2||ptr->token==3)
           {
               head=insert_end(head,ptr);
           }
            else
           {
               printf("Invalid token number\n");
           }

       }
       count(head);
       //display(head);
       head=delete(head);
       display(head);
       }
       else
       {
           printf("Invalid number of students\n");
       }
   }
   s* insert_end(s *head,s *ptr)
   {
       if(head==NULL)
       {
           head=ptr;
           ptr->link=NULL;
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
   void count(s *head)
   {
       start=head;
       int i=0,r=0,p=0;
       while(start!=NULL)
       {
           if(start->token==1)
           {
               i++;
           }
           else if(start->token==2)
           {
               r++;
           }
           else if(start->token==3)
           {
               p++;
           }
           start=start->link;
       }
       printf("students issued book=%d\n",i);
        printf("students returned book=%d\n",r);
         printf("students returned with penalty book=%d\n",p);
   }
   s* delete(s *head)
   {
       start=head;
       s *next;
        if(head->token==1)
               {
                   temp=start;
                   head=start->link;
                   printf("librarian issued the book:\n");
                   printf("student token no.=%d\n",start->token);
                   free(temp);
               }
               cur=start;
               start=start->link;
       while(start!=NULL)
       {

           if(start->token==1)
           {
                   temp=start;
                   cur->link=start->link;
                   printf("librarian issued the book:\n");
                   printf("student token no.=%d\n",start->token);
                   free(temp);

           }

           cur=start;
           start=start->link;
       }
       return(head);
   }
   void display(s *head)
   {
       start=head;
       printf("remaining students are :\n");
     while(start!=NULL)
     {
         printf("student token no.=%d\n",start->token);
         start=start->link;
     }
   }
