#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
struct node{
	std::vector<node*> connections;
};
bool isConnected(node* s, node* g)
{
	std::vector<node*> visited;
	std::queue<node*> q;
	q.push(s);

	while(!q.empty())
	{
		node* cur = q.front();
		q.pop();
		for(int i = 0; i<cur->connections.size(); i++)
		{
			node* n = cur->connections[i];
			if(n == g)
				return true;
			if(std::find(visited.begin(), visited.end(), n) == visited.end()) 
			{
				q.push(n);	
			}
		}
	}	
	return false;
}
int main()
{
	node* A = new node;
	node* B = new node;
	node* C = new node;
	node* D = new node;
	node* E = new node;
	node* F = new node;
	A->connections.push_back(B);
	A->connections.push_back(C);
	C->connections.push_back(D);
	D->connections.push_back(E);
	
	std::cout<<isConnected(A, E)<<" "<<isConnected(A, F)<<std::endl;
}
