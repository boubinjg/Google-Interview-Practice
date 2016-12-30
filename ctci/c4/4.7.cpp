#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
struct node{
	std::vector<node*> dlist;	
	std::string s;
};
void buildAdd(node* n, std::vector<node*>& bo, std::vector<node*>& visited)
{
	visited.push_back(n);
	for(int i = 0; i<n->dlist.size(); i++)
	{
		node *cur = n->dlist[i];
		if(std::find(visited.begin(), visited.end(), cur) == visited.end()) 
		{	
			buildAdd(cur, bo, visited);
		}
	}
	bo.push_back(n);
}
void buildOrder(std::vector<node*> v)
{
	std::vector<node*> bo;
	std::vector<node*> visited;
	for(int i = 0; i<v.size(); i++)
	{
		if(std::find(visited.begin(), visited.end(), v[i]) == visited.end())
		{
			buildAdd(v[i], bo, visited);
		}
	}	
	for(int i = 0; i<bo.size(); i++)
	{
		std::cout<<bo[i]->s<<std::endl;
	}
}
int main()
{
	node* A = new node;
	node* B = new node;
	node* C = new node;
	node* D = new node;
	node* F = new node;
	node* E = new node;

	A ->dlist.push_back(F);
	B ->dlist.push_back(F);
	C ->dlist.push_back(D);
	D ->dlist.push_back(B);
	D ->dlist.push_back(A);

	A->s = "A";
	B->s = "B";
	C->s = "C";
	D->s = "D";
	F->s = "F";
	E->s = "E";
	
	std::vector<node*> v;
	v.push_back(A);
	v.push_back(B);
	v.push_back(C);
	v.push_back(D);
	v.push_back(E);	
	v.push_back(F);
	std::vector<node*> a;
	std::vector<node*> b;
	//buildAdd(A, a, b);
	buildOrder(v);
}
