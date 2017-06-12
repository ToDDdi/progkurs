#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "frequency.h"

void print_tree(struct words *head) {
    if(head == NULL)
        return ;
    print_tree(head->right); //note that print_tree uses the post order traversal to print the tree
    printf("|%-20s | %-5d |\n",head->word,head->count);
    print_tree(head->left);
    return ;   
}

//char *printin (struct words *word, struct words)
char *readfile(char *filename) {
    FILE *fp = fopen(filename,"r");
    if(fp == NULL)
    {
        printf("Файл не найден\n");
        exit(0);
    }
    char *str=NULL;
    if(fp !=NULL){
        fseek(fp,0,SEEK_END); //moves the pointer 2 the end of the file
        long int size = ftell(fp); //ftel determine the size of the file
        rewind(fp); //rewind brings the pointer back to te beginning
        str = malloc(size + 1);
        fread(str,size,1,fp); //fread read the the entire file and stores it in a file.the 1 signifies it is reading the entire file as one block
        fclose(fp);
    }
    return str;
}

struct words *bintree(struct words **head,char *word) {
    
	if(*head == NULL){
        *head = malloc(sizeof(struct words *));//allocate space for the words
        (*head)->word = malloc(sizeof(char) * strlen(word) + 1);
        strcpy((*head)->word,word);
        (*head)->count = 1;
        (*head)->left = (*head)->right = NULL;
        total++;
    }
    else if(strcasecmp((*head)->word,word) < 0) { //strcasecmp compares without considering the cases
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

/*To compile the file just do gcc -o frequency frequency.c

To run the file, just do ./frequency  the-name-of-the-file-you-want-to-count-the-words*/
