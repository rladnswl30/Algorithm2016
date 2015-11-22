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
*/

#include <stdio.h>
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
			leafs.erase(it);
	}
};


void search(vector<Tree*>& tree, int parent, int item) {
	Tree *leaf;

	for (int i = 0; i < tree.size(); ++i) {
		if (tree[i]->node == parent)
			tree[i]->leafs.push_back(new Tree(item));
		else
			search(tree[i]->leafs, parent, item);
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
	int leng, parent, node, cnt = 0;

	scanf("%d", &leng);

	for (int i = 0; i < leng; ++i) {
		scanf("%d ", &parent);

		if (parent == -1)
			tree.push_back(new Tree(i));
		else
			search(tree, parent, i);

	}

	scanf("%d", &node);
	delNode(tree, node, &cnt);

	printf("%d ", cnt);

	return 0;
}