#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "frequency.h"

#ifdef _linux_
setlocale(LC_ALL, "ru_RU.utf-8");
#endif

int main (int argc, char *argv[])
{
if (argc != 3) {
	printf("Usage:\n"
		"./calcfraquency <in-file-name.txt> <out-file-name.txt>\n");
		exit(0);
}	

    char *word=NULL,*str=NULL;
    total = 0;
    struct words *head=NULL;
    if((str = readfile(argv[1])) != NULL)//
    {
        const char* delim = " ,\n\r\t.;:_-()~`|!?><%^&*$#@{}[]0123456789\'\"/";//список всех символов, которые отделяют слова
        word = strtok(str,delim); //разделяет слова используя ключи
        head = bintree(&head, word);
        while((word = strtok(NULL, delim)) != NULL) {
            head = bintree(&head, word);
        }
        FILE *outputfile = fopen(argv[2], "w+");
        printf("Количество слов всего = %d\n",total);
        //fprintf(outputfile, "|%-20s | %-5s |\n%25s\n","WORDS","freq","|============================");
       // for (i = 0; i <=total; i++) {
        print_tree(head);
        //fprintf(outputfile, "|%-20s | %-5d |\n",head->word,head->count);
    //}
}
    return 0;
}

/*To compile the file just do gcc -o frequency frequency.c

To run the file, just do ./frequency  the-name-of-the-file-you-want-to-count-the-words*/
