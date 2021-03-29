//
//  main.cpp
//  Telephone
//
//  Created by Shin Lee on 2/26/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, k; const int MAX = 5e4+5;
int arr[MAX];
int dp[MAX];
int visit[MAX];
int p[51][51];
struct state{int node, val;};
struct cmp{bool operator () (state a, state b){return a.val>b.val;}};
priority_queue<state,vector<state>,cmp>pq;
vector<int>members[51];
vector<pair<int,int>>edges[MAX];
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        members[arr[i]].push_back(i);
    }
    for(int i=1;i<=k;i++){
        string s; cin >> s;
        for(int j=1;j<=k;j++){
            p[i][j] = s[j-1]=='1';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(p[arr[i]][j]){
                auto it = upper_bound(members[j].begin(),members[j].end(),i);
                int num1 = *it;
                int num2 = it!=members[j].begin()? *(--it) : num1;
                
                
                if(abs(num1-i)>abs(num2-i))swap(num1,num2);
                edges[i].push_back({num1,abs(num1-i)});
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d:\n",i);
        for(auto con : edges[i]){
            printf("(%d %d)",con.first,con.second);
        }
        printf("\n");
    }
    pq.push({1,0});
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        visit[now.node]=1;
        
        for(auto con : edges[now.node]){
            if(!visit[con.first]){
                pq.push({con.first,con.second+now.val});
            }
        }
        dp[now.node] = now.val;
    }
    cout << (dp[n]==1e9?-1:dp[n]);
    return 0;
}
