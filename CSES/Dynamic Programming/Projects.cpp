#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

struct Project{
	int start;
	int end;
	int money;
	Project(){}
	Project(int a,int b,int c): start(a),end(b),money(c) {}
};
struct compare {
	bool operator()(Project lhs, Project rhs)const{
		return lhs.end<rhs.end;
	}
};


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cin.tie(0);

	int n;cin>>n;
	multiset<Project,compare> projects;
	for(int i=0;i<n;i++){
		int a,b,p;cin>>a>>b>>p;
		projects.emplace(Project(a,b,p));
	}
	map<int, ll> DP;DP[0] = 0;int prev=0;
	for(auto ptr =projects.begin();ptr!=projects.end();ptr++){
		auto last = DP.lower_bound(ptr->start); if(last!=DP.begin()){last--;}
		DP[ptr->end]=max({DP[ptr->end],last->second+ptr->money,DP[prev]});
		prev=ptr->end;
	}

	cout<<(--DP.end())->second<<'\n';
	cin.ignore(1);
	return 0;
}

