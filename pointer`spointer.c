#include <stdio.h>

int main(){
	int a;
	int *pa;
	int **ppa;

	pa=&a;
	ppa=&pa;

	a=3;

	printf("a : %d // *pa : %d // **ppa : %d \n", a, *pa, **ppa);
    printf("&a : %d // pa : %d // *ppa : %d \n", &a, pa, *ppa);
    printf("&pa : %d // ppa : %d \n", &pa, ppa);
    
	return 0;
}