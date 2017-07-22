#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
        setlocale(LC_CTYPE,"Spanish");
        int n,i,suma;
        printf("\n Los números perfectos hasta 100 mil son: \n");
        for(n=1;n<=100000;n++)
            {
            suma=0;
            for(i=1;i<n;i++)
                if(n%i==0)
                    suma+=i;
            if(suma==n)
                printf("\n %d \n",n);
            }
        getch();
    }
