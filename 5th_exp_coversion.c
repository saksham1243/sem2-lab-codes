#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 100
char stack[max];
int top=-1;
char val;
void push(char stack[], char);
char pop(char stack[]);
void reverse(char str[]);
void infixtopostfix(char source[], char target[]);
void prefixtoinfix(char source[], char target[]);
void postfixtoinfix(char source[], char target[]);
int getpriority(char);
char infix[100],postfix[100],temp[100],prefix[100];
void reverse(char str[])
{
    int len,i=0,j=0;
    len=strlen(str);
    j=len-1;
    while(j>=0)
    {
        if(str[j]=='(')
        {
            temp[i]=')';
        }
        else if(str[j]==')')
        {
            temp[i]='(';
        }
        else
        {
            temp[i]=str[j];
        }
        i++;
        j--;
    }
    temp[i]='\0';
}
void infixtopostfix(char source[], char target[])
{
    int i=0,j=0;
    char t;
    strcpy(target,"");
    while(source[i]!='\0')
    {
        if(source[i]=='(')
        {
            push(stack, source[i]);
            i++;
        }
        else if((isdigit(source[i]))||(isalpha(source[i])))
        {
            target[j]=source[i];
            i++;
            j++;
        }
        else if(source[i]==')')
        {
            while((top!=-1)&&(stack[top]!='('))
            {
                target[j]=pop(stack);
                j++;
            }
            if(top==-1)
            {
                printf("\nInvalid expression...");
                
            }
            t=pop(stack);
            i++;   
        }
        else if((source[i]=='+')||(source[i]=='-')||(source[i]=='*')||(source[i]=='/')||(source[i]=='%')||(source[i]=='^'))
        {
            while((top!=-1)&&(stack[top]!='(')&&(getpriority(stack[top])>=getpriority(source[i])))
            {
                target[j]=pop(stack);
                j++;
            }
            push(stack,source[i]);
            i++;

        }
        else
        {
            printf("\nInvalid expression...");
        }
        
    
    }
    while((top!=-1)&&(stack[top]!='('))
        {
            target[j]=pop(stack);
            j++;
        }
        target[j]='\0';
}
int getpriority(char o)
{
    if(o=='^')
    {
        return  2;
    }
    else if((o=='/')||(o=='*')||(o=='%'))
    {
        return 1;
    }
    else if((o=='+')||(o=='-'))
    {
        return 0;
    }
}
void push(char stack[], char val)
{
    if(top==max-1)
    {
        printf("Overflow.....");
    }
    else{
        top++;
        stack[top]=val;
    }
}
char pop(char stack[])
{
    
    if(top==-1)
    {
        printf("Underflow....");
    }
    else{
        val=stack[top];
        top--;
        
    }
    return val;
}
void prefixtoinfix(char source[], char target[]) {
    int i=0; 
    int k=0;
    int len=strlen(source);
    char temp[100], s1[100][30];
    strcpy(target, "");
    for(i=len-1;i>=0;i--) {
        if (isalnum(source[i])) {
            char t[]={source[i],'\0'};
            strcpy(s1[k++], t);
            
        } else {
            char *op1 = s1[--k]; // First operand
            char *op2 = s1[--k]; // Second operand
            sprintf(temp, "(%s%c%s)", op1, source[i], op2); // Create infix expression
            strcpy(s1[k++], temp); // Push the infix expression onto stack
            
        }
    } 
    strcpy(target, s1[--k]); // The final infix expression will be at the top of the stack
}
void postfixtoinfix(char source[], char target[]) {
    int i = 0;
    int k = 0;
    int len=strlen(source);
    char temp[100],s1[100][30];
    strcpy(target, "");
    for(i=0;i<=len-1;i++) {
        if (isalnum(source[i])) {
            char t[]={source[i],'\0'};
            strcpy(s1[k++], t);
        } else {
            char *op2 = s1[--k]; // Second operand
            char *op1 = s1[--k]; // First operand
            sprintf(temp, "(%s%c%s)", op1, source[i], op2); // Create infix expression
            strcpy(s1[k++], temp); // Push the infix expression onto stack
        }
        
    }
    strcpy(target, s1[--k]); // The final infix expression will be at the top of the stack
}
int main()
{
    int ch;
    printf("1.Infix to Postfix\n2.Infix to Prefix\n3.Prefix to Infix\n4.Postfix to Infix");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("Enter the Infix expression: ");
            scanf("%s",infix);
            
            strcpy(postfix,"");
            infixtopostfix(infix,postfix);
            printf("\nThe postfix expression is: %s",postfix);   
            break;
        case 2:
            printf("Enter the Infix expression: ");
            scanf("%s",infix);
            reverse(infix);
            printf("\nThe reverse infix expression is:temp= %s",temp);
            strcpy(postfix,"");
            infixtopostfix(temp,postfix);
            printf("\nThe postfix expression is: %s",postfix); 
            reverse(postfix);           
            printf("\nThe prefix expression is: %s",temp);
            break;
        case 3:
            printf("Enter the prefix expression: ");
            scanf("%s",prefix);       
            strcpy(infix,"");
            prefixtoinfix(prefix,infix);
            printf("\nThe Infix expression is: %s\n",infix);   
            break; 
        case 4:
            printf("Enter the postfix expression: ");
            scanf("%s",postfix);            
            strcpy(infix,"");
            postfixtoinfix(postfix,infix);
            printf("\nThe Infix expression is: %s",infix);   
            break; 
        default:
            printf("Invalid...");
    }
    return 0;
}