/*
 * Author: Ugur Yagmur 
 * Definition of the problem:
 * http://codeforces.com/contest/1657/problem/B
 *
 */

#include <algorithm>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#define hmap unordered_map
#define hset unordered_set


using namespace std;

typedef double d;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<d> vd;
typedef vector<string> vs;


void solve(ll n, ll B, ll x, ll y){
	vll seq(n+1);
	seq[0] = 0;
	for (int i=1; i < n+1; i++){
		if (seq[i-1] + x > B)
			seq[i] = seq[i-1] - y;
		else
			seq[i] = seq[i-1] + x;
		
	}
	ll sum=0;
	for (auto elem: seq){
		sum += elem;
	}
	cout << sum << '\n';
}


int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);

	int test_num;
	ll n, B, x, y;
	cin >> test_num;
	for (int i=0; i<test_num; i++){
		cin >> n >> B >> x >> y;
		solve(n, B, x, y);
	}
	return 0;
}
