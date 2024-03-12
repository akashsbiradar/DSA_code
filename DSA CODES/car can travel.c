   #include<stdio.h>
   main()
   {
   float p,x,d,dist;
   printf("enter the value of x,p,d,dist\n");
   scanf("%d%d%d",&p,&x,&d);
   dist=p*x;
   if(dist>=d)
   printf("car can travel\n");
   else
   printf("car can not travel\n");

   }
