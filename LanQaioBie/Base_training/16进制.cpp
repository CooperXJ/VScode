#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int count;
    cin>>count;

    for(int i =0;i<count;i++)
    {
        string val;
        cin>>val;

        int value = 0;
        int e = 0;
        for(int j = val.length()-1;j>=0;j--)
        {
            switch(val[j]){
                case 'A':
                    value+=pow(16,e)*10;
                    e+=1;
                    break;
                case 'B':
                    value+=pow(16,e)*11;
                    e+=1;
                    break;
                case 'C':
                    value+=pow(16,e)*12;
                    e+=1;
                    break;
                case 'D':
                    value+=pow(16,e)*13;
                    e+=1;
                    break;
                case 'E':
                    value+=pow(16,e)*14;
                    e+=1;
                    break;
                case 'F':
                    value+=pow(16,e)*15;
                    break;
                default:
                    int x;
                    stringstream ss;
                    ss<<val[j];
                    ss>>x;
                    value+=pow(16,e)*x;
                    e++;
            }
        }
        cout<<value<<endl;
    }
    //system("pause");
}