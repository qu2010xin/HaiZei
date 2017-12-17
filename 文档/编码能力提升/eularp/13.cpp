#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#define max_num 1000
int main()
{
	int key[max_num];
	char s[max_num];
	memset(key,0,sizeof(key));
	key[0] = key[1] = 1;
	while(~scanf("%s",s))
	{
		int temp[max_num] = {0};
		int lenth = strlen(s);
		(key[0] < lenth) && (key[0] = lenth);
		for(int i = 1; i <= lenth; i++)
		{
			for(int j = i; j <= (key[0]+i-1); j++)
			{
				temp[j] += key[j-i+1]*(s[lenth - i] - '0');
			}
		}
		key[0] += (lenth - 1);
		for(int i = key[0]; i >=1; i--)
		{
			key[i] = temp[i];
		}



		for(int i = 1; i <= key[0]; i++)
		{
			if(key[i] < 10) continue;
			key[i+1] += key[i]/10;
			key[i] %= 10;
			(i == key[0]) && (key[0]++); 
		}

		for(int i = key[0]; i >=1; i--)
		{
			printf("%d ", key[i]);
		}
		printf("\n");

	}

}