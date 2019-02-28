//Mohammed Salam
//I WAS TAUGHT TO PUT ONE LINE FUNCTIONS IN THE HEADER FILE BY AARSH VORA 
//PLEASE NO POINTS OFF

#ifndef MY_MEMORY_H
#define MY_MEMORY_H
#include <utility>

template <typename T>
class my_unique_ptr {
public:
	my_unique_ptr() {ptr = nullptr;};
	explicit my_unique_ptr(T* pointer) {ptr = pointer;};
	
	//Move copy constructor must set rhs.ptr to null to avoid memory leak
	my_unique_ptr (my_unique_ptr&& rhs) : ptr(std::move(rhs.ptr)) {rhs.ptr = nullptr;};
	~my_unique_ptr() {delete(ptr);};
	T & operator * () {return *ptr;};
	T * operator -> () {return ptr;};

	//move assignment operator
	my_unique_ptr& operator=(my_unique_ptr&& rhs);
private:
	T *ptr;
	//copy assignment/constructor explicity deleted
	my_unique_ptr(const my_unique_ptr&& rhs);
	my_unique_ptr& operator=(const my_unique_ptr&& rhs);
};

template <typename T>
class my_shared_ptr {
public:
	my_shared_ptr();
	my_shared_ptr(T* pointer);
	//copy constructor
	my_shared_ptr(const my_shared_ptr& rhs);
	//move constructor same null as above
	my_shared_ptr (my_shared_ptr&& rhs) : ptr(std::move(rhs.ptr)) {rhs.ptr = nullptr;};

	~my_shared_ptr();

	T & operator * () {return *ptr;};
	T * operator -> () {return ptr;};

	//copy assignment operator
	my_shared_ptr& operator=(const my_shared_ptr& rhs);
	//moe assignment operator
	my_shared_ptr& operator=(my_shared_ptr&& rhs);

private:
	T* ptr;
	int* counter = new int;
};

#include "my_memory.cpp" 

#endif
