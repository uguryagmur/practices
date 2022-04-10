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
typedef vector<ull> vull;
typedef vector<d> vd;
typedef vector<string> vs;


struct Node{
	public:
		ull fun_score;
		Node* parent;
		vector<Node*> childs;

		Node(): fun_score(0){}
		Node(ull value): fun_score(value){}

		void add_parent(Node* iParent){
			this->parent = iParent;
		}

		void add_child(Node* iChild){
			this->childs.push_back(iChild);
		}

		ull find_node_score(){
			if (childs.empty())
				return this->fun_score;
			else{
				vull child_scores(childs.size());
				for (int i=0; i < childs.size(); i++){
					child_scores[i] = childs[i]->find_node_score();
				}
				auto min_score = min_element(child_scores.begin(), child_scores.end());
				ull sum_scores = 0;
				for (auto e: child_scores){
					sum_scores += e;
				}
				if (*min_score < this->fun_score)
					sum_scores += this->fun_score - *min_score;
				return sum_scores;
			}
		}
};


void solve(int test_num, vull fun, vi path){
	std::cout << "Case #" << test_num + 1 << ": ";
	vector<Node*> nodes;
	nodes.push_back(new Node(0));
	for (int i=0; i < fun.size(); i++){
		Node* node = new Node(fun[i]);
		nodes.push_back(node);
	}
	for (int i=1; i < nodes.size(); i++){
		nodes[i]->add_parent(nodes[path[i-1]]);
		nodes[path[i-1]]->add_child(nodes[i]);
	}
	ull num_leaf_nodes = 0;
	for (auto node: nodes){
		if (node->childs.empty())
			num_leaf_nodes += 1;
	}
	vull max_nums(num_leaf_nodes);
	for (auto node: nodes){
		for (int i=0; i < num_leaf_nodes; i++){
			if (max_nums[i] < node->fun_score){
				max_nums[i] = node->fun_score;
				break;
			}
		}
	}
	ull max_score = 0;
	for (auto p: max_nums){
		max_score += p;
	}
	cout << max_score << '\n';
}


int main(){
	int test_num, num_nodes;
	cin >> test_num;
	for (int i=0; i < test_num; i++){
		cin >> num_nodes;
		vull fun(num_nodes); vi path(num_nodes);
		for (int j=0; j < num_nodes; j++){
			cin >> fun[j];
		}
		for (int j=0; j < num_nodes; j++){
			cin >> path[j];
		}
		solve(i, fun, path);
	}
	return 0;
}
