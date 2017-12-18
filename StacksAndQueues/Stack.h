#ifndef STACK_H
#define STACK_H
template<class T>
struct StackNode {
	T data;
	StackNode<T>* next;
	StackNode<T>(const T& d) : data(d), next(nullptr) {}
};

template<class T>
struct Stack {
	
	Stack<T>* top = nullptr;
	
	void push(T data) {
		
		if(!top) top = new StackNode<T>(data);
		else {
			
			StackNode<T>* temp = new StackNode<T>(data);
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

template<class T>
struct StackMin : public Stack<T> {
	
	Stack<T>* minTop = nullptr;
	
	void push(T data) {
		
		Stack<T>::push(data);
		
		if(!minTop) minTop = new StackNode<T>(data);
		else {
			if(data < minTop->data) {
				StackNode<T>* temp = new StackNode<T>(data);
				temp->next = minTop;
				minTop = temp;
			}
		}

	}
	
	T pop() {
		
		T val = Stack<T>::pop();
		
		StackNode<T>* temp = minTop;
		minTop = minTop->next;
		delete temp;
		
		return val;
		
		
	}
	
	T min() { return minTop->data; }
};
#endif