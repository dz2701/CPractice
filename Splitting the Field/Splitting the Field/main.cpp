//
//  main.cpp
//  Splitting the Field
//
//  Created by Shin Lee on 1/11/21.
//

#include <bits/stdc++.h>
using namespace std;
long long  n;
multiset<long long>X, Y, XX, YY;
vector<pair<long long ,long long >>Input;
bool cmp(pair<long long ,long long >a, pair<long long ,long long >b){return a.first!=b.first? a.first<b.first : a.second<b.second;}
bool dmp(pair<long long,long long>a, pair<long long,long long>b){return a.second!=b.second? a.second<b.second : a.first<b.first;}
int main(){
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    cin >> n;
    long long min_val = 1e18;
    for(long long  i=1;i<=n;i++){
        long long  x, y; cin >> x >> y;
        Input.push_back(make_pair(x,y));
        X.insert(x); Y.insert(y);
    }
    XX= X; YY = Y;
    sort(Input.begin(),Input.end(),cmp);
    long long original_value = (*X.rbegin()-*X.begin()) * (*Y.rbegin() - *Y.begin());
    long long leftX1=1e9, rightX1=-1e9, leftY1=1e9, rightY1=-1e9;
    for(pair<long long, long long>entry : Input){
        //printf("entry: %d %d\n",entry.first,entry.second);
        X.erase(X.find(entry.first)); Y.erase(Y.find(entry.second));
        if(X.empty())break;
        //check if 겹쳐
        leftX1 = min(leftX1,entry.first); rightX1 = max(rightX1,entry.first); leftY1 = min(leftY1,entry.second); rightY1 = max(rightY1,entry.second);
        long long leftX2 = *X.begin(), rightX2 = *X.rbegin(), leftY2 = *Y.begin(), rightY2 = *Y.rbegin();
        
        //printf("%lld %lld %lld %lld\n %lld %lld %lld %lld\n",leftX1,rightX1,leftY1,rightY1,leftX2,rightX2,leftY2,rightY2);
        if(rightX1>=leftX2)continue; //overlap
        
        long long calc = (rightX1-leftX1) * (rightY1-leftY1) + (rightX2-leftX2) * (rightY2-leftY2);
        //printf("calc:%lld\n",calc);
        min_val = min(calc,min_val);
    }
    
    sort(Input.begin(), Input.end(),dmp);
    X = XX; Y = YY;
    
    //printf("cases of Y\n");
    leftX1=1e9; rightX1=-1e9; leftY1=1e9; rightY1=-1e9;
    for(pair<long long, long long>entry : Input){
        //printf("entry: %d %d\n",entry.first,entry.second);
        X.erase(X.find(entry.first)); Y.erase(Y.find(entry.second));
        if(X.empty())break;
        //check if 겹쳐
        leftX1 = min(leftX1,entry.first); rightX1 = max(rightX1,entry.first); leftY1 = min(leftY1,entry.second); rightY1 = max(rightY1,entry.second);
        long long leftX2 = *X.begin(), rightX2 = *X.rbegin(), leftY2 = *Y.begin(), rightY2 = *Y.rbegin();
        
        //printf("%lld %lld %lld %lld\n %lld %lld %lld %lld\n",leftX1,rightX1,leftY1,rightY1,leftX2,rightX2,leftY2,rightY2);
        if(rightY1>=leftY2)continue; //overlap
        
        long long calc = (rightX1-leftX1) * (rightY1-leftY1) + (rightX2-leftX2) * (rightY2-leftY2);
        
        //printf("calc:%lld\n",calc);
        min_val = min(calc,min_val);
    }
    //printf("original: %lld, later: %lld\n",original_value, min_val);
    cout << original_value - min_val;
    return 0;
}
