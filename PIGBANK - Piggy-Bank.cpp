#include <bits/stdc++.h>
using namespace std;

int n;	int s,e,res,cst,wt;
vector<int> cost(501);
vector<int> weight(501);
int Knapsack(){
	vector<int> dp(s+1,0);
	dp[0]=0;
	for(int i=0,j;i<n;i++){
		cst=cost[i];
		wt=weight[i];
		j=wt;
		if(wt<s)
		dp[wt]=dp[wt]==0?cst:min(cst,dp[wt]);
		while(j<=s){
			if(dp[j-wt] !=0)
				if(dp[j])
				dp[j]=min(dp[j],dp[j-wt]+cst);
				else dp[j]=dp[j-wt]+cst;
			j=j+1;
		}
	}
	return dp[s];
	
}
int main(int argc, char** argv) {
	int t; cin>>t;
	while(t--){
		cin>>s>>e;
		s=e-s;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>cost[i]>>weight[i];
		}
	res=Knapsack();
	if(!res){
		cout<<"This is impossible.\n";
	}
	else{
		cout<<"The minimum amount of money in the piggy-bank is "<<res<<endl;
	}
	}
	
	return 0;
}
