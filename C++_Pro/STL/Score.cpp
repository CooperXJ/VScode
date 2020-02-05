#include <iostream>
#include <math.h>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <algorithm>
#include <string>
using namespace std;

void swap(int &a,int &b)
{
    int t = a;
    a = b;
    b = t;
}

class Student
{
    public:
        Student(){
            
        }
        Student(string name,int score):mname(name),mscore(score){
           
        }

        // Student(string name,int score){
        //    this->mname = name;
        //    this->mscore =score;
        // }和上面一个构造函数不可以同时出现

        ~Student(){}
    
    public:
        string mname;
        int mscore;
};

void Create_Student(vector<Student> &stu)
{
    string nameSeed = "ABCDE";
    for(int i =0;i<5;i++)
    {
        Student s;
        s.mname = "player";//此处需要注意不能写成下面的 否则name无法被初始化
        s.mname += nameSeed[i];
        //s.mname = "player"+'A';
        s.mscore = 0;

        stu.push_back(s);
    }
}

void print_deque(int i)
{
    cout<<i<<" ";
}

void Set_Score(vector<Student> &stu)
{
    for(vector<Student>::iterator it= stu.begin();it!=stu.end();it++)
    {
        deque<int> dScore;
        for(int i =0;i<10;i++)
        {
            int score = rand()%41+60;
            dScore.push_back(score);
        }

        sort(dScore.begin(),dScore.end());

        dScore.pop_front();
        dScore.pop_back();

        int sum_score = 0;
        for(deque<int>::iterator it = dScore.begin();it!=dScore.end();it++)
        {
            sum_score+=(*it);
        }

        (*it).mscore = sum_score/dScore.size();
    }
}

bool compare(Student &stu1,Student &stu2)
{
    return stu1.mscore>stu2.mscore;
}

void print_stu(Student stu)
{
    cout<<stu.mname<<" "<<stu.mscore<<endl;
}

void Rank(vector<Student> &stu)
{
    sort(stu.begin(),stu.end(),compare);
    // for(vector<Student>::iterator it = stu.begin();it!=stu.end();it++)
    // {
    //     cout<<(*it).mname<<" "<<(*it).mscore<<endl;
    // }

    for_each(stu.begin(),stu.end(),print_stu);
}

int main()
{
    vector<Student> stu;
    Create_Student(stu);
    Set_Score(stu);
    for(vector<Student>::iterator it = stu.begin();it!=stu.end();it++)
    {
        cout<<(*it).mname<<" "<<(*it).mscore<<endl;
    }
    cout<<"---------------"<<endl;
    Rank(stu);

    // string name;
    // string ss = "abcd";
    // for(int i =0;i<4;i++)
    // {
    //     string ss1(ss[i]);
    //     name = "ABCD"+ss1;
    //     cout<<name<<endl;
    // }

    // Student s;
    // s.mname = "xuejin"+'A';
    // cout<<s.mname<<endl;

    
    system("pause");
}

