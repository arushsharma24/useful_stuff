#include <iostream> 
int main(){long long n,p,c,x,a;std::cin>>n>>x;p=x;a=p;for(int i=1;i<n;i++){std::cin>>x;c=x+(p>0?p:0);a=c>a?c:a;p=c;}std::cout<<a<<"\n";}