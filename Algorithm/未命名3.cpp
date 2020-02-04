#include  <stdio.h>
#define   WEEKDAYS  7
#define   MAX_STR_LEN  10
main()
{
    int i, pos;
    int findFlag;
    char x[MAX_STR_LEN];
    char weekDay[][MAX_STR_LEN] = {"Sunday", "Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday"};
    printf("Please enter a string:\n");
    scanf("%s", &x);
    puts(weekDay[1]); 
}
