// WordList.cpp: определяет точку входа для консольного приложения.
//
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#include<ctype.h>
typedef struct List {
	int cnt;
	char *word;
	struct List * next;
} List;

List *list_add(List *head, char *s) {
	List *a, *b;
	a = (List*)malloc(sizeof(List));
	//a->word = (char*)malloc(40 * sizeof(char));
	(a->word) = s;
	a->next = NULL;
	if (head == NULL) {
		return a;
	}
	a->next = head;
	return a;
}
List *list_add1(List *head, char *s) {
	List *a, *b;
	a = (List*)malloc(sizeof(List));
	(a->word) = s;
	a->next = NULL;
	if (head == NULL) {
		return a;
	}
	head->next = a;
	return a;
}

int main() {
	List *a, *b, *f;
	char *c;
	int sum = 0;
	int i=1,j=0,k=0;
	FILE * fp,*fo;
	a = NULL;
	b = NULL;
	fp = fopen("input.txt", "r");
	fo = fopen("output.txt", "w");
	c = (char*)malloc(10 * sizeof(char));
	fscanf(fp, "%s ", c);
	a = list_add1(a, c);
	a->cnt = 0;
	b = a;
	c = (char*)malloc(10 * sizeof(char));
	while (fscanf(fp, "%s ", c) != -1) {
       a = list_add1(a, c);
	   a->cnt = 0;
	   c = (char*)malloc(10 * sizeof(char));
	}
	f = b;
	a = b;
	 while (a != NULL) {
		b = a;
		if (isupper((b->word)[0])) {
			while (b != NULL) {
				if (strcmp(a->word, b->word) == 0) {
					if (j > 0) {
						if (b->cnt == 0) {
							b->cnt = i;
							k++;
						}
					}
				}
				j++;
				b = b->next;
			}
		}
		if (k > 0) {
			i++;
		}
		j = 0;
		k = 0;
		a = a->next;
	} 
	a = f;
	while (a != NULL) {
		if (a->cnt == 0) {
			fprintf(fo,"%s ",a->word);
		}
		else {
			fprintf(fo, "[%d] ", a->cnt);
		}
		a = a->next;
	}
	fclose(fp);
	fclose(fo);
	return 0;
}