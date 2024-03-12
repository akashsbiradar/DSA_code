#include<stdio.h>
#define NULL 0
typedef struct song
{
   struct song *prev;
   char tit[30];
   char s_name[30];
   float dur;
   struct song *next;
}s;
s* create_node();
s* insert_song_front(s *,s *);
s* insert_song_end(s *,s *);
s* delete_song_front(s *);
s* delete_song_end(s *);
void display_forward(s*);
void display_backward(s*);
s* insert_pos(s *,s *,int pos);
int count_song(s *head);
s* delete_pos(s *head,int pos);
s* next_dur(s *head);
s* left_dur(s *head);
s* insert_next(s *head,s *ptr);
s* insert_left(s *head,s *ptr);
s *head,*start,*temp,*cur,*ptr,*last;
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
   printf("5--display all songs in forward direction\n");
   printf("6--display all songs in backward direction\n");
   printf("7--count number of songs\n");
   printf("8--insert at position\n");
   printf("9--delete at position\n");
   printf("10--display next duration song\n");
   printf("11--display left duration song\n");
   printf("12--insert song next to duration\n");
   printf("13--insert song next to duration\n");
   printf("14--exit\n");

   printf("enter your choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
      case 1: ptr=create_node();
                     head=insert_song_front(head,ptr);
                     break;
     case 2: ptr=create_node();
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
                          display_forward(head);
                      }
                      break;
    case 6:if(head==NULL)
               printf("no songs to display\n");
             else
             {
                 display_backward(head);
             }
             break;
    case 7: count=count_song(head);
             printf("total songs are=%d\n",count);
             break;
    case 8: printf("enter the position\n");
             scanf("%d",&pos);
             if(pos<1 || pos>count_song(head)+1)
                    printf("invalid position\n");

             else
             {
                 ptr=create_node();

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
     case 9: printf("enter the position\n");
              scanf("%d",&pos);
              if(pos<1||pos>count_song(head))
                        printf("invalid position\n");
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
    case 10: if(head==NULL)
               printf("CDll is empty\n");
               else
               {
                   head=next_dur(head);
               }
               break;
    case 11: if(head==NULL)
                printf("CDll is empty\n");
                else
                {
                    head=left_dur(head);
                }
                break;
    case 12:  if(head==NULL)
                printf("CDll is empty\n");
                else
                {
                    ptr=create_node();
                    head=insert_next(head,ptr);
                }
                break;
    case 13:  if(head==NULL)
                printf("CDll is empty\n");
                else
                {
                    ptr=create_node();
                    head=insert_left(head,ptr);
                }
                break;
    case 14:exit(0);break;
    default:printf("Invalid choice\n");break;
   }
}while(ch!=14);
}

s* create_node()
{
   ptr= (s*)malloc(sizeof(s));
    printf("enter the details of new song\n");
    scanf("%s%s%f",&ptr->tit, &ptr->s_name,&ptr->dur);
    return(ptr);
}
s* insert_song_front(s *head, s *ptr)
{
   if(head==NULL)
   {
     head=ptr;
     head->next=head;
     head->prev=head;
   }
   else
   {
      last=head->prev;
      ptr->next=head;
      head->prev=ptr;
      ptr->prev=last;
      last->next=ptr;
      head=ptr;
   }
    return(head);
}

s* insert_song_end(s *head, s *ptr)
{

  if(head==NULL)
   {
     head=ptr;
     head->next=head;
     head->prev=head;
   }

   else
   {
      last=head->prev;
       last->next=ptr;
       ptr->prev=last;
       ptr->next=head;
       head->prev=ptr;

   }
   return(head);
}

s* delete_song_front(s *head)
{
    if(head->next==head)
    {
       printf("song deleted\n");
       printf("title=%s\t singer name=%s\t duration=%f\n",head->tit, head->s_name, head->dur);
       free(head);
       head=NULL;
    }
    else
    {
        cur=head;
        last=head->prev;
        printf("song deleted\n");
       printf("title=%s\t singer name=%s\t duration=%f\n",cur->tit, cur->s_name, cur->dur);
       head=head->next;
       free(cur);
       head->prev=last;
       last->next=head;
    }
    return(head);
}


s* delete_song_end(s *head)
{
    if(head->next==head)
    {
       printf("song deleted\n");
       printf("title=%s\t singer name=%s\t duration=%f\n",head->tit, head->s_name, head->dur);
       free(head);
       head=NULL;
    }

    else
    {
        last=head->prev;
        cur=last->prev;
        printf("song deleted\n");
       printf("title=%s\t singer name=%s\t duration=%f\n",last->tit, last->s_name, last->dur);
        free(last);
        head->prev=cur;
        cur->next=head;
    }
    return(head);
}




void display_forward(s *head)
{
    start=head;
    printf("the songs are in correct order\n");
    while(start->next!=head)
    {
         printf("title=%s\t singer name=%s\t duration=%f\n",start->tit, start->s_name, start->dur);
         start=start->next;
    }
        printf("title=%s\t singer name=%s\t duration=%f\n",start->tit, start->s_name, start->dur);
}

void display_backward(s *head)
{
    start=head->prev;
    last=start;
    printf("the songs are in reverse order\n");
    while(start->prev!=last)
    {
        printf("title=%s\t singer name=%s\t duration=%f\n",start->tit, start->s_name, start->dur);
         start=start->prev;
    }
    printf("title=%s\t singer name=%s\t duration=%f\n",start->tit, start->s_name, start->dur);

}
int count_song(s *head)
{
    int c=0;
    if(head==NULL)
        return(c);
    else
    {
        start=head;
        while(start->next!=head)
        {
            c++;
            start=start->next;
        }
        c++;
        return(c);
    }
}

s* insert_pos(s *head,s *ptr,int pos)
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
    ptr->prev=temp;
    return(head);
}

s* delete_pos(s *head,int pos)
{
    int p=1;
    start=head;
    while(p!=pos)
    {
        start=start->next;
        p++;
    }
    temp=start->prev;
    cur=start->next;
    printf("song deleted is\n");
    printf("title=%s\t singer name=%s\t duration=%f\n",start->tit, start->s_name, start->dur);
    free(start);
    temp->next=cur;
    cur->prev=temp;
    return(head);
}

s* next_dur(s *head)
{
    float tdur;
    int status=0;
    printf("enter the required duration song\n");
    scanf("%f",&tdur);
    start=head;
    while(start->next!=head)
    {
       if(start->dur==tdur)
       {
           temp=start->next;
            printf("title=%s\t singer name=%s\t duration=%f\n",temp->tit, temp->s_name, temp->dur);
            status=1;
            break;
       }
       start=start->next;
    }
    if(start->dur==tdur)
    {
        temp=start->next;
         printf("title=%s\t singer name=%s\t duration=%f\n",temp->tit, temp->s_name, temp->dur);
         status=1;
    }
    if(status==0)
    {
        printf("song is not found\n");
    }
    return(head);
}

s* left_dur(s *head)
{
    float tdur;
    int status=0;
    printf("enter the required duration song\n");
    scanf("%f",&tdur);
    start=head;
    while(start->next!=head)
    {
       if(start->dur==tdur)
       {
           temp=start->prev;
            printf("title=%s\t singer name=%s\t duration=%f\n",temp->tit, temp->s_name, temp->dur);
            status=1;
            break;
       }
       start=start->next;
    }
    if(start->dur==tdur)
    {
        temp=start->prev;
         printf("title=%s\t singer name=%s\t duration=%f\n",temp->tit, temp->s_name, temp->dur);
         status=1;
    }
    if(status==0)
    {
        printf("song is not found\n");
    }
    return(head);
}

s* insert_next(s *head,s *ptr)
{
    float tdur;
    int status=0;
    printf("enter the required duration song\n");
    scanf("%f",&tdur);
    start=head;
    while(start->next!=head)
    {
       if(start->dur==tdur)
       {
           temp=start->next;
            start->next=ptr;
            ptr->prev=start;
            ptr->next=temp;
            temp->prev=ptr;
            status=1;

       }
       start=start->next;
    }
     if(start->dur==tdur)
       {
           temp=start->next;
            start->next=ptr;
            ptr->prev=start;
            ptr->next=temp;
            temp->prev=ptr;
            status=1;

       }
    if(status==0)
    {
        printf("song is not found\n");
    }
    return(head);
}


s* insert_left(s *head,s *ptr)
{
    float tdur;
    int status=0;
    printf("enter the required duration song\n");
    scanf("%f",&tdur);
    start=head;
    while(start->next!=head)
    {
       if(start->dur==tdur)
       {
           if(start==head)
           {
               temp=start->prev;
            start->prev=ptr;
            ptr->next=start;
            ptr->prev=temp;
            temp->next=ptr;
            head=ptr;
            status=1;
           }
           else
          {
           temp=start->prev;
            start->prev=ptr;
            ptr->next=start;
            ptr->prev=temp;
            temp->next=ptr;
            status=1;
          }
       }
       start=start->next;
    }
     if(start->dur==tdur)
       {
           temp=start->prev;
            start->prev=ptr;
            ptr->next=start;
            ptr->prev=temp;
            temp->next=ptr;
            status=1;

       }
    if(status==0)
    {
        printf("song is not found\n");
    }
    return(head);
}
