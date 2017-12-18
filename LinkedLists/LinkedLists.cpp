#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>
#include "ListNode.h"
#include <string>

template<class T>
ListNode<T>* addNode(T data, ListNode<T>* node) {
	
	while(node->next) node = node->next;
	node->next = new ListNode<T>*(data);
	return node->next;
}

template<class T>
ListNode<T>* partition(ListNode<T>* root, T value) {
	
	ListNode<T>* newRoot;
	ListNode<T>* leftRoot = newRoot;
	ListNode<T>* rightRoot = nullptr;
	
	ListNode<T>* current = root;
	
	while(current) {
		if(current->data < value) leftRoot = addNode(current->data, leftRoot);
		else rightRoot = addNode(current->data, rightRoot);
		current = current->next;
	}
	
	return newRoot;
}

template<class T>
void removeNode(ListNode<T>* node) {
	
	ListNode<T>* temp = node->next;
	node->value = temp->next->value;
	node->next = temp->next;
	delete temp;
}

template<class T>
std::pair<int,T> kthRecurse(ListNode<T>* node, int k) {
	
	if(!node->next) return std::make_pair(0, node->data);
	
	std::pair<int, T> ans = kthRecurse(node->next, k);
	if(ans.first == k - 1) return ans;
	else return std::make_pair(ans.first + 1, node->data);
	
}

template<class T>
T kthElement(ListNode<T>* root, int k) {
	std::vector<T> list;
	
	ListNode<T>* currentNode = root;
	while(currentNode) {
		list.push_back(currentNode->data);
		currentNode = currentNode->next;
	}
	
	return list[ list.size() - (k - 1) - 1];
	
}

template<class T>
ListNode<T>* removeNode(ListNode<T>* prevNode, ListNode<T>* removedNode) {
	
	prevNode->next = removedNode->next;
	delete removedNode;
	return prevNode->next;
	
}



int main() {
	
	ListNode<int>* root = new ListNode<int>(10);
	root->next = new ListNode<int>(5);
	root->next->next = new ListNode<int>(10);
	
	//removeDuplicate(root);
	printLinkedList(root);
	
	std::cout << kthElement(root, 2) << "\n";
	std::cout << kthRecurse(root, 2).second;
	return 0;
	
}