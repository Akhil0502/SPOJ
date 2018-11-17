#include<bits/stdc++.h>
using namespace std;
vector<int> weight(50);
vector<int> cost(50);
int max_size,n;

int Knapsack(){
	int dp[n+1][max_size+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=max_size;j++){
			if(weight[i-1]  <= j){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]] + cost[i-1]);
			}
			else dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][max_size];
}
int main(){
	int t;cin>>t;
	while(t--){
		cin>>max_size>>n;
		for(int i=0;i<n;i++)cin>>weight[i]>>cost[i];
		cout<<"Hey stupid robber, you can get "<<Knapsack()<<"."<<endl;	
	}
}
