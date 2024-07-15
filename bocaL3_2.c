#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main(){

    float num1, num2, result;
    char op;

    scanf ("%f", &num1);

    while (scanf(" %f %c", &num2, &op) == 2) { 

    if (op == '+') {
    result = Soma(num1, num2);
    }
    if (op == '-') {
    result = Subtracao(num1, num2);
    }
    if (op == '/') {
    result = Divisao(num1, num2);
    }
    if (op == '*') {
    result = Multiplicacao(num1, num2);
    }
    num1 = result;
}

printf ("%.2f", result);

return 0;
}


float Soma(float num1, float num2){
    return num1 + num2;
}

float Subtracao(float num1, float num2) {
    return num1 - num2;
}
float Divisao(float num1, float num2) {
    return num1 / num2;
}
float Multiplicacao(float num1, float num2) {
    return num1 * num2;
}