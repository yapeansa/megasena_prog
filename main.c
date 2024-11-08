#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *bd;

void leitura()
{
    int x_1, x_2, x_3, x_4, x_5, x_6;
    fscanf(bd, "%d %d %d %d %d %d", &x_1, &x_2, &x_3, &x_4, &x_5, &x_6);
    printf("Prognóstico: %d %d %d %d %d %d\n", x_1, x_2, x_3, x_4, x_5, x_6);
}

void grava(int x_1, int x_2, int x_3, int x_4, int x_5, int x_6)
{
    bd = fopen("arquivo.txt", "a");
    fprintf(bd, "%d %d %d %d %d %d ", x_1, x_2, x_3, x_4, x_5, x_6);
    fclose(bd);
}

int Random(int low, int high)
{
    int k;
    double d;
    d = (double)rand() / ((double)RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}

int main(void)
{
    int i, N;
    srand(time(NULL));

    printf("Por favor, digite o número de prognósticos desejado: ");
    scanf("%d", &N);

    for (i = 1; i <= 100; i++)
        grava(Random(1, 60), Random(1, 60), Random(1, 60), Random(1, 60), Random(1, 60), Random(1, 60));

    bd = fopen("arquivo.txt", "r");

    for (i = 1; i <= N; i++)
        leitura();

    fclose(bd);
    return 0;
}
