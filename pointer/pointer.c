#include<stdio.h>
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%p\n", arr);
	for (int i = 0; i < 10; i++) {
		printf("%p\t%x\n", &arr[i],&arr[i]);
	}
	
}