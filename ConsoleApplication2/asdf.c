#include<stdio.h>
int main() {
	char  *pc = 0;
	double *pd = 0;
	short     **pps = 0;
	float     *pf = 0;
	pc++;
	pd += 5;
	pps += 2;
	pf = (char *)pf + 1;
	printf("%x %x %x %x \n", pc, pd, pps, pf);

}