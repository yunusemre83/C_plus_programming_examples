
#include <iostream>
//#include "Header.h";
#include "stack_def.h"

using namespace std;


int main(){
	
	ListNode<int> AA(23);
	ListNode<int>* BB = new ListNode<int>(45);
	
	cout << AA.getData() << '\n';
	cout << BB->getData() << '\n';

	LinkedList<int>* LL = new LinkedList<int>();

	for (int i = 0; i < 7; i++){
		if (i % 2 == 0){
			LL->insert_from_front(i);
		}
		else{
			LL->insert_from_back(i);
		}
	}
	LL->print_list();

	for (int i = 0; i < 1; i++){
		cout << LL->remove_from_front() << " ";
	}
	cout << "\n";
	for (int i = 0; i < 1; i++){
		cout << LL->remove_from_back() << " ";
	}
	cout << "\n";
	LL->print_list();

	for (int i = 0; i < 7; i++){
		LL->insert_from_front(i);
	}

	LL->print_list();

	LL->remove_dubs();

	LL->print_list();
	

	LinkedList<unsigned>* LL1 = new LinkedList<unsigned>();
	LL1->insert_from_back(7);
	LL1->insert_from_back(1);
	LL1->insert_from_back(8);
	LL1->print_list();

	LinkedList<unsigned>* LL2 = new LinkedList<unsigned>();
	LL2->insert_from_back(5);
	LL2->insert_from_back(9);
	LL2->insert_from_back(2);
	LL2->print_list();

	LinkedList<unsigned>* LL3 = new LinkedList<unsigned>();
	sum_ascending(LL1, LL2, LL3);
	LL3->print_list();

	LinkedList<unsigned>* LL4 = new LinkedList<unsigned>();
	// Same size LL1 and LL2
	sum_descending(LL1, LL2, LL4);
	LL4->print_list();

	cout << sizeof(unsigned) << endl;
	
	Stack_Single<int> * sstack = new Stack_Single<int>(6);
	for (int i = 0; i < 7; i++){
		sstack->push(i);
	}
	sstack->print_stack();
	int temp;
	sstack->pull(temp);
	cout << temp << endl;
	sstack->pull(temp);
	cout << temp << endl;

	Stack<int> * slstack = new Stack<int>(6);
	for (int i = 0; i < 7; i++){
		slstack->push(i);
	}
	slstack->print_stack();
	slstack->pull(temp);
	cout << temp << endl;
	slstack->pull(temp);
	cout << temp << endl;
	

	Queue<int> * squeue = new Queue<int>(6);
	for (int i = 0; i < 7; i++){
		squeue->enqueue(i);
	}
	int temp;
	squeue->print_queue();
	squeue->dequeue(temp);
	cout << temp << endl;
	squeue->dequeue(temp);
	cout << temp << endl;
	squeue->print_queue();

	Queue<int> * qqueue = new Queue<int>(6);
	for (int i = 0; i < 7; i++){
		qqueue->enqueue(i);
	}
	temp;
	qqueue->print_queue();
	qqueue->dequeue(temp);
	cout << temp << endl;
	qqueue->dequeue(temp);
	cout << temp << endl;
	qqueue->print_queue();


	system("pause");

}
