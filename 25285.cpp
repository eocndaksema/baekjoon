//25285번
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tc; cin>>tc;
    while(tc--)
    {
        double cm, kg;
        cin>>cm>>kg;
        double m = cm / 100;
        double BMI = kg / (m * m);
        if(cm < 140.1)
        {
            cout<<6;
        }
        else if(140.1 <= cm && cm < 146)
        {
            cout<<5;
        }
        else if (146 <= cm && cm < 159)
        {
            cout<<4;
        }
        else if (159 <= cm && cm < 161)
        {
            if(16.0 <= BMI && BMI < 35.0)
            {
                cout<<3;
            }
            else
            {
                cout<<4;
            }
        }
        else if (161 <= cm && cm < 204)
        {
            if(20.0 <= BMI && BMI < 25.0)
            {
                cout<<1;
            }
            else if((18.5 <= BMI && BMI < 20.0) || (25.0 <= BMI && BMI < 30.0))
            {
                cout<<2;
            }
            else if((16.0 <= BMI && BMI < 18.5) || (30.0 <= BMI && BMI < 35.0))
            {
                cout<<3;
            }
            else if(BMI < 16.0 || BMI >= 35.0)
            {
                cout<<4;
            }
        }
        else if (204 <= cm)
        {
            cout<<4;
        }
        cout<<"\n";
    }
}