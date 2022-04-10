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
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<d> vd;
typedef vector<string> vs;


void solve(ull num){

	if (32768 - num <= 15){
		cout << 32768 - num;
		return;
	}

	int num_ops = 0;

	for (int a=14; a > 0; a-=1){
		if ((num + a) % ((int) pow(2, a + 1)) == 0){
			num_ops += a;
			num += a;
			break;
		}
	}

	while (num % 32768 != 0){
		num *= 2;
		num_ops += 1;
	}
	cout << num_ops;
}


int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);

	int test_num;
	ull num;
	cin >> test_num;
	for (int i=0; i < test_num; i++){
		cin >> num;
		solve(num);
		if (i < test_num - 1)
			cout << ' ';
	}
	return 0;
}
