#include <bits/stdc++.h>
using namespace std;
#define ll long long
// const int M = (int) 1e9 + 7;
#define M 1000000007

int dp[101][1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    

    int n, k; cin>>n>>k;
    vector<int> ac(n);
    for(int i = 0; i < n; i++) cin>>ac[i];
    sort(ac.begin(), ac.end());
    // cout << "X: ";
    // for(int i = 1; i <= k; i++) cout << i << " ";
    // cout << "\n";
    // memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
        // cout << ac[i-1] << ": ";
        for(int j = 1; j <= k; j++){    // current value under consideration
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= M;
            if((j - ac[i-1]) >= 0){
                dp[i][j] += dp[i][j-ac[i-1]];
                dp[i][j] %= M;
            }
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }    

    cout << dp[n][k] << "\n";
}