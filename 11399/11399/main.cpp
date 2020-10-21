//
//  main.cpp
//  11399
//
//  Created by dz2701 on 9/17/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main(){
    int n; cin >> n; for(int i=1;i<=n;i++)cin >> arr[i];
    sort(arr+1,arr+n+1);
    int ans = 0, cnt = 0;
    for(int i=1;i<=n;i++){
        cnt+=arr[i];
        ans+=cnt;
    }
    cout << ans;
}
