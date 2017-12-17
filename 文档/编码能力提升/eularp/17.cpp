#include <stdio.h>
#include <math.h>
#include <inttypes.h>

//one two three four five six seven eight nine 

int ten_num()
{
	return ("one - ten");
}
 
int hundred_num()
{
	return (ten_num()*9 + "twenty - ninty"*10 + "ten - ninteen");
}

int thosand_num()
{
	return (hundred_num()*10+ten_num()*100+900*7);
}
int main()
{

}