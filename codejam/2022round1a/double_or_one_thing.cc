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


void solve(int test_num, string seq){
	int memory = int(seq[seq.size() - 1]);
	vector<bool> highlight(seq.size());
	for (int i=seq.size() - 2; i >= 0; i--){
		if (int(seq[i]) < memory)
			highlight[i] = true;
		if (seq[i] != seq[i-1])
			memory = seq[i];
	}

	cout << "Case #" << test_num + 1 << ": ";
	for (int i=0; i<seq.size(); i++){
		cout << seq[i];
		if (highlight[i])
			cout << seq[i];
	}
	cout << '\n';
}


int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);

	int test_num;
	cin >> test_num;
	for (int i=0; i<test_num; i++){
		string seq;
		cin >> seq;
		solve(i, seq);
	}
	return 0;
}
