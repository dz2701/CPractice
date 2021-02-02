//
//  main.cpp
//  택배
//
//  Created by Shin Lee on 1/14/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e3+1;
struct edge{int a, b, cost;};
vector<edge>adj;
int corr_num[MAX];
int arr[MAX];
int n, heli_cost, truck_cost;
bool cmp(edge a, edge b){return a.cost<b.cost;}
int g[MAX], sz[MAX];
int Find(int a){
    if(g[a]==a)return a;
    else return g[a]=Find(g[a]);
}
bool Union(int a, int b){
    a = Find(a); b = Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    g[a]=g[b]; sz[b]+=sz[a];
    return true;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    int prev=-1, previdx = 0;
    for(int i=1;i<=n;i++){
        int temp; cin >> temp;
        if(prev!=temp){
            corr_num[++previdx] = temp;
        }
        arr[previdx]++;
    }
    cin >> truck_cost >> heli_cost;
    //construct edges
    
    for(int i=1;i<previdx;i++){
        g[i] = i; sz[i] = 1;
        adj.push_back({0,i,arr[i]*i*truck_cost});
        adj.push_back({0,i,heli_cost});
        
        for(int j=1;j<previdx;j++){
            if(i!=j){
                adj.push_back({i,j,arr[j]*abs(corr_num[i]-corr_num[j])*truck_cost*arr[j]});
            }
        }
    }
    //PROBLEM: IF YOU ARE TO TAKE THE TRUCK TO 4 THEN 5, THEN THE COST OF THE TRUCK INCREASES
    //SOLUTION: CHANGE THIS MST ALGORITHM TO A BFS ALGORITHM SO REAL-TIME MONITORING IS POSSIBLE
    for(auto con : adj){
        printf("%d %d %d\n",con.a,con.b,con.cost);
    }
    /*for(auto it=entry.begin(); it!=entry.end(); it++){
        //initialize union find
        g[*it] = *it;
        sz[*it] = 1;
        //from 0 to them
        adj.push_back({0,*it,min(arr[*it]**it*truck_cost, heli_cost)});//use truck
        adj.push_back({0,*it, heli_cost}); //use helicopter
        
        //from them to other nodes via truck
        for(auto itt = entry.begin(); itt!=entry.end(); itt++){
            if(*it!=*itt)adj.push_back({*it, *itt, arr[*itt]*abs(*it-*itt)*truck_cost});
        }
    }*/
    
    //using kruskal's method to form mst
    sort(adj.begin(),adj.end(),cmp);
    int fac = n-1; long long ans = 0;
    for(edge e : adj){
        if(Union(e.a, e.b)){
            ans += e.cost;
            fac--;
        }
        if(!fac)break;
    }
    cout << ans;
    return 0;
}
