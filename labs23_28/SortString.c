#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "SortString.h"

static char filename[] = "c:\\Temp\\Lection15_2023\\dict0.txt";

// Максимальная длина слова в массиве
#define MAX_LEN_WORD 80
// Максимальное количество слов
#define MAX_WORDS 20000

// Слова, загруженные из файла 
char words[MAX_WORDS][MAX_LEN_WORD + 1];
// Количество слов в массиве
int n = 0;

// Массив для сортировки 
char a[MAX_WORDS][MAX_LEN_WORD + 1];

int getNextDelim(FILE* fp, char token[]);
int getNextWord(FILE* fp, char token[]);
//void printElements() {
//	printf("< ");
//
//	for (int i = 0; i < n; i++) {
//		printf("%d ", arr[i]);
//	}
//
//	printf(">\n");
//}
//void QuickSortStrings() {
//	qsort(a, n, sizeof(a[0]), strcmp);
//}
//void fillArray() {
//	for (int i = 0; i < n; i++) {
//		arr[i] = arr1[i];
//	}
//}
//void bubble_sort() {
//	for (int i = NUM_ELEMENTS - 1; i > 0; i--) {
//		for (int j = 0; j < i; j++) {
//			if (arr[j] > arr[j + 1]) {
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//void select_sort() {
//	for (int i = 0; i + 1 < NUM_ELEMENTS; i++) {
//		int min = i;
//		for (int j = i + 1; j < NUM_ELEMENTS; j++) {
//			if (arr[j] < arr[min]) {
//				min = j;
//			}
//		}
//		if (i != min) {
//			int temp = arr[i];
//			arr[i] = arr[min];
//			arr[min] = temp;
//		}
//	}
//}
//void insert_sort() {
//	for (int pos = 1; pos < n; pos++) {
//		int value = arr[pos];
//		int i = pos;
//		while ((i > 0) && (value < arr[i - 1])) {
//			arr[i] = arr[i - 1];
//			i--;
//		}
//		arr[i] = value;
//	}
//
//}
//int binary_search(int value) {
//	int left = 0;
//	int right = NUM_ELEMENTS - 1;
//
//	while (left <= right) {
//		int middle = (right + left) / 2;
//		if (arr[middle] == value) {
//			return middle;
//		}
//		else if (value > arr[middle]) {
//			left = middle + 1;
//		}
//		else if (value < arr[middle]) {
//			right = middle - 1;
//		}
//	}
//	return -1;
//}


int LoadWords(char* filename) {
	// открыть файл
	FILE* fin = fopen(filename, "rt");
	if (fin == NULL) {
		// если файл не смогли открыть - сообщаем об этом
		printf("File %s doesn't opened!\n", filename);
		return 0;
	}

	char token[MAX_LEN_WORD + 1];
	// пока не конец файла
	while (!feof(fin)) {
		// пока есть разделитель - берем его
		while (getNextDelim(fin, token)) {
		}
		// если есть слово - берем его
		if (getNextWord(fin, token)) {
			if (n < MAX_WORDS) {
				strcpy(words[n], token);
				n++;
			}
			else {
				printf("Words are more than elements in array!!\n", filename);
				fclose(fin);
				return 0;
			}
		}
	}
	// Закрываем файл с текстом
	fclose(fin);
	return 1;
}
int isalpha_my(unsigned char ch) {

	if (isalpha(ch))
		return 1;

	// ANSI кодировка!!!
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 255)
		return 1;

	return 0;
}
int getNextDelim(FILE* fp, char token[])
{
	int ch = getc(fp);
	if (ch == EOF) {
		return 0;
	}
	if (isalpha_my((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
		return 1;
}
int getNextWord(FILE* fp, char token[])
{
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < MAX_LEN_WORD)) {
		if (!isalpha_my((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';
		if (i == 0)
			return 0;
	return 1;
}
void fillArrayStrings() {

	for (int i = 0; i < n; i++) {
		strcpy(a[i], words[i]);
	}

}
int isSortedStrings() {
	for (int i = 0; i < n - 1; i++) {
		if (strcmp(a[i], a[i + 1]) > 0) {
			return 0;
		}
	}
	return 1;
}
void SelectionSortStrings() {
	for (int i = 0; i < n - 1; i++) {

		int iMin = i;
		for (int j = i + 1; j < n; j++) {
			if (strcmp(a[j], a[iMin]) < 0) {
				iMin = j;
			}
		}

		if (i != iMin) {
			char tmp[MAX_LEN_WORD + 1];
			strcpy(tmp, a[i]);
			strcpy(a[i], a[iMin]);
			strcpy(a[iMin], tmp);
		}
	}
}
void QuickSortStrings() {
	qsort(a, n, sizeof(a[0]), strcmp);
}
