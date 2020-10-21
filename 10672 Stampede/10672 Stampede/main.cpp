//
//  main.cpp
//  10672 Stampede
//
//  Created by dz2701 on 10/6/20.
//

#include <bits/stdc++.h>
using namespace std;
struct cowpoint{int id, time; bool enter;};
struct cow{int id, y;};
struct cmp{bool operator() (cowpoint a, cowpoint b){return a.time!=b.time?a.time<b.time:a.enter<b.enter;}};
struct ccmp{bool operator() (cow a, cow b){return a.y<b.y;}};
vector<cowpoint>v;
int n, y[50001];

int main(){
    //freopen("stampede.in","r",stdin);
    //freopen("stampede.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x, yy, r;
        cin >> x >> yy >> r;
        //enter: (-1-x) * r; exit: (1-x)*r;
        y[i] = yy;
        v.push_back({i,(-1-x)*r,true});
        v.push_back({i,(-x)*r,false});
    }
    
    set<cow, ccmp>s;
    set<int>ans;
    sort(v.begin(),v.end(),cmp());
    int prev = v[0].time;
    for(int i=0;i<v.size();i++){
        prev = v[i].time;
        while(i<v.size() and prev==v[i].time){
            if(v[i].enter){
                s.insert({v[i].id,y[v[i].id]});
            }else{
                s.erase({v[i].id,y[v[i].id]});
            }
            i++;
        }
        i--;
        if(!s.empty())ans.insert((*s.begin()).id);
    }
   

    cout << ans.size();
    return 0;
}
