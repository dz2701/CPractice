//
//  main.cpp
//  15587 Cow at Large (Gold)
//
//  Created by dz2701 on 5/06/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX int(1e5+5)
using namespace std;
int visit[MAX]; int n, k;
vector<int>v[MAX]; queue<int>q;
int main(){
    cin >> n >> k;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(v[i].size()==1){
            //is a leaf
            q.push(i);
            visit[i]=1;
        }
    }
    q.push(k);
    visit[k]=-1;
    int ans=0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(int i=0;i<v[front].size();i++){
            if(visit[v[front][i]]==0){
                visit[v[front][i]]=visit[front];
                q.push(v[front][i]);
            }else if(visit[v[front][i]]>0 and visit[front]==-1){
                ans++;
            }
        }
        
    }
    cout << ans;
    
    
    return 0;
}
