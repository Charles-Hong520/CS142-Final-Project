#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;
#define ll long long
const ll mod = 1000000007;
const ll h = 128ll;

int main() {
	// ofstream out("output.txt");
	// int n = 1e4; out<<n<<endl;
	// for(int i = 0; i < n; i++) {
	// 	out<< ((i*i+i)%151+1)<<' ';
	// }

	// ofstream out("output.txt");
	// int n = 1e5; out<<n<<endl;
	// for(ll i = 0; i < n; i++) {
	// 	ll a = 1+(i*i+53*i)%29;
	// 	a*=i;
	// 	a%=17;
	// 	a++;
	// 	out<<a<<' ';
	// }

	// ofstream out("input7.txt");
	// int n = 1e6; out<<n<<endl;
	// for(ll i = 0; i < n; i++) {
	// 	ll a = 1+(i*i+53*i)%29;
	// 	a%=893;
	// 	a++;
	// 	out<<a<<' ';
	// }
	// out<<endl;
	// for(ll i = 1000; i < 400000; i++) {
	// 	ll a = 1+(i*i+53*i)%29;
	// 	a%=893;
	// 	a++;
	// 	out<<a<<' ';
	// }

	// ofstream out("input9.txt");
	// int n = 1e6; out<<n<<endl;
	// for(ll i = 0; i < n; i++) {
	// 	ll a = 1+(i*i+53*i)%4;
	// 	a++;
	// 	out<<a<<' ';
	// }
	// out<<endl;
	// for(ll i = 100; i < 200; i++) {
	// 	ll a = 1+(i*i+53*i)%4;
	// 	a++;
	// 	out<<a<<' ';
	// }

	ofstream out("input10.txt");
	int n = 1e6; out<<n<<endl;
	int i = 0;
	for(int j = 0;j < n/10000; j++) {
		for(i = 0; i < 10000-1; i++) {
			out<<2<<' ';
		} out<<3<<' ';
	}
	out<<endl;
	for(i = 0; i<10000; i++) {
		out<<2<<' ';
	}
	return 0;
}
