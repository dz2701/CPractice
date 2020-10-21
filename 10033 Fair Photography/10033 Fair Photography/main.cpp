//
//  main.cpp
//  10033 Fair Photography
//
//  Created by dz2701 on 10/14/20.
//

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int MAX = 1e5+1;
struct node{
    int loc, val;
};
int maxval[2*MAX+1];
struct cmp{bool operator () (node a, node b){return a.val!=b.val? a.val<b.val : a.loc>b.loc;}};
bool cc(pii a, pii b){return a.first<b.first;}
vector<pair<int,int>>inp;
vector<node>v;
int n;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int loc; char tp;
        cin >> loc >> tp;
        if(tp=='W')inp.push_back({loc,1});
        else inp.push_back({loc,-1});
    }
    sort(inp.begin(),inp.end(),cc);
    int value = 0;
    fill(&maxval[0],&maxval[2*MAX+1],-1e9);
    for(int i=0;i<n;i++){
        value+=inp[i].second;
        maxval[inp[i].second+MAX-1] = max(maxval[inp[i].second+MAX-1],inp[i].first);
        v.push_back({inp[i].first,value});
    }
    int val = -1e9;
    for(int i=2*MAX+1;i>=0;i--){
        maxval[i] = max(maxval[i],val);
        val = max(maxval[i],val);
    }
    
    sort(v.begin(),v.end(),cmp());
    
    int ans = -1e9;
    for(int i=0;i<n;i++){
        ans = max(ans, maxval[v[i].val+MAX-1]-v[i].loc);
    }
    cout << ans;
}
