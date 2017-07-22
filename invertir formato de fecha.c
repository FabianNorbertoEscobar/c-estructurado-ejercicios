#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int f,d1,d2,m1,m2,a1,a2;
    printf("\n\n Ingrese una fecha en formato DDMMAA \n\n");
    scanf("%d",&f);
    a2=f%10;
    a1=f/10%10;
    m2=f/10/10%10;
    m1=f/10/10/10%10;
    d2=f/10/10/10/10%10;
    d2=f/10/10/10/10/10;
    printf("\n\n La fecha en formato AAMMDD es: %d%d%d%d%d%d \n\n",a1,a2,m1,m2,d1,d2);
    getch();
    }
