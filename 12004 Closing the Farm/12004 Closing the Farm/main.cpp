//
//  main.cpp
//  Closing the Farm (silver)
//
//  Created by Shin Lee on 26/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n, m;
set<int>s;
vector<int>connect[3005];
int order[3005]; int closed[3005]; int visit[3005];
void dfs(int pos){
    if(visit[pos]!=0 or closed[pos]==1)return;
    s.insert(pos);
    visit[pos]=1;
    for(int i=0;i<connect[pos].size();i++){
        dfs(connect[pos][i]);
    }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    for(int i=0;i<n;i++)cin >> order[i];
    
    dfs(1);
    if(s.size()==n)printf("YES\n");
    else printf("NO\n");
    for(int i=0;i<n-1;i++){
        s.clear();
        memset(visit,0,sizeof(visit));
        closed[order[i]]=1;
        dfs(order[n-1]);
        if(s.size()==n-i-1){
            printf("YES\n");
        }else printf("NO\n");
        
    }
    
    return 0;
    
}
