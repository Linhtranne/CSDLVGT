#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;
int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == MAX_SIZE - 1;
}

void push(char c)
{
    if (isFull())
    {
        printf("Ngan xep day\n");
        return;
    }
    stack[++top] = c;
}
char pop()
{
    if (isEmpty())
    {
        return '\0';
    }
    return stack[top--];
}

void cleanString(char *input, char *cleaned)
{
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isalnum(input[i]))
        {
            cleaned[j++] = tolower(input[i]);
        }
    }
    cleaned[j] = '\0';
}

int isPalindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        push(str[i]);
    }
    for (int i = (len + 1) / 2; i < len; i++)
    {
        if (str[i] != pop())
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char input[MAX_SIZE];
    char cleaned[MAX_SIZE];
    fgets(input, MAX_SIZE, stdin);
    size_t len = strlen(input);
    if (input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }
    cleanString(input, cleaned);
    if (isPalindrome(cleaned))
    {
        printf("Câu này là đối xứng).\n");
    }
    else
    {
        printf("Câu này không đối xứng\n");
    }

    return 0;
}
