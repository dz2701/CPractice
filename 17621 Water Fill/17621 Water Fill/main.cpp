//
//  main.cpp
//  17621 Water Fill
//
//  Created by dz2701 on 10/13/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
int n, m;
pair<int,int>wall[MAX];
bool not_null(pair<int,int>a){return a.first!=0 and a.second!=0;}
struct cmp{bool operator () (pair<int,int>a, pair<int,int>b){return a.second-a.first>b.second-b.first;}};
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> wall[i].first >> wall[i].second;
    }
    for(int i=1;i<=m;i++){
        pair<int,int> prev = pq.top();
        if(!not_null(wall[i])){
            while(!pq.empty())pq.pop();
        }
        if(not_null(wall[i]))pq.push(wall[i]);
        
    }
}
