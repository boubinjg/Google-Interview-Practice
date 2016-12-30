#include<iostream>
#include<algorithm>
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool searchOver = false;
    int leafCount = 0;
    int treeDepth = 0;
    void inorder(TreeNode* root, int depth)
    {
        if(root != NULL && !searchOver)
        {
            if(root->left == NULL && root->right == NULL && depth == treeDepth)
		leafCount++;
	    if(root->left == NULL && root->right == NULL && depth < treeDepth)
		searchOver = true;
	    inorder(root->left, depth+1);
            inorder(root->right, depth+1);
        }
	
    }
    int getDepth(TreeNode* root)
    {
        if(root != NULL)
        {
            return 1+getDepth(root->left);
        }
        return 0;
    }
    int countNodes(TreeNode* root) {
        if(root != NULL)
        {
            	treeDepth = getDepth(root);
           	int total = pow(2,treeDepth-1)-1;
            	inorder(root, 1);
            	std::cout<<leafCount<<" "<<total<<std::endl;

	    	return total + leafCount;
        }
        return 0;
    }
};
int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(3);
	TreeNode* lc = new TreeNode(4);
	
	root->left = left;
	root->right = right;
	left->left = lc;
	left->right = NULL;
	Solution s;
	std::cout<<s.countNodes(root)<<std::endl;
	return 0;
}
