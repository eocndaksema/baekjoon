//25318번
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <ctime>
#include <cmath>

using namespace std;
vector <int> t[1005];
int l[1005];

double calcYear(int n, int i)
{
    int yearN = t[n][0];
    int monthN = t[n][1];
    int dayN = t[n][2];
    int hourN = t[n][3];
    int minuteN = t[n][4];
    int secondN = t[n][5];

    int yearI = t[i][0];
    int monthI = t[i][1];
    int dayI = t[i][2];
    int hourI = t[i][3];
    int minuteI = t[i][4];
    int secondI = t[i][5];

    struct tm I = {secondI, minuteI, hourI, dayI, monthI - 1, yearI - 1900};
    struct tm N = {secondN, minuteN, hourN, dayN, monthN - 1, yearN - 1900};

    time_t II = mktime(&I);
    time_t NN = mktime(&N);

    if ( NN != (time_t)(-1) && II != (time_t)(-1) )
    {
        double difference = difftime(NN, II) / (60 * 60 * 24 * 365);

        return difference;
    }

    return -1;
}

double calcpi(int n, int i)
{
    return max(pow(0.9, n - i), pow(0.5, calcYear(n, i)));
}

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    if(n == 0)
    {
        cout<<0;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        string ymd, hms;
        cin>>ymd>>hms>>l[i];

        stringstream sstream1(ymd);
        string word;
        while(getline(sstream1, word, '/'))
        {
            t[i].push_back(stoi(word));
        }

        stringstream sstream2(hms);
        while(getline(sstream2, word, ':'))
        {
            t[i].push_back(stoi(word));
        }
    }

    double a = 0;
    double b = 0;
    for(int i = 1; i <= n; i++)
    {
        double c = calcpi(n, i);

        a = a + c * l[i];
        b = b + c;
    }

    cout<<round(a / b);
}