/*
 * Author: Ugur Yagmur
 * Solution of the problem:
 * https://codeforces.com/contest/1635/problem/C
 *
 */

#include <iostream>
#include <vector>
#include <cmath>

void solve(std::vector<long> &array){
	int num_changes = 0;
	std::vector<std::vector<int>> changes;
	for (int i=array.size() - 2; i>=0; i--){
		if (i == array.size() - 2){
			if (array[i] > array[i+1]){
				std::cout << -1 << "\n";
				return;
			}
		}
		else if (i == array.size() - 3){
			if (array[i] > array[i+1] && array[i+1] - array[i+2] <= array[i+1]){
				num_changes += 1;
				changes.push_back(std::vector<int> {i, i+1, i+2});
				array[i] = array[i+1] - array[i+2];
				if (std::abs(array[i]) > std::pow(10, 8)){
					std::cout << -1 << "\n";
					return;
				}
			}
			else if (array[i] > array[i+1]){
				std::cout << -1 << "\n";
				return;
			}
		}
		else{
			if (array[i] > array[i+1] && array[i+1] - array[array.size() - 1] <= array[i+1]){
				num_changes += 1;
				changes.push_back(std::vector<int> {i, i+1, array.size() - 1});
				array[i] = array[i+1] - array[array.size() - 1];
				if (std::abs(array[i]) > std::pow(10, 8)){
					std::cout << -1 << "\n";
					return;
				}
			}
			else if (array[i] > array[i+1]){
				std::cout << -1 << "\n";
				return;
			}
		}
	}
	std::cout << num_changes << "\n";
	for (int i=changes.size() - 1; i>=0; i--){
		std::cout << changes[i][0] + 1 << ' ' << changes[i][1] + 1<< ' ' << changes[i][2] + 1 << "\n";
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
