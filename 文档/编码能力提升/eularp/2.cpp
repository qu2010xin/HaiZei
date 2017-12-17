#include <stdio.h>
#include <string.h>
#include <malloc.h>


int main()
{
    int a=1,b=2;
    int c;
    int i=2;
    while(c<=4000000)
    {

    	c = a+b;
    	a = b;
    	b = c;
        (c%2==0)&&(i+=c); //
    } 
    printf("%d\n",i);
}