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


void solve(int test_num, vi& dices){
	cout << "Case #" << test_num + 1 << ": ";
	sort(dices.begin(), dices.end());
	int max_straight = 0, score = 1;
	for (int i=0; i < dices.size(); i++){
		if (score <= dices[i]){
			score += 1;
			max_straight += 1;
		}
		else
			continue;
	}
	cout << max_straight << '\n';
}


int main(){
	int test_num, N, elem;
	cin >> test_num;
	for (int i=0; i < test_num; i++){
		cin >> N;
		vi S(N);
		for (int j=0; j < N; j++){
			cin >> S[j];
		}
		solve(i, S);
	}
	return 0;
}
