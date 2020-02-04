#include <iostream>
using namespace std;

string produce(int time)
{
    string res;
    switch (time)
    {
    case 0:
        res += "zero ";
        break;
    case 1:
        res += "one ";
        break;
    case 2:
        res += "two ";
        break;
    case 3:
        res += "three ";
        break;
    case 4:
        res += "four ";
        break;
    case 5:
        res += "five ";
        break;
    case 6:
        res += "six ";
        break;
    case 7:
        res += "seven ";
        break;
    case 8:
        res += "eight ";
        break;
    case 9:
        res += "nine ";
        break;
    case 10:
        res += "ten ";
        break;
    case 11:
        res += "eleven ";
        break;
    case 12:
        res += "twelve ";
        break;
    case 13:
        res += "thirteen ";
        break;
    case 14:
        res += "fourteen ";
        break;
    case 15:
        res += "fifteen ";
        break;
    case 16:
        res += "sixteen ";
        break;
    case 17:
        res += "seventeen ";
        break;
    case 18:
        res += "eighteen ";
        break;
    case 19:
        res += "nineteen ";
        break;
    case 20:
        res += "twenty ";
        break;
    case 30:
        res += "thirty ";
        break;
    case 40:
        res += "forty ";
        break;
    case 50:
        res += "fifty ";
        break;
    case 60:
        res += "sixty ";
        break;
    default:
        res +=produce((time/10)*10);
        if(time%10!=0)
            res +=produce(time%10);
        break;
    }

    return res;
}
int main()
{
    int h, m;
    cin >> h >> m;

    int time;
    string res = produce(h);
    if(m!=0)
        res+=produce(m);
    else
    {
        res+="o'clock";
    }
    
    cout<<res<<endl;
    system("pause");
}