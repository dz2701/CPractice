//
//  main.cpp
//  11047
//
//  Created by dz2701 on 9/17/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int coin[11];
int main(){
    int a, b;cin >> a >> b;
    for(int i=1;i<=a;i++)cin >> coin[i];
    int cnt = 0;
    while(b){
        for(int i=a;i>=1;i--){
            if(coin[i]<=b){
                b-=coin[i];
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}
