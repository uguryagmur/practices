/*
 * Author: Ugur Yagmur
 * Solution of the problem:
 * https://codeforces.com/contest/1635/problem/C
 *
 */

#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <vector>

void solve(std::vector<long> &array){
	int n = array.size();
	if (array[n - 2] > array[n - 1])
		std::cout << "-1\n";
	else if (array[n - 1] < 0 && is_sorted(array.begin(), array.end()))
		std::cout << "0\n";
	else if(array[n - 1] < 0)
		std::cout << "-1";
	else{
		std::cout << n - 2 << '\n';
		for (int i=1; i <= n - 2; i++){
			std::cout << i << ' ' << array.size() - 1 << ' ' << array.size() << '\n';
		}
	}
}


int main(){
	int test_num, array_size;
	std::cin >> test_num;
	for (int i=0; i<test_num; i++){
		std::cin >> array_size;
		std::vector<long> array(array_size);
		for (int j=0; j<array_size; j++){
			std::cin >> array[j];
		}
		solve(array);
	}
	return 0;
}
