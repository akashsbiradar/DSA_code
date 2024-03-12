#include<stdio.h>
struct song
{
   struct song *prev;
   char tit[30];
   char s_name[30];
   float dur;
   struct song *next;
};

struct song* insert_song_front(struct song *,struct song *);
struct song* insert_song_end(struct song *,struct song *);
struct song* delete_song_front(struct song *);
struct song* delete_song_end(struct song *);
void display_song(struct song*);
struct song* insert_pos(struct song *,struct song *,int pos);
struct song* delete_pos(struct song *,int pos);
int count_song(struct song *head);
struct song *head,*start,*temp,*cur,*ptr;
main()
{
   int ch,pos,count;
   head=NULL;
   do
   {
   printf("1--insert a song at front\n");
   printf("2--insert a song at end\n");
   printf("3--delete a song at front\n");
   printf("4--delete a song at end\n");
   printf("5--display all songs\n");
   printf("6--count number of songs\n");
   printf("7--insert at position\n");

   printf("enter your choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
      case 1: ptr=(struct song*)malloc(sizeof(struct song));
                     printf("enter title, singer name and duration\n");
                     scanf("%s%s%f",&ptr->tit, &ptr->s_name,&ptr->dur);
                     head=insert_song_front(head,ptr);
                     break;
     case 2: ptr=(struct song*)malloc(sizeof(struct song));
                     printf("enter title, singer name and duration\n");
                     scanf("%s%s%f",&ptr->tit, &ptr->s_name,&ptr->dur);
                     head=insert_song_end(head,ptr);
                     break;
    case 3: if(head==NULL)
                      printf("no songs to delete\n");
                      else
                      {
                          head=delete_song_front(head);
                      }
                      break;
    case 4:  if(head==NULL)
                      printf("no songs to delete\n");
                      else
                      {
                          head=delete_song_end(head);
                      }
                      break;
    case 5: if(head==NULL)
                      printf("no songs to display\n");
                      else
                      {
                          display_song(head);
                      }
                      break;
    case 6: count=count_song(head);
             printf("total songs are=%d\n",count);
             break;
    case 7: printf("enter the position\n");
             scanf("%d",&pos);
             if(pos<1 || pos>count_song(head)+1)
                    printf("invalid position\n");

             else
             {
                 ptr=(struct song*)malloc(sizeof(struct song));
                 printf("enter the details of new song\n");
                 scanf("%s%s%f",&ptr->tit, &ptr->s_name,&ptr->dur);

                  if(pos==1)
                 {
                     head=insert_song_front(head,ptr);
                 }
                 else if(pos==count_song(head)+1)
                 {
                     head=insert_song_end(head,ptr);
                 }
                 else
                 {
                     head=insert_pos(head,ptr,pos);
                 }
             }
             break;
     case 8: printf("enter the position\n");
                    scanf("%d",&pos);
                    if(pos<1 || pos>count_song(head))
                         printf("Invalid position\n");
                    else
                    {
                        if(pos==1)
                        {
                            head=delete_song_front(head);
                        }
                        else if(pos==count_song(head))
                        {
                            head=delete_song_end(head);
                        }
                        else
                        {
                            head=delete_pos(head,pos);
                        }
                    }
                    break;
    case 9:exit(0);break;
    default:printf("Invalid choice\n");break;
   }
}while(ch!=9);
}

struct song* insert_song_front(struct song *head, struct song *ptr)
{
   if(head==NULL)
   {
     head=ptr;
     head->next=NULL;
     head->prev=NULL;
   }
   else
   {
      ptr->next=head;
      head->prev=ptr;
      ptr->prev=NULL;
      head=ptr;
   }
    return(head);
}

struct song* insert_song_end(struct song *head, struct song *ptr)
{

  if(head==NULL)
   {
     head=ptr;
     head->next=NULL;
     head->prev=NULL;
   }

   else
   {
       start=head;
       while(start->next!=NULL)
       {
          start=start->next;
       }

       start->next=ptr;
       ptr->prev=start;
       ptr->next=NULL;

   }
   return(head);
}

struct song* delete_song_front(struct song *head)
{
    if(head->next==NULL)
    {
       printf("song deleted\n");
       printf("title=%s\t singer name=%s\t duration=%f\n",head->tit, head->s_name, head->dur);
       free(head);
       head=NULL;
    }
    else
    {
        cur=head;
        printf("song deleted\n");
       printf("title=%s\t singer name=%s\t duration=%f\n",cur->tit, cur->s_name, cur->dur);
       head=head->next;
       free(cur);
       head->prev=NULL;
    }
    return(head);
}


struct song* delete_song_end(struct song *head)
{
    if(head->next==NULL)
    {
       printf("song deleted\n");
       printf("title=%s\t singer name=%s\t duration=%f\n",head->tit, head->s_name, head->dur);
       free(head);
       head=NULL;
    }

    else
    {
        start=head;
        while(start->next!=NULL)
        {
            start=start->next;
        }
        printf("song deleted\n");
       printf("title=%s\t singer name=%s\t duration=%f\n",start->tit, start->s_name, start->dur);
        start->prev->next=NULL;
        free(start);
    }
    return(head);
}




void display_song(struct song *head)
{
    start=head;
    printf("the songs are\n");
    while(start!=NULL)
    {
         printf("title=%s\t singer name=%s\t duration=%f\n",start->tit, start->s_name, start->dur);
         start=start->next;
    }
}

int count_song(struct song *head)
{
    int c=0;
    if(head==NULL)
        return(c);
    else
    {
        start=head;
        while(start!=NULL)
        {
            c++;
            start=start->next;
        }
        return(c);
    }
}

struct song* insert_pos(struct song *head,struct song *ptr,int pos)
{
    int p=1;
    start=head;
    while(p!=pos)
    {
        start=start->next;
        p++;
    }
    temp=start->prev;
    start->prev=ptr;
    ptr->next=start;
    temp->next=ptr;
    return(head);
}

struct song* delete_pos(struct song *head,int pos)
{
    int p=1;
    start=head;
    while(p!=pos)
    {
        cur=start;
        start=start->next;
        p++;
    }
    temp=start->next;
    cur->next=temp;
     printf("song deleted\n");
    printf("title=%s\t singer name=%s\t duration=%f\n",start->tit, start->s_name, start->dur);
    free(start);
    return(head);
}
