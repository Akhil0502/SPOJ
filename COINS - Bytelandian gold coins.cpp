#include<bits/stdc++.h>
using namespace std;
map<int,long long> dp;

long long coins(int n){
	if(dp[n] != 0) return dp[n];
	if(n==0) return 0;
	long long ret=coins(n/2)+coins(n/3)+coins(n/4);
	if(ret>n) dp[n]=ret;
	else dp[n]=n;
	return dp[n];
	}
int main(){
	int n;
	while(cin>>n){
		cout<<coins(n)<<endl;
	}
	return 0;
}
