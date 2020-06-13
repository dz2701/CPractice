//
//  main.cpp
//  ACM CRAFT하실?
//
//  Created by dz2701 on 6/11/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int t;
int main(){
    cin >> t;
    while(t--){
        int v[MAX], ind[MAX], dp[MAX], w;
        vector<int>arr[MAX];
        int n, k;
        cin >> n >> k;
        for(int i=1;i<=n;i++)cin >> v[i];
        for(int i=0;i<k;i++){
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            ind[b]++;
        }
        cin >> w;
        queue<int>q;
        for(int i=1;i<=n;i++)if(ind[i]==0){
            q.push(i);
            dp[i]=v[i];
        }
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            for(auto i : arr[front]){
                ind[i]--;
                dp[i] = max(dp[i],dp[front]+v[i]);
                if(ind[i]==0)q.push(i);
            }
        }
        printf("%d\n",dp[w]);
    }
}
