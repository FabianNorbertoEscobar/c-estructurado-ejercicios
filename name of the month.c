#include<stdio.h>
#include<conio.h>
int validdata(int,int,int);
void main()
    {
    int month;
    printf("\n\n Enter the number of a month to view its name:\n\n\t");
    do
        {
        scanf("%d",&month);
        }
    while(!validdata(month,1,12));
    switch(month)
        {
        case 1:printf("\n January \n");
        break;
        case 2:printf("\n February \n");
        break;
        case 3:printf("\n March \n");
        break;
        case 4:printf("\n April \n");
        break;
        case 5:printf("\n May \n");
        break;
        case 6:printf("\n June \n");
        break;
        case 7:printf("\n July \n");
        break;
        case 8:printf("\n August \n");
        break;
        case 9:printf("\n September \n");
        break;
        case 10:printf("\n October \n");
        break;
        case 11:printf("\n November \n");
        break;
        default:printf("\n December \n");
        }
    getch();
    }
int validdata(int data,int l1,int l2)
    {
    if(data>=l1&&data<=l2)
        return 1;
    else
        return 0;
    }
