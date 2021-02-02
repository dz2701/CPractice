//
//  main.cpp
//  Dance Mooves
//
//  Created by Shin Lee on 1/23/21.
//  brute force

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int MAX = 1e5+5;
long long n, m, k;
pii moves[MAX];
int arr[MAX];
set<int>loc[MAX];
int main(){
    cin >> n >> k >> m;
    for(int i=0;i<k;i++){
        cin >> moves[i].first >> moves[i].second;
    }
    for(int i=1;i<=n;i++){
        arr[i] = i;
        loc[i].insert(i);
    }
    if(m!=1e18){
    for(int i=0;i<m;i++){
        loc[arr[moves[i%(k)].first]].insert(moves[i%(k)].second);
        loc[arr[moves[i%(k)].second]].insert(moves[i%(k)].first);
        swap(arr[moves[i%(k)].first],arr[moves[i%(k)].second]);
    }
    for(int i=1;i<=n;i++){
        printf("%lld\n",loc[i].size());
    }
    }else{
        set<int>coll_sum;
        for(int i=1;i<=k;i++){
            coll_sum.insert(moves[i].first);
            coll_sum.insert(moves[i].second);
        }
        for(int i=1;i<=n;i++){
            if(coll_sum.find(i)!=coll_sum.end()){
                printf("%lld\n",coll_sum.size());
            }else{
                printf("%d\n",1);
            }
        }
    }
}
