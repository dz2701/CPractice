//
//  main.cpp
//  Diamond Collector (silver)
//
//  Created by Shin Lee on 25/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e4+5;
int n, k; int eff[MAX]; int meff[MAX];
vector<int>candy;
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int a; cin >> a;
        candy.push_back(a);
    }
    sort(candy.begin(),candy.end());
    for(int i=0;i<n;i++){
        eff[i] = distance(candy.begin(),upper_bound(candy.begin(),candy.end(),candy[i]+k)) - i;
    }
    int cnt = eff[n-1];
    for(int i=n-1;i>=0;i--){
        cnt = max(cnt, eff[i]);
        meff[i]=cnt;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans, eff[i]+meff[i+eff[i]]);
    }
    
    cout << ans;
    
    
    return 0;
}
