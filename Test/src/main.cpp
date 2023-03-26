#include <stdio.h>
#include "add.hpp"
#include "minus.hpp"

int main()
{
    int a=10;
    int b=5;
    int res;
    int res1 = add(a, b);
    int res2 = minus(a, b);

    printf("a+b=%d\n", res1);
    printf("a-b=%d\n", res2);

    return 0;
}