#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll factorial(ll n){
    if(n == 0 || n == 1) return 1;
    else return n*factorial(n-1);
}   
// a hopefully practical approach to create permutations of a string by randomizing it, 
int main(){
    string s; cin>>s;
    map<char, int> m;
    for(int i = 0; i < s.length(); i++){
        m[s[i]]++;
    }
    ll num = factorial(s.length());
    ll den = 1;
    for(auto it = m.begin(); it != m.end(); it++){
        den *= factorial(it->second);
    }
    num /= den;
    // one way is to use the default function in stl apparently of next_permutation
    cout<<num<<"\n";
    sort(s.begin(), s.end());
    vector<string> v;
    do{
        v.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<"\n";
    }
}