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
	printf("Максимов Александр\n");
	printf("ЛР23 Задача 1\n");
	// Входной файл
	FILE* fin = fopen("C:\\Users\\Александр\\Desktop\\Labs\\oaip\\Files_for_problems\\text1in.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	// Выходной файл
	FILE* fout;
	fout = fopen("C:\\Users\\Александр\\Desktop\\Labs\\oaip\\Files_for_problems\\text1out.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	// в цикле для всех строк
	while (!feof(fin)) {
		// загрузить строку
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// обработать загруженную строку
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == '\t') // Если прочитан пробел
					s[i] = '%'; // Заменяем его на '%’
			}
			// сохранить строку в выходной файл
			fprintf(fout, "%s", s);
			printf(">>%s\n", s);
		}
	}
	// закрыли файлы
	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 1 FINISH\n");
}
void problem3() {
	printf("Максимов Александр\n");
	printf("ЛР23 Задача 3\n");
	// Входной файл
	FILE* fin = fopen("C:\\Users\\Александр\\Desktop\\Labs\\oaip\\Files_for_problems\\text3in.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	// Выходной файл
	FILE* fout;
	fout = fopen("C:\\Users\\Александр\\Desktop\\Labs\\oaip\\Files_for_problems\\text3out.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	// в цикле для всех строк
	while (!feof(fin)) {
		// загрузить строку
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// обработать загруженную строку
			for (int i = 0; s[i] != '\0'; i++) {
				if (isalpha(s[i])) { // Если прочитан пробел
					s[strlen(s) - 1] = '#'; // Заменяем его на '%’
					break;
				}
			}
			// сохранить строку в выходной файл
			fprintf(fout, "%s", s);
			printf(">>%s\n", s);
		}
	}
	// закрыли файлы
	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 3 FINISH\n");
}
void problem4() {
	printf("Максимов Александр\n");
	printf("ЛР23 Задача 4\n");
	// Входной файл
	FILE* fin = fopen("C:\\Users\\Александр\\Desktop\\Labs\\oaip\\Files_for_problems\\filename.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	// в цикле для всех строк
	while (!feof(fin)) {
		// загрузить строку
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// обработать загруженную строку
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
	// закрыли файлы
	fclose(fin);

	printf("ЛР23 Задача 3 FINISH\n");
}
void problem5(){
	char filenameIn[] = "C:\\Users\\Александр\\Desktop\\Labs\\oaip\\Files_for_problems\\filename.txt";
	char filenameHTML[] = "C:\\Users\\Александр\\Desktop\\Labs\\oaip\\Files_for_problems\\filename_out.txt";
	printf("BEGIN!!!\n");
	FILE* fin = fopen(filenameIn, "rt");
	if (fin == NULL) {
		// если файл не смогли открыть - сообщаем об этом
		printf("File %s doesn't opened!\n", filenameIn);
		return;
	}
	FILE* fout = fopen(filenameHTML, "wt");
	if (fout == NULL) {
		// закрываем ранее успешно открытый входной файл 
		fclose(fin);
		// если файл не смогли открыть - сообщаем об этом
		printf("File %s doesn't opened!\n", filenameHTML);
		return;
	}
	// Выводим в выходной файл заголовок HTML документа
	fprintf(fout, "<!DOCTYPE html>");
	fprintf(fout, "<html>");
	fprintf(fout, "<head>");
	fprintf(fout, "<meta http - equiv = \"Content-Type\" content = 	\"text/html; charset=utf-8\" />");
	fprintf(fout, "<title>HTML Document</title>");
	fprintf(fout, "</head>");
	fprintf(fout, "<body>");
	int ch;
	while ((ch = getc(fin)) != EOF) {
		// в HTML файл добавляем только что прочитанный 
		// символ "КАК ЕСТЬ"
		fprintf(fout, "%c", ch);

		// если в тексте был символ новой строки – 
		// в HTML добавляем тег <BR> - новая строка
		if (ch == '\n')
			fprintf(fout, "<br>");

	}

	// выводит в HTML завершающие теги документа HTML
	fprintf(fout, "</body>");
		fprintf(fout, "</html>");
		// Закрываем файл с текстом
		fclose(fin);

		// Закрываем HTML файл 
		fclose(fout);
	printf("END!!!\n");

}
void problem6(){
	printf("Максимов Александр\n");
	printf("ЛР23 Задача 6\n");
	// Входной файл
	FILE* fin = fopen("C:\\Users\\Александр\\Desktop\\Labs\\oaip\\Files_for_problems\\text6in.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	// Выходной файл
	FILE* fout;
	fout = fopen("C:\\Users\\Александр\\Desktop\\Labs\\oaip\\Files_for_problems\\text6out.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	// в цикле для всех строк
	while (!feof(fin)) {
		// загрузить строку
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// обработать загруженную строку
			int k = 0;
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == ';')k++;
			}
			
			for (int i = 0; i < strlen(s) - 1; i++) {
				fprintf(fout, "%c", s[i]);
			}

			// сохранить строку в выходной файл
			fprintf(fout, "%d", k);
			fprintf(fout, "\n");
			printf(">>%s\n", s);
		}
	}
	// закрыли файлы
	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 3 FINISH\n");
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
