#ifndef STACKMIN_H
#define STACKMIN_H
template<class T>
struct StackNode {
	T data;
	StackNode<T>* next;
	StackNode<T>(const T& d) : data(d), next(nullptr) {}
};

template<class T>
struct StackMin {
	
	StackNode<T>* top    = nullptr;
	StackNode<T>* minTop = nullptr;
	
	void push(T data) {
		
		if(!top) {
			top = new StackNode<T>(data);
			min = new StackNode<T>(data);
		}
		else {
			
			StackNode<T>* minTemp = nullptr;
			if(data < minTop->data) minTemp = new StackNode<T>(data);
			else minTemp = new StackNode<T>(minTop->data);
			
			minTop->next = minTemp;
			minTop = minTemp;
			
			StackNode<T>* temp = new StackNode<T>(data);
			temp->next = top;
			top = temp;
			
		}
		
	}
	
	T pop() : pop() {
		
		
		T val = top->data;
		StackNode<T>* temp = top;
		top = top->next;
		delete temp;
		
		temp = minTop;
		minTop = minTop->next;
		delete temp;
		
		return val;
		
	}
	
	T peek() {
		if(top) return top->data;
	}
	
	bool isEmpty() { return top == nullptr; }
	
	T min() {
		return minTop->data;
	}
};
#endif