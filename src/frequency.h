#ifndef FREQUENCY_H
#define FREQUENCY_H

struct words
{
    char *word;        //struct words is a binary tree that stores a node and a pointer to the left and right siblings
    int count;
    struct words *left;
    struct words *right;
};

struct words *bintree(struct words **head,char *word);//bintree is a function of type struct words and the 1st arg is a pointer to the bin tree that stores the words
void print_tree(FILE *fout, struct words *head, int total);//print_tree is a function that prints a binary tree
char *readfile(char *filename);//readfile is a function that reads a text file and stores it in a string
void hash_tab_add(int id, char *data);
void print_table(FILE *fout, int total);
int total;//an interger to store the total number of words in the file

#endif
