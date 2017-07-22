#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n,m,pr,j,i;
    printf("\n\n Pida una cantidad de números primos: \n\n\t");
    scanf("%d",&n);
    m=2;
    printf("\n\n Los primeros %d números primos son:\n\n1 \n",n);
    for(pr=1;pr<n;pr++)
        {
        do
            {
            do
                {
                i=2;
                j=m%i;
                i++;
                }
            while(j!=0&&i<m);
            m++;
            }
        while(j!=0);
        printf("%d \n",m);
        }
    getch();
    }
