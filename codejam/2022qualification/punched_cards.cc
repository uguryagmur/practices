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


void solve(int test_num, int row, int column){
	cout << "Case #" << test_num + 1 << ":\n";
	row = 2 * row + 1;
	column = 2 * column + 1;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			// starting dots
			if ((i == 0 || i == 1) && j < 2){
				cout << "..";
				j = 2;
			}

			// rest of the table
			if (i % 2 == 0 && j % 2 == 0)
				cout << "+";
			if (i % 2 == 0 && j % 2 == 1)
				cout << "-";
			if (i % 2 == 1 && j % 2 == 0)
				cout << "|";
			if (i % 2 == 1 && j % 2 == 1)
				cout << ".";
		}
		cout << '\n';
	}
}


int main(){
	// no sync with stdio
	ios_base::sync_with_stdio(false);
	// no thread safe since there is only one thread
	cin.tie(nullptr);

	int test_num;
	int row, column;
	cin >> test_num;
	for (int i=0; i < test_num; i++){
		cin >> row >> column;
		solve(i, row, column);
	}
	return 0;
}
