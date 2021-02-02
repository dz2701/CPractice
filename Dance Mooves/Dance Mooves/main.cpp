//
//  main.cpp
//  Dance Mooves
//
//  Created by Shin Lee on 2/1/21.
//
#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+5;
int n, m, k;
struct moves{int p1, p2;};
moves scenario[MAX];
int arr[MAX]; //number that is in that position right now.
struct swaps{int pos, t;};
vector<swaps>simulation[MAX];
int visit[MAX];
int ending[MAX];
vector<int>cycle;
void dfs(int pos){
    cycle.push_back(pos); visit[pos]=1;
    if(!visit[ending[pos]])dfs(ending[pos]); //다시 나올때까지 계속 돌리기
}

int ans[MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> m;
    for(int i=1;i<=k;i++){
        int a, b; cin >> a >> b;
        scenario[i] = {a,b};
    }
    //initialize position
    for(int i=1;i<=n;i++)arr[i]=i;
    
    //perform 1 simulation to figure out cycle. mark where it can go
    for(int i=1;i<=k;i++){
        simulation[arr[scenario[i].p1]].push_back({scenario[i].p2,i});
        simulation[arr[scenario[i].p2]].push_back({scenario[i].p1,i});
        swap(arr[scenario[i].p1], arr[scenario[i].p2]);
    }
    
    //mark ending position of each number
    for(int i=1;i<=n;i++)ending[arr[i]] = i;
    
    //figure out each cycle by using DFS
    fill(visit,visit+n+1,0);
    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            //new cycle
            dfs(i);
            //'cycle' now has cycle length and cycle components
            printf("this cycle includes: \n");
            for(auto num: cycle){
                printf("%d ",num);
            }
            printf("\n");
            //case 1. the amount of cycles encompass entire process
            
            printf("for each members, here is more info:\n");
                for(auto num:cycle){
                    printf("%d:\n",num);
                    for(auto event : simulation[num]){
                        printf("(%d %d) ",event.pos, event.t);
                    }
                    printf("\n");
                }
            if(m/k >= cycle.size()){
                set<int>temp;
                for(int nodes : cycle){
                    temp.insert(nodes);
                }
                for(int nodes: cycle)ans[nodes] = temp.size();
            }else{
                printf("initialization of value\n");
                //case 2, it cannot cover the entire thing
                int iterations = m/k; //number of cycles that can be run
                
                //the first number can go through the first number in the cycle until (iterations-1)th set of the cycle.
                int cnt[MAX] = {0}, sz = 0;
                for(int j=0;j<iterations;j++){
                    for(auto events : simulation[cycle[j]]){
                        printf("adding event %d\n",events.pos);
                            if(cnt[events.pos]==0)sz++;
                            cnt[events.pos]++;
                    }
                }
                //then we need to add the remainders of the (0+iterations)th cycle
                int temp = 0;
                for(auto events: simulation[cycle[iterations]]){
                    if(events.t<=m%k){
                        printf("adding event %d\n",events.pos);
                        if(cnt[events.pos]==0)sz++;
                        cnt[events.pos]++;
                    }
                }
                ans[cycle[0]] = sz;
                printf("finished initialization\n\n");
                for(int j=1;j<=cycle.size()-iterations;j++){
                    printf("j=%d\n",j);
                    //the maximum cycle[j] can reach is up until [cycle[j+iteration-1]. therefore, subtract cycle[j-1] and add cycle[j+iteration-1] but the later is from m%k~cycle.size();
                    for(auto events: simulation[cycle[j-1]]){
                        printf("removing event %d\n",events.pos);
                        if(cnt[events.pos]==1)sz--;
                        cnt[events.pos]--;
                    }
                    for(auto events: simulation[cycle[j+iterations-1]]){
                        if(events.t>m%k){
                            printf("adding event %d\n",events.pos);
                            if(cnt[events.pos]==0)sz++;
                            cnt[events.pos]++;
                        }
                    }
                    for(auto events: simulation[cycle[j+iterations]]){
                        if(events.t<=m%k){
                            printf("adding event %d\n",events.pos);
                            if(cnt[events.pos]==0)sz++;
                            cnt[events.pos]++;
                        }
                    }
                    
                    ans[cycle[j]] = sz;
                }
            }
            cycle.clear();
        }
        
    }
    
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
