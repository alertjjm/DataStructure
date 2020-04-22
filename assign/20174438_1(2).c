#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<math.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
typedef struct {
	int coef;//계수
	int expo;//차수
}element;
int isinpoly(element* p, int expo, int len) {
	int i;
	for (i = 0; i < len; i++) {
		if (p[i].expo == expo)
			return i;
	}
	return -1;
}
element* Polymul(element* p1, element* p2, int*Q, int N, int M) {
	int posp3 = 0;
	int expo_temp, coef_temp;
	element* e_temp;
	element* p3 = (element*)malloc(sizeof(element)*(N *M));

	int i, j,k,index;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			coef_temp = p1[i].coef*p2[j].coef;
			expo_temp = p1[i].expo + p2[j].expo;
			index = isinpoly(p3, expo_temp, posp3);
			if (index!=-1) {
				p3[index].coef += coef_temp;
			}
			else {
				p3[posp3].coef = coef_temp;
				p3[posp3].expo = expo_temp;
				posp3++;
			}
		}
	}

	for (i = 0; i < posp3-1; i++) {
		for (j = 0; j < posp3-1; j++) {
			if (p3[j].expo < p3[j+1].expo) {
				expo_temp = p3[j].expo;
				coef_temp = p3[j].coef;
				p3[j].expo = p3[j+1].expo;
				p3[j].coef = p3[j+1].coef;
				p3[j+1].expo = expo_temp;
				p3[j+1].coef = coef_temp;
			}
		}
	}
	*Q = posp3;
	return p3;
}
element* Polyadd(element* p1, element* p2,int*P, int N, int M) {
	int temp;
	int posp1 = 0;
	int posp2 = 0;
	int posp3 = 0;
	element* p3 = (element*)malloc(sizeof(element)*(N + M));
	while (posp1 < N && posp2 < M) {
		if (p1[posp1].expo > p2[posp2].expo) {
			p3[posp3].expo = p1[posp1].expo;
			p3[posp3].coef = p1[posp1].coef;
			posp3++;
			posp1++;
		}
		else if (p1[posp1].expo < p2[posp2].expo) {
			p3[posp3].expo = p2[posp2].expo;
			p3[posp3].coef = p2[posp2].coef;
			posp3++;
			posp2++;
		}
		else {//차수가 같을 때
			temp= p1[posp1].coef + p2[posp2].coef;
			if (temp) {
				p3[posp3].expo = p1[posp1].expo;
				p3[posp3].coef = temp;
				posp3++;
			}
			posp1++;
			posp2++;
		}
	}
	while (posp1 < N) {
		p3[posp3].expo = p1[posp1].expo;
		p3[posp3].coef = p1[posp1].coef;
		posp3++;
		posp1++;
	}
	while (posp2 < M) {
		p3[posp3].expo = p2[posp2].expo;
		p3[posp3].coef = p2[posp2].coef;
		posp3++;
		posp2++;
	}
	*P = posp3;
	p3 = (element*)realloc(p3, sizeof(element)*posp3);
	return p3;
}
int Polycalc(element* p,int len, int x) {
	int result = 0;
	int i;
	for (i = 0; i < len; i++) {
		result = result + p[i].coef*pow(x, p[i].expo);
	}
	return result;
}
int main() {
	int N, M, i, P,Q;
	int num1, num2;
	element* poly1 = NULL;
	element* poly2 = NULL;
	element* poly3 = NULL;
	element* poly4 = NULL;
	//입력
	printf("수식 1은 몇 개의 항으로 구성되어 있나요? ");
	scanf("%d", &N);
	poly1 = (element*)malloc(sizeof(element)*N);
	printf("수식 1을 입력하세요 : ");
	for (i = 0; i < N; i++) {
		scanf("%d", &(poly1[i].coef));
		scanf("%d", &(poly1[i].expo));
	}
	printf("수식 2은 몇 개의 항으로 구성되어 있나요? ");
	scanf("%d", &M);
	poly2 = (element*)malloc(sizeof(element) * M);
	printf("수식 2을 입력하세요 : ");
	for (i = 0; i < M; i++) {
		scanf("%d", &(poly2[i].coef));
		scanf("%d", &(poly2[i].expo));
	}
	//입력끝
	poly3 = Polyadd(poly1, poly2, &P, N, M);
	printf("수식 1 + 2 는 ");
	for (i = 0; i < P; i++) {
		printf("%d %d ", poly3[i].coef, poly3[i].expo);
	}
	printf("\n");
	printf("수식 1 * 2 는 ");
	poly4 = Polymul(poly1, poly2, &Q, N, M);
	for (i = 0; i < Q; i++) {
		printf("%d %d ", poly4[i].coef, poly4[i].expo);
	}
	printf("\n");
	while (1) {
		printf("수식에 값을 넣으세요 ");
		scanf("%d", &num1);
		scanf("%d", &num2);
		printf("결과값은 ");
		switch (num1)
		{
		case 1:
			printf("%d", Polycalc(poly1, N, num2));
			break;
		case 2:
			printf("%d", Polycalc(poly2, M, num2));
			break;
		case 3:
			printf("%d", Polycalc(poly3, P, num2));
			break;
		case 4:
			printf("%d", Polycalc(poly4, Q, num2));
			break;
		}
		printf("\n");
	}

	free(poly1);
	free(poly2);
	free(poly3);
	free(poly4);
	return 0;
}