#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int a,b,c,d,men,ord;
    printf("\n\n Ingrese cuatro números enteros positivos, de a uno, confirmando c/u con enter:\n\n");
    scanf("%d%d%d%d",&a,&b,&c,&d);
    men=a;
    ord=1;
    if(b<=men&&b<=c&&b<=d)
        {
        men=b;
        ord=2;
        }
    else
        if(c<=men&&c<=b&&men<=d)
            {
            men=c;
            ord=3;
            }
        else
            if(d<=men&&d<=b&&d<=c)
                {
                men=d;
                ord=4;
                }
    printf("\n\n Valores ingresados:%d, %d, %d, %d \n",a,b,c,d);
    printf("\n\n Menor: %d \t Orden: %d \n\n",men,ord);
    getch();
    }
