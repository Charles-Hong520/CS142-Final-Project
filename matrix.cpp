#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;
#define ll long long
const ll mod = 1000000007;
const ll h1 = 128ll;
const ll h2 = 257ll;
ll r1,r2;
vector<vector<ll> > mat,pat;
ll r,c,n,m;
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



vector<vector<ll> > hashRow() {
	//first dig: a = 96*128^s-1, b = 97*128^s-1 ...
	//second last dig: a = 96*128, b = 97*128 ...
	//last dig: a = 96, b = 97 ...
	ll val = 0;

	ll colRange = c-m+1;
	vector<vector<ll> > rowMat(r, vector<ll> (colRange));
	for(int i = 0; i < r; i++) {
		//for each row
		//calc first hash
		val = 0;
		for(int j = 0; j < colRange; j++) {
			val += (val*h1 + mat[i][j])%mod;
		}
		rowMat[i][0] = val;
		val = 0;
		for(int j = 0; j < colRange; j++) {
			val -= r*mat[i][j];
			//"move to the left" (multiply)
			val *= h1;
			//add last digit
			if(j<colRange-1)
			val += mat[i][m+j];
			
			//result may be negative
			rowMat[i][j] = (val%mod + mod) % mod;
		}
	}

	val = 0;
	ll rowRange = r-n+1;
	vector<vector<ll> > vMat(rowRange, vector<ll> (colRange));
	for(int j = 0; j < colRange; j++) {
		//for each col
		//calc first hash
		val = 0;
		for(int i = 0; i < rowRange; i++) {
			val += (val*h2 + rowMat[i][j])%mod;
		}
		vMat[0][j] = val;
		val = 0;
		for(int i = 0; i < rowRange; i++) {
			val -= r*rowMat[i][j];
			//"move to the left" (multiply)
			val *= h2;
			//add last digit
			if(i<rowRange-1)
			val += rowMat[i+n][j];
			
			//result may be negative
			vMat[i][j] = (val%mod + mod) % mod;
		}
	}
	return val;
}

int main() {
	cin>>r>>c;
	mat.resize(r,vector<ll>(c));
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin>>mat[i][j];
		}
	}

	cin>>n>>m;
	pat.resize(n,vector<ll>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin>>mat[i][j];
		}
	}

	r1 = powMod(h1, n-1);
	r2 = powMod(h2, m-1);
	vector<int> ans;

	int searchRange = parent.size()-c_size+1;
	for(int i = 0; i < searchRange; i++) {
		cout<<i<<": "<<p<<endl;
		//roll
		//remove first dig
		p -= r*parent[i];
		//"move to the left" (multiply)
		p *= h;
		//add last digit
		p += parent[c_size+i];
		
		//result may be negative
		p = (p%mod + mod) % mod;

	}
	cout<<"answers found at: ";
	for(int e : ans) cout<<e<<' ';
	return 0;
}
