#include <iostream>
#include <math.h>
#include <malloc.h>
#include <vector>
using namespace std;

void find_number(string str)
{
    vector<string> vec;

    int i = 0;
    string res;
    while (i!=str.size())
    {
       if(isdigit(str[i]))
       {
           res.push_back(str[i]);

           //如果下一个字符不是数字，则将res存入vec中
           if(!isdigit(str[i+1]))
           {
               vec.push_back(res);
               res.clear();
           }
       }
       i++;
    }
    
    int *arr = (int*)malloc(sizeof(int)*vec.size());
    for(int i =0;i<vec.size();i++)
    {
        arr[i] = stoi(vec[i]);//字符串转为数字  stoi  string to int
    }

    cout<<vec.size()<<endl;
    for(int i =0;i<vec.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    free(arr);
}

int main()
{
    string str = "a123x456 7689+89=321/ab23";
    find_number(str);
    system("pause");
}