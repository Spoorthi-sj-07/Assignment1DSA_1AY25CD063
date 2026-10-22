#include <stdio.h>

typedef struct {
    int degree;
    float coef[101];
} polynomial;

polynomial add(polynomial a, polynomial b)
{
    polynomial c;
    int i;

    c.degree = (a.degree > b.degree) ? a.degree : b.degree;

    for (i = 0; i <= c.degree; i++) {
        c.coef[i] = 0;
    }

    for (i = 0; i <= a.degree; i++) {
        c.coef[i] += a.coef[i];
    }

    for (i = 0; i <= b.degree; i++) {
        c.coef[i] += b.coef[i];
    }

    while (c.degree > 0 && c.coef[c.degree] == 0) {
        c.degree--;
    }

    return c;
}

void display(polynomial p)
{
    int i, first = 1;

    for (i = p.degree; i >= 0; i--) {
        if (p.coef[i] == 0)
            continue;

        if (!first) {
            if (p.coef[i] > 0)
                printf(" + ");
            else
                printf(" - ");
        } else if (p.coef[i] < 0) {
            printf("-");
        }

        float value = (p.coef[i] < 0) ? -p.coef[i] : p.coef[i];

        if (i == 0) {
            printf("%g", value);
        } else {
            printf("%gx", value);

            if (i > 1)
                printf("^%d", i);
        }

        first = 0;
    }

    if (first)
        printf("0");

    printf("\n");
}

int main()
{
    polynomial a, b, c;
    int i;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &a.degree);

    printf("Enter coefficients from highest degree to constant term:\n");

    for (i = a.degree; i >= 0; i--) {
        scanf("%f", &a.coef[i]);
    }

    printf("Enter degree of second polynomial: ");
    scanf("%d", &b.degree);

    printf("Enter coefficients from highest degree to constant term:\n");

    for (i = b.degree; i >= 0; i--) {
        scanf("%f", &b.coef[i]);
    }

    c = add(a, b);

    printf("First polynomial: ");
    display(a);

    printf("Second polynomial: ");
    display(b);

    printf("Sum of polynomials: ");
    display(c);

    return 0;
}
