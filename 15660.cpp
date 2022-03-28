#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
void f(int n, int m);
int a[505][505];
int ans=-1;
vector< tuple<int,int,int,int,int,int,int,int> > v;
vector< tuple<int,int,int,int,int,int,int,int> > u;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    f(n,m);
    u.assign(v.begin(),v.end());

    int x=ans; int z=-99999;
    for(int i=0; i<u.size(); i++)
    {
        ans=-1; v.clear();
        int tmp1=a[get<0>(u[i])][get<1>(u[i])];
        int tmp2=a[get<2>(u[i])][get<3>(u[i])];
        int tmp3=a[get<4>(u[i])][get<5>(u[i])];
        int tmp4=a[get<6>(u[i])][get<7>(u[i])];
        a[get<0>(u[i])][get<1>(u[i])]=-9999;
        a[get<2>(u[i])][get<3>(u[i])]=-9999;
        a[get<4>(u[i])][get<5>(u[i])]=-9999;
        a[get<6>(u[i])][get<7>(u[i])]=-9999;
        f(n,m);
        int y=ans;
        z=max(z,y);
        a[get<0>(u[i])][get<1>(u[i])]=tmp1;
        a[get<2>(u[i])][get<3>(u[i])]=tmp2;
        a[get<4>(u[i])][get<5>(u[i])]=tmp3;
        a[get<6>(u[i])][get<7>(u[i])]=tmp4;
    }
    cout<<x+z<<"\n";
}
void f(int n, int m){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int sum1=a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3];
            if(ans<sum1)
            {
                v.clear();
                v.push_back({i,j,i,j+1,i,j+2,i,j+3});
                ans=sum1;
            }
            else if(ans==sum1)
            {
                v.push_back({i,j,i,j+1,i,j+2,i,j+3});
            }

            int sum2=a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j];
            if(ans<sum2)
            {
                v.clear();
                v.push_back({i,j,i+1,j,i+2,j,i+3,j});
                ans=sum2;
            }
            else if(ans==sum2)
            {
                v.push_back({i,j,i+1,j,i+2,j,i+3,j});
            }

            int sum3=a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];
            if(ans<sum3)
            {
                v.clear();
                v.push_back({i,j,i,j+1,i+1,j,i+1,j+1});
                ans=sum3;
            }
            else if(ans==sum3)
            {
                v.push_back({i,j,i,j+1,i+1,j,i+1,j+1});
            }

            int sum4=a[i][j]+a[i+1][j]+a[i+2][j]+a[i+2][j+1];

            if(ans<sum4)
            {
                v.clear();
                v.push_back({i,j,i+1,j,i+2,j,i+2,j+1});
                ans=sum4;
            }
            else if(ans==sum4)
            {
                v.push_back({i,j,i+1,j,i+2,j,i+2,j+1});
            }

            int sum5=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j];
            if(ans<sum5)
            {
                v.clear();
                v.push_back({i,j,i,j+1,i,j+2,i+1,j});
                ans=sum5;
            }
            else if(ans==sum5)
            {
                v.push_back({i,j,i,j+1,i,j+2,i+1,j});
            }

            int sum6=a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+2][j+1];
            if(ans<sum6)
            {
                v.clear();
                v.push_back({i,j,i,j+1,i+1,j+1,i+2,j+1});
                ans=sum6;
            }
            else if(ans==sum6)
            {
                v.push_back({i,j,i,j+1,i+1,j+1,i+2,j+1});
            }

            int sum7=a[i][j+2]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2];
            if(ans<sum7)
            {
                v.clear();
                v.push_back({i,j+2,i+1,j,i+1,j+1,i+1,j+2});
                ans=sum7;
            }
            else if(ans==sum7)
            {
                v.push_back({i,j+2,i+1,j,i+1,j+1,i+1,j+2});
            }

            int sum8=a[i][j+1]+a[i+1][j+1]+a[i+2][j]+a[i+2][j+1];
            if(ans<sum8)
            {
                v.clear();
                v.push_back({i,j+1,i+1,j+1,i+2,j,i+2,j+1});
                ans=sum8;
            }
            else if(ans==sum8)
            {
                v.push_back({i,j+1,i+1,j+1,i+2,j,i+2,j+1});
            }

            int sum9=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+2];
            if(ans<sum9)
            {
                v.clear();
                v.push_back({i,j,i,j+1,i,j+2,i+1,j+2});
                ans=sum9;
            }
            else if(ans==sum9)
            {
                v.push_back({i,j,i,j+1,i,j+2,i+1,j+2});
            }

            int sum10=a[i][j]+a[i][j+1]+a[i+1][j]+a[i+2][j];
            if(ans<sum10)
            {
                v.clear();
                v.push_back({i,j,i,j+1,i+1,j,i+2,j});
                ans=sum10;
            }
            else if(ans==sum10)
            {
                v.push_back({i,j,i,j+1,i+1,j,i+2,j});
            }

            int sum11=a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2];
            if(ans<sum11)
            {
                v.clear();
                v.push_back({i,j,i+1,j,i+1,j+1,i+1,j+2});
                ans=sum11;
            }
            else if(ans==sum11)
            {
                v.push_back({i,j,i+1,j,i+1,j+1,i+1,j+2});
            }

            int sum12=a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j+1];
            if(ans<sum12)
            {
                v.clear();
                v.push_back({i,j,i+1,j,i+1,j+1,i+2,j+1});
                ans=sum12;
            }
            else if(ans==sum12)
            {
                v.push_back({i,j,i+1,j,i+1,j+1,i+2,j+1});
            }

            int sum13=a[i][j+1]+a[i][j+2]+a[i+1][j]+a[i+1][j+1];
            if(ans<sum13)
            {
                v.clear();
                v.push_back({i,j+1,i,j+2,i+1,j,i+1,j+1});
                ans=sum13;
            }
            else if(ans==sum13)
            {
                v.push_back({i,j+1,i,j+2,i+1,j,i+1,j+1});
            }

            int sum14=a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+2][j];
            if(ans<sum14)
            {
                v.clear();
                v.push_back({i,j+1,i+1,j,i+1,j+1,i+2,j});
                ans=sum14;
            }
            else if(ans==sum14)
            {
                v.push_back({i,j+1,i+1,j,i+1,j+1,i+2,j});
            }

            int sum15=a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+1][j+2];
            if(ans<sum15)
            {
                v.clear();
                v.push_back({i,j,i,j+1,i+1,j+1,i+1,j+2});
                ans=sum15;
            }
            else if(ans==sum15)
            {
                v.push_back({i,j,i,j+1,i+1,j+1,i+1,j+2});
            }

            int sum16=a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2];
            if(ans<sum16)
            {
                v.clear();
                v.push_back({i,j+1,i+1,j,i+1,j+1,i+1,j+2});
                ans=sum16;
            }
            else if(ans==sum16)
            {
                v.push_back({i,j+1,i+1,j,i+1,j+1,i+1,j+2});
            }

            int sum17=a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j];
            if(ans<sum17)
            {
                v.clear();
                v.push_back({i,j,i+1,j,i+1,j+1,i+2,j});
                ans=sum17;
            }
            else if(ans==sum17)
            {
                v.push_back({i,j,i+1,j,i+1,j+1,i+2,j});
            }

            int sum18=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1];
            if(ans<sum18)
            {
                v.clear();
                v.push_back({i,j,i,j+1,i,j+2,i+1,j+1});
                ans=sum18;
            }
            else if(ans==sum18)
            {
                v.push_back({i,j,i,j+1,i,j+2,i+1,j+1});
            }
            int sum19=a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+2][j+1];
            if(ans<sum19)
            {
                v.clear();
                v.push_back({i,j+1,i+1,j,i+1,j+1,i+2,j+1});
                ans=sum19;
            }
            else if(ans==sum19)
            {
                v.push_back({i,j+1,i+1,j,i+1,j+1,i+2,j+1});
            } 
        }
    }
    return;
}