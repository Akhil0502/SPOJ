#include<bits/stdc++.h>
using namespace std;

void util(string s,string t){
	int m=s.size();
	int n=t.size();
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(!i || !j)dp[i][j]=0;
			else if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}	
	int mx=dp[m][n];
	char lcs[m+n-mx];
	mx=m+n-mx-1;
	int p=mx;
	int i=m,j=n;
	while(i>0 && j>0){
		if(s[i-1] == t[j-1]){
			lcs[mx] =s[i-1];
			i--;
			j--;
			mx--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			lcs[mx]=s[i-1];
			mx--;
			i--;
			
		}
		else{
			lcs[mx]=t[j-1];
			mx--;
			j--;
			
		}
	}
	while(i>0 && mx>=0){
		lcs[mx--]=s[i-1];i--;
	}
	while(j>0 && mx>=0){
		lcs[mx--]=t[j-1];j--;
	}
	lcs[p+1]='\0';
	cout<<lcs<<endl;
}
int main(){
	string s,t;
	while(cin>>s){
		cin>>t;
		util(s,t);
	}	
	return 0;
}
