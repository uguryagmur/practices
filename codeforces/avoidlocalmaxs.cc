/*
 * Author: Ugur Yagmur
 * Solution of the problem:
 * https://codeforces.com/contest/1635/problem/B
 *
 */

#include <iostream>
#include <vector>

void solve(std::vector<long> array){
	int num_changes = 0;
	for (int i=1; i<array.size() - 1; i++){
		if (array[i-1] < array[i] && array[i+1] < array[i]){
			num_changes += 1;
			if (i+2 < array.size() && array[i+2] > array[i])
				array[i+1] = array[i+2];
			else
				array[i+1] = array[i];
		}
	}
	std::cout << num_changes << "\n";
	for (int i=0; i<array.size(); i++){
		std::cout << array[i] << ' ';
	}
	std::cout << "\n";
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
