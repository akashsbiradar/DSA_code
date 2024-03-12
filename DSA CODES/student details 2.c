#include<stdio.h>
#define NULL 0
struct student
{
  char name[30];
  int rno;
  float ht;
  struct student *link;
};

main()
{
    struct student *head,*ptr2,*start;
    head=NULL;

      struct student *ptr1;
      ptr1=(struct student *)malloc(sizeof(struct student));
      head=ptr1;

    printf("enter details of  a student \n");
    scanf("%s%d%f",&ptr1->name,&ptr1->rno,&ptr1->ht);
    ptr1->link=NULL;

      ptr1=(struct student *)malloc(sizeof(struct student));

       printf("enter details of  a student \n");
    scanf("%s%d%f",&ptr1->name,&ptr1->rno,&ptr1->ht);

    head->link=ptr1;
    ptr1->link=NULL;
    ptr2=ptr1;
      ptr1=(struct student *)malloc(sizeof(struct student));
    printf("enter details of  a student \n");
    scanf("%s%d%f",&ptr1->name,&ptr1->rno,&ptr1->ht);

    ptr1->link=NULL;
    ptr2->link=ptr1;

    start=head;
    printf("linked list of students is\n");
    while(start->link!=NULL)
    {
        printf("name=%s\t rollno=%d\t height=%f\n",start->name, start->rno,start->ht);
         start=start->link;
    }

    printf("name=%s\t rollno=%d\t height=%f\n",start->name, start->rno,start->ht);



}
