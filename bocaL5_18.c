#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n = 0, n2 = 0, n3 = 0, n4 = 0;
    int i, j, i2, j2;
    int qtdMtrx;
    int matrix1[i][j];
    int matrix2[i2][j2];
    int matrix3[i][j2];

    scanf("%d", &qtdMtrx);
    scanf("%*c");

    for (n = 0; n < qtdMtrx; n++)
    {

        scanf("%d %d", &j, &i);

        int matrix1[i][j];

        for (n2 = 0; n2 < i; n2++)
        {

            for (n3 = 0; n3 < j; n3++)
            {

                scanf("%d", &matrix1[n2][n3]);
            }
        }

        scanf("%d %d", &j2, &i2);

        int matrix2[i2][j2];

        for (n2 = 0; n2 < i2; n2++)
        {

            for (n3 = 0; n3 < j2; n3++)
            {

                scanf("%d", &matrix2[n2][n3]);
            }
        }

        if (j != i2)
        {
            printf("IMPOSSIVEL\n\n");
        }

        else
        {
            int matrix3[i][j2];
            for (n2 = 0; n2 < i; n2++)
            {
                for (n3 = 0; n3 < j2; n3++)
                {
                    matrix3[n2][n3] = 0;
                }
            }

            for (n2 = 0; n2 < i; n2++)
            {

                for (n3 = 0; n3 < j2; n3++)
                {

                    for (n3 = 0; n3 < j2; n3++)
                    {

                        for (n4 = 0; n4 < j; n4++)
                        {
                            matrix3[n2][n3] += matrix1[n2][n4] * matrix2[n4][n3];
                        }
                        printf("%d ", matrix3[n2][n3]);
                        matrix3[n2][n3] = 0;
                    }
                    printf("\n");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
