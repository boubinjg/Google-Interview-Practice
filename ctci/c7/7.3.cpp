//design a musical jukebox using object oriented principles
/*
Jukeboxes have:
	a list of songs
	
	a price per song (assume flat rate)
	
	buttons to select songs to play
	
	a queue of songs which it will play
	
 	the ability for a manager to add songs
	
a Jukebox does:
	plays songs
	takes money
	adds songs to its queue
	
*/
#include<vector>
#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
#include<unistd.h>
struct song{
	std::string name;
	int length;
};
class jukebox{
private:
	std::unordered_map<std::string, bool> songList;
	int pricePerSong, password;
	std::queue<std::string> songsToPlay;
	bool playing = false;
	void playSongs()
	{
		while(!songsToPlay.empty())
		{
			sleep(5);
			songsToPlay.pop();
		}
		playing = false;
	}
public:
	jukebox(int songPrice, int password)
	{
		pricePerSong = songPrice;
	}
	void addSong(std::string newSong, int password)
	{
		if(this->password == password)
			songList[newSong] = true;
	}
	int selectSongs(std::vector<std::string> songs, int cash)//returns change
	{
		if(songs.size() * pricePerSong <= cash)
		{
			for(int i = 0; i<songs.size(); i++)
			{
				cash -= pricePerSong;
				if(songList[songs[i]])
					songsToPlay.push(songs[i]);
			}
			if(!playing)
				playSongs();
			return cash;
		}
		else
			return cash;
	}
};
int main()
{
	jukebox j(1, 1);
	j.addSong("1", 1);
	j.addSong("2", 1);
	j.addSong("3", 1);
	std::vector<std::string> s;
	s.push_back("1");
	s.push_back("2");
	s.push_back("3");
	j.selectSongs(s, 5);
	return 0;
}
