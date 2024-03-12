#include<stdio.h>
main()
{
float dis,perc_amt,bil_amt;
printf("enter the perc_amt\n");
scanf("%f",&perc_amt);
if(perc_amt>10000)
{
bil_amt=perc_amt-0.1*perc_amt;
printf("tot_amt to be paid=%f\n",bil_amt);
printf("u have got 10per disc");
}
else
{
printf("tot_amt to be paid=%f\n",perc_amt);
}
}
