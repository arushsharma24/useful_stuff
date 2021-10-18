#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long 
ll factorial(ll n){
    if(n == 0 || n == 1) return 1;
    else return n*factorial(n-1);
}   
// an impractical approach to create permutations of a string by randomizing it, 
// checking if that has already been generated, if not, add it to my vector of strings
// then sort that vector
// ba-da boom we can get the result
// needless to say, this is a shitty way to do it lol, very very slow even for small strings of even single digit length
// basically bogoPermuteAndAdd lol
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
    cout<<num<<"\n";
    vector<string> v;
    v.push_back(s);
    for(int i = 1; i < num; i++){
        do{
            random_shuffle(s.begin(), s.end());
        } while ((find(v.begin(), v.end(), s) != v.end()));
        //cout<<s<<endl;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<"\n";
    }
}