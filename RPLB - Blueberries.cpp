#include<bits/stdc++.h>
using namespace std;
int RPLB(vector<int> &data,int size){
	int n=data.size();
	int dp[n+1][size+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=size;j++){
			if(i==1){dp[i][j]=(data[i-1]<=j)?data[i-1]:0;}
			else
			{ if(j-data[i-1] <0) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max( data[i-1]+dp[i-2][j-data[i-1]] , dp[i-1][j]);	
		}
		}
	}
	return dp[n][size];
}
int main(){
	int t,n,max_size;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>max_size;
		vector<int> data(n);
		for(int k=0;k<n;k++)cin>>data[k];
		cout<<"Scenario #"<<i<<": "<<RPLB(data,max_size)<<endl;
	}
}
