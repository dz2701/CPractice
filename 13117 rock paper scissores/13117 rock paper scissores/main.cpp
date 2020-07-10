//
//  main.cpp
//  13117 rock paper scissores
//
//  Created by dz2701 on 6/29/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 15; int n, k;
struct pb{
    int s, r, p;
};pb prob[MAX];
int rock(int p, int st, int ed){
    if(st>1 or ed<1)return 1;
    int rt = 1;
    
    
    return rt;
}

int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++)cin >> prob[i].s >> prob[i].r >> prob[i].p;
    
    return 0;
}
