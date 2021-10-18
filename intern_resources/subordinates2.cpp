#include <bits/stdc++.h>
using namespace std;

vector<int> tree[200001];

void calcSubs(int root, int parent, vector<int>& vec){
    int subs = 0;
    for(int child : tree[root]){
        if(child != parent){
            calcSubs(child, root, vec);
            subs += 1 + vec[child];
        }
    }
    vec[root] = subs;
}


int main(){
    long long t = 1; 
    while(t--){
        long long n; cin>>n;
        vector<int> ans(n+1);
        for(int i = 2; i < n + 1; i++){
            long long x; cin>>x;
            tree[x].push_back(i);
            tree[i].push_back(x);
        }
        calcSubs(1,0,ans);
        for(int i = 1; i < n+1; i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}