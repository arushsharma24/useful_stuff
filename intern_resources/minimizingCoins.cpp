#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 10000000007

void solve(){
    ll n, x; cin>>n>>x;
    vector<ll> c(n);
    for(ll i = 0; i < n; i++) cin>>c[i];
    sort(c.begin(), c.end());
    // 
    vector<ll> dp(x+1, INT_MAX);    // minimum number of coins required to represent this value.
    dp[0] = 0;
    for(ll y : c){
        ll ii = 1;
        while(y * ii <= x ){
            dp[y*ii] = min(dp[y*ii], ii);
            // cout << dp[y*ii] << " ";
            ii++;
        }
    }
    for(ll i = 0; i <= x; i++){
        for(ll y : c){
            if(i - y >= 0)    dp[i] = min(dp[i], 1 + dp[i - y]);
        }
    //     cout << dp[i] << " ";
    }
    // cout <<"\n";
    if(dp[x] == INT_MAX) cout << "-1\n";
    else    cout << dp [x] << "\n";

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        solve();
    }
    return 0;   
}