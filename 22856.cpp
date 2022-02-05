#include <iostream>
using namespace std;
void inorder(int node,bool flag);
int tree[100001][2];
int all_sub_tree_cnt=-1;
int right_sub_tree_cnt=-1;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        tree[a][0]=b;
        tree[a][1]=c;
    }
    inorder(1,1);
    int ans=2*all_sub_tree_cnt-right_sub_tree_cnt;
    cout<<ans;
}
void inorder(int node,bool flag){
    if(node==-1)
    {
        return;
    }
    int left=tree[node][0];
    int right=tree[node][1];
    all_sub_tree_cnt++;
    inorder(left,0);
    if(flag==1)
    {
        right_sub_tree_cnt++;
        inorder(right,1);
    }
    else
    {
        inorder(right,0);
    }
    return;
}