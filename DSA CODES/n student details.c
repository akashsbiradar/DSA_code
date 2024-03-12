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
      int i,n;
      printf("enter the values of n\n");
      scanf("%d",&n);
      struct student *ptr,*start,*head;
      head=NULL;
      ptr=(struct student*)malloc(sizeof(struct student));
      head=ptr;
      start=ptr;
       printf("enter the details of %d student\n",i+1);
       scanf("%s%d%f",&head->name,&head->rno,&head->ht);

        for(i=1;i<n;i++)
        {
            ptr=(struct student*)malloc(sizeof(struct student));
            printf("enter the details of %d student\n",i+1);
            scanf("%s%d%f",&ptr->name,&ptr->rno,&ptr->ht);
            start->link=ptr;
            start=ptr;
        }
        start->link=NULL;
       start=head;
        while(start!=NULL)
        {
            printf("name=%s\t roll no=%d\t height=%f\n",start->name,start->rno,start->ht);
            start=start->link;
        }


  }
