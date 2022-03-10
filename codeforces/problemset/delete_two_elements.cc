/*
 * Author: Ugur Yagmur 
 * Solution of the problem:
 * https://codeforces.com/problemset/problem/1598/C
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
void print_array(const T array){
	for (auto elem: array){
		cout << elem << ' ';
	}
	cout << '\n';
}


template <class T>
void print_map(const T map){
	for (auto elem: map){
		cout << elem.first << ": " << elem.second << "  ";
	}
	cout << '\n';
}

void solve(vi array){
	map<ll, ll> bucket;
	ll reverse;
	ll mean = 0;
	ll result = 0;
	for (auto elem: array){
		mean += elem;	
		if (bucket.find(elem) == bucket.end())
			bucket.insert(std::pair<ll, ll> {elem, 1});
		else
			bucket[elem] += 1;
	}


	if ((mean * 2) % array.size() != 0){
		cout << 0 << "\n";
		return;
	}

	mean *= 2;
	mean /= array.size();

	for (auto elem: bucket){
		reverse = mean - elem.first;
		if (bucket.find(reverse) != bucket.end()){
			if (reverse == elem.first)
				result += elem.second * (elem.second - 1);
			else
				result += elem.second * bucket[reverse];
		}
	}
	cout << (ll) round(((double)result) / 2) << "\n";
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_num, array_size;
	cin >> test_num;
	for (int i=0; i < test_num; i++){
		cin >> array_size;
		vi array(array_size);
		for (int j=0; j < array_size; j++){
			cin >> array[j];
		}
		solve(array);
	}
	return 0;
}
