#include <stdio.h>
const int digitCount=10;

void getDigit(//����һ��������������ֽ��ʮ������λ�ĺ���
    unsigned int a,//����ȡ��λ����
    int digits[/*digitCount*/]//���ڽ�����ȡ����ģ�����ΪdigitCount�����飬��λ�Ӹߵ�������
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
