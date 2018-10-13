#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	int a[t];
	for(int i=0;i<t;i++)cin>>a[i];
	int dp[t];
	int mx=-1;
	dp[0]=1;
	for(int i=1;i<t;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(a[i]>a[j] && (dp[i]<dp[j]+1 )) 
				dp[i]=dp[j]+1;					
		}	
	}
	for(int i=0;i<t;i++)if(dp[i]>mx)mx=dp[i];
	cout<<mx<<endl;
	return 0;
}
