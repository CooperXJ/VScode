#include <stdio.h>
const int digitCount=10;

void getDigit(//这是一个将输入的整数分解成十进制数位的函数
    unsigned int a,//被提取数位的数
    int digits[/*digitCount*/]//用于接收提取结果的，长度为digitCount的数组，数位从高到低排列
    ){
    unsigned int mask[digitCount]={
        1000000000,
        100000000,
        10000000,
        1000000,
        100000,
        10000,
        1000,
        100,
        10,
        1};
    for(int i=0;i<digitCount;i++){
        digits[i]=0;
        while(a>=mask[i]){
            digits[i]++;
            a-=mask[i];
            printf("%d\n",digits[i]);
        }
    }
}

int main()
{
	int a = 2345233;
	int digits[9] = {0};
	getDigit(a,digits);
	
	for(int i =0;i<10;i++)
	{
		printf("%d  ",digits[i]);
	}
	printf("\n");
}


int da = max(a,b);
	int xiao = min(a,b);
	if(da % xiao == 0)        return xiao;
	else   	return gcd(xiao, da % xiao);
