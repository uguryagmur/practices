/*
 * Author: Ugur Yagmur
 * Solution of the problem:
 * https://codeforces.com/contest/1635/problem/A
 *
 */

#include <iostream>
#include <vector>

void solve(std::vector<long long> array){
	long long result = 0;
	for (auto elem: array){
		result |= elem;
	}
	std::cout << result << "\n";
}

int main(){
	int test_num, array_size;
	std::cin >> test_num;
	for (int i=0; i<test_num; i++){
		std::cin >> array_size;
		std::vector<long long> array(array_size);
		for (int j=0; j<array_size; j++){
			std::cin >> array[j];
		}
		solve(array);
	}
	return 0;
}
