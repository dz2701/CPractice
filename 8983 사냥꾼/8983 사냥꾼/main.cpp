//
//  main.cpp
//  사냥꾼
//
//  Created by Shin Lee on 24/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+5;
long long n, m ,l;
vector<long long>shoot;
pair<long long, long long>animal[MAX];
long long dist[MAX];
int main(){
    cin >> m >> n >> l;
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        shoot.push_back(a);
    }
    sort(shoot.begin(),shoot.end());
    shoot.push_back(int(1e9));
    for(int i=0;i<n;i++){
        cin >> animal[i].first >> animal[i].second;
    }
    long long cnt=0;
    for(int i=0;i<n;i++){
        long long nu = animal[i].first;
        auto iter = lower_bound(shoot.begin(),shoot.end(),nu);auto iter2 = iter-1;
        if(iter==shoot.begin())iter2 = iter;
        
        
        long long num = min(*iter - nu, abs(nu - *iter2));
        //printf("animal[%d].first = %lld, *iter = %lld, *iter2 = %lld, so num = %lld\n",i,nu,*iter,*iter2,num);
        if(num+animal[i].second<=l)cnt++;
    }
    
    cout << cnt;
    
    return 0;
}
