#include <stdio.h>


float ResolveExpressao();
float FazOperacao(float num1, float num2, char op);

int main (){
    float resultado, maiorresultado = -999999;
    char c;

    while (1) {

        scanf("%c", &c);

        if (c == '.') {
            printf("%c", c);
            break;
        }

        if (c != '(') {
            if (c != ')') {
            printf("%c", c);
            }
        }


        if (c == '(') {
            resultado = ResolveExpressao();
            if (resultado > maiorresultado) {
                maiorresultado = resultado;
            }
            printf("%.2f", resultado);
        }
    }
    printf(" MAIOR:%.2f", maiorresultado);
return 0;
}

float ResolveExpressao() {

    float num1, num2, result = 0;
    char op;

    scanf ("%f", &num1);

    while (scanf(" %f %c", &num2, &op) == 2) { 
    result = FazOperacao(num1, num2, op);
    num1 = result;

}
return result;
}

float FazOperacao(float num1, float num2, char op){

float result;

    if (op == '+') {
    result = num1 + num2;
    }
    if (op == '-') {
    result = num1 - num2;
    }
    if (op == '/') {
    result = num1 / num2;
    }
    if (op == '*') {
    result = num1 * num2;
    }
    return result;
}