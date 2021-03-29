//
//  main.cpp
//  최솟갓과 최댓값
//
//  Created by Shin Lee on 3/9/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, m; const int MAX = 1e5+1;
int arr[MAX], max_tree[2*MAX+1], min_tree[2*MAX+1];

int init_max(int cur, int st, int ed){
    if(st==ed)return max_tree[cur]=arr[st];
    else return max_tree[cur] = max(init_max(cur*2,st,(st+ed)/2), init_max(cur*2+1,(st+ed)/2+1,ed));
}
int init_min(int cur, int st, int ed){
    if(st==ed)return min_tree[cur]=arr[st];
    else return min_tree[cur] = min(init_min(cur*2,st,(st+ed)/2), init_min(cur*2+1,(st+ed)/2+1,ed));
}
int query(bool is_max, int cur, int qs, int qe, int st, int ed){
    //completely irrelevant, or can't go further
    if(qe<st or qs>ed)return is_max?-(1e9+5):1e9+5;
    //if completely encompassed
    if(qs<=st and ed<=qe)return is_max?max_tree[cur]:min_tree[cur];
    //if partial
    return is_max? max(query(is_max,cur*2,qs,qe,st,(st+ed)/2),query(is_max,cur*2+1,qs,qe,(st+ed)/2+1,ed)):min(query(is_max,cur*2,qs,qe,st,(st+ed)/2),query(is_max,cur*2+1,qs,qe,(st+ed)/2+1,ed));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    init_max(1,1,n); init_min(1,1,n);
    
    while(m--){
        int a, b; cin >> a >> b;
        cout << query(false,1,a,b,1,n) << " " << query(true,1,a,b,1,n) << "\n";
    }
    return 0;
}
