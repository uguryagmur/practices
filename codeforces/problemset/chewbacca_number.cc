/*
 * Author: Ugur Yagmur 
 * Definition of the problem:
 * https://codeforces.com/problemset/problem/514/A 
 *
 * NOTE: Very good question for edge cases :D
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


void solve(){
	std::string integer;
	cin >> integer;
	int digit;
	for (int i=0; i<(int) integer.size(); i++){
		char ch(integer[i]);
		digit = std::atoi(&ch);
		if (i == 0 && digit == 9)
			continue;
		if (digit > 4){
			digit = 9 - digit;
			integer[i] = *to_string(digit).data();
			if (std::atoll(&integer[0]) <= 0)
				integer[i] = *to_string(9 - digit).data();
		}
	}
	cout << integer << "\n";
}


int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);

	solve();
	return 0;
}
