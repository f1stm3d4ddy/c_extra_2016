// wordlist.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include < string.h >

typedef struct word {
	int cnt = 0;
	int nomb = 0;
	char *pword;
	struct word *next;
} word;

int k=0;

/*void push(word **head, char * data) {
	word *tmp = (word*)malloc(sizeof(word));
	tmp->pword = data;
	k++;
	tmp->cnt = k;
	tmp->next = *head;
	*head = tmp;
}

word* getN(word* head, int n) {
	int counter = 0;
	while (counter < n && head) {
		head = head->next;
		counter++;
	}
	return head;
}
*/
void push1(word **head, char * data) {
	word *tmp = (word*)malloc(sizeof(word));
	tmp->pword = (char*)malloc(40 * sizeof(char));
	memmove(tmp->pword, data, 40 * sizeof(char));
	///tmp->pword = data;
	k++;
	tmp->nomb = k;
	tmp->next = (*head);
	(*head) = tmp;
}

void push2(word **head, word *one) {
	word *tmp = (word*)malloc(sizeof(word));
	tmp->cnt = one->nomb;
	tmp->next = (*head);
	(*head) = tmp;
}

word * nthToLast(word  * head, char * uWord) {
	if (head == NULL) {
		return NULL;
	}
	word * dp = nthToLast(head->next, uWord);
	//printf("%p\n%p\n", *(head->pword), *uWord);
	if (strcmp((head->pword), uWord) == 0) {
		return head;
	}			
	return dp;
}

void printLinkedList(const word *head) {
	while (head) {
		if(head->cnt > 0)
			printf("%d ", head->cnt);
		else
			printf("%s ", head->pword);
		head = head->next;
	}
	printf("\n");
}
/*
int main()
{
	int i;
	int check = 0;
	int n = 0;
	word b;
	word *a;
	a = (word*)malloc(sizeof(word));
	a->next = NULL;
	a->cnt = 0;
	((*a).pword) = "";
	char *s;
	s = (char*)malloc(40 * sizeof(char));
	FILE *fp;
	fp = fopen("article.txt", "r");
	FILE *fp1;
	fp1 = fopen("article1.txt", "w");
	while (fscanf(fp, "%s", s) == 1) {
		if (isupper(s[0])) {
			for (i = 0; i < n; i++) {
				if (*s == *((*getN(a, n)).pword)) {
					check = 1;
					fprintf(fp1, "[%d] ", (*getN(a, n)).cnt);
					break;
				}
			}
			if (check==0) {
				push(&a, s);
				fprintf(fp1, "%s ", s);
				n++;
			}
			check = 0;
		}
		else {
			fprintf(fp1, "%s ", s);
		}
	}
	fclose(fp);
	fclose(fp1);
    return 0;
}*/
/*
int main() {
	word *a, *b, *r;
	a = (word*)malloc(sizeof(word));
	b = (word*)malloc(sizeof(word));
	char *c;
	c = (char*)malloc(20 * sizeof(char));
	FILE *pfile;
	pfile = fopen("article.txt", "r");
	FILE *pfile1;
	pfile1 = fopen("article1.txt", "w");
	do {
		fscanf(pfile, "%s", c);
		if (isupper(c[0])) {
			a->cnt = 1;
			a->pword = c;
			a->next = NULL;
		}
		fprintf(pfile1, "%s ", c);
	} while (isupper(c[0]) != 0);

	do {
		fscanf(pfile, "%s", c);
		if (isupper(c[0])) {
			if (*c != *(a->pword)) {
				b->cnt = 2;
				b->pword = c;
				b->next = NULL;
				a->next = b;
			}
			else
			{
				fprintf(pfile1, "[1]");
			}

		}
		fprintf(pfile1, "%s ", c);
	} while (isupper(c[0]) != 0);


	while (fscanf(pfile, "%s", c))
	{
		if (isupper(c[0])) {
			a->cnt = 1;
			a->pword = c
		}
	}

	return 0;
}*/
//////////////////////////////////////////////////////////

int main() {
	FILE *pfile;
	char *s;
	word *b, *a = NULL;
	s = (char*)malloc(40 * sizeof(char));

	pfile = fopen("article.txt", "r");

	while (fscanf(pfile, "%s", s) == 1) {
		if (isupper(s[0])) {
			b = nthToLast(a, s);
			if (b)
				push2(&a, b);
			else
				push1(&a, s);
		}
	}
	printLinkedList(a);
	return 0;
}