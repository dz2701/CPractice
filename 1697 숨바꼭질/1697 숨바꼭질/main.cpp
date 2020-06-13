//
//  main.cpp
//  숨바꼭질
//
//  Created by Shin Lee on 21/04/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX int(1e5+5)
using namespace std;
int x1, x2;
int visit[MAX];
int main(){
    cin >> x2 >> x1;
    queue<int>q;
    q.push(x2);
    visit[x2]=1;

    
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        if(front>0 and visit[front-1]==0){
            q.push(front-1);
            visit[front-1]=visit[front]+1;
        }
        if(visit[front+1]==0){
            q.push(front+1);
            visit[front+1] = visit[front]+1;
        }
        if(front<=1e5/2 and visit[2*front]==0){
            q.push(front*2);
            visit[2*front]=visit[front]+1;
        }
       
        if(visit[x1]!=0)break;
    }
    
    cout << visit[x1]-1;
    
    return 0;
}
