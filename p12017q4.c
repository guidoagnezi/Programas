#include <stdio.h>

int main (){

    int h, m, s;
    int h2, m2, s2;
    int mh, mm, ms;
    int soma, dezena;

    scanf("%d %d %d %d %d %d", &h, &m, &s, &h2, &m2, &s2);

    if (h > h2) {
        mh = h;
        mm = m;
        ms = s;
    }
    if (h2 > h) {
        mh = h2;
        mm = m2;
        ms = s2;
    }
    if (h == h2) {
        if (m > m2) {
        mh = h;
        mm = m;
        ms = s;
        }
        if (m2 > m) {
        mh = h2;
        mm = m2;
        ms = s2;
        }
        if (m == m2) {
            if (s > s2) {
            mh = h;
            mm = m;
            ms = s; 
            }
            if (s2 > s) {
            mh = h2;
            mm = m2;
            ms = s2;
            }
            if (s == s2) {
                printf ("IGUAIS");
                return 0;
            }
        }
    }
    soma = mh + mm + ms;
    dezena = (soma % 100) / 10;
    printf("RESP:%d", dezena);
}