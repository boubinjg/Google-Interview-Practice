#include<algorithm>
#include<vector>
#include<iostream>

struct node{
	int val;
	int top;
	int bottom;
	int left;
	int right;
};
class jigsaw
{
private:
	std::vector<std::vector<node> > puzzle;
	std::vector<node> pieces;
public:
	jigsaw(int size)
	{
		std::vector<node> pieces;
		for(int i = 0; i<size; i++)
		{
			std::vector<node> row;
			for(int j = 0; j<size; j++)
			{
				node n;
				n.val = size*i + j;
				std::cout<<"1"<<std::endl;
				if(i>0)
				{
					n.top = puzzle[i-1][j].val;
					puzzle[i-1][j].bottom = n.val;
				}
				else
					n.top = -1;
				if(j>0)
				{
					std::cout<<n.left
					n.left = puzzle[i][j-1].val;
					puzzle[i][j-1].right = n.val;
				}
				else
					n.left = -1;
				if(j == size)
					n.right = -1;
				if(i == size)
					n.bottom = -1;
				pieces.push_back(n);
			}
			puzzle.push_back(row);
		}
	}
	bool fits(node n, node m)
	{

	}
	node getPiece(int i)
	{
		return pieces[i];
	}
};
int main()
{
	jigsaw j(10);
	std::cout<<j.getPiece(5).val<<std::endl;	
}
