/*
 * Author: Ugur Yagmur 
 * Definition of the problem:
 * https://codingcompetitions.withgoogle.com/codejam/round/00000000000000cb/0000000000007966#problem 
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


template <class T>
void print_vector(vector<T> inp){
	for (auto e: inp){
		cout << e << ' ';
	}
	cout << '\n';
}

void swap_seq(string& seq, ll i){
	auto memory = seq[i];
	seq[i] = seq[i-1];
	seq[i-1] = memory;
}


void compute(ll ss, string seq, ll num_hacks = -1){
	bool is_charge = false, terminate = true;
	for (auto e: seq){
		if (e == 'C')
			is_charge = true;
		if (is_charge && e == 'S'){
			terminate = false;
			break;
		}
	}

	if (terminate){
		if (num_hacks == -1){
			cout << "IMPOSSIBLE\n";
		}
		else
			cout << num_hacks << '\n';
		return;
	}

	// if it's possible
	vll stv(seq.size());
	ll strength = 1, total_damage = 0;
	for (int i=0; i < seq.size(); i++){
		if (seq[i] == 'C'){
			strength *= 2;
			stv[i] = -1;
		}
		else{
			stv[i] = strength;
			total_damage += strength;
		}
	}

	num_hacks = 0;
	for (auto i = stv.size() - 1; i >= 0; i--){
		if (ss >= total_damage)
			break;
		if (stv[i] == -1)
			continue;
		if (stv[i-1] == -1){
			num_hacks += 1;
			total_damage -= stv[i]/2;
			stv[i-1] = stv[i]/2;
			stv[i] = -1;
			swap_seq(seq, i);
		}
	}

	cout << "LOG -> " << num_hacks << '\n';
	if (ss >= total_damage)
		cout << num_hacks << '\n';
	else
		compute(ss, seq, num_hacks);
}


void solve(int test_num, ll ss, string seq){
	cout << "Case #" << test_num << ": ";
	ll num_damage = 0;

	// check possibility
	for (auto e: seq){
		if (e == 'S'){
			num_damage += 1;
		}
	}

	// if it's impossible
	if (num_damage > ss){
		cout << "IMPOSSIBLE\n";
		return;
	}

	compute(ss, seq);
}


int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);

	int test_num;
	cin >> test_num;
	string seq;
	ll ss;
	for (int i=0; i<test_num; i++){
		cin >> ss >> seq;
		solve(i, ss, seq);
	}
	return 0;
}
