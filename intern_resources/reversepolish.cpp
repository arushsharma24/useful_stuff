#include <string>
#include <bits/stdc++.h>
using namespace std;
int Solution(vector<string> tokens) {
    stack<int> s;
    for(int i = 0; i<tokens.size(); i++){
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*"){
            int a1 = s.top();
            s.pop();
            cout<<a1;
            int a2 = s.top();
            s.pop();
            cout<<a2;
            if(tokens[i] == "+"){
                s.push(a2+a1);
            }
            if(tokens[i] == "-"){
                s.push(a2-a1);
            }
            if(tokens[i] == "*"){
                s.push(a2*a1);
            }
            if(tokens[i] == "/"){
                s.push(a2/a1);
            }
        }
        else{
            s.push(stoi(tokens[i]));
        }
        return s.top();
    }
}

int main(){
    vector<int> tokens;
    int n = tokens.size();
    for(int i = 0; i<n; i++){
        cin>>tokens[i];
    }

}