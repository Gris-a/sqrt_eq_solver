#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define STACK_SIZE 1000
#define ISNUMBER 0

double stack[STACK_SIZE];
int stackp = 0;

void push(double c);
double pop(void);

int main(int argc, char* argv[])
{
    double op;
    while(--argc > 0)
    {
        argv++;
        switch((!isdigit((*argv)[0])) ? (*argv)[0] : ISNUMBER)
        {
            case ISNUMBER:
                push(atof(*argv));
                break;
            case '+':
                push(pop() + pop());
                break;
            case 'x':
                push(pop() * pop());
                break;
            case '-':
                op = pop();
                push(pop() - op);
                break;
            case '/':
                op = pop();
                push(pop() / op);
                break;
            default:
                printf("Incorrect input.\n");
        }
    }
    printf("%lf", pop());
}

double pop(void)
{
    return stack[--stackp];
}

void push(double c)
{
    stack[stackp++] = c;
}
