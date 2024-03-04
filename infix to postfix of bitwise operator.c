#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

int isOperator(char ch) {
    return (ch == '&' || ch == '|' || ch == '^' || ch == '~' || ch == '!');
}

int precedence(char ch) {
    if (ch == '&' || ch == '|')
        return 1;
    else if (ch == '^')
        return 2;
    else if (ch == '~' || ch == '!')
        return 3;
    return 0;
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top == -1) {
                printf("Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            }
            pop(); // Discard '('
        } else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (top != -1) {
        if (stack[top] == '(') {
            printf("Mismatched parentheses\n");
            exit(EXIT_FAILURE);
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

