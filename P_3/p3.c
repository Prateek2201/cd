//WAP to convert infix expression to prefix expression
#include<stdio.h>
#include<conio.h>
#include<string.h>

char str1[]="A+(C*D)*F";
char str[]="F*(D*C)+A";
char stack[10];
int top=-1;

void push(char s)
{
   top=top+1;
   stack[top]=s;
}

char pop()
{
   char item;
    item=stack[top];
    top--;
    return(item);
}

int precede(char c)
{
   if(c==47)     // Division(/)
    return(5);

    if(c==42)     // Multiplication(*)
    return(4);

     if(c==43)     //Addition(+)
     return(3);

      else
      return(2);
}





void main()
{
   char prefix[10];
   int l, i=0, j=0;
   char s, temp;

   printf("Infix string: ");
   puts(str1);

   l=strlen(str);
   push('#');

   while(i<l)
   {
      s=str[i];
      switch(s)
       {
	   case '(':
	    push(s);
	    break;

	  case ')':
	    temp=pop();
	    while(temp!='(')
	    {
	     prefix[j]=temp;
	     j++;
	     temp=pop();
	    }
	    break;

	  case '+':
	  case '-':
	  case '*':
	  case '/':
	   while(precede(stack[top])>=precede(s))
	   {
		temp=pop();
		prefix[j]=temp;
		j++;
	    }
	  push(s);
	  break;

	  default:
	  prefix[j++]=s;
	  break;
      }
   i++;
  }

  while(top>0)
    {
	temp=pop();
	prefix[j++]=temp;
     }

   prefix[j++]='\0';

   printf("\nPrefix string: ");

   for(i=6;i>=0;i--)
   printf("%c", prefix[i]);

   getch();
}
