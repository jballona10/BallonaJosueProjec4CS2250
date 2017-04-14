#include "LinkedList.hpp"
// constructor
LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

// add a node to the beginning of the list
void LinkedList::reAppend(int a)
{
	ListNode * newNode;
	newNode = new ListNode;
	newNode->data = a;


	// if empty list
	if (!head)
	{
		head = newNode;
		newNode->next = tail;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

// add a node to the end of the list
void LinkedList::appendNode(int b)
{
	// pointers for new node and to move through the list
	ListNode * newNode, * nodePtr;
	// allocate the new node
	newNode = new ListNode;
	newNode->data = b;
	newNode->next = nullptr;


	// if empty list
	if (!head)
	{
		head = newNode;
		newNode->next = tail;
	}
	else // insert node at the end
	{
		// initialize nodePtr to head
		nodePtr = head;

		// find the last node
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// insert newNode as the last node
		// make newNode point to tail
		nodePtr->next = newNode;
		newNode->next = tail;
	}
}

// insert a node after the first number lower than it
void LinkedList::insertNodeInSortedOrder(int c)
{
	// pointers for new node and to move through the list
	ListNode * newNode, * nodePtr;
	// dynamically allocate the new node
	newNode = new ListNode;
	newNode->data = c;
	newNode->next = nullptr;

	// initialize nodePtr to head
	nodePtr = head;
	// while the number in the nodes is smaller than c
	// make nodePtr point to the next node
	while (nodePtr->data > c)
		nodePtr = nodePtr->next;
	// set newNode next to the pointer after the one with c
	newNode->next = nodePtr->next;
	// set nodePtr next to new node
	nodePtr->next = newNode;
}

// delete the first node with the value, d.
void LinkedList::deleteNodeOfValue(int d)
{
	// pointer to move through list
	ListNode * nodePtr, * previousPtr;

	// initialize nodePtr to head
	nodePtr = head;

	// if only one node
	if (ListNode::objectcount == 1)
	{
		if (nodePtr->data == d)
		{
			head = nodePtr->next;
			delete nodePtr;
			ListNode::objectcount--;
		}
		else
		{
			cout << "The value does not exist in the list\n";
			return;
		}
	}
	else
	{
		if (head->data == d)
		{
			nodePtr = head->next;
			delete head;
			ListNode::objectcount--;
			head = nodePtr;
		}
		else// if (head->data != d)
		{
			// move through list to find the first instance of d
			while (nodePtr->data != d && nodePtr->next)
			{
				previousPtr = nodePtr;
				nodePtr = nodePtr->next;
			}
			if (nodePtr->data == d)
			{
				previousPtr->next = nodePtr->next;
				delete nodePtr;
				ListNode::objectcount--;
			}
			else
			{
				cout << d << " does not exist in the list\n";
				return;
			}
		}

	}
}

// delete the node at location e
void LinkedList::deleteNodeAtLocation(int e)
{
	//  ptrs to move through the list
	ListNode * nodePtr, * previousPtr;

	//initialize nodePtr to head
	nodePtr = head;

	if (e > ListNode::objectcount)
	{
		cout << "The location chosen does not exist\n";
	}
	else if (ListNode::objectcount > 1 && ListNode::objectcount > e)
	{
		// move through list to find the location.
		for (int count = 0; count < e; count++)
		{
			previousPtr = nodePtr;
			nodePtr = nodePtr->next;
		}

		// delete node
		previousPtr->next = nodePtr->next;
		delete nodePtr;
		ListNode::objectcount--;
	}
	else
	{
		head = nodePtr->next;
		delete nodePtr;
		ListNode::objectcount--;
	}
}

// get the number stored in the node at locaiton f
int LinkedList::getNodeValueAtLocation(int f)
{
	// pointer to move through list
	ListNode * nodePtr;

	//initialize nodePtr to head
	nodePtr = head;

	// if f is larger than objectcount
	if (f > ListNode::objectcount)
	{
		cout << "The location chosen does not exist\n";
	}
	else
	{
		for (int count = 1; count < f; count++)
		{
			nodePtr = nodePtr->next;
		}
		return nodePtr->data;
	}
}

// add the numbers of two nodes, store it in g, delete h.
void LinkedList::mergeTwoNodes(int g, int h)
{
	// pointers to find locations g, h, and the one before h
	ListNode * nodePtrg, * nodePtrh, * previousPtrh;

	// initialize nodePtrg and nodePtrh to head
	nodePtrg = nodePtrh = head;

	if (g > ListNode::objectcount || h > ListNode::objectcount)
	{
		cout << "One (or both) of the locations chosen does not exist\n";
	}
	else
	{
		// find the node at location g
		for (int count = 1; count < g; count++)
		{
			nodePtrg = nodePtrg->next;
		}
		// find node at location h and one previous
		for (int count = 1; count < h; count++)
		{
			previousPtrh = nodePtrh;
			nodePtrh = nodePtrh->next;
		}

		// add the values together and store them in location g
		nodePtrg->data = nodePtrg->data +nodePtrh->data;
		// make the previousPtrh point to the pointer after nodeptrh
		previousPtrh->next = nodePtrh->next;
		// delete nodeptrh
		delete nodePtrh;
	}
}

// swap the values in nodes i and j
void LinkedList::swapNodes(int i, int j)
{
	// pointers to find locations i and j
	ListNode * nodePtri, * nodePtrj;
	// temp variable to hold one of the values
	int temp = 0;

	// initialize pointers to head
	nodePtri = nodePtrj = head;

	// if i or j is greater than number of nodes
	if (i > ListNode::objectcount || j > ListNode::objectcount)
	{
		cout << "One or both of the locations does not exist\n";
	}
	else
	{
		// find node at i
		for (int count = 1; count < i; count++)
		{
			nodePtri = nodePtri->next;
		}
		// find node at j
		for (int count = 1; count < j; count++)
		{
			nodePtrj = nodePtrj->next;
		}

		// store the value at i in temp
		temp = nodePtri->data;
		// store the value at j in nodePtri
		nodePtri->data = nodePtrj->data;
		// store temp in nodePtrj
		nodePtrj->data = temp;
	}
}

// remove all duplicate nodes
void LinkedList::removeAllDuplicates()
{
	ListNode * nodePtr, * previousPtr, * examinePtr, * tempPtr;

	nodePtr = head->next;
	previousPtr = head;

	while (nodePtr != tail)
	{
		examinePtr = head;

		while (examinePtr != nodePtr)
		{
			if (examinePtr->data == nodePtr->data)
			{
				tempPtr = nodePtr;
				nodePtr = nodePtr->next;
				previousPtr->next = nodePtr;
				delete tempPtr;
				ListNode::objectcount--;
				break;
			}
			examinePtr = examinePtr->next;
		}

		if (examinePtr == nodePtr)
		{
			nodePtr = nodePtr->next;
			previousPtr = previousPtr->next;
		}
	}
}

// return the number of nodes
int LinkedList::numberOfNodes()
{
	return ListNode::objectcount;
}

//display the list
void LinkedList::displayList() const
{
	// pointer to move through list
	ListNode * nodePtr;

	// initialize nodeptr to head
	nodePtr = head;

	while (nodePtr)
	{
		cout << nodePtr->data << " ";
		nodePtr = nodePtr->next;
	}
}
// delete the entire list
void LinkedList::deleteList()
{
	// pointers to move through and delete list
	ListNode * nodePtr, * previousPtr;

	// initialize nodePtr to head
	nodePtr = head;

	if (ListNode::objectcount == 1)
	{
		head = nodePtr->next;
		delete nodePtr;
		ListNode::objectcount--;
	}
	else
	{
		while (nodePtr)
		{
			previousPtr = nodePtr;
			nodePtr = nodePtr->next;
			delete previousPtr;
			ListNode::objectcount--;
		}
	}
}

int LinkedList::ListNode::objectcount = 0;
