#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i,acum,num,vnum[5],prom;
    acum=0;
    for(i=0;i<5;i++)
        {
        printf("\n Ingrese un número:\n\n");
        scanf("%d",&num);
        vnum[i]=num;
        acum+=vnum[i];
        }
    prom=acum/5;
    printf("\n Mayores al promedio: \n\n");
    for(i=0;i<5;i++)
        if(vnum[i]>prom)
            printf("\n %d",vnum[i]);
    getch();
    }
