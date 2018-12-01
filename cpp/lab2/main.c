#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int whitespace_counter(char *str, int len)
{
	int cnt = 0;
	for (int i = 0; i < len-1; ++i)
	{
		// printf("str[%d]=%c\n",i,str[i]);
		if (str[i] == ' ') 
			cnt++;
	}
	// printf("%d\n", cnt);
	return cnt;
}
static int stringcmpr(const void *p1, const void *p2)
{
	return whitespace_counter(p1, strlen((char *)p1))-whitespace_counter(p2, strlen((char *)p2));
}

int main(int argc, char const *argv[])
{
	int count;
	scanf("%d\n", &count);
	printf("count=%d\n",count );
	char data [count][256];
	for (int i = 0; i < count; ++i)
	{
		gets(data[i]);
		printf("i=%d\n", i);
	}
	qsort(data, count, 256*sizeof(char), stringcmpr);
	for (int i = 0; i < count; ++i)
	{
		printf("строка %s\n", data[i]);
		
		printf("число пробелов %d\n", whitespace_counter(data[i],strlen(data[i])));
	}

	return 0;
}