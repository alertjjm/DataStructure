#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<math.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct {
	int degree;
	int* coef;
}polynomial;
polynomial Polyadd(polynomial p1, polynomial p2) {
	polynomial p3;
	int posp1 = 0;
	int posp2 = 0;
	int posp3 = 0;
	int degreep1 = p1.degree;
	int degreep2 = p2.degree;
	p3.degree = MAX(p1.degree, p2.degree);
	p3.coef = (int*)calloc(p3.degree + 1, sizeof(int));
	
	while (posp1 <= p1.degree&&posp2 <= p2.degree) {
		if (degreep1 > degreep2) {
			p3.coef[posp3++] = p1.coef[posp1++];
			degreep1--;
		}
		else if (degreep1 == degreep2) {
			p3.coef[posp3++] = p1.coef[posp1++] + p2.coef[posp2++];
			degreep1--;
			degreep2--;
		}
		else {
			p3.coef[posp3++] = p2.coef[posp2++];
			degreep2--;
		}
	}
	return p3;
}
polynomial Polymul(polynomial p1, polynomial p2) {
	polynomial p3;
	int posp1 = 0;
	int posp2 = 0;
	int degreep1;
	int degreep2;
	int posp3;
	p3.degree = p1.degree + p2.degree;
	p3.coef = (int*)calloc(p3.degree + 1, sizeof(int));
	for (posp1 = 0; posp1 < p1.degree + 1; posp1++) {
		for (posp2 = 0; posp2 < p2.degree + 1; posp2++) {
			degreep1 = p1.degree - posp1;
			degreep2 = p2.degree - posp2;
			posp3 = p3.degree - degreep1 - degreep2;
			p3.coef[posp3] += (p1.coef[posp1] * p2.coef[posp2]);
		}
	}
	return p3;
}
int Polycalc(polynomial* p, int x) {
	int result = 0;
	int i;
	int degree;
	for (i = 0; i < (p->degree) + 1; i++) {
		degree = p->degree - i;
		result = result + p->coef[i]*pow(x, degree);
	}
	return result;
}
int main() {
	polynomial poly1, poly2,poly3,poly4;
	int N, M, i, num1, num2;
	int* temp=NULL;
	poly1.coef = NULL;
	poly2.coef = NULL;
	poly3.coef = NULL;
	poly4.coef = NULL;

	printf("수식 1은 몇 개의 항으로 구성되어 있나요? ");
	scanf("%d", &N);
	printf("수식 1을 입력하세요 : ");
	temp = (int*)malloc(sizeof(int) * 2 * N);
	for (i = 0; i < 2 * N; i++) {
		scanf("%d", &temp[i]);
	}
	poly1.coef = (int*)calloc(temp[1]+1,sizeof(int));//temp의 두번째 들어있는 값이 최고차수 degree
	poly1.degree = temp[1];
	for (i = 0; i < N; i++) {
		poly1.coef[temp[1]-temp[2 * i + 1]] = temp[2 * i];
	}

	printf("수식 2은 몇 개의 항으로 구성되어 있나요? ");
	scanf("%d", &M);
	printf("수식 2을 입력하세요 : ");

	temp = (int*)realloc(temp,sizeof(int) * 2 * M);
	for (i = 0; i < 2 * M; i++) {
		scanf("%d", &temp[i]);
	}
	poly2.coef = (int*)calloc(temp[1]+1,sizeof(int));//temp의 두번째 들어있는 값이 최고차수 degree
	poly2.degree = temp[1];
	for (i = 0; i < M; i++) {
		poly2.coef[temp[1] - temp[2 * i + 1]] = temp[2 * i];
	}


	poly3 = Polyadd(poly1, poly2);
	printf("수식 1 + 2 는 ");
	for (i = 0; i < poly3.degree + 1; i++) {
		if (poly3.coef[i] != 0)
			printf("%d %d ", poly3.coef[i],poly3.degree-i);
	}
	printf("\n");
	printf("수식 1 * 2 는 ");
	poly4 = Polymul(poly1, poly2);
	for (i = 0; i < poly4.degree + 1; i++) {
		if(poly4.coef[i]!=0)
			printf("%d %d ", poly4.coef[i],poly4.degree-i);
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
			printf("%d", Polycalc(&poly1,num2));
			break;
		case 2:
			printf("%d", Polycalc(&poly2, num2));
			break;
		case 3:
			printf("%d", Polycalc(&poly3, num2));
			break;
		case 4:
			printf("%d", Polycalc(&poly4,num2));
			break;
		}
		printf("\n");
	}

	free(poly1.coef);
	free(poly2.coef);
	free(poly3.coef);
	free(poly4.coef);
	free(temp);
	return 0;
}