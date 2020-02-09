#include<stdio.h>
#include<math.h>
int main() {
	int i, j, k, ren, star, N;
	scanf("%d", &N);
	for (i = -N; i < N+1; i++) {
		ren = abs(i);
		for (k = 0; k < ren; k++) {
			printf(" ");}
		star = (N - ren) * 2 + 1;
		for (j = 0; j < star; j++) {
			printf("*");}
		printf("\n");}}