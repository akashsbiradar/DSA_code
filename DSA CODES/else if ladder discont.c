  #include<stdio.h>
  main()
  {
  float p,tot_bill;
  printf("enter the purchase amount\n");
  scanf("%f",&p);
  if(p>=0 && p<=1000)
  printf("tot_bill=%f\n",p);
  else if(p>=1001&&p<=5000)
  printf("tot_bill=%f\n",p-(0.02*p));
  else if(p>=5001&&p<=10000)
  {
  tot_bill=p-(0.03*p);
  printf("tot_bill=%f\n",tot_bill);
  }
  else
  printf("tot_bill=%f\n",p*0.95);
  }
