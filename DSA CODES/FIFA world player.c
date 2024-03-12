 #include<stdio.h>
 #include<stdlib.h>
 struct fifa
 {
     char name[30],con[30];
     int a,g,j;
 };
 struct fifa *s;
 struct fifa q[30];
 int n,f,r;
 int main()
 {
    f=-1;
    r=-1;
    printf("enter the number of players\n");
    scanf("%d",&n);
    s=(struct fifa*)malloc(n*sizeof(struct fifa));
    void insert(struct fifa *s);
    void award(int n,int f,int r);


    if(n>0)
    {
         int i;
     for(i=0;i<n;i++)
     {
         printf("enter the name country age goals jersey of player %d\n",i+1);
         scanf("%s%s%d%d%d",&s->name,&s->con,&s->a,&s->g,&s->j);
         insert(s);
     }

        award(n,f,r);
    }
    else
        printf("Invalid number of players\n");
 }

 void insert(struct fifa *s)
 {
    if(r==29)
        printf("Q is full\n");
    else if(f==-1 && r==-1)
    {
        f++;
        r++;
        strcpy(q[r].name,s->name);
        strcpy(q[r].con,s->con);
        q[r].a=s->a;
         q[r].g=s->g;
          q[r].j=s->j;
    }
    else
    {
        r++;
        strcpy(q[r].name,s->name);
        strcpy(q[r].con,s->con);
        q[r].a=s->a;
         q[r].g=s->g;
          q[r].j=s->j;
    }
 }

 void award(int n,int f,int r)
 {
     int j,max,a;
     max=q[f].g;
     for(j=f;j<=r;j++)
     {
       if(q[j].g>max)
       {
           max=q[j].g;
           a=j;
       }
     }
     printf("name=%s\t country=%s\t afe=%d\t goals=%d\t jersey no=%d\n",q[a].name,q[a].con,q[a].a,q[a].g,q[a].j);
 }
