/*
 * Author: Ugur Yagmur 
 * Definition of the problem:
 * http://codeforces.com/contest/1657/problem/A
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


void solve(ll x, ll y){
	ll result = pow(x, 2) + pow(y, 2);
	ll root = sqrt(result);
	if (x == 0 && y == 0)
		cout << 0;
	else if (root * root == result)
		cout << 1;
	else
		cout << 2;
	cout << "\n";
}


int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);

	int test_num;
	ll x, y;
	cin >> test_num;
	for (int i=0; i<test_num; i++){
		cin >> x >> y;
		solve(x, y);
	}
	return 0;
}
