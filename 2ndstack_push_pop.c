#include <stdio.h>
void push();
void pop();
#define MAX_SIZE 100
int stack[MAX_SIZE], choice, max, i, top = -1;
void push() {
    int val;
    if (top == max - 1) {
        printf("Overflow...");
    } else {
        printf("Push the elements into stack..\n");
        while (top < max - 1) {
            top = top + 1;
            printf("Enter the %d index value: ", top);
            scanf("%d", &val);
            stack[top] = val;
        }
        printf("\nThe elements inside the stack are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
void pop()
{
    int c;
    if(top==-1)
    {
        printf("underflow..");
    }
    else{
        printf("\nNo. of elements to delete...");
        scanf("%d",&c);
        if(c>max)
        {
            printf("\nNo enough elements to be deleted...");
        }
        else{
            top=-c;
            printf("the element's are deleted");
        }
        if(top==-1)
        {
            printf("\nthere are no elements left in stack..");
        }
        else{
            printf("\nthe elements after in stack pop operation");
            for(i=top;i>=0;i--)
            {
                printf("%d\n",stack[i]);
            }
        }
    }
}
int main() {
    printf("\nEnter no. of elements to push into stacks: ");
    scanf("%d", &max);
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("\nExiting...");
                return 0;
            default:
                printf("\nInvalid choice....");
        }
    }
    return 0;
}