#ifndef QUEUE_H
#define QUEUE_H
template<class T>
struct QueueNode {
	T data;
	QueueNode<T>* prev;
	QueueNode<T>(const T& d) : data(d), prev(nullptr) {}
};

template<class T>
struct Queue {
	
	Stack<T>* top = nullptr;
	
	void push(T data) {
		
		if(!top) top = new QueueNode<T>(data);
		else {
			
			QueueNode<T>* temp = new QueueNode<T>(data);
			temp->next = top;
			top = temp;
			
		}
		
	}
	
	T pop() {
		
		T val = top->data;
		StackNode<T>* temp = top;
		top = top->next;
		delete temp;
		
		return val;
		
	}
	
	T peek() {
		if(top) return top->data;
	}
	
	bool isEmpty() { return top == nullptr; }
		
};
#endif