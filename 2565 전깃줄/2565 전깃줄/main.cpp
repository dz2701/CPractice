//
//  main.cpp
//  전깃줄
//
//  Created by Shin Lee on 19/04/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
pair<int, int>p[505];
int n;
bool cmp(pair<int,int>a, pair<int,int>b){return a.first<b.first;}
 
int main(){
    cin >> n;
    for(int i=0;i<n;i++)cin >> p[i].first >> p[i].second;
    sort(p,p+n,cmp);
    vector<int>v;
    v.push_back(-1);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(p[i].second>v.back()){
            ans++;
            v.push_back(p[i].second);
        }else{
            auto it = lower_bound(v.begin(),v.end(),p[i].second);
            *it  = p[i].second;
        }
    }
    cout << n-ans;
    return 0;
}
