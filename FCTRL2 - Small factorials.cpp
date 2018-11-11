#include <bits/stdc++.h>
#include<vector>
using namespace std;
string _util(string A,string B){
	 if (A=="0" || B=="0")
        return "0";
        
    int aL = A.length(), bL = B.length();
    vector<int> result(aL+bL, 0);
    string res = "";
    
    for (int i=aL-1; i>=0; --i)
    {
        for (int j=bL-1; j>=0; --j)
        {
            result[i+j+1] += (A[i] - '0')*(B[j] - '0');
        }
    }
    
    for (int k=aL+bL-1; k>0; --k)
    {
        if (result[k] >= 10)
        {
            result[k-1] += result[k]/10;
            result[k] %= 10;
        }
    }
    
    int cnt = 0;
    for (int l=0; l<result.size(); ++l)
    {
        if (result[l]==0 && l==cnt) 
            ++cnt;
        else
            res += result[l] + '0';
    }
    return res;
}
void util(int n){
	string ret="1";
	while(n>0){
		stringstream ss;
		ss<<n;
		ret=_util(ss.str(),ret);
		n--;
	}
	cout<<ret<<endl;
}
int main() {
	
	int n,t;
	cin>>n;
	while(n--){
		cin>>t;
		util(t);
	}

	return 0;
}
