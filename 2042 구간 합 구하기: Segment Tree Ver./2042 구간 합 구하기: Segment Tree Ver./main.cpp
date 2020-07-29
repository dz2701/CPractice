//
//  main.cpp
//  2042 구간 합 구하기: Segment Tree Ver.
//
//  Created by dz2701 on 7/17/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
long long arr[MAX]; map<int,long long>tree;


long long init(int node, int start, int end){
    if(start==end)return tree[node]=arr[start];
    else{
        return tree[node]=init(node*2,start,(start+end)/2) + init(node*2+1,(start+end)/2+1, end);
    }
}
long long sum(int node, int start, int end, int x, int y){
    if(x>end or y<start)return 0; //this means it's out of range
    if(x<=start && end<=y) return tree[node]; //if it perfectly falls in the range add the number that I need
    return sum(node*2,start,(start+end)/2,x,y) + sum(node*2+1,(start+end)/2+1,end,x,y);
}
void change(int node, int start, int end, int idx, long long ch){
    //change idx --> val
    if(idx<start || idx>end)return; //idx does not fall into the range
    tree[node]+=ch;
    if(start!=end){ //if it isn't leaf --> need to change children
        change(node*2,start,(start+end)/2,idx,ch);
        change(node*2+1,(start+end)/2+1,end,idx,ch);
    }else{
        arr[start] = tree[node]; //?
    }
}
int n, m, k;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    init(1,1,n);
    int num = m+k;
    while(num--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==1){
            change(1,1,n,b,c-arr[b]);
        }
        else{
            cout << sum(1,1,n,b,c) << "\n";
        }
        
    }
    return 0;
}

