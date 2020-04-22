#include<stdio.h>
#include<string.h>
#define STNUM 10
//�л� ����ü
typedef struct _student {
	char major[3];
	char name[6];
	int grade1;
	int grade2;
	int grade3;
	float avg;
}student;
//���������ľ�&������ ���� �ľ� ���� majorinfo����ü
typedef struct _majorinfo {
	char name[3];
	int num;
}majorinfo;

int main() {
	student arr[STNUM];
	int i, j;
	student temp;
	majorinfo is, cs, ce;
	//���� �ʱ�ȭ&���� �迭 ���ĺ� �� ����
	strcpy(is.name, "IS");
	is.num = 0;
	strcpy(cs.name, "CS");
	cs.num = 0;
	strcpy(ce.name, "CE");
	ce.num = 0;
	majorinfo* majorinfoarr[3] = { &is,&cs,&ce };
	majorinfo* tempmajor;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (strcmp((*majorinfoarr[i]).name, (*majorinfoarr[j]).name) < 0) {
				tempmajor = majorinfoarr[i];
				majorinfoarr[i] = majorinfoarr[j];
				majorinfoarr[j] = tempmajor;
			}
		}
	}
	//�Է¹����� �ʱ�ȭ
	for (i = 0; i < STNUM; i++) {
		printf("�а���: ");
		scanf("%s", arr[i].major);
		if (strcmp("IS", arr[i].major) == 0) {
			is.num++;
		}
		else if(strcmp("CS", arr[i].major) == 0) {
			cs.num++;
		}
		else if (strcmp("CE", arr[i].major) == 0) {
			ce.num++;
		}
		printf("�̸�: ");
		scanf("%s", arr[i].name);
		printf("1���� ����: ");
		scanf("%d", &arr[i].grade1);
		printf("2���� ����: ");
		scanf("%d", &arr[i].grade2);
		printf("3���� ����: ");
		scanf("%d", &arr[i].grade3);
		arr[i].avg = (float)(arr[i].grade1 + arr[i].grade2 + arr[i].grade3) / (float)3;
	}
	//�̸� ����(��ü 10�� �ѹ���)
	for (i = 0; i < STNUM; i++) {
		for (j = 0; j < STNUM; j++) {
			if (strcmp(arr[i].major, arr[j].major) < 0) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	//�а� ����(3���� �� ���� ������)
	for (i = 0; i < majorinfoarr[0]->num; i++) {
		for (j = 0; j < majorinfoarr[0]->num; j++) {
			if (strcmp(arr[i].name, arr[j].name) < 0) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (i = majorinfoarr[0]->num; i < majorinfoarr[0]->num+majorinfoarr[1]->num; i++) {
		for (j = majorinfoarr[0]->num; j < majorinfoarr[0]->num + majorinfoarr[1]->num; j++) {
			if (strcmp(arr[i].name, arr[j].name) < 0) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (i = majorinfoarr[0]->num + majorinfoarr[1]->num; i < majorinfoarr[0]->num + majorinfoarr[1]->num+majorinfoarr[2]->num; i++) {
		for (j = majorinfoarr[0]->num + majorinfoarr[1]->num; j < majorinfoarr[0]->num + majorinfoarr[1]->num + majorinfoarr[2]->num; j++) {
			if (strcmp(arr[i].name, arr[j].name) < 0) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	//���
	printf("\n====================\n");
	printf("%s\n", majorinfoarr[0]->name);
	for (i = 0; i < majorinfoarr[0]->num; i++) {
		printf("%s %d %d %d %.2f\n", arr[i].name, arr[i].grade1, arr[i].grade2, arr[i].grade3, arr[i].avg);
	}
	printf("\n");
	printf("%s\n", majorinfoarr[1]->name);
	for (i = majorinfoarr[0]->num; i < majorinfoarr[0]->num+majorinfoarr[1]->num; i++) {
		printf("%s %d %d %d %.2f\n", arr[i].name, arr[i].grade1, arr[i].grade2, arr[i].grade3, arr[i].avg);
	}
	printf("\n");
	printf("%s\n", majorinfoarr[2]->name);
	for (i = majorinfoarr[0]->num + majorinfoarr[1]->num; i < majorinfoarr[0]->num + majorinfoarr[1]->num+majorinfoarr[2]->num; i++) {
		printf("%s %d %d %d %.2f\n", arr[i].name, arr[i].grade1, arr[i].grade2, arr[i].grade3, arr[i].avg);
	}
}