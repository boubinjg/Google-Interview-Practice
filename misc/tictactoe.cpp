#include <vector>
#include <iostream>
class board
{
private:
	std::vector<std::vector<char> > tboard;
public:
	board()
	{
		std::vector<char> v;
		for(int i = 0; i<3; i++)
		{
			for(int j = 0; j<3; j++)
				v.push_back('E');
			tboard.push_back(v);
		}
	}
	char getPos(int x, int y)
	{
		return tboard[x][y];
	}
	bool setPos(int x, int y, char c)
	{
		if(x>-1 && x<3 && y>-1 && y<3)
			tboard[x][y] = c;
		else
			return false;
		return true;
	}
	void printBoard()
	{
		for(int i = 0; i<3; i++)
		{
			for(int j = 0; j<3; j++)
			{
				std::cout<<tboard[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
	bool won() 
	{
		//vertical or horizontal wins
	for(int i = 0; i<3; i++)
	{
		if     (tboard[i][1] == 'X' && tboard[i][2] == 'X' && tboard[i][0] == 'X')
			return true;
		else if(tboard[i][0] == 'O' && tboard[i][1] == 'O' && tboard[i][2] == 'O')
			return true;
		else if(tboard[0][i] == 'O' && tboard[1][i] == 'O' && tboard[2][i] == 'O')
			return true;
		else if(tboard[0][i] == 'X' && tboard[1][i] == 'X' && tboard[2][i] == 'X')
			return true;
		}
		//diagonals
		if     (tboard[0][0] == 'X' && tboard[1][1] == 'X' && tboard[2][2] == 'X')
			return true;
		else if(tboard[0][0] == 'O' && tboard[1][1] == 'O' && tboard[2][2] == 'X')
			return true;
		else if(tboard[0][2] == 'X' && tboard[1][1] == 'X' && tboard[2][0] == 'X')
			return true;
		else if(tboard[0][2] == 'O' && tboard[1][1] == 'O' && tboard[2][0] == 'O')
			return true;
		
		return false;
	}
};
int main()
{
	board b;
	int x, y;
	bool p1 = false;
	while(!b.won())
	{
		p1 = !p1;
		b.printBoard();
		char c;
		if(p1)
		{
			c = 'X';
			std::cout<<"p1, make a move"<<std::endl;
		}
		else
		{
			c = 'O';	
			std::cout<<"p2 make a move"<<std::endl;
		}
		std::cin>>x>>y;
		while(!b.setPos(x,y,c))
		{
			std::cout<<"Please input valid numbers"<<std::endl;
			std::cin>>x>>y;
		}
	}
	b.printBoard();
	if(p1)
		std::cout<<"gz p1"<<std::endl;
	else
		std::cout<<"gz p2"<<std::endl;
}
