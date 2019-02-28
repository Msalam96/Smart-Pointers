//Mohammed Salam
#ifdef MY_MEMORY_H
/*template <typename T>
my_unique_ptr<T>::my_unique_ptr(my_unique_ptr&& rhs) {
		//delete(ptr);
		ptr = std::move(rhs.ptr);
}

*/
template<typename T>
my_unique_ptr<T>& my_unique_ptr<T>::operator=(my_unique_ptr&& rhs) {
	ptr = std::move(rhs.ptr);
	rhs.ptr = nullptr;
	return *this;
}

template<typename T>
my_shared_ptr<T>::my_shared_ptr() {
	ptr = nullptr;
	counter = new int;
	*counter = 1;
	//counter = NULL;
}

template<typename T>
my_shared_ptr<T>::my_shared_ptr(T* pointer) {
	ptr = pointer; 
	//counter = new int;
	*counter = 1;
	//*counter += 1;
	//std::cout << *counter << std::endl;
}

template<typename T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr& rhs) {
	//counter = new int;
	//std::cout << *counter << std::endl;
	ptr = rhs.ptr;
	counter = rhs.counter;
	//counter = new int;
	*counter += 1;
	//std::cout << *counter << std::endl;
}

template<typename T>
my_shared_ptr<T>::~my_shared_ptr() {
	if (ptr == nullptr) {
		delete(ptr);
		delete(counter);
	}
}

template<typename T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(const my_shared_ptr& rhs) {
	if (ptr != nullptr) {
		*counter -= 1;
		//std::cout << *counter << std::endl;
		if (*counter == 0) {
			delete(ptr);
			delete(counter);
			//std::cout << *counter << std::endl;

		}
	}
	if (this != &rhs) {
		this->ptr = rhs.ptr;
		this->counter = rhs.counter;
	}
	*counter += 1;
	return *this;
}

template<typename T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(my_shared_ptr&& rhs) {
	if (ptr != nullptr) {
		*counter -= 1;
		//std::cout << *counter << std::endl;
		if (*counter == 0) {
			delete(ptr);
			delete(counter);
			//std::cout << *counter << std::endl;
		}
	}
	if (this != &rhs) {
		ptr = std::move(rhs.ptr);
		counter = std::move(rhs.counter);
		rhs.ptr = nullptr;
		rhs.counter = nullptr;
	}
	//*counter += 1;
	return *this;
}

#endif
//void TemporaryFunction () {
 //   my_unique_ptr<int> temp;
 //   my_shared_ptr<int> temp2;
//}
