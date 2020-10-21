#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 1e3;
const int INF = 1e9;
int cost[MAX+1][MAX+1]; //칸수로

// + 
int a, b, n;
struct state{int node, num; long long val;}; struct cmp{bool operator() (state a, state b){return a.val!=b.val? a.val<b.val : a.num < b.num;}};
priority_queue<state,vector<state>,cmp>pq;
ll arr[MAX+1];
ll nu[MAX+1];
int visit[MAX+1];
int main(){
    cin >> a >> b >> n;
    fill(&cost[0][0], &cost[MAX][MAX+1],INF);
    for(int i=1;i<=n;i++){
        int c, no;
        cin >> c >> no;
        vector<int>temp(no);
        for(int k=0;k<no;k++){
            cin >> temp[k];
        }
        for(int k=0;k<no;k++){
            for(int j=no-1;j>k;j--){
                cost[temp[k]][temp[j]]= min(cost[temp[k]][temp[j]],c);
            }
        }
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            if(cost[i][j]==INF)printf("INF ");
            else printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
    
    pq.push({a,0,0});
    fill(&arr[0],&arr[MAX],INF); fill(&nu[0],&nu[MAX],INF); arr[a]=0; nu[a] = 0;
    fill(&visit[0],&visit[MAX],0);
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        for(int i=1;i<=MAX;i++){
            if(arr[i] > now.val + cost[now.node][i] or (arr[i]==now.val+cost[now.node][i] and nu[i] > now.num+1)){
                pq.push({i,now.num+1,now.val+cost[now.node][i]});
                arr[i] = now.val + cost[now.node][i];
                nu[i] = now.num + 1;
            }
            
        }
    }
    if(arr[b]==INF)printf("\"-1 -1\"");
    else printf("%d %d",arr[b],nu[b]);
}
