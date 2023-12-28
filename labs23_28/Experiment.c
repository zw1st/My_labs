#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "SortString.h"

char filename[] = "C:\\Users\\���������\\Desktop\\Labs\\oaip\\Files_for_problems\\dict1.txt";
void main() {
	char words[7][10] = { "abra", "codabra", "cadabra", "abraham", "aaa", "AbaA", "bfbb" };
	n = 7;
	// t0 - ������� ������ ������� �� ������ ��������� �� ������� ����� � ������� main()
	long t0 = clock();
	printf("t0 = %.3f sec \n", t0 / (float)CLOCKS_PER_SEC);

	LoadWords(filename);
	// �������� ����� ������ ��������������
	printf("Experiment with array lenth = %d, file = %s\n", n, filename);

	// t1 - ������� ������ ������� �� ������ ��������� �� ��������� �������� 	�������
	int t1 = clock();
	printf("t1 = %.3f sec \n", t1 / (float)CLOCKS_PER_SEC);
	for (int i = 0; i < 1; i++) {
		fillArrayStrings();
		bubble_sort();
		//SelectionSortStrings();
		//QuickSortStrings();

		if (!isSortedStrings()) {
			printf("Array is not sorted!!!\n");
		}
	}

	// t2 - ������� ������ ������� �� ������ ��������� �� ��������� ����������
	long t2 = clock();
	printf("t2 = %.3f sec \n", t2 / (float)CLOCKS_PER_SEC);

	printf("t1 - t0 = %.3f sec (Run time of array loading)\n",
		(t1 - t0) / (float)CLOCKS_PER_SEC);
	printf("t2 - t1 = %.3f sec (Run time of sorting)\n",
		(t2 - t1) / (float)CLOCKS_PER_SEC);
}
