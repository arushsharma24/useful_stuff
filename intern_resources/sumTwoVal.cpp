#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, x, y, z, index = 0; cin>>n>>x;
    vector<pair<ll, ll>> a;
    vector<ll>b;
    for(ll i = 0; i < n; i++){
        cin>>y;
        a.push_back(make_pair(y, i));
        b.push_back(y);
    }    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        y = b[i];
        if ( y >= x ){
            cout<<"IMPOSSIBLE\n";
            break;
        } 
        z = x - y;
        auto it = lower_bound(b.begin() , b.end() , z);
        index = it - b.begin();
        while(index <= i)   index++;
        // will return iterator to value where >= z
        // if > z, nahi chalega
        // so , if == z
        //cout<<b[index]<<" "<<z<<" "<<index<<"\n";
        if(a[index].first == z && (index > i)){
            // milgaya!!
            cout<<++a[i].second<<" "<<++a[index].second<<"\n";
            break;
        }
        else if (i == n-1){
            cout<<"IMPOSSIBLE\n";
        }
    }
    
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