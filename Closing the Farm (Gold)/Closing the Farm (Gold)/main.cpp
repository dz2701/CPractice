//
//  main.cpp
//  Closing the Farm (Gold)
//
//  Created by Shin Lee on 2/23/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAX = 2e5+1;
vector<int>adj[MAX];
int arr[MAX]; int sz[MAX], check[MAX];
stack<int>ans;
int Find(int a){
    if(arr[a]==a)return a;
    else return arr[a]=Find(arr[a]);
}
void Union(int a, int b){
    a = Find(a); b=Find(b);
    if(a==b)return;
    if(sz[a]>sz[b])swap(a,b);
    arr[a]=b; sz[b]+=sz[a];
}
int main(){
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    stack<int>order;
    for(int i=1;i<=n;i++){
        int t; cin >> t; order.push(t);
        sz[i]=1; arr[i]=i;
    }
    int cnt = 0;
    while(!order.empty()){
        int now = order.top(); order.pop(); cnt++;
        check[now]=1;
        for(int con:adj[now]){
            if(check[con]){
                Union(con,now);
            }
        }
        if(sz[Find(now)]==cnt){
            ans.push(1);
        }else ans.push(0);
    }
    
    while(!ans.empty()){
        if(ans.top()==1)cout << "YES\n";
        else cout << "NO\n";
        ans.pop();
    }
    return 0;
    
}
