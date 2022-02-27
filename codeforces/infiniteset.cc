/*
 * Author: Ugur Yagmur
 * Solution of the problem:
 * https://codeforces.com/contest/1635/problem/D
 *
 * It's a numeric solution and it's giving wrong answer
 * But I believe that my solution is correct since they are counting
 */

#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <vector>

void solve(long p, std::vector<long> &array){
	std::vector<long> searched;
	std::sort(array.begin(), array.end());
	long long num_elems = 0;
	bool pass;
	for (auto x: array){
		pass = false;
		for (auto y: searched){
			bool is_der_of_1st_func = (int)std::ceil(std::log2((long double) (x+1) / (y+1)) * 10) % 10 == 0;
			bool is_der_of_2nd_func = (int)std::ceil(std::log2((long double) x / y) * 5) % 10 == 0;
			// std::cout << "x: " << x << " y: " << y << '\n';
			// std::cout << " 1st " << is_der_of_1st_func << '\n';
			// std::cout << " 2nd " << is_der_of_2nd_func << '\n';
			pass = is_der_of_1st_func || is_der_of_2nd_func;
		}
		// std::cout << " for x:" << x << " -> pass " << pass << '\n';
		if (!pass){
			num_elems += std::ceil((long double) p / 2 - 0.5 * std::log2(x));
			searched.push_back(x);
		}
			num_elems += std::ceil((long double) p + 0.1 - std::log2(x + 1));
			// std::cout << " after x:" << x << " -> num_elems: " << num_elems << '\n';
	}
	std::cout << num_elems << '\n';
}


int main(){
	long long n, p;
	std::cin >> n;
	std::cin >> p;
	std::vector<long> array(n);
	for (int i=0; i<n; i++){
		std::cin >> array[i];
	}
	solve(p, array);
	return 0;
}
