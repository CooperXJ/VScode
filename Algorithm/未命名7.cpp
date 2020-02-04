#include <stdio.h>
main()
{
    printf("Press a key and then press Enter:");
    char c = getchar();
    printf("%c",c+32);
}

