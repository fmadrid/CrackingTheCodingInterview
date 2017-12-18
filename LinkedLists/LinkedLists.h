#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <string>
#include <sstream>

template<class T>
struct ListNode {
	T data;
	ListNode<T>* next;
	ListNode<T>(const T& d) : data(d), next(nullptr) {}
};

template<class T>
struct LinkedList {
	ListNode<T>* root = nullptr;
	
	// Appends value to the end of the LinkedList. Returns a reference to the created
	ListNode<T>* add(T value) {
		if(!root) {
			root = new ListNode<T>*(value);
			return root;
		}
		
		ListNode<T>* current = root;
		while(current->next) current = current->next;
		current->next = new ListNode<T>*(value);
		
		return current->next;
	}
	
	// Removes the first occurrence of value
	ListNode<T>* remove(T value) {
		
		ListNode<T>* current = root;
		
		if(current->data == value) {
			root = current->next;
			delete current;
		} else {
		
			ListNode<T>* prev = root;
			current = prev->next;
			
			while(current) {
				if(current->data == value) {
					prev = current->next;
					delete current;
				} else {
					prev = current;
					current = prev->next;
				}
			}
			
		}
		
		return nullptr;
		
	}
	
	std::string toString() {
		
		std::ostringstream oss;
		
		oss << "[";
		ListNode<T>* currentNode = root;
		while(currentNode) {
			oss << currentNode->data;
			if(currentNode->next) oss << ", ";
			else oss << "]";
		}
		
		return oss.str();
		
	}
	
};

#endif