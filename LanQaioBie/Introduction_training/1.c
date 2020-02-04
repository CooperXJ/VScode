#include <stdio.h>

int Fib(int a)
{
    if(a==1)
    {
        return 1;
    }

    if(a==2)
    {
        return 1;
    }

    else
    {
        return (Fib(a-1)+Fib(a-2))%10007;
    }
}

int main()
{
    int n;
    int F[1000001];
    scanf("%d",&n);
    for(int i =3;i<=n;i++)
    {
        F[i] = F[i-1]+F[i-2];
    }
    printf("%d\n",F[n]);
    system("pause");
    return 0;
}