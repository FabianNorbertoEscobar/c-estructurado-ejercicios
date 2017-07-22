#include<stdio.h>
#include<conio.h>
#include<locale.h>
void mayorymenor(int,int,int,int*,int*);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int a,b,c,*may,*min;
    printf("\n\n Ingrese una terna de números naturales de dos dígitos, de a uno, \n confirmando cada uno con enter.\n (Terna 65,67,98 para finalizar)\n\n");
    do
        {
        scanf("%d%d%d",&a,&b,&c);
        }
    while(a<=0||b<=0||c<=0||a>=99||b>=99||c>=99);
    while(a!=96&&b!=97&&c!=98)
        {
        mayorymenor(a,b,c,*may,*min);
        printf("\n\n\t Mayor: %d \t Menor: %d \n\n",may,min);
        printf("\n\n Ingrese una terna de números naturales de dos dígitos, de a uno, \n confirmando cada uno con enter.\n (Terna 65,67,98 para finalizar)\n\n");
        do
            {
            scanf("%d%d%d",&a,&b,&c);
            }
        while(a<=0||b<=0||c<=0||a>=99||b>=99||c>=99);
            }
        getch();
    }
void mayorymenor(int a,int b,int c,int *may,int *min)
    {
    int max,men;
    if(a>=b)
        {
        max=a;
        men=b;
        }
    else
        {
        max=b;
        men=a;
        }
    if(c>max)
        max=c;
    else
        if(c<men)
            men=c;
    *min=men;
    *may=max;
    return;
    }
