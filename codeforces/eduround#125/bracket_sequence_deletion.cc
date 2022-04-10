/*
 * Author: Ugur Yagmur 
 * Definition of the problem:
 * http://codeforces.com/contest/1657/problem/C
 *
 */

#include <algorithm>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <stack>
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


void solve(std::string seq){
	ll num_ops = 0, i;	
	ll len = seq.size();
	for(i=1; i< len; i++){
		if (seq[i] == '('){
			i++;
		}
		else{
			ll r = i;
			while (r < len && seq[r] != ')'){
				r++;
			}
			if (r == len)
				break;
			i = r;
		}
		num_ops++;
	}
	cout << num_ops << ' ' << (ll) seq.size() - i << '\n';
}


int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);

	int test_num;
	std::string seq;
	int seq_size;
	cin >> test_num;
	for (int i = 0; i < test_num; i++){
		cin >> seq_size;
		cin >> seq;
		solve(seq);
	}
	return 0;
}
