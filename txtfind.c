#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define LINE 256
#define WORD 30

int getLine(char s[])
{

    char tmp;
    int i;
    for (i = 0; i < LINE; i++)
    {
        tmp = getchar();
        if (tmp != '\n' && tmp != '\r')
        {
            s[i] = tmp;
        }
        else
        {
            break;
        }
    }
    s[i] = '\0';
    return i;
}

int getWord(char w[])
{

    char tmp;
    int count = 0;
    int i;
    for (i = 0; i < WORD; i++)
    {
        tmp = getchar();
        if (tmp != '\n' && tmp != '\t' && tmp != ' ' && tmp != '\r')
        {
            w[i] = tmp;
            count++;
        }
        else
        {
            break;
        }
    }
    w[i] = '\0';
    return count;
}

int substring(char *str1, char *str2)
{

    char *ptr1 = str1;
    char *ptr2 = str2;
    int j = 0;
    for (int i = 0; i < strlen(str1) && j < strlen(str2); i++)
    {
        if (*(ptr1 + sizeof(char) * i) == *(ptr2 + sizeof(char) * j))
        {
            j++;
        }
        else
        {
            j = 0;
        }
    }
    if (j == strlen(str2))
    {
        return 1;
    }
    return 0;
}

int similar(char *s, char *t, int n)
{

    if (!strcmp(s, t))
    {
        return 1;
    }
    if (n > strlen(s))
    {
        return 0;
    }
    if (substring(s, t) && (strlen(s) - strlen(t) == n))
    {
        return 1;
    }
    int j = 0;
    int check_n = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (*(s+i) ==*(t+j))
        {
            j++;
        }
        else
        {
            check_n++;
        }
    }
    if (check_n != n)
    {
        return 0;
    }
    if (j == strlen(t))
    {
        return 1;
    }
    return 0;
}

void print_lines(char *str)
{

    char Line[LINE];
    for (int i = 0; i < 250; i++)
    {
        getLine(Line);
        if (substring(Line, str))
        {
            printf("%s\n", Line);
        }
        bzero(Line, LINE);
    }
}

void print_similar_words(char *str)
{

    char Word[WORD];
    for (int i = 0; i < 250; i++)
    { // The amount of lines double the amount of word in a line
        getWord(Word);
        if (similar(Word, str, 1))
        {
            printf("%s\n", Word);
        }
        bzero(Word, WORD);
    }
}


int main()
{
    // char str [LINE]="";
    // int a = getLine(str);
    // int b = getWord(str);
    // printf("%s \n",str);
    // int c = similar("cats","cat",1);
    // printf("%d \n",c);
    //print_similar_words("cat");

    char Word[WORD]; 
    getWord(Word);
    char choose_file=getchar();
    if(choose_file=='a'){
        print_lines(Word);
    }
    else{
        print_similar_words(Word);
    }
     

    return 0;
}
