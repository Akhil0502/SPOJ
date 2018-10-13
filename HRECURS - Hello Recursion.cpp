#include <bits/stdc++.h>
using namespace std;
int Sum(vector<int> &data,int n){
	if( n == data.size()) return 0;
	return data[n]+Sum(data,n+1);
}
int main() {
	int t,p;
	cin>>t;
	int n;
	for(int i=0;i<t;i++){
		cin>>n;
		vector<int> data(n);
		for(int j=0;j<n;j++){
			cin>>data[j];
		}
		cout<<"Case "<<i+1<<": "<<Sum(data,0)<<endl;;
	}
	return 0;
} 
