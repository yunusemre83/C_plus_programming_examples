#include "Header.h"


////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////// Stackf from Array

template<class T>
class Stack_Single{

public:
	Stack_Single(unsigned max_size=20);
	~Stack_Single();
	bool push(T data_in);
	bool pull(T & out_data);
	bool isEmpty() { return (size == 0) ? true : false; };
	bool isFull() { return (size < maxsize) ? false : true; };
	void print_stack();
	unsigned getSize() { return size;  };
	unsigned getMaxSize() { return maxsize; };
private:
	unsigned maxsize;
	unsigned size;
	int top;
	T * stackptr;
};

template<class T>
Stack_Single<T>::Stack_Single(unsigned max_size){
	maxsize = max_size;
	top = -1;
	size = 0;
	stackptr = new T[maxsize];
}

template <class T>
Stack_Single<T>::~Stack_Single(){
	delete [] stackptr;
}

template<class T>
bool Stack_Single<T>::push(T in_data){

	if (!isFull()){
		top++;
		size++;
		stackptr[top] = in_data;
		return true;
	}
	return false;
}


template<class T>
bool Stack_Single<T>::pull(T &out_data){

	if (!isEmpty()){
		out_data = stackptr[top];
		top--;
		size--;
		return true;
	}
	return false;
}

template<class T>
void Stack_Single<T>::print_stack(){

	for (int i = 0; i < (int)(size); i++)
		cout << stackptr[i] << " ";
	cout << "\n";
}

////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////// Stackf from LinkedList
template<class T>
class Stack : public LinkedList<T>{

public:
	Stack(unsigned max_size=20);
	~Stack(){};
	bool push(T in_data);
	bool pull(T& out_data);
	void print_stack();
private:
	unsigned maxsize;
};

template<class T>
Stack<T>::Stack(unsigned max_size ):LinkedList<T>() {
	maxsize = max_size;
}

template<class T>
bool Stack<T>::push(T in_data){
	if (get_size() < (int)(maxsize)){
		insert_from_front(in_data);
		return true;
	}
	return false;
}

template<class T>
bool Stack<T>::pull(T& out_data){
	if (get_size() != 0){
		out_data = remove_from_front();
		return true;
	}
	return false;
}

template<class T>
void Stack<T>::print_stack(){
	print_list();
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////  QUEUE from Array

template<class T>
class Queue_Single{

public:
	Queue_Single(unsigned maxsize=20);
	~Queue_Single();
	bool enqueue(T in_data);
	bool dequeue(T& out_data);
	void print_queue();

private:
	T* queue_ptr;
	unsigned size;
	unsigned max_size;
	unsigned read_ptr;
	unsigned write_ptr;
};

template<class T>
Queue_Single<T>::Queue_Single(unsigned maxsize){
	max_size = maxsize;
	read_ptr = 0;
	write_ptr = 0;
	size = 0;
	queue_ptr = new T[max_size];
}

template<class T>
Queue_Single<T>::~Queue_Single(){
	delete[] queue_ptr;
}

template<class T>
bool Queue_Single<T>::enqueue(T in_data){
	if (size < max_size){
		queue_ptr[write_ptr] = in_data;
		size++;
		write_ptr++;
		if (write_ptr == max_size){
			write_ptr = 0;
		}
		return true;
	}
	return false;
}

template<class T>
bool Queue_Single<T>::dequeue(T& in_data){
	if (size > 0 ){
		out_data = queue_ptr[read_ptr];
		size--;
		read_ptr++;
		if (read_ptr == max_size){
			read_ptr = 0;
		}
		return true;
	}
	return false;
}

template<class T>
void Queue_Single<T>::print_queue(){

	unsigned i = read_ptr;
	while (i != write_ptr){
		cout << queue_ptr[i] << " ";
		i++;
		if (i == max_size){
			i = 0;
		}
	}
	cout << "\n";
}

////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////// QUEUE from LinkedList

template<class T>
class Queue : public LinkedList<T>{

public:
	Queue(unsigned =20 );
	~Queue();
	bool enqueue(T in_data);
	bool dequeue(T& out_data);
	void print_queue();
private:
	unsigned max_size;
};

template<class T>
Queue<T>::Queue(unsigned in_max_size):LinkedList<T>(){
	max_size = in_max_size;
}

template<class T>
Queue<T>::~Queue(){
}

template<class T>
bool Queue<T>::enqueue(T in_data){

	if ((int)(max_size) > get_size()){
		insert_from_front(in_data);
	}
	return false;
}

template<class T>
bool Queue<T>::dequeue(T& out_data){

	if (get_size() != 0){
		out_data = remove_from_back();
	}
	return false;
}

template<class T>
void Queue<T>::print_queue(){
	print_list();
}