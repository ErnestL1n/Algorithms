#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {};
	TreeNode(int value) :val(value),left(nullptr),right(nullptr) {};
	TreeNode(int value, TreeNode* leftchild, TreeNode* rightchild) :val(value), left(leftchild), right(rightchild) {};
};
//leetcode 783 && 530 , they are the same
class Minimum_Distance_Between_BST_Nodes {
public:
	TreeNode* BuildTree(vector<int>& nodes) {
		if (nodes.empty() || nodes.size() == 0)
			return nullptr;
		queue<int> intqueue;
		queue<TreeNode*> treenodequeue;
		TreeNode* root = new TreeNode(nodes[0]);
		treenodequeue.push(root);
		for (int i = 1; i < nodes.size(); ++i)
			intqueue.push(nodes[i]);
		while (!intqueue.empty()) {
			TreeNode* curr = treenodequeue.front();
			treenodequeue.pop();
			int leftvalue, rightvalue;
			if (!intqueue.empty()) {
				leftvalue = intqueue.front();
				intqueue.pop();
			}
			if (!intqueue.empty()) {
				rightvalue = intqueue.front();
				intqueue.pop();
			}
			if (leftvalue != NULL) {
				TreeNode* leftchild = new TreeNode(leftvalue);
				treenodequeue.push(leftchild);
				curr->left = leftchild;
			}
			if (rightvalue != NULL) {
				TreeNode* rightchild = new TreeNode(rightvalue);
				treenodequeue.push(rightchild);
				curr->right = rightchild;
			}
		}
		return root;
	}
	int TreeSize(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int totalcount = 1;
		queue<TreeNode*> treenodequeue;
		treenodequeue.push(root);
		while (!treenodequeue.empty()) {
			TreeNode* curr = treenodequeue.front();
			treenodequeue.pop();
			if (curr->left != nullptr) {
				++totalcount;
				treenodequeue.push(curr->left);
			}
			if (curr->right != nullptr) {
				++totalcount;
				treenodequeue.push(curr->right);
			}
		}
		return totalcount;
	}
	void printTree(TreeNode* root) {
		if (root == nullptr)return;
		queue<TreeNode*> treenodequeue;
		int treesize = TreeSize(root);
		treenodequeue.push(root);
		cout << "I am root ,my value is " << root->val << "\n";
		--treesize;
		while (treesize != 0) {
			TreeNode* curr = treenodequeue.front();
			treenodequeue.pop();
			if (curr->left != nullptr) {
				treenodequeue.push(curr->left);
				cout << "I am leftchild of value " << curr->val << " , my value is " << curr->left->val << "\n";
				--treesize;
			}
			if (curr->right != nullptr) {
				treenodequeue.push(curr->right);
				cout << "I am rightchild of value " << curr->val << " , my value is " << curr->right->val << "\n";
				--treesize;
			}
		}
	}
    set<int> s;
    int res=INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if(!root)
            return res;
        if(!s.empty()){
            auto lw=s.lower_bound(root->val);
            if(lw!=s.begin()){
                --lw;
                if(*lw<root->val){
                    res=min(res,root->val-*lw);
                }
            }
            auto up=s.upper_bound(root->val);
            if(*up>root->val)
                res=min(res,*up-root->val);
        }
        s.insert(root->val);
        minDiffInBST(root->left);
        minDiffInBST(root->right);
        return res;
    }
};
int main() {
	Minimum_Distance_Between_BST_Nodes c;
	
	vector<int> nodes = { 1,3,5 };

	TreeNode* root = c.BuildTree(nodes);
	
	cout << c.minDiffInBST(root);
	
	return 0;
}