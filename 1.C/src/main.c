
#include <stdio.h>

int add(int a, int b);
int minus(int a, int b);

int main()
{
    int a = 10;
    int b = 5;
    int c;
    c = add(a, b);
    printf("a+b = %d\n", c);
    c = minus(a, b);
    printf("a_b = %d\n", c);
    return 0;
}
