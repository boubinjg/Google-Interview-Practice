//create a data structure which holds two types (dogs/cats), the structure can enqueue any
//and dequeue dog, cats, or any.
#include<deque>
#include<algorithm>
#include<iostream>
#include<stack>
struct animal{
	bool dog;
	std::string name;
	int age;
};
class animalQueue{
private:
	std::deque<animal> cats;
	std::deque<animal> dogs;
	int age;
public:
	animalQueue()
	{
		age = 0;
	}
	void enqueue(animal a)
	{
		age++;
		a.age = age;
		if(a.dog)
			dogs.push_back(a);
		else
			cats.push_back(a);
	}
	animal dequeueAny()
	{
		animal ret;
		if(cats.front().age < dogs.front().age)
		{
			ret = cats.front();
			cats.pop_front();
		}
		else
		{
			ret = dogs.front();
			dogs.pop_front();
		}
		return ret;
	}
	animal dequeueCat()
	{
		animal ret;
		if(!cats.empty())	
		{
			ret = cats.front();
			cats.pop_front();
		}
		else
		{
			ret = dogs.front();
			dogs.pop_front();
		}
		return ret;
	}
	animal dequeueDog()
	{
		animal ret;
		if(!dogs.empty())	
		{
			ret = dogs.front();
			dogs.pop_front();
		}
		else
		{
			ret = cats.front();
			cats.pop_front();
		}
		return ret;
	}
	
};
int main()
{
	animalQueue q;
	animal a;
	a.dog = true;
	a.name = "A";
	animal b;
	b.dog = false;
	b.name = "B";
	animal c;
	c.dog = false;
	c.name = "C";
	animal d;
	d.dog = true;
	d.name = "D";
	q.enqueue(a);
	q.enqueue(b);
	q.enqueue(c);
	q.enqueue(d);
	std::cout<<q.dequeueDog().name<<" ";
	std::cout<<q.dequeueAny().name<<" ";
	std::cout<<q.dequeueDog().name<<" ";
	std::cout<<q.dequeueDog().name<<" ";
}
