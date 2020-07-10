//
//  main.cpp
//  10749 Superbull_
//
//  Created by dz2701 on 7/6/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e5;
long long n; long long bulls[MAX], p[MAX], sz[MAX];
struct fight{long long a, b, cost;};
bool cmp(fight a, fight b){return a.cost<b.cost;}
priority_queue<fight,vector<fight>,function<bool(fight,fight)>>pq(cmp);
long long Find(long long a){return p[a]==a?a:p[a]=Find(p[a]);}
bool Union(long long a, long long b){
    a=Find(a);b=Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    sz[b]+=sz[a];
    p[a]=b;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("superbull.in","r",stdin);
    freopen("superbull.out","w",stdout);
    cin >> n;
    for(long long i=1;i<=n;i++)cin >> bulls[i];
    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            long long cost = bulls[i]^bulls[j];
            pq.push({i,j,cost});
        }
    }
    
    long long idx=1; long long ans=0;
    idx=n-1;
    for(long long i=1;i<=n;i++){p[i]=i;sz[i]=1;}
    while(!pq.empty() and idx){
        if(Union(pq.top().a,pq.top().b)){
            ans+=pq.top().cost;
            idx--;
        }
        pq.pop();
    }
    cout << ans;
    
}

