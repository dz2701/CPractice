//
//  main.cpp
//  17023 Shortcut
//
//  Created by dz2701 on 10/9/20.
//

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
struct state{
    int node, val;
};
struct compare{
    bool operator () (state a, state b){
        return a.val!=b.val? a.val<b.val : a.node < b.node;
    }
};
const int MAX = 1e4;
const int INF = 1e9;

priority_queue<state,vector<state>,compare>pq;

struct value_type{
    int val_without_shortcut;
    int val_with_shortcut[MAX];
};


int n, m, t;
int cows[MAX+1]; int Prev[MAX+1];
int arr[MAX+1];
vector<int>Including[MAX+1];
vector<pii>adj[5*MAX+1];
map<pair<int,int>,int>test;
int main(){
    cin >> n >> m >> t;
    
    for(int i=1;i<=n;i++){
        int temp; cin >> temp; cows[i]+=temp;
    }
    for(int i=1;i<=m;i++){
        int st, ed, val;
        cin >> st >> ed >> val;
        adj[st].push_back(make_pair(ed,val));
        adj[ed].push_back(make_pair(st,val));
        test[{st,ed}] = val;
        test[{ed,st}] = val;
    }
    for(int i=1;i<=n;i++)arr[i] = INF;
    //initial dijkstra
    pq.push({1,0}); arr[1]=0; Prev[1] = 1;
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        for(auto con : adj[now.node]){
            if(arr[con.first] > now.val + con.second or (arr[con.first] == now.val+con.second and Prev[con.first] > now.node)){
                arr[con.first] = con.second + now.val;
                Prev[con.first] = now.node;
                pq.push({con.first, arr[con.first]});
            }
        }
    }
    for(int i=1;i<=n;i++){
        arr[i] = arr[i] * cows[i];
        //printf("arr[%d]=%d\n",i,arr[i]);
    }
    for(int i=1;i<=n;i++){
        int p = i;
        while(Prev[p]!=p){
            Including[p].push_back(i);
            p = Prev[p];
        }
    }
    /*for(int i=2;i<=n;i++){
        //printf("indlucing[%d] includes:\n",i);
        for(int j : Including[i]){
            //printf("%d ",j);
        }//printf("\n");
    }
    */
    int ans = -1e9;
    for(int i=2;i<=n;i++){
        int temp = 0;
        for(auto inc : Including[i]){
            temp+=max(arr[inc]-cows[inc]*(test[{i,inc}]+t),0);
        }
        ans = max(ans, temp);
    }
    cout << ans;
    return 0;
}
