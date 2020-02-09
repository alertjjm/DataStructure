#include<stdio.h>
#include<queue>
#include<math.h>
#define BUCKET_NUM 10
void RadixSort(int arr[], int num, int maxLen) {
	queue buckets[BUCKET_NUM];
	int i,j,k,div,n;
	for (i = 0; i < maxLen; i++) {
		for (i = 0; i < BUCKET_NUM; i++) {
			QueueInit(&buckets[i]);
		}
		div = pow(10, i + 1);
		for (j = 0; j < num; j++) {
			n = arr[j] % div;
			Enqueue(&buckets[n], arr[j]);
		}
		k = 0;
		for (j = 0; j < BUCKET_NUM; j++) {
			while (!QIsEmpty(&buckets[j])) {
				arr[k] = Dequeue(&buckets[j]);
				k++;
			}
		}

	}
}
int main() {
	int arr[7] = { 13,212,14,7141,10987,6,15 };
	int len = sizeof(arr) / sizeof(int);
	int i;
	RadixSort(arr, len, 5);
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}