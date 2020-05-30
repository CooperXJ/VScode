#include <iostream>
#include <string>
#include  <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    vector<string> vec;
    cin.get();//这个一定要加  因为cin后面会有回车符会被getline接收

    vector<int> play1[8];
    vector<int> play2[8];
    vector<int> attack[1000];
    int play1_slaver = 0;
    int play1_slaver_left = 0;
    int play2_slaver = 0;
    int play2_slaver_left = 0;

    play1[0].push_back(30);
    play2[0].push_back(30);

    for(int i =0;i<n;i++)
    {
        string s;
        getline(cin,s);
        vec.push_back(s);
    }

    vec.push_back("end");

    bool play1_round = false;
    bool play2_round = true;
    int index = 0;

    int c = 1;
    for(int i =0;i<vec.size();i++)
    {
        if(vec[i].find("summon")!=string::npos)
        {
            string num;
            for(int j = vec[i].find("summon")+6;j<=vec[i].size();j++)
            {
                if(isdigit(vec[i][j]))
                {
                    num+=vec[i][j];
                }

                else
                {
                    int val;
                    if(!num.empty())
                        {
                        
                            char *s =(char*) num.data();
                            sscanf(s,"%d",&val);

                             if(play1_round == false&&play2_round==true)
                            {
                                play1[c].push_back(val);
                            }

                            else
                            {
                                play2[c].push_back(val);
                            }

                            if(vec[i][j]==' ')
                            {
                                num.clear();
                            }
                        }
                }
            }
            c++;

            if(play1_round == false&&play2_round==true)
            {
                play1_slaver++;
                play1_slaver_left++;
            }
                
            else if(play1_round == true&&play2_round==false)
            {
                play2_slaver++;
                play2_slaver_left++;
            }
                
        }

        else if(vec[i].find("attack")!=string::npos)
        {
            for(int m =1;m<=play1_slaver;m++)
            {
               if(play1[m][0]!=0&&play1[m][2]>0)
               {
                   for(int n =m+1;n<=play1_slaver;n++)
                   {
                        if(play1[n][0]!=0&&play1[n][0]<=play1[m][0]&&play1[n][2]>0)
                        {
                            play1[m][0]+=1;
                            int temp1;
                            temp1 = play1[n][1];
                            play1[n][1] = play1[m][1];
                            play1[m][1] = temp1; 

                            int temp2;
                            temp2 = play1[n][2];
                            play1[n][2] = play1[m][2];
                            play1[m][2] = temp2; 
                        }
                        else
                        {
                            continue;
                        }
                   }
               }
               else
               {
                   continue;
               }
            }

            for(int m =1;m<=play2_slaver;m++)
            {
               if(play2[m][0]!=0&&play2[m][2]>0)
               {
                   for(int n =m+1;n<=play2_slaver;n++)
                   {
                        if(play2[n][0]!=0&&play2[n][0]<=play2[m][0]&&play2[n][2]>0)
                        {
                            play2[n][0]+=1;
                            int temp1;
                            temp1 = play2[n][1];
                            play2[n][1] = play2[m][1];
                            play2[m][1] = temp1; 

                            int temp2;
                            temp2 = play2[n][2];
                            play2[n][2] = play2[m][2];
                            play2[m][2] = temp2; 
                        }
                        else
                        {
                            continue;
                        }
                   }
               }
               else
               {
                   continue;
               }
            }

        

            string num;
            for(int j = vec[i].find("attack")+6;j<=vec[i].size();j++)
            {
                if(isdigit(vec[i][j]))
                {
                    num+=vec[i][j];
                }
                else
                {
                    int val;
                    if(!num.empty())
                        {
                        
                            char *s = (char*)num.data();
                            sscanf(s,"%d",&val);
                             attack[index].push_back(val);
                        }

                    if(vec[i][j]==' ')
                    {
                        num.clear();
                    }
                }
            }

            index++;

            if(play1_round==false&&play2_round==true)
            {
                int a;
                int b;
                for(a = 0;a<=play2_slaver;a++)
                {
                    if(play2[a][0]==attack[index-1][0])
                    {
                        break;
                    }
                    else
                        continue;
                }

                for(b = 0;b<=play1_slaver;b++)
                {
                    if(play1[b][0]==attack[index-1][1])
                    {
                        break;
                    }
                    else
                        continue;
                }

                if(a==0)
                {
                    //play1[b][2]-=play2[a][0];
                    play2[a][0]-=play1[b][1];
                }

                if(b==0)
                {
                    play1[b][0]-=play2[a][1];
                    //play2[a][2]-=play1[b][1];
                }

                if(a!=0&&a!=0)
                {
                    play1[b][2]-=play2[a][1];
                    play2[a][2]-=play1[b][1];
                }
                
            }

            else if(play1_round==true&&play2_round==false)
            {
                int a;
                int b;
                for(a = 0;a<=play1_slaver;a++)
                {
                    if(play1[a][0]==attack[index-1][0])
                    {
                        break;
                    }
                    else
                        continue;
                }

                for(b = 0;b<=play1_slaver;b++)
                {
                    if(play1[b][0]==attack[index-1][1])
                    {
                        break;
                    }
                    else
                        continue;
                }

                 if(a==0)
                {
                    //play2[b][2]-=play1[a][1];
                    play1[a][0]-=play2[b][1];
                }

                if(b==0)
                {
                    play2[b][0]-=play1[a][1];
                    //play1[a][2]-=play2[b][1];
                }

                if(a!=0&&a!=0)
                {
                    play2[b][2]-=play1[a][1];
                    play1[a][2]-=play2[b][1];
                }
            }
        }

        else if(vec[i].find("end")!=string::npos)
        {
            for(int m = 1;m<=play1_slaver;m++)
            {
                if(play1[m][2]<=0)
                {
                    play1[m][0] = 0;
                    play1_slaver_left--;
                    for(int n = m+1;n<=play1_slaver;n++)
                    {
                        play1[n][0] -= 1;
                    }
                }
            }

            for(int m = 1;m<=play2_slaver;m++)
            {
                if(play2[m][2]<=0)
                {
                    play2[m][0] = 0;
                    play2_slaver_left--;
                    for(int n = m+1;n<=play2_slaver;n++)
                    {
                        play2[n][0] -= 1;
                    }
                }
            }

            play1_round = true;
            play2_round = false;
            c = 1;
        }
    }

            if(play1[0][0]<=0)
            {
                cout<<"-1"<<endl;
                cout<<play2[0][0]<<endl;
                cout<<play2_slaver_left<<" ";
                for(int i =1;i<=play2_slaver;i++)
                {
                    if(play2[i][0]!=0)
                    {
                        cout<<play2[i][2]<<" ";
                    }
                    else
                        continue;
                }
                cout<<endl;
            }

            else if(play2[0][0]<=0)
            {
                cout<<"1"<<endl;
                cout<<play1[0][0]<<endl;
                cout<<play1_slaver_left<<" ";
                for(int i =1;i<=play1_slaver;i++)
                {
                    if(play1[i][0]!=0)
                    {
                        cout<<play1[i][2]<<" ";
                    }
                    else
                        continue;
                } 
            }

            else
            {
                cout<<"0"<<endl;
                cout<<play1[0][0]<<endl;
                cout<<play1_slaver_left<<" ";
                for(int i =1;i<=play1_slaver;i++)
                {
                    if(play1[i][0]!=0)
                    {
                        cout<<play1[i][2]<<" ";
                    }
                    else
                        continue;
                }
                cout<<endl;
                cout<<play2[0][0]<<endl;
                cout<<play2_slaver_left<<" ";
                for(int i =1;i<=play2_slaver;i++)
                {
                    if(play2[i][0]!=0)
                    {
                        cout<<play2[i][2]<<" ";
                    }
                    else
                        continue;
                } 
            }
            
    cout<<endl;
    //system("pause");
    return 0;
}
