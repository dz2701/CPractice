//
//  main.cpp
//  12002 Field Reduction
//
//  Created by dz2701 on 10/1/20.
//

#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int MAX = 5e4+1;
pii cow[MAX];
int n;
struct cmpxb{
    bool operator () (pii a, pii b){
        return a.first > b.first;
    }
};
struct cmpxs{
    bool operator () (pii a, pii b){
        return a.first < b.first;
    }
};
struct cmpyb{
    bool operator () (pii a, pii b){
        return a.second > b.second;
    }
};
struct cmpys{
    bool operator () (pii a, pii b){
        return a.second < b.second;
    }
};

set<pii,cmpxb>sxb;
set<pii,cmpxs>sxs;
set<pii,cmpyb>syb;
set<pii,cmpys>sys;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> cow[i].first >> cow[i].second;
        sxb.insert(cow[i]);
        sxs.insert(cow[i]);
        syb.insert(cow[i]);
        sys.insert(cow[i]);
    }
    pii xb[3], xs[3], yb[3], ys[3];
    auto it1 = sxb.begin();
    auto it2 = sxs.begin();
    auto it3 = syb.begin();
    auto it4 = sys.begin();
    
    for(int i=0;i<3;i++){
        xb[i] = *it1;
        xs[i] = *it2;
        yb[i] = *it3;
        ys[i] = *it4;
        it1++;it2++;it3++;it4++;
    }
    
    //multiple cases where we select 3 from 12 --> 12C3 = 12*11*10 --> efficient enough, but hard to code.
    
    
}
