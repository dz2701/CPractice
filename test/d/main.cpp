//
//  main.cpp
//  d
//
//  Created by dz2701 on 6/8/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int dur;
    int no;
    int starttime;
};
auto cmp = [](node a, node b){
    return a.starttime < b.starttime;
};


int main(){
    priority_queue<node,vector<node>,decltype(cmp)>pq(cmp);
    pq.push({1,0,0});
    pq.push({2,3,1});
    pq.push({5,3,1});
    pq.push({-4,3,9});
    
    while(!pq.empty()){
        cout << pq.top().dur << pq.top().no << pq.top().starttime << "\n";
        pq.pop();
    }
}
