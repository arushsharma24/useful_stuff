#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = (int) 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    

    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    ll dp[k+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i <= k; i++){
        for(int j = 0; j < n; j++){ // start with coin of value x
            if(i - a[j] >= 0){ // if it is possible to take that coin
                dp[i] += dp[i- a[j]];   // number of ways to write the remaining number
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[k] << "\n";
}