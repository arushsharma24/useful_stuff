#include <bits/stdc++.h>
using namespace std;
#define ll long long  

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    ll n, m, k, x; cin>>n>>m>>k;
    vector<ll> want(n);
    vector<ll> ap(m);
    for(int i = 0; i < n; i++)
        cin>>want[i];
    for(int i = 0; i < m; i++){
        cin>>x;
        ap[i] = x;
    }
    sort(want.begin(), want.end());
    sort(ap.begin(), ap.end());

    ll count = 0;
    int index = 0;// for traversing the ap vector
    // hmm , this exceeds time limit however
    for(int i = 0; i < n; i++){
        ll start = want[i] - k;
        ll end = want[i] + k;
        while(ap[index] <= end && index < m){
            if(ap[index] < start){
                index++;
            }
            else {
                count++;// this apartment will be taken
                ap[index] = 0;
                index++;
                break;
            }
        }
    }
    cout<<count<<"\n";
}