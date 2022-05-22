/*
 * Author: Ugur Yagmur
 *
 */

#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define print_cont(arr)                                                        \
  for (auto e : arr)                                                           \
    cout << e << " ";                                                          \
  cout << endl;
#define print_map(arr)                                                         \
  for (auto e : arr)                                                           \
    cout << e.first << " " << e.second << " ";                                 \
  cout << endl;

using namespace std;

typedef double d;
typedef string s;
typedef long long ll;
typedef long double ld;
typedef set<int> si;
typedef set<ll> sll;
typedef set<ld> sld;
typedef set<s> ss;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<s> vs;

#ifndef ONLINE_JUDGE
FILE *iFile = freopen("input.txt", "r", stdin);
FILE *oFile = freopen("output.txt", "w", stdout);
#endif

void solve() {}

int main() {
  // no sync with stdio
  ios_base::sync_with_stdio(false);
  // no thread safe since there is only one thread
  cin.tie(nullptr);

  int test_num;
  cin >> test_num;
  for (int i = 1; i < test_num + 1; i++) {
    ll size;
    cin >> size;
    vll seq(size);
    for (int j = 0; j < size; j++) {
      cin >> seq[j];
    }
    solve();
  }
  return 0;
}
