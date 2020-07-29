//
//  main.cpp
//  2042 구간 합 구하기
//
//  Created by dz2701 on 7/14/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+5;
long long fw[MAX]; int n, m, k;
long long sum(int pos){
    long long rt = 0;
    for(;pos;pos-=pos&-pos){
        rt+=fw[pos];
    }
    return rt;
}
void add(int pos, int val){
    for(;pos<MAX;pos+=pos&-pos){
        fw[pos]+=val;
    }
}
int num[MAX];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)cin >> num[i];
    for(int i=1;i<=n;i++)add(i,num[i]);
    int qtime = m+k;
    while(qtime--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==1){
            add(b,c-sum(b)+sum(b-1));
        }else{
            cout << sum(c)-sum(b-1) << "\n";
        }
    }
    return 0;
}
