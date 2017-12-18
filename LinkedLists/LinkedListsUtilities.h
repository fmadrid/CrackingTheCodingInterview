#ifndef LINKEDLISTSUTILITIES_H
#define LINKEDLISTSUTILITIES_H

#include <unordered_set>
#include "LinkedLists.h"
// Removes duplicate elements from a linked list (w/o buffer)
template<class T>
void removeDuplicate(LinkedList<T>* list) {

	ListNode<T>* currentNode = list->root;
	
	while(currentNode->next) {
		
		ListNode<T>* prevNode = currentNode;
		ListNode<T>* checkNode = prevNode->next;
		
		while(checkNode) {
			if(currentNode->data == checkNode->data)
				removeNode(prevNode, checkNode);
			prevNode = checkNode;
			checkNode = prevNode->next;
		}
		
		currentNode = currentNode->next;;
		
	}

}

// Removes duplicate elements from a linked list (w buffer)
template<class T>
void removeDuplicateWithBuffer(LinkedList<T>* list) {

	std::unordered_set<T> table;
	table.insert(list->root->data);
	

	ListNode<T>* prevNode = list->root;
	ListNode<T>* checkNode = prevNode->next;
	while(checkNode) {
		if(table.count(checkNode->data))
			prevNode->next = removeNode(prevNode, checkNode);
		else table.insert(checkNode->data);
		
		if(!prevNode->next) break;
		
		prevNode = prevNode->next;
		checkNode = prevNode->next;
	}
	
}
#endif