#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void print_A();
void print_B();
void print_C();
void print_D();
bool visited[200001];
vector <int> A[101];
vector <int> B[101];
vector <int> C[101];
vector <int> D[101];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N,X,inputA,inputB,inputC,inputD;;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>X>>inputA>>inputB>>inputC>>inputD;
        A[inputA].push_back(X);
        B[inputB].push_back(X);
        C[inputC].push_back(X);
        D[inputD].push_back(X);
    }
    for(int i=0; i<101; i++)
    {
        sort(A[i].begin(),A[i].end());
        sort(B[i].begin(),B[i].end());
        sort(C[i].begin(),C[i].end());
        sort(D[i].begin(),D[i].end());
    }
    print_A();
    print_B();
    print_C();
    print_D();
}
void print_A(){
    for(int i=100; i>=0; i--)
    {
        for(int j=0; j<A[i].size(); j++)
        {
            cout<<A[i][j]<<" ";
            visited[A[i][j]]=1;
            return;
        }
    }
}
void print_B(){
    for(int i=100; i>=0; i--)
    {
        for(int j=0; j<B[i].size(); j++)
        {
            if(visited[B[i][j]]==1)
            {
                continue;
            }
            else
            {
                cout<<B[i][j]<<" ";
                visited[B[i][j]]=1;
                return;
            }
        }
    }
}
void print_C(){
    for(int i=100; i>=0; i--)
    {
        for(int j=0; j<C[i].size(); j++)
        {
            if(visited[C[i][j]]==1)
            {
                continue;
            }
            else
            {
                cout<<C[i][j]<<" ";
                visited[C[i][j]]=1;
                return;
            }
        }
    }
}
void print_D(){
    for(int i=100; i>=0; i--)
    {
        for(int j=0; j<D[i].size(); j++)
        {
            if(visited[D[i][j]]==1)
            {
                continue;
            }
            else
            {
                cout<<D[i][j]<<" ";
                visited[D[i][j]]=1;
                return;
            }
        }
    }
}
