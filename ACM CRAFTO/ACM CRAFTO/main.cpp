//
//  main.cpp
//  ACM CRAFTO
//
//  Created by dz2701 on 6/8/20.
//  Copyright © 2020 dz2701. All rights reserved.
//  Algorithm Type: Topological Sort

#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

//custom comparator for pq
class node{
public:
    int dur;
    int no;
    int starttime;
};
auto cmp = [](node a, node b){ //lamba?
    return a.starttime > b.starttime;
};
//define variables
int n, d[MAX], w, ind[MAX];
vector<int>adj[MAX];


int main(){
    cin >> n;
    while(n--){
        memset(ind,0,sizeof(ind));
        int a, b; cin >> a >> b;
        //initialize
        for(int i=1;i<=a;i++){
            //amount of time required to finish
            cin >> d[i];
        }
        memset(adj,0,sizeof(adj));
        for(int i=1;i<=b;i++){
            int n1, n2; cin >> n1 >> n2;
            adj[n1].push_back(n2);
            ind[n2]++;
        }
        cin >> w;
        priority_queue<node,vector<node>,decltype(cmp)>pq(cmp);
        //initial setup: without prerequisite can be executed immediately
        for(int i=1;i<=a;i++){
            if(ind[i]==0){
                pq.push({dur:d[i],no:i,starttime:0});
                
            }
        }
        int ans=0;
        
        while(!pq.empty()){
            node now = pq.top();
            pq.pop();
            
            
            if(now.no == w){
                ans = now.starttime + now.dur;
                break;
            }
            
            int time = now.starttime + now.dur;
            for(int i : adj[now.no]){
                ind[i]--;
                if(ind[i]==0){
                    pq.push({dur:d[i],no:i,starttime:time});
                }
            }
        }
        
        cout << ans << "\n";
        
        
    }
}
