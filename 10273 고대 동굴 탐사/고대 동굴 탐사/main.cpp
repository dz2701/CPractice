//
//  main.cpp
//  고대 동굴 탐사
//
//  Created by dz2701 on 6/8/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX 20005
using namespace std;

//need a file type that can store information about the path taken and its value + how many caves it went through.
struct Case{
    vector<int>path;
    int value;
};
//and then the caves should contain its number and its value. Instead of separate arrays, I'll make a file type to contain the values.
struct Cave{
    int number, value;
};
Cave caves[MAX]; //array of caves

vector<pair<int,int>>roads[MAX]; //will contain first:end and second: price
struct tem{
    int visit[MAX];
    int num;
    vector<int>path;
    int value;
    int prevcost;
};
//needed global variable: t: number of test cases,
int t;

int main(){
    cin >> t;
    for(int z=0;z<t;z++){
        int n, e;
        cin >> n >> e; //n: number of caves, e: number of edges
        for(int i=1;i<n;i++){
            caves[i].number = i;
            cin >> caves[i].value;
        }
        for(int i=0;i<e;i++){
            int a, b, c;
            cin >> a >> b >> c;
            roads[a].push_back(make_pair(b,c));
            
        }
        queue<tem>q;
        //all explorations start from 1
        q.push({{},1,{},0,0});
        Case ans = {{},0};
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front.visit[front.num]==1)continue;
            else front.visit[front.num]=1;
            front.path.push_back(front.num);
            if(front.value + caves[front.num].value - front.prevcost > ans.value){
                ans.value = front.value + caves[front.num].value - front.prevcost;
                ans.path = front.path;
            }
            for(auto i : roads[front.num]){
                if(front.visit[i.first]!=1){
                    tem now;
                    copy(front.visit,front.visit+n+1,now.visit);
                    now.num = i.first;
                    now.path = front.path;
                    now.value = front.value + caves[front.num].value - front.prevcost;
                    now.prevcost = i.second;
                    q.push(now);
                }
            }
            
        }
        cout << ans.value << " " << ans.path.size() << "\n";
        for(int i : ans.path){
            cout << i << " ";
        }
        cout << "\n";
    }
    
}
