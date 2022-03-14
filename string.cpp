#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "get_time.h"
using namespace std;
#define ll long long
#define NUM_ROUNDS 1
const ll mod = 1000000007;
const ll h = 128ll;
ll n,m;
vector<ll> parent,child;
ll powMod(ll base, int pow) {
	ll ans = 1;
	while(pow) {
		if(pow&1) {
			ans*=base;
			ans%=mod;
		}
		base *= base;
		base %= mod;
		pow>>=1;
	}
	return ans%mod;
}


ll hashVal(const vector<ll> &s,int size) {
	//first dig: a = 96*128^s-1, b = 97*128^s-1 ...
	//second last dig: a = 96*128, b = 97*128 ...
	//last dig: a = 96, b = 97 ...
	ll val = 0;
	for(int i = 0; i < size; i++) {
		//first letter is 128^s-1
		//last letter is 128^0
		val = (val*h + s[i])%mod;
	}
	return val;
}



vector<ll> karp() {
	ll c = hashVal(child,m);
	ll p = hashVal(parent,m);
	ll r = powMod(h,m-1);
	vector<ll> ans;

	int searchRange = n-m+1;
	bool match = true;
	for(int i = 0; i < searchRange; i++) {
		if(c==p) {
			for(int j = 0; j < m; j++) {
				if(parent[j+i]!=child[j]) {
					match=false;
					break;
				}
			}
			if(match) ans.push_back(i);
			else match=true;
		}
		//roll
		//remove first dig
		p = ((p-(r*parent[i])) * h);
		//"move to the left" (multiply)
		//add last digit
		if(i<searchRange-1)
		p += parent[m+i];
		
		//result may be negative
		p = (p%mod + mod) % mod;
	}
	return ans;
	// cout<<"answers found at: ";
	// for(int i=0;i<ans.size();i++) {
	// 	cout<<ans[i]<<": ";
	// 	for(int j=0;j<m;j++) {
	// 		cout<<parent[j+ans[i]]<<' ';
	// 	}
	// 	cout<<endl;
	// }
}

vector<ll> karp2() {
	ll c = hashVal(child,m);
	ll p = hashVal(parent,m);
	ll r = powMod(h,m-1);
	vector<ll> ans;

	int searchRange = n-m+1;
	bool match = true;
	for(int i = 0; i < searchRange; i++) {
		if(c==p) {
			for(int j = 0; j < m; j++) {
				if(parent[j+i]!=child[j]) {
					match=false;
					break;
				}
			}
			if(match) ans.push_back(i);
			else match=true;
		}
		//roll
		//remove first dig
		p -= (r*parent[i]);
		//"move to the left" (multiply)
		//add last digit
		p *= h;

		if(i<searchRange-1)
		p += parent[m+i];
		
		//result may be negative
		p = (p%mod + mod) % mod;
		
	}
	return ans;
	// cout<<"answers found at: ";
	// for(int i=0;i<ans.size();i++) {
	// 	cout<<ans[i]<<": ";
	// 	for(int j=0;j<m;j++) {
	// 		cout<<parent[j+ans[i]]<<' ';
	// 	}
	// 	cout<<endl;
	// }
}

vector<ll> naive() {
	vector<ll> ans;
	bool match = true;
	int searchRange = n-m+1;
	for(int i = 0; i < searchRange; i++) {
		for(int j = 0; j < m; j++) {
			if(parent[j+i]!=child[j]) {
				match=false;
				break;
			}
		}
		if(match) ans.push_back(i);
		else match=true;
	}
	return ans;
}

void test(ifstream& fin) {
	int a;
	fin>>n;
	parent.resize(n);
	child.resize(0);
	for(int i = 0; i < n; i++) fin>>parent[i];
	while(fin>>a) child.push_back(a);
	m=child.size();

	cout<<"String size n: "<<n<<endl;
	cout<<"Pattern size m: "<<m<<endl;
	vector<ll> ans1,ans2,ans3;
	double tot_time = 0.0;
	for (int round = 0; round < NUM_ROUNDS; round++) {
		timer t; t.start();
		ans1 = karp();
		t.stop();
		double tm = t.get_total();
		cout << "Karp , time: " << tm << endl;
		tot_time += tm;
	}

	for (int round = 0; round < NUM_ROUNDS; round++) {
		timer t; t.start();
		ans2 = naive();
		t.stop();
		double tm = t.get_total();
		cout << "Naive, time: " << tm << endl;
		tot_time += tm;
	}
	for (int round = 0; round < NUM_ROUNDS; round++) {
		timer t; t.start();
		ans3 = karp2();
		t.stop();
		double tm = t.get_total();
		cout << "Karp2, time: " << tm << endl;
		tot_time += tm;
	}
	// cout << "Average time: " << tot_time/NUM_ROUNDS << endl;
	
	for(int i = 0; i < ans1.size();i++) {
		if(ans1[i]!=ans2[i] && ans2[i]!=ans3[i]) {
			cout<<"Not equal"<<endl;
			return;
		}
	}
	cout<<"They are equal"<<endl;
	cout<<"Number of matches: "<<ans1.size()<<endl;
}

int main() {
	for(int i = 1; i<11; i++) {
		string a = "input"+to_string(i)+".txt";
		cout<<a<<endl;
		ifstream fin(a);
		test(fin);
		cout<<endl;
	}
}
