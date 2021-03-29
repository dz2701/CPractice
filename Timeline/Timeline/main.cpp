//
//  main.cpp
//  Timeline
//
//  Created by Shin Lee on 3/2/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, c; const int MAX = 1e5+1;
int min_time[MAX];
vector<pair<int,int>>adj[MAX];
vector<int>con[MAX];
int arr[MAX];
int cnt[MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("timeline.in","r",stdin);
    freopen("timeline.out","w",stdout);
    cin >> n >> m >> c;
    for(int i=1;i<=n;i++)cin >> min_time[i];
    for(int i=1;i<=c;i++){
        int p,q,r; cin >> p >> q >> r;
        adj[q].push_back({p,r});
        con[p].push_back(q);
        cnt[q]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(cnt[i]==0)q.push(i);
    }
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        //update value
        arr[now] = min_time[now];
        for(pair<int,int>c_n : adj[now]){
            arr[now] = max(arr[now],arr[c_n.first]+c_n.second);
        }
        for(int c_n : con[now]){
            cnt[c_n]--;
            if(cnt[c_n]==0)q.push(c_n);
        }
    }
    for(int i=1;i<=n;i++){
        cout << arr[i] << "\n";
    }
    return 0;
}
