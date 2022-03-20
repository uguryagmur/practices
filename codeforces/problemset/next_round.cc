/*
 * Author: Ugur Yagmur 
 * Definition of the problem:
 * https://codeforces.com/problemset/problem/158/A
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


void solve(vll array, ll k){
	ll result = 0;
	for (auto elem: array){
		if (elem > 0 && elem >= array[k-1])
			result++;
	}
	cout << result << "\n";
}


int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);

	ll array_size, k;
	cin >> array_size >> k;
	vll array(array_size);
	for (int i = 0; i<array_size; i++){
		cin >> array[i];
	}
	solve(array, k);
	return 0;
}
