//
//  main.cpp
//  Sleepy Cow Sorting
//
//  Created by dz2701 on 10/8/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX], fw[MAX];
void update (int p, int v){ //update arr[p] +v, update BIT(FT)
    for(; p<MAX;p+=p&-p){
        fw[p] += v;
    }
}
int sum(int p){//sum from 1~p;
    int ret=0;
    for(; p;p-=p&-p){
        ret+=fw[p];
    }
    return ret;
}
int n;
int inv[MAX];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    //init number of inversions
    for(int i=1;i<=n;i++){
        update(arr[i],1);
        inv[arr[i]] = sum(n) - sum(arr[i]);
    }
    for(int i=1;i<=n;i++){
        printf("inv[%d]=%d\n",arr[i],inv[arr[i]]);
    }
    int ans; vector<int>path;
    while(sum(n)){
        for(int i=1;i<=n;i++){
            if(inv[i]){
                
            }
        }
    }
    
}
