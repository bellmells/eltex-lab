#include <stdio.h>
#include <stdlib.h>
struct worker
{
	char name[64];
	int year_birth;
	int department_number;
	int salary;
};

static int cmp_func(const void *p1, const void *p2)
{
	struct worker * w1 = (struct worker *) p1;
	struct worker * w2 = (struct worker *) p2;
	
	return w1->year_birth-w2->year_birth;
}

#define LEN 5

int main(int argc, char const *argv[])
{
	// struct worker workers[LEN];
	struct worker * workers = NULL;
	workers = (struct worker *) malloc(sizeof(struct worker)*LEN);
	if(NULL == workers) return -1;
	for (int i = 0; i < LEN; ++i)
	{
		printf("Введите фамилию\n");
		scanf("%s", workers[i].name);
		printf("Введите год рождения\n");
		scanf("%d", &workers[i].year_birth);
		printf("Введите номер отдела\n");
		scanf("%d", &workers[i].department_number);
		printf("Введите сумму оклада\n");
		scanf("%d", &workers[i].salary);

	}

	qsort(workers, LEN, sizeof(struct worker), cmp_func);

	printf("Cортировка ...\n");

	for (int i = 0; i < LEN; ++i)
	{
		printf("Введите фамилию\n");
		printf("%s\n", workers[i].name);
		printf("Введите год рождения\n");
		printf("%d\n", workers[i].year_birth);
		printf("Введите номер отдела\n");
		printf("%d\n", workers[i].department_number);
		printf("Введите сумму оклада\n");
		printf("%d\n", workers[i].salary);
	}

	if (NULL != workers) free(workers);

	return 0;
}