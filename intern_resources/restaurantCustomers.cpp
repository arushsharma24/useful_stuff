#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<int> a;
    vector<int> b;
    int i, x, y;
    for(i = 0; i < n; i++){
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int imax = INT_MIN;
    for(int i = 0; i < n; i++){
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        int num = it - a.begin() - i;
        imax = max(imax, num);
        //cout<<imax<<" ";
    }
    //cout<<"\n";
    cout<<imax<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    //cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}