//
//  main.cpp
//  고대 동굴 탐사합니까?
//
//  Created by dz2701 on 6/11/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
struct road{int start, end, val;};
struct vals{int val; vector<int>road;};
int t, v[MAX];
int main(){
    cin >> t;
    while(t--){
        
        vector<int>arr[MAX];
        road roads[MAX];
        int n, e;
        vals dp[MAX];
        cin >> n >> e;
        for(int i=1;i<=n;i++)cin >> v[i];
        for(int i=1;i<=e;i++){
            int a, b, c;
            cin >> a >> b >> c;
            arr[a].push_back(i);
            roads[i] = {a,b,c};
        }
        
        //dp: val obtained + my value since here.
        queue<int>q;
        vals ans = {v[1],{1}};
        q.push(1);
        dp[1].val = v[1];
        dp[1].road = {1};
        while(!q.empty()){
            auto now = q.front();
            q.pop();
            
            for(int i: arr[now]){ //i is road id.
                if(dp[roads[i].end].val<dp[now].val+v[roads[i].end]-roads[i].val){
                    dp[roads[i].end].val = dp[now].val+v[roads[i].end]-roads[i].val;
                    dp[roads[i].end].road = dp[now].road;
                    dp[roads[i].end].road.push_back(roads[i].end);
                    q.push(roads[i].end);
                    if(dp[roads[i].end].val > ans.val){
                        ans = dp[roads[i].end];
                    }
                }
            
            }
            
        }
        
        
        
        cout << ans.val << " " << ans.road.size() << "\n";
        for(int i : ans.road){
            cout << i << " ";
        }
        
    }
}
