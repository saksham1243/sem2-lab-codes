#include<stdio.h>
#include<string.h>
#define max 15
char stack[max];
int i, top=-1;// Function prototypes
void push(char);
char pop();
void display();
void main()
{
    char expression[max], temp;
    int count = 1; // Initialize count to 1
    display(); // Display initial stack (which is empty)
    printf("\nEnter an expression: ");
    scanf("%s", expression);
    for(i = 0; i < strlen(expression); i++)
    {
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[') // Fixed the condition
        {
            push(expression[i]);
        }
        else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']') // Fixed the condition
        {
            if(top == -1)
            {
                count = 0;
                break; // Break out of the loop as soon as count becomes 0
            }
            else
            {
                temp = pop();
                if((expression[i] == ')' && (temp == '{' || temp == '[')) ||
                   (expression[i] == '}' && (temp == '(' || temp == '[')) ||
                   (expression[i] == ']' && (temp == '(' || temp == '{')))
                {
                    count = 0;
                    break; // Break out of the loop as soon as count becomes 0
                }
            }
        }
    }
    if(top >= 0) // Checking if the stack is not empty after the loop
    {
        count = 0;
    }

    if(count == 1) // Fixed the condition
    {
        printf("\nValid expression.");
    }
    else
    {
        printf("\nInvalid expression.");
    }
}
void push(char c)
{
    if(top == max - 1)
    {
        printf("\nOverflow...");
    }
    else
    {
        top++;
        stack[top] = c;
    }
}
char pop()
{
    if(top == -1)
    {
        printf("\nUnderflow...");
    }
    else
    {
        return stack[top--];
    }
}
void display()
{
    if(top == -1)
    {
        printf("\nNo elements in the stack.");
    }
    else
    {
        printf("\nStack contents: ");
        for(i = 0; i <= top; i++)
        {
            printf("%c ", stack[i]);
        }
    }
}