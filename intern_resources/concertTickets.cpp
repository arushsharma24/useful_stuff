#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
    int n,m; cin>>n>>m;
    //vector<int> t(n);
    multiset<int> t;
    vector<int> p(m);
    for (int i = 0; i < n; i++){
        int x; cin>>x;
        t.insert(x);
    }
    for (int i = 0; i < m; i++){
        cin>>p[i];
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < m; i++){
        // max price this customer will pay is p[i];
        auto it = lower_bound(t.begin(), t.end(), p[i]); // log n
        //int idx = it - t.begin();
        if(it == t.begin()){
            cout<<"-1\n";
        }
        else{
            cout<<*(--it)<<"\n";
            t.erase(it);
        }
        //cout<<"idx: "<<idx<<" ";
        // if(idx-1 < 0){
        //     cout<<"-1\n";
        // }
        // else{
        //     if(idx == t.size()-1){
        //         if(t.back() <= p[i]){
        //             cout<<t.back()<<"\n";
        //             t.pop_back();
        //         }
        //         else{
        //             cout<<t[idx-1]<<"\n";
        //             t.erase(--it);
        //         }
        //         continue;
        //     } 
        //     cout<<t[idx-1]<<"\n";
        //     t.erase(--it);
        // }
    }
    return;
}

void solve2(){
    map<int, int> t;
    int n,m; cin>>n>>m;
    //vector<int> p(m);
    for (int i = 0; i < n; i++){
        int x; cin>>x;
        t[x]++;
    }
    for (int  i = 0; i < m; i++){
        int x; cin>>x; 
        auto ix = t.end();
        ix--;
        auto end = --t.begin();
        for(auto it = ix; it != end; it--){
            if(it->first >= x){
                if(it->second > 0){
                    cout<<(it->first)<<"\n";
                    it->second--;
                    continue;
                }
                else continue;
            }
            if(it == t.begin()) {
                cout<<"-1\n";
                continue;
            }
        }
    }
    
}

void solve3() {
    int n,m,h,t; multiset<int> tickets;
	cin >> n >> m;
	for (int i=0;i<n;++i){
		cin >> h; tickets.insert(h);
	}
	for (int i=0;i<m;++i){
		cin >> t;
		auto it = tickets.upper_bound(t);
		if (it==tickets.begin()){
			cout << -1 << "\n";
		}
		else{
			cout << *(--it) << "\n";
			tickets.erase(it);
		}
	}
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