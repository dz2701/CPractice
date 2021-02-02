//
//  main.cpp
//  Telephone
//
//  Created by Shin Lee on 1/23/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e4+1;

int b[MAX];
int n, k;
vector<int>adj[MAX];
vector<int>coor[MAX]; //locations that have this.
int check[MAX];

struct state{int loc, val;};
struct cmp{bool operator () (state a, state b){return a.val>b.val;}};
priority_queue<state,vector<state>,cmp>pq;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> b[i];
        coor[b[i]].push_back(i);
    }
    for(int i=1;i<=k;i++){
        string temp; cin >> temp;
        for(int j=0;j<k;j++){
            if(temp[j]=='1')adj[i].push_back(j+1);
        }
    }
    pq.push({1,0});
    check[1]=1;
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        if(now.loc==n){
            cout << now.val;
            return 0;
        }
        for(int con : adj[b[now.loc]]){
            for(int dest : coor[con]){
                if(check[dest])continue;
                pq.push({dest,now.val+abs(dest-now.loc)});
                check[dest]=1;
            }
        }
    }
}
