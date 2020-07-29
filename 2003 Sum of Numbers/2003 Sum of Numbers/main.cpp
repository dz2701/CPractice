//
//  main.cpp
//  2003 Sum of Numbers
//
//  Created by dz2701 on 7/27/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4+1;
long long n,m, arr[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> arr[i];
    long long st = 1, ed = 1, sum=arr[1], ans = 0;
    while(ed!=n+1){
        if(sum>=m){
            if(sum==m){
                ans++;
            }
            sum-=arr[st];
            st++;

        }else{
            ed++;
            sum+=arr[ed];
        }
    }
    cout << ans;
}
