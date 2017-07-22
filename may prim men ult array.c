#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i,cont,n,v[10];
    cont=0;
    for(i=0;i<10;i++)
        {
        printf("\n Ingrese un número:\n");
        scanf("%d",&n);
        v[i]=n;
        }
    printf("\n Mayores al primero \n");
    for(i=0;i<10;i++)
        {
        if(v[i]>v[0])
            printf("\n %d",v[i]);
        if(v[i]<v[9])
            cont++;
        }
    printf("\n\n Cantidad de números menores al último: %d \n\n",cont);
    getch();
    }
