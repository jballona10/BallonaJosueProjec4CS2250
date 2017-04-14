#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_
#include <iostream>
using namespace std;

class LinkedList
{
private:
	struct ListNode
	{
		int data;
		ListNode * next;
		static int objectcount;
		ListNode()
	{ objectcount++;
	data = 0;
	next = nullptr;}
	};
	ListNode * head, * tail;
public:
	LinkedList();
	void reAppend(int);
	void appendNode(int);
	void insertNodeInSortedOrder(int);
	void deleteNodeOfValue(int);
	void deleteNodeAtLocation(int);
	int getNodeValueAtLocation(int);
	void mergeTwoNodes(int, int);
	void swapNodes(int, int);
	void removeAllDuplicates();
	int numberOfNodes();
	void displayList() const;
	void deleteList();
};




#endif
