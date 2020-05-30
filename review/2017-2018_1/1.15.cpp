#include <iostream>
#include <math.h>
using namespace std;

struct stu
{
    char num[10];
    float score[3];
};

int main()
{
    struct stu s[2] = {{"20021",90,95,85},{"20022",95,80,75}};
    int i;
    float sum = 0;
    for(i=0;i<3;i++)
        sum = sum+s[0].score[i];
    printf("%6.2f\n",sum);

    system("pause");
}