#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<locale.h>
#define Pi 3.14
float hipotenusa(float,float);
float longcircunf(float);
float areacirculo(float);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float a,b,h,longi,area;
    printf("\n\n Ingrese dos medidas de catetos, de a una, \n y confirmando cada una con enter \n\n");
    do
        {
        scanf("%f%f",&a,&b);
        }
    while(a<0||b<0);
    while(a!=0&&b!=0)
        {
        h=hipotenusa(a,b);
        if(h<150)
            {
            longi=longcircunf(h);
            printf("\n\n La longitud de la circunferencia de diámetro %8.2f es %8.2f cm\n\n",h,longi);
            }
        else
            {
            area=areacirculo(h/2);
            printf("\n\n El área del círculo de radio %f es %f cm2 \n\n",h,area);
            }
        printf("\n\n Ingrese dos medidas de catetos, de a una, \n y confirmando cada una con enter \n\n");
        do
            {
            scanf("%f%f",&a,&b);
            }
        while(a<0||b<0);
        }
    getch();
    }
float hipotenusa(float x,float y)
    {
    float hip;
    hip=sqrt(x*x+y*y);
    return hip;
    }
float longcircunf(float x)
    {
    float y;
    y=Pi*2*x;
    return y;
    }
float areacirculo(float x)
    {
    float y;
    y=Pi*x*x;
    return y;
    }
