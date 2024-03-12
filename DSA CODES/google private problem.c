    #include<stdio.h>
    struct student
    {
        char name[30];
        int class;
        char project[40];
        char DOB[20];
    };
    struct resource
    {
        char operating[50];
        int ram;
        int storage;
        char processor[40];
    };

    struct student *ptr1;
    struct resource *ptr2;
    int i;

    main()
    {
        int n;
        printf("enter the number of students requested\n");
        scanf("%d",&n);
        ptr1=(struct student*)malloc(n*sizeof(struct student));
        ptr2=(struct resource*)malloc(n*sizeof(struct resource));
        void r(struct student *ptr1,int n);
        void d(struct student *ptr1,int n);
        void R(struct resource *ptr2,int n);
        void D(struct resource *ptr2,int n);
        void search(struct student *ptr1,int n);
        void Average(struct resource *ptr2,int n);
        void sort(struct student *ptr1,int n);
        if(n<3)
            printf("minimum number of student request should be more the 3\n");
        else
        {
            r(ptr1,n);
            R(ptr2,n);
            printf("\n");
            d(ptr1,n);
            printf("\n");
            D(ptr2,n);
            search(ptr1,n);
            Avg(ptr2,n);
            sort(ptr1,n);
        }
    }

    void r(struct student *ptr1,int n)
    {
        printf("enter the details of student\n");
        for(i=0;i<n;i++)
        {
            printf("enter the details of student %d\n",i+1);
            scanf("%s%d%s%s",&ptr1->name,&ptr1->class,&ptr1->project,&ptr1->DOB);
            ptr1++;
        }
    }

     void d(struct student *ptr1,int n)
    {
        printf(" details of student\n");
        for(i=0;i<n;i++)
        {
            printf(" details of student %d\n",i+1);
            printf("name=%s\t studing in=%d\t project=%s\t date of birth=%s\n",ptr1->name,ptr1->class,ptr1->project,ptr1->DOB);
            ptr1++;
        }
    }

     void R(struct resource *ptr2,int n)
    {
        printf("enter the details of student resource\n");
        for(i=0;i<n;i++)
        {
            printf("enter the details of student resource %d\n",i+1);
            scanf("%s%d%d%s",&ptr2->operating,&ptr2->ram,&ptr2->storage,&ptr2->processor);
            ptr2++;
        }
    }

     void D(struct resource *ptr2,int n)
    {
        printf("enter the details of student resource\n");
        for(i=0;i<n;i++)
        {
            printf("enter the details of student resource %d\n",i+1);
            printf("operator=%s\t ram=%d\t storage=%d\t processor=%s\n",ptr2->operating,ptr2->ram,ptr2->storage,ptr2->processor);
            ptr2++;
        }
    }

    void search(struct student *ptr1,int n)
    {
        char pro[40];
        printf("enter the project name\n");
        scanf("%s",&pro);
        for(i=0;i<n;i++)
        {
            if(strcmp(ptr1->project,pro)==0)
            {
                printf("student name=%s\n",ptr1->name);
            }
            ptr1++;
        }
    }

    void Avg(struct resource *ptr2,int n)
    {
        char win[50];
        int count;
        float ram;
        printf("enter the operating system\n");
        scanf("%s",&win);
        for(i=0;i<n;i++)
        {
            if(strcmp(ptr2->operating,win)==0)
            {
                ram=ram+ptr2->ram;
                count++;
            }
            ptr2++;
        }
        printf("average ram=%f\n",(float)(ram/count));
    }

    void sort(struct student *ptr1,int n)
    {
        struct student temp;
        int i,j,min_index;
        for(i=0;i<n-1;i++)
        {
            min_index=i;
            for(j=i+1;j<n;j++)
            {
                if((ptr1+j)->class<(ptr1+min_index)->class)
                {
                    min_index=j;
                }
            }
           temp=*(ptr1+i);
           *(ptr1+i)=*(ptr1+min_index);
           *(ptr1+min_index)=temp;
        }

        for(i=0;i<n;i++)
        {
          printf("name=%s\t studing in=%d\t project=%s\t date of birth=%s\n",ptr1->name,ptr1->class,ptr1->project,ptr1->DOB);
          ptr1++;
        }
    }
