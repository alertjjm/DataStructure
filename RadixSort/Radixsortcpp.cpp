#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define BUCKET_NUM 10
void RadixSort(vector<int>& arr, int num, int maxLen) {
	queue<int> buckets[BUCKET_NUM];
	int i, j, k, div, n;
	for (i = 0; i < maxLen; i++) {
		div = pow(10, i);
		for (j = 0; j < num; j++) {
			n = arr[j] / div%10;
			buckets[n].push(arr[j]);
		}
		k = 0;
		for (j = 0; j < BUCKET_NUM; j++) {
			while (!buckets[j].empty()) {
				arr[k] = buckets[j].front();
				buckets[j].pop();
				k++;
			}
		}

	}
}
int main() {
	vector<int> arr= { 13,212,14,7141,10987,6,15 };
	int len = arr.size();
	int i;
	RadixSort(arr, len, 5);
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}