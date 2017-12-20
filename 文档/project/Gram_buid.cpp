#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define GRAMNUM 26

typedef struct product
{
	struct product *next;
	char product_s[20];
	char head;
}Product;

typedef struct grammar
{
	int lenth;
	int number[26];
	Product *S[GRAMNUM];
}Grammar;

Product *new_Product()
{
	Product *q = (Product *)malloc(sizeof(Product));
	for(int i = 0; i < 20; i++)
	{
		q->product_s[i] = 0;
	}
	q->next = NULL;
	return q;
}

Grammar *new_Grammar()
{
	Grammar *q = (Grammar *)malloc(sizeof(Grammar));
	q->lenth = 0;
	for(int i = 0; i < GRAMNUM; i++)
	{
		q->number[i] = 0;
		q->S[i] = NULL;
	}
	return q;
}



Grammar *Grammar_Build(int argc, char *argv[])
{
	Grammar *q = new_Grammar();
	for(int i = 0; i < argc; i++)
	{
		//if(test(argv[i][0]))      // print( erro );
		int temp = 0;
		int pos;
		Product *pro;
		for(int j = 0; j < strlen(argv[i]); j++)
		{
			if(argv[i][j] == ' ') 	continue;
			temp++;
			if(temp == 1)
			{
				pos = q->number[argv[i][j] - 'A'];
				if(pos == 0)
				{
					pos = ++q->lenth;
					q->number[argv[i][j] - 'A'] = pos;					
				}
				if(q->lenth == 1)
				{
					Product *f_pro = new_Product();
					f_pro->product_s[0] = 3;
					f_pro->product_s[1] = '#'; 
					f_pro->product_s[2] = argv[i][j]; 
					f_pro->product_s[3] = '#';
					q->S[0] = f_pro;
				}
				if(q->S[pos] == NULL)
				{
					pro = new_Product();
					pro->head = argv[i][j];
					q->S[pos] = pro;
				}
				else
				{
					pro = q->S[pos];
					while(pro->next != NULL)  	pro = pro->next;
					pro->next = new_Product();
					pro->next->head = pro->head;
					pro = pro->next; 
				}
				continue;
			} 
			if((temp == 3 && !(argv[i][j] == '>' && argv[i][j - 1] == '-')))
			{
				printf("erro \n");
				return 	NULL;
			}
			if(argv[i][j] == '|')
			{
				pro->next = new_Product();
				pro->next->head = pro->head; 
				pro = pro->next;
				continue; 
			}
			if(temp > 3) pro->product_s[++pro->product_s[0]] = argv[i][j];
			
		}
	}
	return q;
}

void Grammar_show(Grammar *q)
{
	for(int i = 0; i <= q->lenth; i++)
	{
		Product *pro = q->S[i];
		if(i == 0) printf("root");
		while(pro)
		{
			printf("%c -> %s\n", pro->head, pro->product_s + 1);
			pro = pro->next;
		}
	}
}

int main()
{
	char **s = (char **)malloc(sizeof(char *) * 20);
	for(int i = 0; i < 20; i++)
	{
		s[i] = (char *)malloc(sizeof(char) * 20);
	}
	int argc = 0;
	while(scanf("%[^\n]s", s[argc++]) != EOF) getchar();
	Grammar *q = Grammar_Build(argc, s);
	Grammar_show(q);
}
