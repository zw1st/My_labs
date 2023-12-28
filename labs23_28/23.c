#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#define MAX_LEN 80
char s[MAX_LEN];

void cat(char s1[], char s2[]) {
	int l = strlen(s1);
	int i = 0;
	while (s2[i] != '\0') {
		s1[l] = s2[i];
		i++;
		l++;
	}
}
void problem1() {
	printf("�������� ���������\n");
	printf("��23 ������ 1\n");
	// ������� ����
	FILE* fin = fopen("C:\\Users\\���������\\Desktop\\Labs\\oaip\\Files_for_problems\\text1in.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	// �������� ����
	FILE* fout;
	fout = fopen("C:\\Users\\���������\\Desktop\\Labs\\oaip\\Files_for_problems\\text1out.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	}
	// � ����� ��� ���� �����
	while (!feof(fin)) {
		// ��������� ������
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// ���������� ����������� ������
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == '\t') // ���� �������� ������
					s[i] = '%'; // �������� ��� �� '%�
			}
			// ��������� ������ � �������� ����
			fprintf(fout, "%s", s);
			printf(">>%s\n", s);
		}
	}
	// ������� �����
	fclose(fin);
	fclose(fout);

	printf("��23 ������ 1 FINISH\n");
}
void problem3() {
	printf("�������� ���������\n");
	printf("��23 ������ 3\n");
	// ������� ����
	FILE* fin = fopen("C:\\Users\\���������\\Desktop\\Labs\\oaip\\Files_for_problems\\text3in.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	// �������� ����
	FILE* fout;
	fout = fopen("C:\\Users\\���������\\Desktop\\Labs\\oaip\\Files_for_problems\\text3out.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	}
	// � ����� ��� ���� �����
	while (!feof(fin)) {
		// ��������� ������
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// ���������� ����������� ������
			for (int i = 0; s[i] != '\0'; i++) {
				if (isalpha(s[i])) { // ���� �������� ������
					s[strlen(s) - 1] = '#'; // �������� ��� �� '%�
					break;
				}
			}
			// ��������� ������ � �������� ����
			fprintf(fout, "%s", s);
			printf(">>%s\n", s);
		}
	}
	// ������� �����
	fclose(fin);
	fclose(fout);

	printf("��23 ������ 3 FINISH\n");
}
void problem4() {
	printf("�������� ���������\n");
	printf("��23 ������ 4\n");
	// ������� ����
	FILE* fin = fopen("C:\\Users\\���������\\Desktop\\Labs\\oaip\\Files_for_problems\\filename.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	// � ����� ��� ���� �����
	while (!feof(fin)) {
		// ��������� ������
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// ���������� ����������� ������
			int start = -1;
			int end;
			for (int i = 0; s[i] != '\0'; i++) {
				if (isalpha(s[i])) {
					if (start == -1) { start = i; }
					end = i;
				}
				else if(start != -1){
					printf("<WORD>");
					for (int j = start; j <= end; j++) {
						printf("%c", s[j]);
					}
					printf("</WORD>\n");
					start = -1;
					printf("<DELIM>%c</DELIM>\n", s[i]);
				}
				else {
					printf("<DELIM>%c</DELIM>\n", s[i]);
				}
			}
			printf(">>%s\n", s);
		}
	}
	// ������� �����
	fclose(fin);

	printf("��23 ������ 3 FINISH\n");
}
void problem5(){
	char filenameIn[] = "C:\\Users\\���������\\Desktop\\Labs\\oaip\\Files_for_problems\\filename.txt";
	char filenameHTML[] = "C:\\Users\\���������\\Desktop\\Labs\\oaip\\Files_for_problems\\filename_out.txt";
	printf("BEGIN!!!\n");
	FILE* fin = fopen(filenameIn, "rt");
	if (fin == NULL) {
		// ���� ���� �� ������ ������� - �������� �� ����
		printf("File %s doesn't opened!\n", filenameIn);
		return;
	}
	FILE* fout = fopen(filenameHTML, "wt");
	if (fout == NULL) {
		// ��������� ����� ������� �������� ������� ���� 
		fclose(fin);
		// ���� ���� �� ������ ������� - �������� �� ����
		printf("File %s doesn't opened!\n", filenameHTML);
		return;
	}
	// ������� � �������� ���� ��������� HTML ���������
	fprintf(fout, "<!DOCTYPE html>");
	fprintf(fout, "<html>");
	fprintf(fout, "<head>");
	fprintf(fout, "<meta http - equiv = \"Content-Type\" content = 	\"text/html; charset=utf-8\" />");
	fprintf(fout, "<title>HTML Document</title>");
	fprintf(fout, "</head>");
	fprintf(fout, "<body>");
	int ch;
	while ((ch = getc(fin)) != EOF) {
		// � HTML ���� ��������� ������ ��� ����������� 
		// ������ "��� ����"
		fprintf(fout, "%c", ch);

		// ���� � ������ ��� ������ ����� ������ � 
		// � HTML ��������� ��� <BR> - ����� ������
		if (ch == '\n')
			fprintf(fout, "<br>");

	}

	// ������� � HTML ����������� ���� ��������� HTML
	fprintf(fout, "</body>");
		fprintf(fout, "</html>");
		// ��������� ���� � �������
		fclose(fin);

		// ��������� HTML ���� 
		fclose(fout);
	printf("END!!!\n");

}
void problem6(){
	printf("�������� ���������\n");
	printf("��23 ������ 6\n");
	// ������� ����
	FILE* fin = fopen("C:\\Users\\���������\\Desktop\\Labs\\oaip\\Files_for_problems\\text6in.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	// �������� ����
	FILE* fout;
	fout = fopen("C:\\Users\\���������\\Desktop\\Labs\\oaip\\Files_for_problems\\text6out.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	}
	// � ����� ��� ���� �����
	while (!feof(fin)) {
		// ��������� ������
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// ���������� ����������� ������
			int k = 0;
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == ';')k++;
			}
			
			for (int i = 0; i < strlen(s) - 1; i++) {
				fprintf(fout, "%c", s[i]);
			}

			// ��������� ������ � �������� ����
			fprintf(fout, "%d", k);
			fprintf(fout, "\n");
			printf(">>%s\n", s);
		}
	}
	// ������� �����
	fclose(fin);
	fclose(fout);

	printf("��23 ������ 3 FINISH\n");
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//problem1();
	//problem3();
	//problem4();
	//problem5();
	//problem6();
}
