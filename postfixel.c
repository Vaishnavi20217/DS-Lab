#include <stdio.h>
#include <ctype.h>  // for isdigit()
#include <stdlib.h> // for atoi()
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Stack operations
void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    int i;
    for (i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // Skip whitespaces
        if (ch == ' ')
            continue;

        // If operand, push to stack
        if (isdigit(ch)) {
            push(ch - '0');  // Convert char to int
        }
        // If operator, pop two elements and apply operation
        else {
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return -1;
            }
        }
    }

    return pop();
}

// Main
int main() {
    char expression[100];

    printf("Enter a postfix expression (e.g., 23*54*+9-): ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}


