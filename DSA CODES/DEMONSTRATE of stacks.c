 #include<stdio.h>
 #define size 5
 int stack[size];
 main()
 {
     int top=-1;
     int ch,ele;
     int push(int top,int ele);
     int pop(int top);
     void display(int top);

     do
     {
         printf("1--push\n");
          printf("2--pop\n");
           printf("3--display\n");
            printf("4--exit\n");
         printf("enter the choice\n");
         scanf("%d",&ch);

         switch(ch)
         {
             case 1: if(top==size-1)
                       printf("stack is full\n");
                       else
                       {
                           printf("enter the element\n");
                           scanf("%d",&ele);
                           top=push(top,ele);
                       }
                       break;
             case 2: if(top==-1)
                   printf("stack is empty\n");
                   else
                   {
                       top=pop(top);
                   }
                   break;
            case 3:if(top==-1)
                   printf("stack is empty\n");
                   else
                   {
                       display(top);
                   }
                   break;

            case 4: exit(0);break;
            default:printf("invalid choice\n");
            break;
         }
     }while(ch!=4);
 }

 int push(int top,int ele)
 {
     top=top+1;
     stack[top]=ele;
     return(top);
 }

 int pop(int top)
 {
     printf("element poped is =%d\n",stack[top]);
     top=top-1;
     return(top);
 }

 void display(int top)
 {
     int i;
     i=top;
     printf("element poped is =\n");
     while(i!=-1)
     {
       printf("%d\n",stack[i]);
       i--;
     }
 }

