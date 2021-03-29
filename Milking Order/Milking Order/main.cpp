//
//  main.cpp
//  Milking Order
//
//  Created by Shin Lee on 2/25/21.
//  Topological Sort + Binary Search
//  O O O O X X X..

#include <bits/stdc++.h>
using namespace std;
int n, m; const int MAX = 1e5+1;
vector<int>ob[50001];
set<int>con[MAX]; //no duplicates!
int cnt[MAX];
int visit[MAX];
bool cmp(int a, int b){return a>b;}
int main(){
    //freopen("milkorder.in","r",stdin);
    //freopen("milkorder.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int sz; cin >> sz;
        for(int j=1;j<=sz;j++){
            int t; cin >> t; ob[i].push_back(t);
        }
    }
    int lo = 1, hi = m;
    while(lo!=hi){
        int mid = (lo+hi+1)/2;
        for(int i=1;i<=n;i++)con[i].clear(); //reset top.sort
        fill(&cnt[0],&cnt[MAX-1],0);
        for(int i=1;i<=mid;i++){
            for(int j=0;j<ob[i].size()-1;j++){
                con[ob[i][j+1]].insert(ob[i][j]);
                cnt[ob[i][j]]++;
            }
        }
        
        //perform top.sort
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(cnt[i]==0){
                q.push(i); //is a leaf
            }
        }
        
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(int node : con[now]){
                cnt[node]--;
                if(cnt[node]==0)q.push(node);
            }
        }
        bool okay = true;
        for(int i=1;i<=n;i++){
            if(cnt[i]!=0){ //not in order, i.e in cycle!!
                okay = false;
            }
        }
        
        if(okay){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }
    //now we know that until ~lo th rule we can obey without a problem
    //so we need the most lexiconographically fastest rule
    deque<int>dq;
    fill(&cnt[0],&cnt[MAX-1],0);
    for(int i=1;i<=lo;i++){
        for(int j=0;j<ob[i].size()-1;j++){
            con[ob[i][j+1]].insert(ob[i][j]);
            cnt[ob[i][j]]++;
        }
    }
    queue<int>q; vector<int>ans, first;
    for(int i=1;i<=n;i++){
        if(cnt[i]==0){
            q.push(i); //is a leaf
            first.push_back(i);
        }
    }
    sort(first.begin(),first.end(),cmp);
    while(!q.empty()){
        int now = q.front(); q.pop();
        vector<int>temp;
        for(int node : con[now]){
            cnt[node]--;
            if(cnt[node]==0){
                q.push(node);
                temp.push_back(node);
            }
        }
        sort(temp.begin(),temp.end(),cmp);
        for(int num:temp){
            ans.push_back(num);
        }
    }
    int aidx=0, fidx=0;
    vector<int>real;
    for(int con : first){
        printf("%d ",con);
    }printf("\n\n\n");
    while(1){
        if(aidx==ans.size() and fidx==first.size())break;
        else if(aidx==ans.size()){
            real.push_back(first[fidx]);
            fidx++;
        }else if(fidx==first.size()){
            real.push_back(ans[aidx]);
            aidx++;
        }
        else if(ans[aidx]>first[fidx]){
            real.push_back(ans[aidx]); aidx++;
        }else{
            real.push_back(first[fidx]); fidx++;
        }
    }
    for(int i=real.size()-1;i>=0;i--){
        printf("%d ",real[i]);
    }
    return 0;
}
