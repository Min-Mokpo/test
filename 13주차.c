/* 15장 Programming */
// 01
/* #include <stdio.h>

int main() {
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	
	fp1 = fopen("text1.txt", "w");
	fp2 = fopen("text2.txt", "w");
	
//	fp1 = fopen("text1.txt", "r");
	if(fp1 == NULL)
		printf("파일 열기 실패\n");
	
//	fp2 = fopen("text2.txt", "r"); 
	if(fp2 == NULL)
		printf("파일 열기 실패\n");
		
	fputc('a', fp1);
	
	while(1) {
		if(fgetc(fp1) == fgetc(fp2)) {
			printf("두 파일은 서로 같습니다.\n");
			break;
		}
		else if(fgetc(fp1) != fgetc(fp2)) {
			printf("두 파일은 서로 다릅니다.\n");
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
	
	printf("원본 파일 이름: ");
	scanf("%s", file1);
	printf("복사 파일 이름: ");
	scanf("%s", file2);
	
	if(	(fp1 = fopen(file1, "rb")) == NULL ) {
		fprintf(stderr, "원본 파일 %s를 열 수 없습니다.\n", file1);
		exit(1);
	}
	if(	(fp2 = fopen(file2, "wb")) == NULL ) {
		fprintf(stderr, "복사 파일 %s를 열 수 없습니다.\n", file2);
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
	
	printf("학생의 성적이 입력된 파일 이름: ");
	scanf("%s", filename1);
	printf("성적의 평균을 기록할 파일 이름: ");
	scanf("%s", filename2);
	
	if(	(fp1 = fopen(filename1, "r")) == NULL ) {
		fprintf(stderr, "%s를 열 수 없습니다.\n", filename1);
		exit(1);
	}
	if(	(fp2 = fopen(filename2, "w")) == NULL ) {
		fprintf(stderr, "%s를 열 수 없습니다.\n", filename2);
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

// 07 안된다 
/* #include <stdio.h>
#define SIZE 30

int main() {
	FILE *fp = NULL;
	char file[SIZE];
	char buffer;
	
	printf("파일 이름을 입력하시오: ");
	scanf("%s", file);
	
	if(	(fp = fopen(file, "w")) == NULL ) {
		fprintf(stderr, "원본 파일 %s를 열 수 없습니다.\n", file);
		exit(1);
	}
		
	while(fgets(buffer, SIZE, stdin) != 0) {
		fputs(buffer, fp);
	}
	fclose(fp);
	
	return 0;
} */

/* 17장 Programming */ 
// 01
/* #include <stdio.h>
#include <stdlib.h>

int main() {
	int *add;
	int n;
	int sum = 0;
	int arr[10];
	
	printf("정수의 개수를 입력하시오: ");
	scanf("%d", &n);
	add = (int *)malloc(100 * sizeof(int));
	
	if(add == NULL) {
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	for(int i = 0; i < n; i++) {
		printf("양의 정수를 입력하시오: ");
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	printf("정수의 합은 %d입니다.\n", sum);
	
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
	
	printf("주소의 개수: ");
	scanf("%d", &size);
	
	contacts = (CONTACTS *)malloc(sizeof(CONTACTS)* size);
	
	if(contacts == NULL) {
		printf("동적 메모리 할당 오류");
		exit(1);
	}
	for(int i = 0; i < size; i++) {
		printf("이름을 입력하시오: ");
		scanf("%s", &(contacts[i].name));
		printf("휴대폰 번호를 입력하시오: ");
		scanf("%s", &(contacts[i].phone_number));
	}
	printf("=======================\n");
	printf("이름 \t 휴대폰 번호 \n");
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
		printf("메모리 할당 오류\n");
		exit(1);
	}
	printf("단어를 입력하시오(최대 50글자): ");
	scanf("%s", s);
	
	return s;
}
int main() {
	char *a;
	a = get_word();
	printf("동적 메모리에 저장된 단어는 %s입니다.", a); 
	free(a); 
	
	return 0;
}
