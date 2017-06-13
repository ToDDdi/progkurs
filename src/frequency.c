#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "frequency.h"

struct hash_tab
{
    char *data;
    struct hash_tab *next;
};

struct hash_tab **table;

void hash_tab_add(int id, char *data)
{
    if (table != NULL)
    {
        struct hash_tab *newElement = (struct hash_tab*)malloc(sizeof(struct hash_tab));
        if (newElement != NULL)
        {
            newElement->data = data;
            newElement->next = table[id] ? table[id] : NULL;
            table[id] =  newElement;
        }
    }
}

void _print_tree(struct words *head, int total)
{
    if (head == NULL)
        return ;
    _print_tree(head->right, total);
    int id = head->count % total;
    if (head->count >= 2) {
    hash_tab_add(id, head->word);
}
    _print_tree(head->left, total);

}

void print_table(FILE *fout, int total)
{
    if (table)
    {
        if (table[0] != NULL)
        {
            fprintf(fout, "|%-20s | %-5d |\n", table[0]->data, total);
        }
        else
        {
            int id = total - 1;
            for (; id > 0; --id)
            {
                struct hash_tab *val = table[id];
                while(val != NULL)
                {
                    fprintf(fout, "|%-20s | %-5d |\n", val->data, id);
                    val = val->next;
                }
            }
        }
    }
}

void print_tree(FILE *fout, struct words *head, int total) {
    if(fout == NULL || head == NULL)
        return ;
    
    table = calloc(total, sizeof(struct hash_tab*)); //получает элементы и их размер
    _print_tree(head, total);
    print_table(fout, total);
    return;   
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
