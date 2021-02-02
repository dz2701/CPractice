//
//  main.cpp
//  9372 상근이의 여행
//
//  Created by Shin Lee on 12/23/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3+1;
int T; int arr[MAX], sz[MAX];
int Find(int a){
    if(arr[a]==a)return a;
    else return arr[a] = Find(arr[a]);
}
bool Union(int a, int b){
    a = Find(a); b = Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    sz[b]+=sz[a];
    arr[a]=b;
    return true;
}
vector<int>adj[MAX];
struct node{int st, ed, val;}; queue<node>q;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        for(int i=1;i<=m;i++){
            int a, b; cin >> a >> b;
            q.push({a,b,1});
        }
        for(int i=1;i<=n;i++){
            sz[i]=1; arr[i]=i;
        }
        int cnt = 0;
        while(!q.empty()){
            node now = q.front(); q.pop();
            if(Union(now.st,now.ed))cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
