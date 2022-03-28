#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
bool bfs();
void reset();
queue < pair<int,int> >q;
vector< pair<int,int> >conv;
int cur_x,cur_y,ftv_x,ftv_y;
int visited[101];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		cin>>cur_x>>cur_y;
		for(int i=0; i<n; i++)
		{
			int x,y;
			cin>>x>>y;
			conv.push_back({x,y});
		}
		cin>>ftv_x>>ftv_y;
		if(bfs())
		{
			cout<<"happy\n";
		}
		else
		{
			cout<<"sad\n";
		}
		reset();
	}
}
bool bfs(){
	q.push({cur_x,cur_y});
	while(!q.empty())
	{
		int cx=q.front().first;
		int cy=q.front().second;
		q.pop();
		if(abs(cx-ftv_x)+abs(cy-ftv_y)<=1000)
		{
			return true;
		}
		for(int i=0; i<conv.size(); i++)
		{
			int d=abs(cx-conv[i].first)+abs(cy-conv[i].second);
			if(d<=1000&&visited[i]==0)
			{
				visited[i]=1;
				q.push(conv[i]);
			}
		}
	}
	return false;
}
void reset(){
	conv.clear();
	q=queue < pair<int,int> >();
	memset(visited,0,sizeof(visited));
}