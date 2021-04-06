//
//  main.cpp
//  subtree queries
//
//  Created by Shin Lee on 12/16/20.
//

#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2e5+1;
long long fw[MAX];
pair<long long,long long>sted[MAX];
vector<long long>adj[MAX];
long long n, q;
long long query(long long p){
    long long ret = 0;
    for(;p;p-=p&-p){
        ret+=fw[p];
    }
    return ret;
}
void update(long long p, long long v){
    for(;p<MAX;p+=p&-p){
        fw[p]+=v;
    }
}
long long val = 0;
long long temp = 0;
long long nodes[MAX];
long long idxs[MAX];
void dfs(long long cur, long long par){
    sted[cur].first = ++val;
    update(++temp,nodes[cur]);
    idxs[cur]=temp;
    for(long long con : adj[cur]){
        if(con!=par)dfs(con, cur);
    }
    sted[cur].second = val;
}
int main(){
    cin >> n >> q;
    for(long long i=1;i<=n;i++){
        cin >> nodes[i];
    }
    for(long long i=1;i<=n-1;i++){
        long long a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    
    dfs(1,-1);
    
    while(q--){
        long long tp; cin >> tp;
        if(tp==1){
            long long idx, value;
            cin >> idx >> value;
            update(idxs[idx],value-(query(idxs[idx])-query(idxs[idx]-1)));
        }
        else{
            long long question; cin >> question;
            printf("%lld\n",query(sted[question].second) - query(sted[question].first-1));
        }
    }
    return 0;
}
