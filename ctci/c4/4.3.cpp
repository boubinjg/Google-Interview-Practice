#include<vector>
#include<iostream>
struct node{
	node* left;
	node* right;
	int val;
};
node* makeBTree(std::vector<int> list)
{
	//std::cout<<list.size()<<std::endl;
	if(list.size() == 0)
		return NULL;
	if(list.size() == 1)
	{
		node *n = new node;
		n->val = list[0];
		n->right = NULL;
		n->left = NULL;
	}
	
	node *root = new node;	
	root->val = list[list.size()/2];
	std::vector<int>::iterator middle = (list.begin() + list.size()/2);
	std::vector<int> right(list.begin(), middle);
	std::vector<int> left(middle+1, list.end());
	
	root->right = makeBTree(right);
	root->left = makeBTree(left);
	
	return root;
}
void preorder(std::vector<std::vector<int> >& byLevel, node* root, int depth)
{
	if(root != NULL)
	{
		if(byLevel.size() <= depth)
		{
			std::vector<int> v;
			byLevel.push_back(v);
		}

		byLevel[depth].push_back(root->val);
		
		preorder(byLevel, root->right, depth+1);
		preorder(byLevel,root->left,depth+1);
	}
}
void listByLevel(std::vector<std::vector<int> >& byLevel, node* root)
{
	std::vector<int> v;
	v.push_back(root->val);
	byLevel.push_back(v);
	
	preorder(byLevel, root->left, 1);
	preorder(byLevel, root->right, 1);
}
int main()
{
	std::vector<int> v;
	for(int i = 0; i<20; i++)
	{
		v.push_back(i);
	}
	node *root = makeBTree(v);
	std::vector<std::vector<int> >bv;
	listByLevel(bv, root);		

	for(int i = 0; i<bv.size(); i++)
	{
		for(int j = 0; j<bv[i].size(); j++)
		{
			std::cout<<bv[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
