#include <iostream>
#include <vector>
class bheap
{
private:
	std::vector<int> heap;
	
	int left(int index)
	{
		int l = 2*index + 1;
		if(l > heap.size())
			return -1;
		else
			return l;
	}
	int right(int index)
	{
		int r = 2*index + 2;
		if(r > heap.size())
			return -1;
		else
			return r;
	}
	int parent(int index)
	{
		int p = (index-1)/2;
		if(index == 0)
			return -1;
		else
			return p;
	}
	void heapifyup(int index)
	{
		int p = parent(index);
		if(p >= 0 && index >= 0 && heap[p] > heap[index])
		{
			std::swap(heap[p], heap[index]);
			heapifyup(p);
		}
	}
	void heapifydown(int index)
	{
		int l = left(index);
		int r = right(index);

		if(l>=0 && r>=0 && heap[l] > heap[r])
			l=r;
		if(l >= 0 && index >= 0 && heap[index] > heap[l])
		{
			std::swap(heap[index], heap[l]);
			heapifydown(l);
		}
	}	
public:
	bheap()
	{
		
	}
	void insert(int i)
	{
		heap.push_back(i);
		heapifyup(heap.size()-1);
	}
	void popmin()
	{
		heap[0] = heap[heap.size()-1];
		heap.pop_back();
		heapifydown(0);
	}
	int peekmin()
	{
		return heap[0];
	}
	int size()
	{
		return heap.size();
	}
};
int main()
{
	bheap h;
	h.insert(5);
	h.insert(1);
	h.insert(100);
	h.insert(2);
	std::cout<<h.peekmin()<<" "<<h.size()<<std::endl;
}
