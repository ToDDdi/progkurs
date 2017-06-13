#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "frequency.h"

void print_tree(struct words *head) {
    if(head == NULL)
        return ;
    print_tree(head->right); //использует обход в глубину
    if(head->count >= 2) {
	printf("|%-20s | %-5d |\n",head->word,head->count);
    }
    print_tree(head->left);
    return ;   
}

char *readfile(char *filename) {
    FILE *fp = fopen(filename,"r");
    if(fp == NULL)
    {
        printf("Файл не найден\n");
        exit(0);
    }
    char *str=NULL;
    if(fp !=NULL){
        fseek(fp,0,SEEK_END); //перемещает указатель в конец файла
        long int size = ftell(fp); //определяет размер файла
        rewind(fp); //возвращает указатель обратно к началу
        str = malloc(size + 1);
        fread(str,size,1,fp); //Fread читает весь файл и сохраняет его в файле. 1 означает, что он считывает весь файл как один блок
        fclose(fp);
    }
    return str;
}

struct words *bintree(struct words **head,char *word) {
    
	if(*head == NULL){
        *head = malloc(sizeof(struct words *));//Выделение места для слов
        (*head)->word = malloc(sizeof(char) * strlen(word) + 1);
        strcpy((*head)->word,word);
        (*head)->count = 1;
        (*head)->left = (*head)->right = NULL;
        total++;
    }
    else if(strcasecmp((*head)->word,word) < 0) { //Сравнивает без рассмотрения случаев
        bintree(&(*head)->left,word);
    }
    else if(strcasecmp((*head)->word,word) > 0) {
        bintree(&(*head)->right,word);
    }
    else {
        (*head)->count++;
        total++;
    }
    return *head;

} 

