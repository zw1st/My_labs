#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int my_strlen(char s[]) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

int my_strcmp(char s1[], char s2[]) {
	int i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	return s1[i] - s2[i];

}

void my_strcopy(char s1[], char s2[]) {
	int i = -1;
	do {
		i++;
		s1[i] = s2[i];
		
	} while (s2[i] != '\0');

}


void ch_to_ch_plus_19(char s) {
	for (int i = s; i <= s + 19; i++) {
		printf("Символ - %c, ее код - %d\n", i, i);
	}
}
void ch_to_ch_minus_29(char s) {
	for (int i = s; i >= s - 29 && i >= 0; i--) {
		printf("Символ - %c, ее код - %d\n", i, i);
	}
}
int amount_of_space() {
	char s[80];
	printf("Введите строку:\n");
	fgets(s, 79, stdin);
	int c = 0;
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == ' ') {
			c++;
		}
		i++;
	}
	return c;
}
void space_to_sharp() {
	char s[80];
	printf("Введите строку:\n");
	fgets(s, 79, stdin);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')
		{
			s[i] = '#';
		}
	}
	printf("%s", s);
}
void numbers_to_dollar() {
	char s[80];
	printf("Введите строку:\n");
	fgets(s, 79, stdin);
	for (int i = 0; i < strlen(s); i++) {
		if (isdigit(s[i]))s[i] = '$';
	}
	printf("%s", s);
}
void another_number_to_dollar() {
	char s[80];
	printf("Введите строку:\n");
	fgets(s, 79, stdin);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= '0' && s[i] <= '9')s[i] = '$';
	}
	printf("%s", s);
}
int upper_all(int c) {
	int new_c = c;
	if ('a' <= c && c <= 'z')
		new_c = 'A' + (c - 'a');
	if (c >= 'а' && c <= 'п')
		new_c = 'А' + (c - 'а');
	if (c >= 'р' && c <= 'я')
		new_c = 'Р' + (c - 'р');
	if (c == 'ё')
		new_c = 'Ё';
	return new_c;
}
void upper() {
	char s[80];
	printf("Введите строку:\n");
	fgets(s, 79, stdin);
	for (int i = 0; i < strlen(s); i++) {
		s[i] = upper_all(s[i]);
	}
	printf("%s", s);
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//ch_to_ch_plus_19('a');
	//ch_to_ch_minus_29('');
	//printf("%d", amount_of_space());
	//space_to_sharp();
	//upper();
	//printf("%d\n", my_strlen("12345678"));
	//printf("%d\n", my_strcmp("abcd", "aaaa"));
	//printf("%d\n", my_strcmp("abcd", "abcda"));

	char string1[20] = "";
	char string2[20] = "two apples";
	my_strcopy(string1, string2);
	printf("%s", string1);
}
