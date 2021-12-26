/* 15�� Programming */
// 01
/* #include <stdio.h>

int main() {
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	
	fp1 = fopen("text1.txt", "w");
	fp2 = fopen("text2.txt", "w");
	
//	fp1 = fopen("text1.txt", "r");
	if(fp1 == NULL)
		printf("���� ���� ����\n");
	
//	fp2 = fopen("text2.txt", "r"); 
	if(fp2 == NULL)
		printf("���� ���� ����\n");
		
	fputc('a', fp1);
	
	while(1) {
		if(fgetc(fp1) == fgetc(fp2)) {
			printf("�� ������ ���� �����ϴ�.\n");
			break;
		}
		else if(fgetc(fp1) != fgetc(fp2)) {
			printf("�� ������ ���� �ٸ��ϴ�.\n");
			break;
		}
	}
	fclose(fp1);
	fclose(fp2);
	
	return 0;
} */

// 03
/* #include <stdio.h>

int main() {
	FILE *fp1, *fp2;
	char file1[100], file2[100];
	char buffer[100];
	
	printf("���� ���� �̸�: ");
	scanf("%s", file1);
	printf("���� ���� �̸�: ");
	scanf("%s", file2);
	
	if(	(fp1 = fopen(file1, "rb")) == NULL ) {
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", file1);
		exit(1);
	}
	if(	(fp2 = fopen(file2, "wb")) == NULL ) {
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", file2);
		exit(1);
	}
		
	while( fgets(buffer, 100, fp1) != NULL) {
		printf("%s", buffer);
		fputs(buffer, fp2);
	}
		
	fclose(fp1);
	fclose(fp2);
	
	return 0;
} */

// 05
/* #include <stdio.h>
#define SIZE 4

struct student {
	char name[10];
	int korean;
	int math;
	int english;
};
int main() {
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	char filename1[100];
	char filename2[100];
	char buffer;
	
	printf("�л��� ������ �Էµ� ���� �̸�: ");
	scanf("%s", filename1);
	printf("������ ����� ����� ���� �̸�: ");
	scanf("%s", filename2);
	
	if(	(fp1 = fopen(filename1, "r")) == NULL ) {
		fprintf(stderr, "%s�� �� �� �����ϴ�.\n", filename1);
		exit(1);
	}
	if(	(fp2 = fopen(filename2, "w")) == NULL ) {
		fprintf(stderr, "%s�� �� �� �����ϴ�.\n", filename2);
		exit(1);
	}
	fgets(buffer, 100, fp1);
	fprintf(fp2, "NAME\tAVG\n");
	
	while(feof(fp1) == 0) {
		float avg;
		struct student s;
		fscanf(fp1, "%s\t%d\t%d\t%d", s.name, &s.korean, &s.math, &s.english);
		//printf("%d %d %d", s.korean, s.math, s.english); 
		avg = (s.korean + s.math + s.english) / 3;
		fprintf(fp2, "%s\t%.2f\n", s.name, avg);
	}
	fclose(fp1);
	fclose(fp2);
	
	return 0;
} */

// 07 �ȵȴ� 
/* #include <stdio.h>
#define SIZE 30

int main() {
	FILE *fp = NULL;
	char file[SIZE];
	char buffer;
	
	printf("���� �̸��� �Է��Ͻÿ�: ");
	scanf("%s", file);
	
	if(	(fp = fopen(file, "w")) == NULL ) {
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", file);
		exit(1);
	}
		
	while(fgets(buffer, SIZE, stdin) != 0) {
		fputs(buffer, fp);
	}
	fclose(fp);
	
	return 0;
} */

/* 17�� Programming */ 
// 01
/* #include <stdio.h>
#include <stdlib.h>

int main() {
	int *add;
	int n;
	int sum = 0;
	int arr[10];
	
	printf("������ ������ �Է��Ͻÿ�: ");
	scanf("%d", &n);
	add = (int *)malloc(100 * sizeof(int));
	
	if(add == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
		exit(1);
	}
	for(int i = 0; i < n; i++) {
		printf("���� ������ �Է��Ͻÿ�: ");
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	printf("������ ���� %d�Դϴ�.\n", sum);
	
	free(add);
	
	return 0;
} */

// 03
/* #include <stdio.h>
#include <stdlib.h>

typedef struct contacts {
	char name[100];
	char phone_number[100];
} CONTACTS;

int main() {
	CONTACTS *contacts;
	int size;
	
	printf("�ּ��� ����: ");
	scanf("%d", &size);
	
	contacts = (CONTACTS *)malloc(sizeof(CONTACTS)* size);
	
	if(contacts == NULL) {
		printf("���� �޸� �Ҵ� ����");
		exit(1);
	}
	for(int i = 0; i < size; i++) {
		printf("�̸��� �Է��Ͻÿ�: ");
		scanf("%s", &(contacts[i].name));
		printf("�޴��� ��ȣ�� �Է��Ͻÿ�: ");
		scanf("%s", &(contacts[i].phone_number));
	}
	printf("=======================\n");
	printf("�̸� \t �޴��� ��ȣ \n");
	printf("=======================\n");
	for(int i = 0; i < size; i++) {
		printf("%s \t %s", contacts[i].name, contacts[i].phone_number);
	}
	free(contacts);
	
	return 0;
} */

// 04
#include <stdio.h>
#include <stdlib.h>

char *get_word() {
	char *s = (char *)malloc(50);
	
	if(s == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}
	printf("�ܾ �Է��Ͻÿ�(�ִ� 50����): ");
	scanf("%s", s);
	
	return s;
}
int main() {
	char *a;
	a = get_word();
	printf("���� �޸𸮿� ����� �ܾ�� %s�Դϴ�.", a); 
	free(a); 
	
	return 0;
}
