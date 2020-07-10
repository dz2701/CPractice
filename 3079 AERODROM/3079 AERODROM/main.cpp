//
//  main.cpp
//  3079 AERODROM
//
//  Created by dz2701 on 7/6/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
long long n, m, judge[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(long long i=1;i<=n;i++)cin >> judge[i];
    sort(judge+1,judge+n+1);
    long long st = 1, ed = 1e14+5;
    while(st!=ed){
        long long mid = (st+ed)/2;
        long long cap = 0;
        for(long long i=1;i<=n;i++){
            cap+=mid/judge[i];
        }
        if(cap>=m){
            ed = mid;
        }else{
            st = mid+1;
        }
    }
    cout << st;
    return 0;
}
