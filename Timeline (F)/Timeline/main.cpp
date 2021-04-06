//
//  main.cpp
//  Timeline
//
//  Created by Shin Lee on 12/14/20.
//
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int n, m, c;
long long S[MAX];
int cnt[MAX];
long long ans[MAX];
vector<pair<int,long long>>adj[MAX];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("timeline.in","r",stdin);
    freopen("timeline.out","w",stdout);
    cin >> n >> m >> c;
    for(int i=1;i<=n;i++){
        cin >> S[i];
    }
    for(int i=1;i<=c;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        cnt[b]++;
    }
    queue<pair<int,long long>>q;
    
    for(int i=1;i<=n;i++){
        if(cnt[i]==0){
            q.push({i,S[i]});
            ans[i] = S[i];
        }
    }
    
    while(!q.empty()){
        auto now = q.front(); q.pop();
        ans[now.first] = max(ans[now.first],S[now.first]);
        for(auto con : adj[now.first]){
            cnt[con.first]--;
            ans[con.first] = max(ans[con.first], con.second + ans[now.first]);
            if(cnt[con.first]==0)q.push({con.first,ans[now.first]});
        }
    }
    
    for(int i=1;i<=n;i++){
        printf("%lld\n",ans[i]);
    }
    return EXIT_SUCCESS;
}
