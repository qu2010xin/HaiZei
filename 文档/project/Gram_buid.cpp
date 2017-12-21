#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define GRAMNUM 26
#define WDNUM 20

typedef struct product
{
	struct product *next;
	char product_s[WDNUM];
	char head;
}Product;

typedef struct grammar
{
	int lenth;
	int number[26];
	Product *S[GRAMNUM];

	char First_G[GRAMNUM][WDNUM];
	char Last_G[GRAMNUM][WDNUM];

	int character[256];
	int functor[GRAMNUM];
	int functr_matrix[GRAMNUM][GRAMNUM];
}Grammar;

Product *new_Product()
{
	Product *q = (Product *)malloc(sizeof(Product));
	for(int i = 0; i < WDNUM; i++)
	{
		q->product_s[i] = 0;
	}
	q->next = NULL;
	return q;
}

Grammar *new_Grammar()
{
	Grammar *q = (Grammar *)malloc(sizeof(Grammar));
	memset(q, 0, sizeof(Grammar));
	for(int i = 0; i < GRAMNUM; i++)
	{
		q->S[i] = NULL;
	}
	return q;
}

Grammar *Grammar_Build(int argc, char *argv[])
{
	Grammar *q = new_Grammar();
	for(int i = 0; i < argc; i++)
	{
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

void string_merge(char *s1, char *s2)
{
	for(int i = 1; i <= s2[0]; i++)
	{
		int write_in = 1;
		for(int j = 1; j <= s1[0]; j++)
		{
			if(s1[j] == s2[i])
			{
				write_in = 0;
				break;
			}
		}
		if(write_in) s1[++s1[0]] = s2[i];
	}
}

void char_merge(char *s1, char c)
{
	int write_in = 1;
	for(int i = 1; i <= s1[0]; i++)
	{
		if(s1[i] == c)
		{
			write_in = 0;
			break;
		}
	}
	if(write_in) s1[++s1[0]] = c;

}

int have_null(char *s1)
{
	// 将 [ 定为空  
	for(int i = 1; i <= s1[0]; i++)
	{
		if(s1[i] == '[') return 1;
	}
	return 0;
}

char *First_G_Found(Grammar *q, Product *pro, int flag[])
{
	int pos = pro->head - 'A';
	int to_continue = 1;
	if(flag[pro->head - 'A'] == 0)
	{
		while(to_continue)
		{
			int i = 1;
			while(i <= pro->product_s[0])
			{
				if(pro->product_s[i] <= 'Z' && pro->product_s[i] >= 'A')
				{
					if(pro->product_s[i] != pro->head) 
					{
						string_merge(q->First_G[pos], First_G_Found(q, q->S[q->number[pro->product_s[i] - 'A']], flag));
					}
					else if(pro->next)
					{
						to_continue = 0;
						string_merge(q->First_G[pos], First_G_Found(q, pro->next, flag));
					}
					if(!have_null(q->First_G[pro->product_s[i] - 'A'])) break;
				}
				else
				{
					if(i <= pro->product_s[0])
					{
						char_merge(q->First_G[pos],pro->product_s[i]);
					}
					break;
				}
				i++;
			}
			if(pro->next == NULL) break;
			pro = pro->next;
		}
		flag[pro->head - 'A'] = 1;
	} 
	return q->First_G[pro->head - 'A'];
}

void First_G_Build(Grammar *q)
{
	int flag[26] = {0};
	q->First_G[q->S[1]->head - 'A'][0] = 1;
	q->First_G[q->S[1]->head - 'A'][1] = '#';
	for(int i = 1; i <= q->lenth; i++)
	{
		First_G_Found(q, q->S[i], flag);
	}
}

char *Last_G_Found(Grammar *q, Product *pro, int flag[])
{
	int pos = pro->head - 'A';
	int to_continue = 1;
	if(flag[pro->head - 'A'] == 0)
	{
		while(to_continue)
		{
			int i = pro->product_s[0];
			while(i >= 1)
			{
				if(pro->product_s[i] <= 'Z' && pro->product_s[i] >= 'A')
				{
					if(pro->product_s[i] != pro->head) 
					{
						string_merge(q->Last_G[pos], Last_G_Found(q, q->S[q->number[pro->product_s[i] - 'A']], flag));
					}
					else if(pro->next)
					{
						to_continue = 0;
						string_merge(q->Last_G[pos], Last_G_Found(q, pro->next, flag));
					}
					if(!have_null(q->Last_G[pro->product_s[i] - 'A'])) break;
				}
				else
				{
					char_merge(q->Last_G[pos],pro->product_s[i]);
					break;
				}
				i--;
			}
			if(pro->next == NULL) break;
			pro = pro->next;
		}
		flag[pro->head - 'A'] = 1;
	} 
	return q->Last_G[pro->head - 'A'];
}

void Last_G_Build(Grammar *q)
{
	int flag[26] = {0};
	q->Last_G[q->S[1]->head - 'A'][0] = 1;
	q->Last_G[q->S[1]->head - 'A'][1] = '#';
	for(int i = 1; i <= q->lenth; i++)
	{
		Last_G_Found(q, q->S[i], flag);
	}
}

void Prior_Less(Grammar *q, char c, char V)
{
	if(q->character[c] == 0) 
	{
		q->character[c] = (++q->functor[0]);
		q->functor[q->functor[0]] = c;
	}
	for(int i = 1; i <= q->First_G[V - 'A'][0]; i++)
	{
		if(q->character[q->First_G[V - 'A'][i]] == 0)
		{
			q->character[q->First_G[V - 'A'][i]] = (++q->functor[0]);
			q->functor[q->functor[0]] = q->First_G[V - 'A'][i];
		}
		q->functr_matrix[q->character[c]][q->character[q->First_G[V - 'A'][i]]] = '<';
		//printf("%c < %c\n", c, q->First_G[V - 'A'][i]);
	}
}

void Prior_Great(Grammar *q, char V, char c)
{
	if(q->character[c] == 0) 
	{
		q->character[c] = (++q->functor[0]);
		q->functor[q->functor[0]] = c;
	}
	for(int i = 1; i <= q->Last_G[V - 'A'][0]; i++)
	{
		if(q->character[q->Last_G[V - 'A'][i]] == 0)
		{
			q->character[q->Last_G[V - 'A'][i]] = (++q->functor[0]);
			q->functor[q->functor[0]] = q->Last_G[V - 'A'][i];
		}
		q->functr_matrix[q->character[q->Last_G[V - 'A'][i]]][q->character[c]] = '>';
		//printf("%c > %c\n", q->Last_G[V - 'A'][i] ,c);
	}
}

void Prior_Equal(Grammar *q, char c1, char c2)
{
	if(q->character[c1] == 0) 
	{
		q->character[c1] = (++q->functor[0]);
		q->functor[q->functor[0]] = c1;
	}
	if(q->character[c2] == 0) 
	{
		q->character[c2] = (++q->functor[0]);
		q->functor[q->functor[0]] = c2;
	}
	//c1 等于 c2
	q->functr_matrix[q->character[c1]][q->character[c2]] = '=';
	//printf("%c = %c\n", c1, c2);
}

void Prior_Matirx_Build(Grammar *q)
{
	for(int i = 0; i <= q->lenth; i++)
	{
		Product *pro = q->S[i];
		while(pro)
		{
			char last_V = 0, last_G = 0, last_C = pro->product_s[1];
			if(pro->product_s[1] >= 'A' && pro->product_s[1] <= 'Z')
			{
				last_V = pro->product_s[1];
			}
			else
			{
				last_G = pro->product_s[1];
			}
			for(int j = 2; j <= pro->product_s[0]; j++)
			{
				if(pro->product_s[j] >= 'A' && pro->product_s[j] <= 'Z' && last_C == last_G )
				{
					
					Prior_Less(q, last_G ,pro->product_s[j]);
					last_V = pro->product_s[j];
				}
				else if(!(pro->product_s[j] >= 'A' && pro->product_s[j] <= 'Z'))
				{
					
					if(last_C == last_V)
					{
						Prior_Great(q, last_V, pro->product_s[j]);
					}
					if(last_G != 0)
					{
						Prior_Equal(q, last_G, pro->product_s[j]);
						
					}
					last_G = pro->product_s[j];
				}
				last_C = pro->product_s[j];
			}
			pro = pro->next;
		}
	}
}



void Grammar_show(Grammar *q)
{
	for(int i = 0; i <= q->lenth; i++)
	{
		Product *pro = q->S[i];
		if(i == 0) printf("root");
		while(pro)
		{
			printf("%c -> %s\n", pro->head,pro->product_s + 1);
			pro = pro->next;
		}
	}
	for(int i = 1; i <= q->lenth; i++)
	{
		printf("First_G(%c):%s\n", q->S[i]->head, q->First_G[q->S[i]->head - 'A'] + 1);
	}
	for(int i = 1; i <= q->lenth; i++)
	{
		printf("Last_G(%c):%s\n", q->S[i]->head, q->Last_G[q->S[i]->head - 'A'] + 1);
	}
	for(int i = 1; i <= q->functor[0]; i++)
	{
		if(i == 1) printf("\t  ");
		printf("%c", q->functor[i]);
		if(i < q->functor[0]) printf(" ");
		else printf("\n");
	}
	for(int i = 1; i <= q->functor[0]; i++)
	{
		printf("\t%c ", q->functor[i]);
		for(int j = 1; j <= q->functor[0]; j++)
		{
			
			if(q->functr_matrix[i][j] == 0) 
			{
				printf("  ");
				continue;
			}
			printf("%c", q->functr_matrix[i][j]);
			if(j < q->functor[0]) printf(" ");
		}
		printf("\n");
	}
}

int is_less(Grammar *q, char c1, char c2)
{
	if(c1 >= 'A' && c1 <= 'Z') return 0;
	return q->functr_matrix[q->character[c1]][q->character[c2]] == '<'; 
}

int is_equal(Grammar *q, char c1, char c2)
{
	if((c2 >= 'A' && c2 <= 'Z')||(c1 >= 'A' && c1 <= 'Z')) return 1;
	return q->functr_matrix[q->character[c1]][q->character[c2]] == '='; 
}

void string_reduct(Grammar *q, char *stack, int *left, int *right)
{
	int l = *right - 1;
	while(l >= *left)
	{
		int break_flag = 1;
		for(int i = 0; i <= q->lenth && break_flag; i++)
		{

			Product *pro = q->S[i];

			while(pro && break_flag)
			{
				if(strcmp(stack + l, pro->product_s + 1) == 0)
				{
					stack[l] = pro->head;
					if(i == 0) stack[l] = 1; 
					l++;
					(*right) = l;
					stack[(*right)] = '\0';
					break_flag = 0;
				} 
				pro = pro->next;
			}
		}
		l--;
	}

}

void string_match(Grammar *q, char s[])
{
	char stack[50] = {0};
	int left = 0;
	int right = 0;
	
	for(int i = 0; i < strlen(s); i++)
	{
		if(!(left == right || is_less(q, stack[right - 1], s[i]) || is_equal(q, stack[right - 1], s[i])))
		{
			printf("\033[;32m reducting %s\033[0m \n",stack);
			string_reduct(q, stack, &left, &right);
			printf("\033[;32m reductover %s\033[0m \n",stack);		
		}
		stack[right] = s[i];
		stack[++right] = '\0';	
	} 
	printf("\033[;32m reducting %s\033[0m \n",stack);
	string_reduct(q, stack, &left, &right);
	printf("\033[;32m reductover %s\033[0m \n",stack);
	if(left + 1 == right && stack[left] == 1) 	printf("match success\n");	
	else 	printf("match erro\n");
	return;
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
	First_G_Build(q);
	Last_G_Build(q);
	Prior_Matirx_Build(q);
	Grammar_show(q);
	char input[20] = "#ntofat#";
	string_match(q, input);
}
