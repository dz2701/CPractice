//
//  main.cpp
//  10763 Bessie's Birthday BUffet
//
//  Created by dz2701 on 10/1/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
struct state{
    int pos;
    int curval, maxval;
};
vector<int>adj[MAX];
int val[MAX];
int n, e;

int main(){
    cin >> n >> e;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        val[i] = a;
        for(int i=1;i<=b;i++){
            int t; cin >> t; adj[i].push_back(t);
        }
    }
    int answer = -1e9;
    for(int i=1;i<=n;i++){
        //i starting point BFS
        
        queue<state>q;
        int ans = -1e9;
        q.push({i,val[i],val[i]}); //did eat
        while(!q.empty()){
            state now = q.front(); q.pop();
            ans = max(ans, now.curval);
            for(int cn : adj[now.pos]){
                if(val[cn]>now.maxval){
                    q.push({cn,now.curval+val[cn]-e,max(now.maxval,val[cn])}); //did eat
                }
            }
        }
        answer = max(answer,ans);
    }
    cout << answer;
}
