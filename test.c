#include <stdio.h>
void f()
{
#define sf 100
    printf("%d", sf);
}
int main()
{
#define sf 99
    f();
    printf("%d", sf);
    return 0;
}
