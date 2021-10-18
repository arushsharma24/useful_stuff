#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll> a(n);
    ll i, x, y, z, j, k;
    for (i = 0; i<n; i++) cin>>a[i];
    ll sum = 0;
    for (i = 0; i < n; i++) sum+=a[i];
    vector<ll>dp(n, 0);
    dp[0] = 0;
    ll l = 0, r = n-1;
    z = 1;
    while(l < r){
        if(a[l] < a[r]) {
            //cout<<dp[z]<<" "<<dp[z-1]<<" "<<a[l];
            dp[z] = dp[z-1] + a[l];
            //cout<<dp[z]<<" "<<dp[z-1]<<" "<<a[l];
            l++;
            //cout<<"yo";
        }
        else{
            dp[z] = dp[z-1] + a[r];
            r--;
            //cout<<"hm";
        }
        z++;
    }
    ll vmin = INT_MAX;
    for(i = 0; i < n; i++){
        vmin = min(vmin, dp[i]);
        //cout<<dp[i]<<" ";
    }
    //cout<<vmin<<"\n";
    cout<<(sum-vmin)<<"\n";

    return;
}

void dpSolMaxSubarray(){
    ll n; cin>>n; 
    ll a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    ll dp[n];// max subarray sum of subarray ending at i
    dp[0] = a[0];
    ll ans = dp[0];
    for(int i = 1; i < n; i++){
        dp[i] = a[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
        // explanation:-
        // if the max subarray sum of the previous number is +ve, there is no harm in adding this element to it.
        // however, if it is negative, we start a new contiguos subarray from hereon.
        ans = max(dp[i], ans);
    }
    cout << ans << "\n";
}

void dpSolMaxSubarrayMinSpace(){    // O(1) space
    ll n; cin>>n; 
    ll prev, curr;
    ll x; cin>>x;
    prev = x;
    ll ans = prev;
    for(int i = 1; i < n; i++){
        cin>>x;
        curr = x + (prev > 0 ? prev : 0);
        // explanation:-
        // if the max subarray sum of the previous number is +ve, there is no harm in adding this element to it.
        // however, if it is negative, we start a new contiguos subarray from hereon.
        ans = max(curr, ans);
        prev = curr;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int test_cases = 1;
    // cin>>test_cases;
    while (test_cases--){
        // solve();
        dpSolMaxSubarrayMinSpace();
    }
    return 0;   
}