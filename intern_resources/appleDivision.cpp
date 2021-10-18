#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// okay so i saw that william lin just did a brute force, so let's do that only

int main(){
	int n; cin>>n;
	vector<ll> a(n);
	ll sum = 0; ll res = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		sum += a[i];
	}
	// now, trying to generate subsets using bitmasks
	for(ll i = 0; i < 1<<n; i++){
		// 2^n subsets
		// now, in this subset, 
		// i will include the number whose bit is set
		// x & (x-1) clears the last bit
		// x & ~(x-1) extracts the last bit
		ll index = i;
		ll tsum = 0;
		while( index != 0){
			ll x = index & ~(index-1);
			tsum += a[n - 1 - log2(x)];
			index = index&(index-1);
		}
		// now tsum is the sum of this subset
		if(tsum <= sum/2){
			res = max(res, tsum);
		}
	}
	cout << sum - 2*res << "\n";
	// okay! this passed
	// and i learnt how to use bitmasks
	// but this looks REAL SLOW
}





/* 	wrong answer ugh
// i had thought that this question was easy, lol rip me
int main(){
	ll n; cin>>n;
	vector<ll>a;
	for(ll i = 0; i < n; i++){
		ll x; cin>>x;
		a.push_back(x);
	}
	vector<ll> one;
	one.push_back(0);
	one.push_back(a[0]);
	one[0] += one[one.size()-1];
	vector<ll> two;
	two.push_back(0);
	two.push_back(a[1]);
	two[0] += two[two.size()-1];

	ll x,y,z, pone, ptwo;
	ll t1, t2, t3;

	for(ll i = 2; i < n; i++){
		x = a[i];
		y = one[one.size()- 1];
		z = two[two.size() -1];
		pone = one[0] - y;
		ptwo = two[0] - z;			

		if(one[0] <= two[0]){
			t1 = (abs)(pone + y + x - ptwo - z);
			t2 = (abs)(pone + y + z - ptwo - x);
			t3 = (abs)(pone + x - ptwo - y - z);
			if(t2 < t1 && t2 < t3){
				one.push_back(z);
				one[0] += z;
				two.pop_back();
				two.push_back(x);
				two[0] += x - z;
			}
			else if(t3 < t1 && t3 < t2){
				two.push_back(y);
				two[0] += y;
				one.pop_back();
				one.push_back(x);
				one[0] += x - y;
			}
			else { // when t1 is the least or when some are equal, ugh this might have bugs
				one.push_back(x);
				one[0] += x;
			}
		}
		else{// one > two
			t1 = (abs)(ptwo + z + x - pone - y);
			t2 = (abs)(pone + y + z - ptwo - x);
			t3 = (abs)(pone + x - ptwo - y - z);
			if(t2 < t1 && t2 < t3){
				one.push_back(z);
				one[0] += z;
				two.pop_back();
				two.push_back(x);
				two[0] += x - z;
			}
			else if(t3 < t1 && t3 < t2){
				two.push_back(y);
				two[0] += y;
				one.pop_back();
				one.push_back(x);
				one[0] += x - y;
			}
			else { // when it is added to two
				two.push_back(x);
				two[0] += x;
			}
		}
		for(int i = 0; i < one.size(); i++){
			cout<<one[i]<<" ";
		}
		cout<<"\n";
		for(int i = 0; i < two.size(); i++){
			cout<<two[i]<<" ";
		}
		cout<<"\n\n";
	}
	ll res = (abs)(two[0] - one[0]);
	cout<<res<<"\n";
}
// ugh, wrong answer again
*/

/* wrong answer
int main(){
	int n; cin>>n;
	vector<ll> a;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		ll x; cin>>x;
		a.push_back(x);	
		sum += x;
	}	
	// now, sum of one group <= x/2;
	// keep adding elements only when sum adheres to it
	ll one = 0;
	sort(a.begin(), a.end());
	ll hsum = sum/2;
	for(int i = n-1; i >=0; i--){
		if(one + a[i] <= hsum){
			one += a[i];
		}
	}
	ll two = sum - one;
	//cout<<two<<" "<<one<<" ";
	cout<<two - one<<"\n";
	// wrong answer
}
*/