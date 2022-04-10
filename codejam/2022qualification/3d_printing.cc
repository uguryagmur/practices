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


void solve(int test_num, vi p1, vi p2, vi p3){
	cout << "Case #" << test_num + 1 << ": ";
	vi c(3), m(3), y(3), k(3);
	c[0] = p1[0]; c[1] = p2[0]; c[2] = p3[0];
	m[0] = p1[1]; m[1] = p2[1]; m[2] = p3[1];
	y[0] = p1[2]; y[1] = p2[2]; y[2] = p3[2];
	k[0] = p1[3]; k[1] = p2[3]; k[2] = p3[3];
	auto cit = min_element(c.begin(), c.end());
	auto mit = min_element(m.begin(), m.end());
	auto yit = min_element(y.begin(), y.end());
	auto kit = min_element(k.begin(), k.end());

	vi mins;
	mins.push_back(*cit);
	mins.push_back(*mit);
	mins.push_back(*yit);
	mins.push_back(*kit);
	int sum = *cit + *mit + *yit + *kit;
	int diff = sum - pow(10, 6);
	if (diff < 0){
		cout << "IMPOSSIBLE\n";
		return;
	}
	else{
		for (int i=0; (i < mins.size()) && diff > 0; i++){
			if (diff > mins[i]){
				diff -= mins[i];
				mins[i] = 0;
			}
			else{
				mins[i] -= diff;
				diff = 0;
			}
		}
		cout << mins[0] << ' ' << mins[1] << ' ' << mins[2] << ' ' << mins[3] << '\n';
	}
}


int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);

	int test_num;
	cin >> test_num;
	vi p1(4), p2(4), p3(4);
	for (int i=0; i < test_num; i++){
		cin >> p1[0] >> p1[1] >> p1[2] >> p1[3];
		cin >> p2[0] >> p2[1] >> p2[2] >> p2[3];
		cin >> p3[0] >> p3[1] >> p3[2] >> p3[3];
		solve(i, p1, p2, p3);
	}
	return 0;
}
