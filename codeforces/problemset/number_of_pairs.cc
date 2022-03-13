/*
 * Author: Ugur Yagmur 
 * Definition of the problem:
 * https://codeforces.com/problemset/problem/1538/C
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


void solve(vector<int> array, int n, int l, int r){
	ll result = 0;
	sort(array.begin(), array.end());
	for (int i=0; i<array.size(); i++){
		result += upper_bound(array.begin(), array.end(), r - array[i])	- array.begin();
		result -= lower_bound(array.begin(), array.end(), l - array[i])	- array.begin();
		if (l <= 2 * array[i] && 2 * array[i] <= r)
			result--;
	}
	cout << result / 2 << '\n';
}


int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);
	int test_num, n, l, r;
	cin >> test_num;
	for (int i=0; i<test_num; i++){
		cin >> n >> l >> r;
		vector<int> array(n);
		for (int &e: array){
			cin >> e;
		}
		solve(array, n, l, r);
	}
	return 0;
}
