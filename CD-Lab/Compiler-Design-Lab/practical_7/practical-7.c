#include <stdio.h>
#include <string.h>

char stack[20];
char input[20];
int top = -1;
int i = 0;

void push(char c)
{
    stack[++top] = c;
}

void pop(int n)
{
    top = top - n;
}

void display()
{
    int j;
    for (j = 0; j <= top; j++)
        printf("%c", stack[j]);
}

int main()
{
    printf("Enter the input string: ");
    scanf("%s", input);

    printf("\nStack\tInput\tAction\n");

    while (input[i] != '\0')
    {
        push(input[i]);
        printf("\n");
        display();
        printf("\t%s\tShift", &input[i + 1]);

        // Reduction rules for grammar
        if (stack[top] == 'i')
        {
            printf("\n");
            pop(1);
            push('E');
            display();
            printf("\t%s\tReduce E->i", &input[i + 1]);
        }

        i++;
    }

    if (stack[0] == 'E' && top == 0)
        printf("\n\nString Accepted\n");
    else
        printf("\n\nString Rejected\n");

    return 0;
}