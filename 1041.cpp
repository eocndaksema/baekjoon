#include <iostream>
#include <algorithm>
typedef long long int ll;
using namespace std;
void f(ll X,ll Y,ll Z,ll n);
ll ans=9223372036854775807;
int a[3];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,A,B,C,D,E,F;
    ll X,Y,Z;
    cin>>n;
    cin>>A>>B>>C>>D>>E>>F;
    if(n==1)
    {
        cout<<A+B+C+D+E+F-max({A,B,C,D,E,F});
    }
    else
    {
        a[0]=A; a[1]=B; a[2]=D;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=B; a[1]=F; a[2]=D;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=F; a[1]=E; a[2]=D;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=E; a[1]=A; a[2]=D;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);

        a[0]=A; a[1]=E; a[2]=C;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=E; a[1]=F; a[2]=C;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=F; a[1]=B; a[2]=C;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=B; a[1]=A; a[2]=C;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);

        a[0]=A; a[1]=C; a[2]=B;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=C; a[1]=F; a[2]=B;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=F; a[1]=D; a[2]=B;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=D; a[1]=A; a[2]=B;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);

        a[0]=C; a[1]=B; a[2]=A;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=B; a[1]=D; a[2]=A;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=D; a[1]=E; a[2]=A;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=E; a[1]=C; a[2]=A;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);

        a[0]=A; a[1]=D; a[2]=E;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=D; a[1]=F; a[2]=E;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=F; a[1]=C; a[2]=E;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=C; a[1]=A; a[2]=E;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);

        a[0]=D; a[1]=B; a[2]=F;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=B; a[1]=C; a[2]=F;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=C; a[1]=E; a[2]=F;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);
        a[0]=E; a[1]=D; a[2]=F;
        sort(a,a+3);
        X=a[0]; Y=a[1]; Z=a[2];
        f(X,Y,Z,n);

        cout<<ans;
    }
}
void f(ll X,ll Y,ll Z,ll n){
    ans=min(ans,2*X*n*n+2*(Y*2*n+X*(n*n-2*n))+Z*4+Y*(4*n-8)+X*(n-2)*(n-2));
    return;
}