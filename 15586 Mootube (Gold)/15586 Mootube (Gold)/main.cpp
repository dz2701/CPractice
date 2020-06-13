//
//  main.cpp
//  Mootube Gold
//
//  Created by dz2701 on 5/7/20.
//  Copyright © 2020 dz2701. All rights reserved.
//
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int n, q, sz[MAX], arr[MAX];
struct triple{int n1, n2, n3;};
struct question{int first, second, id, ans;};
vector<triple>v;
question query[MAX];
bool cmp(triple a, triple b){return a.n3 > b.n3;}
bool cmp2(question a, question b){return a.first>b.first;}
bool cmpl(question a, question b){return a.id<b.id;}
int Find(int a){
    if(arr[a]==a)return a;
    else return arr[a] = Find(arr[a]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a==b)return;
    
    if(sz[a]>sz[b])swap(a,b);
    arr[a]=b;
    sz[b]+=sz[a];
}
int main(){
    cin >> n >> q;
    for(int i=0;i<n-1;i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a,b,c});
    }
    for(int i=0;i<q;i++){
        cin >> query[i].first >> query[i].second;
        query[i].id = i;
    }
    
    //sorts offline query
    sort(v.begin(), v.end(),cmp);
    sort(query,query+q,cmp2);
    
    //initialize
    for(int i=1;i<=n;i++){
        arr[i]=i;
        sz[i]=1;
    }
    
    //start offline query
    int idx = 0;
    for(int i=0;i<q;i++){
        //query[i].first --> value of USADO, query[i].second --> starting point
        //link paths while its USADO is smaller
        while(idx!=v.size()){
            if(v[idx].n3>=query[i].first){
                //ok, connect dot
                Union(v[idx].n1,v[idx].n2);
                idx++;
            }
            else{
                //not ok, stop connecting
                break;
            }
        }
        
        //after linking, obtain the size of the starting point, which is the answer to the specific query
        query[i].ans = sz[Find(query[i].second)];
    }
    
    //after offline query, sort ans in order
    sort(query,query+q,cmpl);
    
    for(int i=0;i<q;i++){
        printf("%d\n",query[i].ans-1);
    }
    
    return 0;
}
