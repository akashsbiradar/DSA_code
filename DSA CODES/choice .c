   #include<stdio.h>
   main()
   {
       char ch;
   int n1,n2,sum,sub,mul,div;
   printf("enter the 2 no.\n");
   scanf("%d%d",&n1,&n2);
   printf("enter the choices\n");
   scanf("%c%c",&ch,&ch);
   if(ch=='+')
   {
   sum=n1+n2;
   printf("sum=%d\n",sum);
   }
   else if(ch=='-')
   {
   sub=n1-n2;
   printf("sub=%d\n",sub);
   }
   else if(ch=='*')
   {
   mul=n1*n2;
   printf("product=%d\n",mul);
   }
   else if(ch=='/')
   {
   div=n1/n2;
   printf("division=%d\n",div);
   }
   else
   printf("invalid choice");
   }
