#include<iostream>
#include<vector>

bool isWon(std::vector<std::vector<char> > board)
{
	for(int i = 0; i<3; i++)
	{
		if(board[i][0] == board[i][1] == board[i][2] && (board[i][0] != 'E'))
			return true;
		if(board[0][i] == board[1][i] == board[2][i] && (board[0][i] != 'E'))
                        return true;
	}
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && (board[0][0] != 'E'))
		return true;
	if(board[2][0] == board[1][1] == board[0][2] && (board[0][0] != 'E'))
                return true;
	
	return false;
}
int main()
{
	std::vector<std::vector<char> > v;
	std::vector<char> c;
	c.push_back('X');
	c.push_back('X');
	c.push_back('X');
	v.push_back(c);
	c.clear();
	c.push_back('X');
	c.push_back('X');
	c.push_back('O');
	v.push_back(c);
	c.clear();
	c.push_back('O');
	c.push_back('O');
	c.push_back('X');
	v.push_back(c);
	std::cout<<isWon(v)<<std::endl;
	
}
