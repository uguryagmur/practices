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


bool is_palindrome(std::string seq){
	char e, re;
	for (size_t i=0; i<seq.size() / 2; i++){
		e = seq[i];
		re = seq[seq.size() - i - 1];
		if (e != re)
			return false;
	}
	return true;
}


bool is_good(std::string seq){
	bool is_reg=true;
	bool is_pal=true;
	static ll last_check=0;
	static ll st = 0;
	for (size_t i=last_check; i<seq.size(); i++){

		if (is_reg && seq[i] == '(')
			st++;
		else if (is_reg && st > 0)
			st--;
		else
			is_reg = false;
		if (!is_reg && !is_pal)
			return false;
	}
	is_reg = is_reg && st == 0;
	if (is_reg)
		is_pal = is_palindrome(seq);
	if (is_reg || is_pal){
		last_check = 0;
		st = 0;
	}
	return is_reg || is_pal;
}


void solve(std::string seq){
	ll num_ops = 0, i;	
	ll base = 0;
	for(i=1; i< (ll) seq.size(); i++){
		if (is_good(seq.substr(base, i+1-base))){
			num_ops++;
			base = i+1;
			i++;
		}
	}
	cout << num_ops << ' ' << seq.size() - base << '\n';
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
