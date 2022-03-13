/*
 * Author: Ugur Yagmur 
 * Definition of the problem:
 * https://codeforces.com/problemset/problem/1593/B 
 *
 */

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>

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


void solve(string number){
	set<string> possible_solutions{"00", "25", "50", "75"};
	int pos, loc_result, result = 10000;	
	for (auto candidate: possible_solutions){
		pos = number.size() - 1;
		loc_result = 0;
		while(pos >= 0 && number[pos] != candidate[1]){
			pos--;
			loc_result++;
		}
		if (pos < 0)
			continue;
		pos--;
		while(pos >= 0 && number[pos] != candidate[0]){
			pos--;
			loc_result++;
		}
		result = pos >= 0 ? min(loc_result, result) : result;
	}
	cout << result << '\n';
}

int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);

	int test_num;
	string number;
	cin >> test_num;
	for (int i=0; i<test_num; i++){
		cin >> number;	
		solve(number);
	}
	return 0;
}
