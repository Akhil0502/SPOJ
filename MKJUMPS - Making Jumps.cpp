#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cou=0;
int ma;
void util(vector<vector<bool> > &v,int i,int j,int c){
	if(ma>c)ma=c;
	if(i<0 || i>=v.size() || j<0 || j>=v[i].size()) return;
		
	if(v[i][j]){
	v[i][j] = false;
 
	util(v,i-2,j-1,c-1);	
 
	util(v,i-2,j+1,c-1);
 
	util(v,i-1,j-2,c-1);
	
	util(v,i-1,j+2,c-1);
	
	util(v,i+1,j+2,c-1);
	
	util(v,i+1,j-2,c-1);
 
	util(v,i+2,j-1,c-1);
	
	util(v,i+2,j+1,c-1);
	v[i][j] =true; 
	}	
}
 
int main(){
	int n,a,b;
	int akhil=1;
	while(cin>>n){
		if(n==0) return 0;
		int x,y;
		cou=0;
		vector<vector<bool> > v(n,vector<bool>(10,0));
			int c=0;
			bool bl=false;
			while(n--){
			cin>>a>>b;
			if(!bl && b+a>0){
				bl=true;
				x=a;
				y=c;
			}	
			for(int i=a;i<a+b;i++){
				cou++;
				v[c][i]=1;
			}
			c++;
		}
		ma=cou;
	
			util(v,y,x,cou);
			cout<<"Case "<<akhil<<", "<<ma
			<<((ma==1)?" square ":" squares ");
			cout<<"can not be reached."<<endl;
			akhil++;
	}
	return 0;
} 
