#include <stdio.h>



#include <string.h>


int fc(int x)
{
    if(x==0)
    {
        return 1;
    }
    int i=1;
    while(x>0)
    {
        i*=x;
        x--;
    }
    return i;
}


int main()
{
    
    int i=1;
    int x=10;
    int b=fc(9);
    int y=b;
    printf("%d\n",y);
    while(x<y)
    {
        y*=b;
        i++;
        x*=10;
    }
    printf("%d\n",i);

 
}