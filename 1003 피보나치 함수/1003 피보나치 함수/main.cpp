//
//  main.cpp
//  피보나치 함수
//
//  Created by Shin Lee on 22/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
pair<long long, long long>fib[45];
vector<int> resp, r;
int main() {
    int n, t;
    cin >> t;
    for(int i=0;i<t;i++){
        int a;
        cin >> a;
        resp.push_back(a);
        r.push_back(a);
    }
    sort(resp.begin(), resp.end());
    n = resp[t-1];
    fib[0]={1,0};
    fib[1]={0,1};
    for(int i=2;i<=n;i++){
        fib[i].first = fib[i-1].first + fib[i-2].first;
        fib[i].second = fib[i-1].second + fib[i-2].second;
    }
    for(int i=0;i<t;i++){
        printf("%d %d\n",fib[r[i]].first, fib[r[i]].second);
    }
    
    return 0;
}
