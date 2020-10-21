//
//  main.cpp
//  10762 Traped in the Haybales
//
//  Created by dz2701 on 8/3/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int n, b;
struct haybale{
    int loc, val;
};
bool cmp(haybale a, haybale b){return a.loc<b.loc;}
haybale haybales[MAX];
pair<int,int>get_range(int val, int st, int ed, int stop){
    bool a = false, b = false;
    //stop --> need to stop!
    if(st!=stop and st>=1 and val>haybales[st].val){
        //move and update val
        val+=haybales[st].loc-haybales[st-1].loc;
        st--;
        a = true;
    }
    if(ed!=stop and ed<=n and val>haybales[ed].val){
        //move and update val
        val+=haybales[ed+1].loc-haybales[ed].loc;
        ed++;
        b = true;
    }
    
    if(!a and !b)return make_pair(st,ed);
    else return get_range(val,st,ed,stop);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("trapped.in","r",stdin);
    freopen("trapped.out","w",stdout);
    cin >> n >> b;
    for(int i=1;i<=n;i++){
        cin >> haybales[i].val >> haybales[i].loc;
    }
    sort(haybales+1, haybales+n+1, cmp);
    int st=0, ed=0;
    for(int i=1;i<=n;i++){
        if(b<=haybales[i].loc){
            st = i-1; ed = i;
            break;
        }
    }
    int ans = 1e9;
    for(int i=1;i<=n;i++){
        //going to assume that we are going to let haybale[i] unbreakable!
        int val = haybales[ed].loc-haybales[st].loc;
        auto range = get_range(val, st, ed, i);
        if(range.first==0 or range.second==n){
            continue;
        }
        ans = min(ans,max(0,haybales[range.second].loc-haybales[range.first].loc-haybales[i].val));
    }
    if(ans==1e9)cout << -1;
    else cout << ans;
    
}
