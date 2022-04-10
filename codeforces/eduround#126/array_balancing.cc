/*
 * Author: Ugur Yagmur 
 * Definition of the problem:
 * 
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


void solve(vll a, vll b){
	ll result = 0, poss1, poss2;
	for (int i=1; i < a.size(); i++){
		poss1 = abs(a[i-1] - a[i]) + abs(b[i-1] - b[i]);
		poss2 = abs(a[i-1] - b[i]) + abs(b[i-1] - a[i]);
		result += min(poss1, poss2);
	}
	cout << result << '\n';
}


int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);

	int test_num, arr_size;
	cin >> test_num;
	for (int i=1; i <= test_num; i++){
		cin >> arr_size;
		vll a(arr_size), b(arr_size);
		for (int j=0; j < arr_size; j++){
			cin >> a[j];
		}
		for (int j=0; j < arr_size; j++){
			cin >> b[j];
		}
		solve(a, b);
	}
	return 0;
}
