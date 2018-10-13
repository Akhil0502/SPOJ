#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void util(vector<vector<char> > &v,set<pair<int,int> > &path, set<set<pair<int,int> > > &ret,vector<vector<bool> > &visit,int i,int j,int n){
	if(i<0 || j<0 || i>=v.size() || j>=v[i].size() )return;
	if(n == 0){
		ret.insert(path);
		return;
	}
	if(!visit[i][j] && v[i][j] != '.'){
		visit[i][j] = true;
		path.insert(make_pair(i,j));
		
		util(v,path,ret,visit,i+1,j,n-1);
		util(v,path,ret,visit,i,j+1,n-1);
		util(v,path,ret,visit,i-1,j,n-1);
		util(v,path,ret,visit,i,j-1,n-1);
		
		path.erase(path.find(make_pair(i,j)));
		visit[i][j] =false;
	}
}
int main() {
	int n,t;
	char x;
	cin>>n;
	while(n--){
		cin>>t;
		vector<vector<char> > v(t,vector<char>(t));
		vector<vector<bool> > visit(t,vector<bool>(t,0));
		for(int i=0;i<t;i++){
			for(int j=0;j<t;j++){
				cin>>x;
				v[i][j] =x;
			}
		}
		set<pair<int,int> > path;
		set<set<pair<int,int> > > ret;
		for(int i=0;i<t;i++)
		for(int j=0;j<t;j++)
		util(v,path,ret,visit,i,j,8);
		cout<<ret.size()<<endl;
	}
	return 0;
}
