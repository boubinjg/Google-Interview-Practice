//write a smart pointer class, a class which uses templates, simulates pointers, and has automatic garbage collection
#include<iostream>
#include<vector>
#include<algorithm>
template <class T>
class SmartPtr{
private:
	T*  ptr;
	int refs;
	void remove()
	{
		refs--;
		if(refs == 0)
			delete ptr;
		ptr = NULL;
	}
public:	
	SmartPtr(T* t)
	{
		std::cout<<*t<<std::endl;
		ptr = t;
		refs = 1;
	}
	SmartPtr(SmartPtr<T>* t)
	{
		ptr = t->ptr;
		refs = t->refs;
		++refs;
	}
	SmartPtr<T>& operator=(SmartPtr<T>& sptr)
	{
		if(this == &sptr)
			remove();
		if(refs > 0)
			remove();
		
		ptr = sptr.ptr;
		refs = sptr.refs;
		refs++;
		return *this;
	}
	~SmartPtr()
	{
		remove();
	}
	T getValue()
	{
		return *ptr;
	}
};
int main()
{
	int i = 0, j = 10;
	int *ip = &i;
	int *jp = &j;

	SmartPtr<int> s(ip);
	//SmartPtr<int> v(s);
	//SmartPtr<int> t(jp);
	
	//std::cout<<s.getValue()<<" "<<v.getValue()<<" "<<t.getValue()<<std::endl;	
}
