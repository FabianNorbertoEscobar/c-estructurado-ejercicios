#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
struct info
    {
    int nc;
    char cl[26];
    int cod;
    float saldo;
    };
struct fecha
    {
    int d;
    int m;
    int a;
    };
int fcarga(struct info[]);
struct fecha fechaproceso(void);
int fechavalida(int,int,int);
int cantdiasmes(int,int);
int bisiesto(int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info vec[700];
    struct fecha proceso;
    int i,band,cant;
    float may;
    printf("\n\n\a\a ***** BANCO RIOMAR ****** \n");
    cant=fcarga(vec);
    printf("\n Control de transacciones bancarias de las cuentas corrientes\n\n");
    printf("\n Ingrese la fecha del proceso: \n");
    proceso=fechaproceso();
    printf("\n LISTADO DE CLIENTES CON SALDO DEUDOR DEL %d/%d/%d\n\n",proceso.d,proceso.m,proceso.a);
    printf("\n NÚMERO DE CUENTA \t NOMBRE DEL CLIENTE \n");
    for(i=0;i<cant;i++)
        if(vec[i].cod==1)
            printf("\n %d \t\t\t %s",vec[i].nc,vec[i].cl);
    band=0;
    for(i=0;i<cant;i++)
        if(vec[i].cod==2&&(band==0||vec[i].saldo>may))
            {
            band=1;
            may=vec[i].saldo;
            }
    printf("\n\n\t MAYOR SALDO ACREEDOR: %.2f \n\n",may);
    printf("\n LISTADO DE CLIENTES CON MAYOR SALDO ACREEDOR DEL %d/%d/%d\n\n",proceso.d,proceso.m,proceso.a);
    printf("\n NÚMERO DE CUENTA \t NOMBRE DEL CLIENTE \n");
    for(i=0;i<cant;i++)
        if(vec[i].cod==2&&may==vec[i].saldo)
            printf("\n %d \t\t\t %s",vec[i].nc,vec[i].cl);
    printf("\n\n Fin del programa \n\n\a\a");
    getch();
    }
int fcarga(struct info v[])
    {
    int i;
    FILE *pf;
    i=0;
    pf=fopen("saldos.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\t\t El archivo está corrupto \n\n");
        exit(0);
        }
    fread(&v[i],sizeof(struct info),1,pf);
    while(!feof(pf))
        {
        i++;
        fread(&v[i],sizeof(struct info),1,pf);
        }
    fclose(pf);
    return i;
    }
struct fecha fechaproceso(void)
    {
    struct fecha aux;
    do
        {
        printf("\n\n Día: \t\t");
        scanf("%d",&aux.d);
        printf("\n\n Mes: \t\t");
        scanf("%d",&aux.m);
        printf("\n\n Año: \t\t");
        scanf("%d",&aux.a);
        }
    while(!fechavalida(aux.d,aux.m,aux.a));
    return aux;
    }
int fechavalida(int d,int m,int a)
    {
    if(a>1600&&m>=1&&m<=12&&d>=1&&d<=cantdiasmes(m,a))
        return 1;
    else
        return 0;
    }
int cantdiasmes(int m,int a)
    {
    int cd;
    if(m==4||m==6||m==9||m==11)
        cd=30;
    else
        {
        if(m==2)
            cd=28+bisiesto(a);
        else
            cd=31;
        }
    return cd;
    }
int bisiesto(int a)
    {
    if((a%4==0&&a%100!=0)||a%400==0)
        return 1;
    else
        return 0;
    }
