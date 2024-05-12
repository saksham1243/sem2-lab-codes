#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define max 100
float stack[max];
int top=-1;
void push(float stack[],float val);
float pop(float stack[]);
float prefix_evaluation(char exp[]);
float postfix_evaluation(char exp[]);
float infix_evaluation(char exp[]);
int getpriority(char);
int operand[100];
char opr[100];
int top1=-1,top2=-1;
void Process();
int main()
{
    float val;
    char exp[100];
    int ch;
    
    printf("1.Prefix\n2.Postfix\n3.Infix\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter the prefix expression: ");
            scanf("%s",exp);
            val=prefix_evaluation(exp);
            printf("The result for prefix expression is : %f",val);
            break;
        case 2:
            printf("\nEnter the postfix expression: ");
            scanf("%s",exp);
            val=postfix_evaluation(exp);
            printf("The result for postfix expression is : %f",val);
            break;
        case 3:
            printf("\nEnter the Infix expression: ");
            scanf("%s",exp);
            val=infix_evaluation(exp);
            printf("The result for Infix expression is : %f",val);
            break;
        default:
            printf("Invalid choice....");

    }
    return 0;
}
int getpriority(char o)
{
    if(o=='^')
    {
        return 2;
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
float prefix_evaluation(char exp[])
{
    int i=0;
    int len=strlen(exp);
    float op1,op2,value;
    for(i=len-1;i>=0;i--)
    {
        if((isdigit(exp[i]))||(isalpha(exp[i])))
        {
            push(stack,(float)(exp[i]-'0'));
        }
        else{
            op1=pop(stack);
            op2=pop(stack);
            switch(exp[i])
            {
                case '+':
                    value=op1+op2;
                    break;
                case '-':
                    value=op1-op2;
                    break;
                case '*':
                    value=op1*op2;
                    break;
                case '/':
                    value=op1/op2;
                    break;
                case '%':
                    value=(int)op1%(int)op2;
                    break;
                default:
                    printf("invalid...");

            }
            push(stack,value);
        }
        
    }
    return (pop(stack));
}
float postfix_evaluation(char exp[])
{
    int i=0;
    int len=strlen(exp);
    float op1,op2,value;
    for(i=0;i<=len-1;i++)
    {
        if((isdigit(exp[i]))||(isalpha(exp[i])))
        {
            push(stack,(float)(exp[i]-'0'));
        }
        else{
            op2=pop(stack);
            op1=pop(stack);
            switch(exp[i])
            {
                case '+':
                    value=op1+op2;
                    break;
                case '-':
                    value=op1-op2;
                    break;
                case '*':
                    value=op1*op2;
                    break;
                case '/':
                    value=op1/op2;
                    break;
                case '%':
                    value=(int)op1%(int)op2;
                    break;
                default:
                    printf("invalid...");

            }
            push(stack,value);
        }
        
    }
    return(pop(stack));
}
void push(float stack[], float val) {
    if (top == max - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = val;
    }
}

float pop(float stack[]) {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        float val = stack[top];
        top--;
        return val;
    }
}
float infix_evaluation(char exp[])
{
	int i;
    
	for(i=0; exp[i]!='\0'; i++){
		if((isdigit(exp[i]))||(isalpha(exp[i])))
			operand[++top1]=(int)(exp[i]-'0');
		else if(exp[i]=='('){
			opr[++top2]=exp[i];
		}
		else if(exp[i]==')'){
			while(opr[top2]!='('){
				Process();
			}
			top2--;
		}
		else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'||exp[i]=='%'|| exp[i]=='^')
		{
			while(top2!=-1 && getpriority(exp[i])<=getpriority(opr[top2])){
				Process();
			}
			opr[++top2]=exp[i];
		}
	}
	while(top2 !=-1){
		Process();
	}
	return operand[top1--];
}
void Process(){
	int op1 = operand[top1--];
	int op2 = operand[top1--];
	char op=opr[top2--];
	int value=0;
	switch(op){
		case '+':
			value=op1+op2;
			break;
		case '-':
			value=op1-op2;
			break;
		case '*':
			value=op1*op2;
			break;
		case '/':
			value=op1/op2;
			break;
        case '%':
            value=(int)op1%(int)op2;
            break;
        
	}
	operand[++top1]=value;
}