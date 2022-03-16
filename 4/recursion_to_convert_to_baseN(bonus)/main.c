#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int DECIMAL=10;
void findBaseN(int toBaseN, int base)
{
    int remainder;


    if (toBaseN == 0)
    {
        return;
    }

    else
    {
        remainder = toBaseN % base; //Least significant digit
        findBaseN(toBaseN/base, base);
        if(base >10  && remainder >= DECIMAL&& remainder<=base)
        {
            printf("%c", remainder+55); //converting a num to char using its ascii code
        }

        else
        {
            printf("%d", remainder);
        }
    }

}



int main()
{
    int X,N;
    scanf("%d%d",&X,&N);
    if (X >= 1&& X<= pow(10,9) && N>=2 && N<=16)
    {
        findBaseN(X, N);
        printf("\n");
    }

    return 0; // return 0 to operating system
}

