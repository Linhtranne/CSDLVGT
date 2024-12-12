#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char data[MAX];
    int top;
} stack;

bool isEmpty(stack *s)
{
    return s->top == -1;
}

bool isFull(stack *s)
{
    return s->top == MAX - 1;
}

bool push(stack *s, char value)
{
    if (isFull(s))
    {
        printf("Ngan xep day!\n");
        return false;
    }
    s->data[++(s->top)] = value;
    return true;
}

bool pop(stack *s, char *value)
{
    if (isEmpty(s))
    {
        printf("Ngan xep rong!\n");

        return false;
    }
    *value = s->data[(s->top)--];
    return true;
}

bool peek(stack *s, char *value)
{
    if (isEmpty(s))
    {
        printf("Ngan xep rong!\n");

        return false;
    }
    *value = s->data[s->top];
    return true;
}

void printstack(stack *s)
{
    if (isEmpty(s))
    {
        printf("Ngan xep rong!\n");
        return;
    }
    printf("Cac phan tu cua stack:\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%c", s->data[i]);
    }
    printf("\n");
}

int main()
{
    stack s;
    s.top = -1;
    char string[100];
    printf("Nhap chuoi: ");
    fgets(string, sizeof(string), stdin);
    char value;
    for (int i = 0; i < strlen(string); i++)
    {
        switch (string[i])
        {
        case '(':
            push(&s, string[i]);
            break;
        case '{':
            push(&s, string[i]);
            break;
        case '[':
            push(&s, string[i]);
            break;
        case ')':
            if (pop(&s, &value))
            {
                if (value != '(')
                {
                    printf("Bieu thuc ko hop le");
                    return 0;
                }
            }

            break;
        case '}':
            if (pop(&s, &value))
            {
                if (value != '{')
                {
                    printf("Bieu thuc ko hop le");
                    return 0;
                }
            }

            break;
        case ']':
            if (pop(&s, &value))
            {
                if (value != '[')
                {
                    printf("Bieu thuc ko hop le");
                    return 0;
                }
            }
            break;
        default:
            break;
        }
    }
    printf("bieu thuc hop le");
    return 0;
}