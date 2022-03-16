#include <stdio.h>
#include <stdlib.h>


#define EMPLOYERS 10^6
int main()
{
     int out_salary=0;
     int in_gross[EMPLOYERS];

     int i,  range2=0,range3=0,range4=0,range5=0,range6=0,range7=0,range8=0,range9=0, range10=0;
     for(i=0;i<=EMPLOYERS ; i++)
        {
                printf("Enter Employee gross sale (-1 to end) :");
                scanf("%d",&in_gross[i]);
                if (in_gross[i]==-1)
                {
                        break;

                }

                out_salary=200+(0.09* in_gross[i]);
                printf("Employee salary is:%d\n",out_salary);
                if(out_salary>= 200 && out_salary<=299 )
                {
                        range2++;

                }else if(out_salary>= 300 && out_salary<=399 )
                {
                        range3++;

                }else if(out_salary>= 400 && out_salary<=499 )
                {
                        range4++;

                }else if(out_salary>= 500 && out_salary<=599 )
                {
                        range5++;

                }else if(out_salary>= 600 && out_salary<=699 )
                {
                        range6++;

                }else if(out_salary>= 700 && out_salary<=799 )
                {
                        range7++;

                }else if(out_salary>= 800 && out_salary<=899 )
                {
                        range8++;

                }else if(out_salary>= 900 && out_salary<=1000 )
                {
                        range9++;

                }else if(out_salary>= 1000 )
                {
                        range10++;

                }


        }

        printf("Total %d Employees Reported \n",i);
        printf("Employees in the range: \n");
        printf("200 299: %d\n",range2);
        printf("300 399: %d\n",range3);
        printf("400 499: %d\n",range4);
        printf("500 599: %d\n",range5);
        printf("600 699: %d\n",range6);
        printf("700 799: %d\n",range7);
        printf("800 899: %d\n",range8);
        printf("900 999: %d\n",range9);
        printf("Over 1000: %d\n",range10);



    return 0;
}
