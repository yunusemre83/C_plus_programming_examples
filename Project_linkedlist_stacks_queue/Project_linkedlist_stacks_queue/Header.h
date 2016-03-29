
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

template<class T>
class ListNode{

public:
	ListNode<T> (T in_data);
	ListNode<T>* getnextPtr();
	void setnextPtr(ListNode<T>*);
	T getData();
	void setData(T data);
private:
	ListNode * nextNode;
	T data;
};

template<class T>
ListNode<T>::ListNode(T in_data){
	nextNode = NULL;
	data = in_data;
}

template<class T>
ListNode<T>* ListNode<T>::getnextPtr(){
	return nextNode;
}

template<class T>
void ListNode<T>::setnextPtr(ListNode<T>* in_next){
	nextNode=in_next;
}

template<class T>
T ListNode<T>::getData(){
	return data;
}

template<class T>
void ListNode<T>::setData(T data_in){
	data = data_in;
}

template<class T>
class LinkedList{

public:
	LinkedList<T>();
	~LinkedList<T>();
	void insert_from_front(T in_data);
	void insert_from_back(T in_data);
	T remove_from_front();
	T remove_from_back();
	int get_size();
	void print_list();
	void remove_dubs();
	void delete_middle(ListNode<T> * node);
	ListNode<T>* gethead(){ return head; };
	ListNode<T>* gettail(){ return tail; };
private:
	ListNode<T>* head;
	ListNode<T>* tail;
	int size;
};


template <class T>
LinkedList<T>::LinkedList(){
	head = NULL;
	tail = NULL;
	size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
	// FILL IN DESTRUCTOR
}

template <class T>
int LinkedList<T>::get_size(){
	return size;
}

template <class T>
void LinkedList<T>::print_list(){

	ListNode<T>* tempNode = head;

	for (int i = 0; i < size; i++){
		cout << tempNode->getData() << " ";
		tempNode = tempNode->getnextPtr();
	}
	cout << '\n';
}

template <class T>
void LinkedList<T>::insert_from_back(T in_data){

	ListNode<T>* newListNode = new ListNode<T>(in_data);

	if (size == 0){
		head = tail = newListNode;
		size++;
	}
	else{
		ListNode<T>* tempNodeptr = tail;
		tempNodeptr->setnextPtr(newListNode);
		tail = newListNode;
		size++;
	}
}

template <class T>
void LinkedList<T>::insert_from_front(T in_data){
	ListNode<T>* newListNode = new ListNode<T>(in_data);

	if (size == 0){
		head = tail = newListNode;
		size++;
	}
	else{
		ListNode<T>* tempNodeptr = head;
		head = newListNode;
		newListNode->setnextPtr(tempNodeptr);
		size++;
	}
}

template <class T>
T LinkedList<T>::remove_from_front(){
	T data_out;

	if (size == 0){
		return NULL;
	}
	else if (size == 1){
		data_out = head->getData();
		ListNode<T>* tempNode = head;
		head = tail = NULL;
		size--;
		delete tempNode;

	}else{
		data_out = head->getData();
		ListNode<T>* tempNode = head;
		head = head->getnextPtr();
		size--;
		delete tempNode;

	}
	return data_out;
}

template <class T>
T LinkedList<T>::remove_from_back(){
	
	T data_out;

	if (size == 0){
		return NULL;
	}
	else if (size == 1){
		data_out = head->getData();
		ListNode<T>* tempNode = head;
		head = tail = NULL;
		size--;
		delete tempNode;
	}
	else{
		data_out = tail->getData();

		ListNode<T>* tempNode = head;

		while (tempNode->getnextPtr() != tail){
			tempNode = tempNode->getnextPtr();
		}
		tail = tempNode;
		tempNode = tempNode->getnextPtr();
		size--;
		delete tempNode;
		tail->setnextPtr(NULL);

	}
	return data_out;

}

template <class T>
void LinkedList<T>::remove_dubs(){
	
	if (head == tail || head == NULL){
		return;
	}

	unordered_map<T, bool> hashtable_data;
	/*
	hashtable_data[head->getData()] = true;
	T which_key = tail->getData();
	
	if (hashtable_data.find(which_key) != hashtable_data.end()){
		cout << "hash: contain key" ;
		cout << hashtable_data[which_key] << '\n';
	}else
		cout << "hash: does not contain key" << '\n';
	*/

	ListNode<T> * cur_ptr = head->getnextPtr();
	ListNode<T> * prev_ptr = head;
	hashtable_data[head->getData()] = true;
	while (cur_ptr != NULL){
		if (hashtable_data.find(cur_ptr->getData()) != hashtable_data.end()){
			// found dub

			prev_ptr->setnextPtr (cur_ptr->getnextPtr());
			ListNode<T> * temp_ptr;
			temp_ptr = cur_ptr;
			cur_ptr = prev_ptr->getnextPtr();
			size--;
			if (temp_ptr != NULL)
				delete temp_ptr;

		}else{
			//
			hashtable_data[cur_ptr->getData()] = true;
			prev_ptr = prev_ptr->getnextPtr();
			cur_ptr = cur_ptr->getnextPtr();
		}
	}
	tail = prev_ptr;

	/*
	// show content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';
	*/

}

template<class T>
void LinkedList<T>::delete_middle(ListNode<T> * node_ptr){

	ListNode<T> * temp_node_ptr = node_ptr->getnextPtr();

	node_ptr->setData(temp_node_ptr->getData());
	node_ptr->setnextPtr(temp_node_ptr->getnextPtr());
	delete temp_node_ptr;

}

template<class T>
void sum_ascending(LinkedList<T>* l1, LinkedList<T>* l2, LinkedList<T>* l3){

	ListNode<T> * cur_ptr_l1 = l1->gethead();
	ListNode<T> * cur_ptr_l2 = l2->gethead();

	unsigned l1_data = 0;
	unsigned l2_data = 0;
	unsigned sum, result;
	unsigned carry=0;
	while (!(cur_ptr_l1 == NULL && cur_ptr_l2 == NULL)){
		if (cur_ptr_l1 == NULL){
			l1_data = 0;
		}else{
			l1_data = cur_ptr_l1->getData();
			cur_ptr_l1 = cur_ptr_l1->getnextPtr();
		}
		if (cur_ptr_l2 == NULL){
			l2_data = 0;
		}
		else{
			l2_data = cur_ptr_l2->getData();
			cur_ptr_l2 = cur_ptr_l2->getnextPtr();
		}
		sum = l1_data + l2_data +carry;
		result = sum % 10;
		carry = sum / 10;
		l3->insert_from_back(result);
	}
	if (carry != 0){
		l3->insert_from_back(carry);
	}
}

template<class T>
void sum_descending(LinkedList<T>* l1, LinkedList<T>* l2, LinkedList<T>* l3){

	ListNode<T> * cur_ptr_l1 = l1->gethead();
	ListNode<T> * cur_ptr_l2 = l2->gethead();
	unsigned carry = 0;
	if (l1->get_size() != l2->get_size()){
		cout << "Input Lists should be at the same size " << endl;
		return;
	}
	carry = get_carry(cur_ptr_l1,cur_ptr_l2,l3);
	l3->insert_from_front(carry);

}

template<class T>
unsigned get_carry(ListNode<T>* cur_ptr_l1, ListNode<T>* cur_ptr_l2, LinkedList<T>* l3){
	ListNode<T> * cur_ptr_l1_temp;
	ListNode<T> * cur_ptr_l2_temp;

	unsigned l1_data = 0;
	unsigned l2_data = 0;
	unsigned sum, result, carry;
	if (cur_ptr_l1 == NULL && cur_ptr_l2 == NULL){
		return 0;
	}
	else{

		cur_ptr_l1_temp = cur_ptr_l1->getnextPtr();
		cur_ptr_l2_temp = cur_ptr_l2->getnextPtr();

		carry = get_carry(cur_ptr_l1_temp, cur_ptr_l2_temp,l3);
		l1_data = cur_ptr_l1->getData();
		l2_data = cur_ptr_l2->getData();
		sum = l1_data + l2_data + carry;
		result = sum % 10;
		carry = sum / 10;
		l3->insert_from_front(result);
		return carry;
	}
}


