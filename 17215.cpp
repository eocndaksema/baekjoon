#include <iostream>
#include <string>
using namespace std;
int score[11][2];
int bonus[9];
int frame=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    int index=0;
    for(int i=0; i<10; i++)
    {
        frame++;
        for(int j=0; j<2; j++)
        {
            if(s[index]=='-')
            {
                score[i][j]=0;
                index++;
            }
            else if(s[index]=='P')
            {
                if(frame==10)
                {
                    if(s[s.size()-1]=='S')
                    {
                        score[10][0]=10;
                    }
                    else
                    {
                        score[10][0]=(int)s[s.size()-1]-(int)'0';
                    }
                }
                score[i][j]=10-score[i][j-1];
                index++;
            }
            else if(s[index]=='S')
            {
                if(frame==10)
                {
                    if(s[s.size()-2]=='S')
                    {
                        score[10][0]=10;
                    }
                    else
                    {
                        score[10][0]=(int)s[s.size()-2]-(int)'0';
                    }
                    if(s[s.size()-1]=='S')
                    {
                        score[10][1]=10;
                    }
                    else if(s[s.size()-1]=='P')
                    {
                        score[10][1]=10-score[10][0];
                    }
                    else
                    {
                        score[10][1]=(int)s[s.size()-1]-(int)'0';
                    }
                }
                score[i][0]=-1;
                score[i][1]=10;
                index++;
                break;
            }
            else
            {
                score[i][j]=(int)s[index]-(int)'0';
                index++;
            }
        }
    }
    for(int k=0; k<9; k++)
    {
        int cnt=0;
        if(score[k][0]==-1&&score[k][1]==10)
        {
            for(int i=k+1; i<11; i++)
            {
                for(int j=0; j<2; j++)
                {
                    if(score[i][j]>=0)
                    {
                        bonus[k]=bonus[k]+score[i][j];
                        cnt++;
                        if(cnt==2)
                        {
                            goto escape;
                        }
                    }
                }
            }
        }
        else if(score[k][0]+score[k][1]==10)
        {
            for(int i=k+1; i<11; i++)
            {
                for(int j=0; j<2; j++)
                {
                    if(score[i][j]>=0)
                    {
                        bonus[k]=bonus[k]+score[i][j];
                        cnt++;
                        if(cnt==1)
                        {
                            goto escape;
                        }
                    }
                }
            }
        }
        escape: continue;
    }
    int ans=0;
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<2; j++)
        {
            if(score[i][j]>=0)
            {
                ans=ans+score[i][j];
            }
        }
    }
    for(int i=0; i<9; i++)
    {
        ans=ans+bonus[i];
    }
    cout<<ans;
}