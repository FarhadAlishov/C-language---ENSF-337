/* lab3exe_A.c
 * ENSF 337 Fall 2018, Lab 3 Exercise A
 */

#include <stdio.h>


void reverse(const int *source, int n, int* reversed, int* m);

int main(void)
{
    int a[] = { 100, 9, 17, 0, 15 };
    int size_a;
    int i;
    int reversed[5];
    int n;

    size_a = sizeof(a) / sizeof(a[0]);

    printf("a has %d elements:", size_a);
    for (i = 0; i < size_a; i++)
        printf("  %d", a[i]);
    printf("\n");
    reverse(a, size_a, reversed, &n);
    printf("reversed values from a:");

    for (i = 0; i < n; i++)
        printf("  %d", reversed[i]);

    return 0;
}


void reverse(const int *source, int n_source, int* reversed, int* m)
{
    int i;

    *m = 0;
    for (i = n_source -1; i >= 0; i--) {
        reversed[*m] = source[i];
        printf("ggg%d\n", reversed[*m]);

        (*m)++;
    }
    printf("\n %d --- %d", *m,i);



    /* point one  (NOTE: This is *outside* of the for loop.) */
}
