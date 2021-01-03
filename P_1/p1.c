//Strings acceptable by grammar are of form: ab*c(a+b)
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

char a[100];
int n, i;

void main()
{
    //clrscr();
    printf("\nEnter string: ");
    scanf("%s",&a);
    n=strlen(a);

    if(a[0]=='a' && (a[n-1]=='a' || a[n-1]=='b') && a[n-2]=='c')
    {
        for(i=1; i<n-2; i++)
         {
              if(a[i]!='b')
               {
                   printf("\nString is not accepted");
                   getch();
                   exit(0);
               }
         }
         printf("\nString is accepted");
    }

    else
    printf("\nString is not accepted");

   getch();
}
