#include <stdio.h>
#include <stdio.h>
main()
{
   printf("Enter a character:");
   char c = getchar();
   printf("%c %c %c\n",c-1,c,c+1);
   printf("%d %d %d\n",c-1,c,c+1);
}
