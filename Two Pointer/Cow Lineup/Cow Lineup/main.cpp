//
//  main.cpp
//  Cow Lineup
//
//  Created by Shin Lee on 2/15/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e4+1;
int n; pair<int,int>cows[MAX];
map<int,int>idx; set<int>ids;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> cows[i].first >> cows[i].second;
        ids.insert(cows[i].second);
    }
    sort(cows+1,cows+n);
    int req_cnt = int(ids.size()); int cnt = 0;
    int st = 1, ed = 0; //번째 보는중
    int ans = 1e9;
    while(st!=n){
        if(cnt<req_cnt){
            if(ed<n){
                ed++;
                if(idx[cows[ed].second]==0){
                    idx[cows[ed].second]++;
                    cnt++;
                }else idx[cows[ed].second]++;
            }else break;
        }else if(cnt==req_cnt){
            ans = min(ans, cows[ed].first - cows[st].first);
            if(idx[cows[st].second]==1){
                cnt--;
            }
            idx[cows[st].second]--;
            st++;
        }else {
            if(idx[cows[st].second]==1){
                cnt--;
            }
            idx[cows[st].second]--;
            st++;
        }
    }
    cout << ans;
}
