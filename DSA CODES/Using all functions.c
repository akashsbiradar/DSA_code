  #include<stdio.h>
  #define NULL 0
  struct player
  {
      char name[30];
      int id;
      int score;
      struct player *link;
  };

  struct player *head,*ptr,*start,*temp,*prev,*cur;
  int i,ch,pos,cnt;

  main()
  {
      struct player* insert_front(struct player *head,struct player *ptr);
      struct player* insert_end(struct player *head,struct player *ptr);
      struct player* delete_front(struct player *head);
      struct player* delete_end(struct player *head);
      void display(struct player *head);
      int count(struct player *head);
      struct player* insert_pos(struct player *head,struct player *ptr,int pos);
      struct player* delete_pos(struct player *head,int pos);
      struct player* max_score(struct player *head);
      struct player* search_name(struct player *head);
      struct player* next_id(struct player *head);
      struct player* left_id(struct player *head);
      struct player* insert_next(struct player *head,struct player *ptr);
      struct player* delete_before(struct player *head);

      do
      {
          printf("1.INSERT PLAYER AT FRONT\n");
          printf("2.INSERT PLAYER AT END\n");
          printf("3.DELETE PLAYER AT FRONT\n");
          printf("4.DELETE PLAYER AT END\n");
          printf("5.DISPLAY PLAYERS\n");
          printf("6.COUNT NUMBER OF PLAYERS\n");
          printf("7.INSERT PLAYER AT POSITION\n");
          printf("8.DELLTE PLAYER AT POSITION\n");
          printf("9.DETAILS OF PLAYER HIGHEST SCORE\n");
          printf("10.SEARCH PLAYER BY NAME\n");
          printf("11.DETAILS OF PLAYER PLAYS AFTER GIVEN PLAYER\n");
          printf("12.DETAILS OF PLAYER PLAYS BEFORE GIVEN PLAYER\n");
          printf("13.INSERT A PLAYER AFTER A GIVEN ID\n");
          printf("14.DELETE A PLAYER before A GIVEN ID\n");
          printf("15.EXIT\n");

          printf("enter the choice\n");
          scanf("%d",&ch);

      switch(ch)
      {
          case 1: ptr=(struct player*)malloc(sizeof(struct player));
              printf("enter the details of player\n");
              scanf("%s%d%d",&ptr->name,&ptr->id,&ptr->score);
              head=insert_front(head,ptr);
              break;
          case 2:  ptr=(struct player*)malloc(sizeof(struct player));
              printf("enter the details of player\n");
              scanf("%s%d%d",&ptr->name,&ptr->id,&ptr->score);
              head=insert_end(head,ptr);
              break;
          case 3: if(head==NULL)
               {
                  printf("CSLL is empty\n");
               }
               else
               {
                   head=delete_front(head);
               }
               break;
          case 4:  if(head==NULL)
               {
                  printf("CSLL is empty\n");
               }
               else
               {
                   head=delete_end(head);
               }
               break;
           case 5:if(head==NULL)
                  {
                      printf("CSLL is empty\n");
                  }
                  else
                  {
                      display(head);
                  }
                  break;
            case 6:cnt=count(head);
                 printf("number of players=%d\n",cnt);
                 break;
            case 7: printf("enter the position\n");
                  scanf("%d",&pos);
                  if(pos<1 || pos>count(head)+1)
                  {
                      printf("Invalid position\n");
                  }
                  else
                  {
                    ptr=(struct player*)malloc(sizeof(struct player));
                   printf("enter the details of player\n");
                   scanf("%s%d%d",&ptr->name,&ptr->id,&ptr->score);
                   if(pos==1)
                   {
                       head=insert_front(head,ptr);
                   }
                   else if(pos==count(head)+1)
                   {
                       head=insert_end(head,ptr);
                   }
                   else
                   {
                       head=insert_pos(head,ptr,pos);
                   }
                  }
              break;
          case 8:printf("enter the position\n");
                  scanf("%d",&pos);
                  if(pos<1 || pos>count(head))
                  {
                      printf("Invalid position\n");
                  }
                  else
                  {
                      if(pos==1)
                      {
                          head=delete_front(head);
                      }
                      else if(pos=count(head))
                      {
                          head=delete_end(head);
                      }
                      else
                      {
                          head=delete_pos(head,pos);
                      }
                  }
                  break;
           case 9:if(head==NULL)
               {
               printf("CSLL if empty\n");
               }
              else
               {
               head=max_score(head);
               }
               break;
           case 10: if(head==NULL)
                  {
                      printf("CSLL is empty\n");
                  }
                  else
                  {
                     head=search_name(head);
                  }
                  break;
            case 11:if(head==NULL)
                   {
                       printf("There are no players\n");
                   }
                   else
                   {
                       head=next_id(head);
                   }
                   break;
             case 12: if(head==NULL)
                     {
                       printf("There are no players\n");
                     }
                   else
                   {
                       head=left_id(head);
                   }
                   break;
             case 13: if(head==NULL)
                     {
                         printf("there are no players\n");
                     }
                     else
                     {
                        ptr=(struct player*)malloc(sizeof(struct player));
                        printf("enter the details of player\n");
                        scanf("%s%d%d",&ptr->name,&ptr->id,&ptr->score);
                        head=insert_next(head,ptr);
                     }
                     break;
             case 14:if(head==NULL)
                     {
                         printf("there are no players\n");
                     }
                     else
                     {
                         head=delete_before(head);
                     }
                     break;

             case 15:exit(0);break;
             default:printf("Invalid choices\n");break;
      }

    }while(ch!=15);
  }

  struct player* insert_front(struct player *head,struct player *ptr)
  {
    if(head==NULL)
    {
        head=ptr;
        ptr->link=head;
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
  }

    struct player* insert_end(struct player *head,struct player *ptr)
  {
    if(head==NULL)
    {
        head=ptr;
        ptr->link=head;
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
  }

  struct player* delete_front(struct player *head)
  {
      if(head->link==head)
      {
          printf("player deleted is\n");
          printf("player name=%s\t id=%d\t score=%d\n",head->name,head->id,head->score);
          free(head);
          head=NULL;
      }
      else
      {
          start=head;
          while(start->link!=head)
          {
              start=start->link;
          }
          temp=head->link;
          printf("player deleted is\n");
          printf("player name=%s\t id=%d\t score=%d\n",head->name,head->id,head->score);
          free(head);
          start->link=temp;
          head=temp;
      }
      return(head);
  }

  struct player* delete_end(struct player *head)
  {
    if(head->link==NULL)
      {
          printf("player deleted is\n");
          printf("player name=%s\t id=%d\t score=%d\n",head->name,head->id,head->score);
          free(head);
          head=NULL;
      }
      else
      {
          start=head;
          while(start->link!=head)
          {
              temp=start;
              start=start->link;
          }
          printf("player deleted is\n");
          printf("player name=%s\t id=%d\t score=%d\n",start->name,start->id,start->score);
          free(start);
          temp->link=head;
       }
       return(head);
  }

  void display(struct player *head)
  {
      start=head;
      while(start->link!=head)
      {
        printf("player name=%s\t id=%d\t score=%d\n",start->name,start->id,start->score);
        start=start->link;
      }
      printf("player name=%s\t id=%d\t score=%d\n",start->name,start->id,start->score);
  }

  int count(struct player *head)
  {
      int c;
      if(head==NULL)
      {
          return(0);
      }
      else
      {
          start=head;
          while(start->link!=head)
          {
              c++;
              start=start->link;
          }
          c++;
          return(c);
      }
  }

  struct player* insert_pos(struct player *head,struct player *ptr,int pos)
  {
      int p=1;
      start=head;
      while(p!=pos)
      {
          temp=start;
          start=start->link;
          p++;
      }
      temp->link=ptr;
      ptr->link=start;
      return(head);
  }

  struct player* delete_pos(struct player *head,int pos)
  {
      int p=1;
      struct player *cur;
      start=head;
      while(p!=pos)
      {
          temp=start;
          start=start->link;
          p++;
      }
      cur=start->link;
       printf("player deleted is\n");
       printf("player name=%s\t id=%d\t score=%d\n",start->name,start->id,start->score);
       free(start);
       temp->link=cur;
       return(head);
  }

  struct player* max_score(struct player *head)
  {
      int max;
      start=head;
      max=head->score;
      while(start->link!=head)
      {
          if(start->score>max)
          {
              max=start->score;
              temp=start;
          }
          start=start->link;
      }
      if(start->score>max)
      {
        printf("player name=%s\t id=%d\t score=%d\n",start->name,start->id,start->score);
      }
      else
      {
        printf("player name=%s\t id=%d\t score=%d\n",temp->name,temp->id,temp->score);
      }
      return(head);
  }

  struct player* search_name(struct player *head)
  {
      char pname[30];
      int status=0;
      printf("enter the required player name\n");
      scanf("%s",&pname);
      start=head;
      while(start->link!=head)
      {
          if(strcmp(start->name,pname)==0)
          {
            status=1;
            break;
          }
          start=start->link;
      }
      if(strcmp(start->name,pname)==0)
      {
        status=1;
      }
        if(status==0)
        {
            printf("player is not plating the game\n");
        }
      else
      {
          printf("player is playing the game\n");
      }

      return(head);
  }

  struct player* next_id(struct player *head)
  {
      int pid,status=0;
      printf("enter the reqiured id\n");
      scanf("%d",&pid);
      start=head;
      while(start->link!=head)
      {
          if(start->id==pid)
          {
              temp=start->link;
              printf("player name=%s\t id=%d\t score=%d\n",temp->name,temp->id,temp->score);
              status=1;
          }
          start=start->link;
      }
      if(start->id==pid)
      {
        temp=start->link;
        printf("player name=%s\t id=%d\t score=%d\n",temp->name,temp->id,temp->score);
        status=1;
      }
        if(status==0)
        {
            printf("player id is not found\n");
        }

      return(head);
  }

   struct player* left_id(struct player *head)
   {
      struct player *cur;
      int pid,status=0;
      printf("enter the reqiured id\n");
      scanf("%d",&pid);
      cur=head;
     while(cur->link!=head)
      {
       cur=cur->link;
      }
      start=head;
      while(start->link!=head)
       {
          if(start->id==pid)
           {
            if(head->id==pid)
            {
                printf("player name=%s\t id=%d\t score=%d\n",cur->name,cur->id,cur->score);
                 status=1;
            }

            else
                {
                printf("player name=%s\t id=%d\t score=%d\n",temp->name,temp->id,temp->score);
                 status=1;
                }


           }
          temp=start;
          start=start->link;
       }

      if(start->id==pid)
         {
        printf("player name=%s\t id=%d\t score=%d\n",temp->name,temp->id,temp->score);
        status=1;
         }
      if(status==0)
            printf("player id is not found\n");


      return(head);
   }

   struct player* insert_next(struct player *head,struct player *ptr)
   {
       int pid,status=0;
       printf("enter the pid\n");
       scanf("%d",&pid);
       start=head;
       while(start->link!=head)
       {
           temp=start->link;
           if(start->id==pid)
           {
               start->link=ptr;
               ptr->link=temp;
               status=1;

           }
           start=start->link;
       }
       if(start->id==pid)
       {
           start->link=ptr;
           ptr->link=head;
           status=1;
       }
       if(status==0)
       {
           printf("player is not found\n");
       }
       return(head);
   }
 struct player* delete_before(struct player *head)
 {
     int pid,status=0;
       printf("enter the pid\n");
       scanf("%d",&pid);
       start=head;
       while(start->link!=head)
       {
           if(start->id==pid)
           {
              if(start==head)
              {
                  printf("there is no player\n");
                  status=1;
              }
              else if(head->link=start)
              {
                  temp=head;
                  head=start;
                  printf("player deleted is\n");
                printf("player name=%s\t id=%d\t score=%d\n",temp->name,temp->id,temp->score);
                free(temp);
                status=1;
              }
              else
                {
                    temp=head;
                  while(temp->link!=cur)
                  {
                      temp=temp->link;
                  }
                  temp->link=start;
                  printf("player deleted is\n");
                printf("player name=%s\t id=%d\t score=%d\n",cur->name,cur->id,cur->score);
                free(cur);
                status=1;
                }
              }
           temp=cur;
           cur=start;
           start=start->link;
       }
       if(start->id==pid)
       {
           temp->link=start;
           printf("player deleted is\n");
                printf("player name=%s\t id=%d\t score=%d\n",cur->name,cur->id,cur->score);
                free(cur);
                status=1;
       }
       if(status==0)
       {
           printf("palyer not found\n");
       }
       return(head);

 }
