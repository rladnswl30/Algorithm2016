/*
트리
https://www.acmicpc.net/problem/1068

테스트 케이스

=========
5
-1 0 0 1 1
2
답 : 2
=========
7
-1 0 0 1 -1 4 4
3
답 : 4
=========
5
-1 0 1 2 2
2
답 : 1
=========
5
2 4 4 2 -1
3
답 : 2
=========

*/

#include <iostream>
#include <vector>

using namespace std;

typedef struct Tree {
	int node;
	vector<Tree *> leafs;
	Tree(int _node) : node(_node) {}
	Tree() { node = -1; }
	~Tree() {
		vector<Tree *>::iterator it = leafs.begin();
		while (it != leafs.end())
			it = leafs.erase(it);
	}
}Tree;

vector<Tree *>* search(vector<Tree *>* tree, int *idx, int item) {
	vector<Tree *>* res = tree;
	if (tree->empty()) {
		*idx = 0;
		return tree;
	}
	else {
		for (int i = 0; i < tree->size(); ++i) {
			if ((*tree)[i]->node == item) {
				*idx = i;
				return tree;
			}
			else
				res = search(&(*tree)[i]->leafs, idx, item);
		}
		return res;
	}
}

void insert(vector<Tree*>* tree, int parent, int child) {

	int i, j;
	vector<Tree*>* cTree;
	vector<Tree*>* pTree;

	if (parent == -1) {
		if ((search(tree, &j, child))->empty())
			tree->push_back(new Tree(child));
		return;
	}

	if ((pTree = search(tree, &i, parent))->empty()) {
		tree->push_back(new Tree(parent));
		pTree = tree;
		i = tree->size() - 1;
	}

	if ((cTree = search(tree, &j, child))->empty())
		(*pTree)[i]->leafs.push_back(new Tree(child));
	else {
		(*pTree)[i]->leafs.push_back((*cTree)[j]);
		cTree->erase(cTree->begin() + j);
	}
}

void delNode(vector<Tree*>& tree, int node, int *cnt) {

	vector<Tree *>::iterator it = tree.begin();
	while (it != tree.end()) {
		if ((*it)->node == node)
			it = tree.erase(it);
		else {
			delNode((*it)->leafs, node, cnt);
			if ((*it)->leafs.empty())
				++(*cnt);
			++it;
		}
	}
}

int main(void) {
	vector<Tree * > tree;
	int leng = 0, node = 0, cnt = 0;
	bool first = true;

	cin >> leng;
	int *parent = new int[leng];
	for (int i = 0; i < leng; ++i)
		cin >> parent[i];
	cin >> node;

	for (int i = 0; i < leng; ++i) {
		if (parent[i] == -1) {
			if (first) {
				first = false;
				insert(&tree, parent[i], i);
			}
			else
				break;
		}
		else
			insert(&tree, parent[i], i);
	}
	delNode(tree, node, &cnt);

	cout << cnt;

	return 0;
}