#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void);
int prompt(void);
void basic(void);
void trig(void);

int main() {
    int ch = prompt();
    switch (ch) {
        case 1: basic();
        break;
        case 2: trig();
        break;
        default: printf("Invalid choice! Please try again \n");
        prompt();
    }
    return 0;
}

int prompt() {
    int ch;
    printf("TermCalc: A simple calculator that runs on your terminal! \n");
    printf("Written by Jesse Stefanson \n");
    printf("What is the type of your operation? \n");
    printf("1. Basic Calculation \n");
    printf("2. Trigonometric Calculation \n");
    printf("Enter a choice (1-2), or press Ctrl-C to exit \n");
    printf("Prompt> ");
    scanf("%d", &ch);
    return ch;
}

void basic() {
    int a, b; 
    float result;
    char c;
    printf("Enter your operation. Allowed operators are \'+\', \'-\', \'*\', \'/\' and \'m\' \n");
    printf("Prompt> ");
    scanf("%d %c %d", &a, &c, &b);
    switch (c) {
        case '+': result = a + b;
        break;
        case '-': result = a - b;
        break;
        case '*': result = a * b;
        break;
        case '/': result = a / b;
        break;
        case 'm': result = a % b;
        break;
        default: printf("Invalid operator! Please try again \n");
        basic(); 
    }
    printf("Result is %.4f \n", result);
}

void trig() {
    char * tf[12] = { "sin", "cos", "tan", "cot", "sec", "cosec", "asin", "acos", "atan", "acot", "asec", "acosec" };
    int i;
    char tri[6];
    double a, result;
    printf("Enter your trigonometric operation. Allowed operators are \'sin\', \'cos\', \'tan\', \'cot\', \'sec\', \'cosec\', \'asin\', \'acos\', \'atan\', \'acot\', \'asec\' and \'acosec\' \n");
    printf("Prompt> ");
    scanf("%s %lf", tri, &a);
    for (i = 0; i < 12; i++) {
        if (strcmp(tri, tf[i]) == 0) break;
        else continue; 
    }
    switch (i) {
        case 0: result = sin(a);
        break;
        case 1: result = cos(a);
        break;
        case 2: result = tan(a);
        break;
        case 3: result = 1/tan(a);
        break;
        case 4: result = 1/cos(a);
        break;
        case 5: result = 1/sin(a);
        break;
        case 6: result = asin(a);
        break;
        case 7: result = acos(a);
        break;
        case 8: result = atan(a);
        break;
        case 9: result = atan(1/a);
        break;
        case 10: result = acos(1/a);
        break;
        case 11: result = asin(1/a);
        break;
        default: printf("Invalid operator! Please try again \n");
        trig(); 
    }
    printf("Result is %.4lf \n", result);
}