//
//  main.cpp
//  2457 공주님의 정원
//
//  Created by dz2701 on 6/24/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int n;
struct date{
    int month;
    int day;
};
pair<date,date>dates[MAX];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++)cin >> dates[i].first.month >> dates[i].first.day >> dates[i].second.month >> dates[i].second.day;
    
    
}
