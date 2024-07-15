#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

int main(){
    int b;
    char a, c, d;
    scanf("%c%d%c%c", &a, &b, &c, &d);

if (a >= 65 && a <= 90 && b >= 0 && b <= 9 && (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') && ((d == 'a' || d == 'A' || d == 'e' || d == 'E' || 
d == 'i' || d == 'I' || d == 'o' || d == 'O' || d == 'u' || d == 'U') == false) && d >= 97 && d <= 122) {

        char x = d - 32;
        printf("%c%d%c%c", a, b, c, x);
    }
else if (a >= 65 && a <= 90 && b >= 0 && b <= 9 && (c == 'a' || c == 'e' ||
c == 'i' || c == 'o' || c == 'u') && ((d == 'a' || d == 'A' || d == 'e' || d == 'E' || 
d == 'i' || d == 'I' || d == 'o' || d == 'O' || d == 'u' || d == 'U') == false) && d >= 97 && d <= 122) {
        char x = d - 32;
        char y = c - 32;
        printf("%c%d%c%c", a, b, y, x);
    }
else {
    printf("Invalido");
} 

return 0;
}