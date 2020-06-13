//
//  main.cpp
//  Rest Stops
//
//  Created by Shin Lee on 25/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+6;
long long l, farmer, cow, n;
pair<int, int>road[MAX];
bool comp(pair<int, int>a, pair<int, int>b){
    return a.second!=b.second ? a.second>b.second : a.first<b.first;
}
int main(){
   
    cin >> l >> n >> farmer >> cow;
    for(int i=0;i<n;i++){
        cin >> road[i].first >> road[i].second;
    }
    sort(road,road+n,comp);
    long long prev =0, cnt= 0;
    long long factor = farmer - cow;
    for(int i=0;i<n;i++){
        if(road[i].first > prev){
            cnt+=factor * (road[i].first-prev) * road[i].second;
            prev = road[i].first;
        }
    }
    cout << cnt;
}


