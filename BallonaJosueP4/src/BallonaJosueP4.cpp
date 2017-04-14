#include "LinkedList.hpp"



int main()
{
	LinkedList list;
	int options;
	int nodeval;
	int mergenode1, mergenode2;
	int swapnode1, swapnode2;
	bool variable = 0;

	cout << "List: ";
	list.displayList();
	cout << endl;
	do
	{

		// if there is no nodes, give the options that work with
		// no node only
		if (list.numberOfNodes() == 0)
		{
			cout << "What would you like to do?\n";
			cout << "1] Add a node at the beginning\n"
					<< "2] Add a node at the end\n"
					<< "3] Quit\n";
			cin >> options;

			switch (options)
			{
			case 1:
			{
				 cout << "Enter data to store in the node\n";
				 cin >> nodeval;
				 list.reAppend(nodeval);

				 cout << "List: ";
				 list.displayList();
				 cout << endl;
				 break;
			}
			case 2:
			{
				cout << "Enter the data to store in the node\n";
				cin >> nodeval;
				list.appendNode(nodeval);

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 3:
			{
				variable = true;
				break;
			}
			default:
				cout << "Option chosen is not valid\n";
			}
		}
		// if there's only one node, give options that work with
		// only one node
		else if (list.numberOfNodes() == 1)
		{
			cout << "What would you like to do?\n";
			cout << "1] Add a node at the beginning\n"
					<< "2] Add a node at the end\n"
					<< "3] Insert a node in numerical order\n"
					<< "4] Delete the first node with a certain value\n"
					<< "5] Delete the node at a certain location\n"
					<< "6] Return the value in a certain node\n"
					<< "7] Get the number of nodes\n"
					<< "8] Display the list\n"
					<< "9] Delete the list\n"
					<< "10] Quit\n";
			cin >> options;

			switch (options)
			{
			case 1:
			{
				cout << "Enter data to store in the node\n";
				cin >> nodeval;
				list.reAppend(nodeval);

				 cout << "List: ";
				 list.displayList();
				 cout << endl;
				 break;
			}
			case 2:
			{
				cout << "Enter the data to store in the node\n";
				cin >> nodeval;
				list.appendNode(nodeval);

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 3:
			{
				cout << "Enter the data to store in the node\n";
				cin >> nodeval;
				list.insertNodeInSortedOrder(nodeval);

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 4:
			{
				cout << "Enter the value you want to delete\n";
				cin >> nodeval;
				list.deleteNodeOfValue(nodeval);

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 5:
			{
				cout << "Enter the location you want to delete\n";
				cin >> nodeval;
				list.deleteNodeAtLocation(nodeval);

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 6:
			{
				cout << "Enter the location you want the value of\n";
				cin >> nodeval;
				if (nodeval > 1)
					cout << "The node does not exist\n";
				else
				{
					cout << "The number in node "
							<< nodeval
							<< " is "
							<< list.getNodeValueAtLocation(nodeval) << endl;
				}
				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 7:
			{
				cout << "There is " << list.numberOfNodes() << " node in the list\n";
				break;
			}
			case 8:
			{
				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 9:
			{
				list.deleteList();

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 10:
			{
				variable = true;
				break;
			}
			default:
				cout << "Option chosen is not valid\n";
			}
		}
		else
		{
			cout << "What would you like to do?\n"
					<< "1] Add a node to the beginning of the list\n"
					<< "2] Add a node to the end of the list\n"
					<< "3] Add a node in numerical order\n"
					<< "4] Delete the first node of a certain value\n"
					<< "5] Delete the node at a certain location\n"
					<< "6] Get the value stored in a certain location\n"
					<< "7] Merge two nodes\n"
					<< "8] Swap two node values\n"
					<< "9] Remove All Duplicates\n"
					<< "10] Get the number of nodes in the list\n"
					<< "11] Display the list\n"
					<< "12] Delete the list\n"
					<< "13] Quit\n";
			cin >> options;

			switch (options)
			{
			case 1:
			{
				cout << "Enter data to store in the node\n";
				cin >> nodeval;
				list.reAppend(nodeval);

				 cout << "List: ";
				 list.displayList();
				 cout << endl;
				 break;
			}
			case 2:
			{
				cout << "Enter the data to store in the node\n";
				cin >> nodeval;
				list.appendNode(nodeval);

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 3:
			{
				cout << "Enter data to store in the node\n";
				cin >> nodeval;
				list.insertNodeInSortedOrder(nodeval);

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 4:
			{
				cout << "Enter the value you want to delete\n";
				cin >> nodeval;
				list.deleteNodeOfValue(nodeval);

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 5:
			{
				cout << "Enter the location you want to delete\n";
				cin >> nodeval;
				list.deleteNodeAtLocation(nodeval);

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 6:
			{
				cout << "Enter the location you want the value of\n";
				cin >> nodeval;
				cout << list.getNodeValueAtLocation(nodeval) << endl;

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 7:
			{
				cout << "Enter the location of the first node\n";
				cin >> mergenode1;
				cout << "Enter the location of the second node\n";
				cin >> mergenode2;
				list.mergeTwoNodes(mergenode1, mergenode2);

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 8:
			{
				cout << "Enter the location of the first node\n";
				cin >> swapnode1;
				cout << "Enter the location of the second node\n";
				cin >> swapnode2;
				list.swapNodes(swapnode1, swapnode2);

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 9:
			{
				list.removeAllDuplicates();

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 10:
			{
				cout << "There are " << list.numberOfNodes() << " in the list\n";
				break;
			}
			case 11:
			{
				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 12:
			{
				list.deleteList();

				cout << "List: ";
				list.displayList();
				cout << endl;
				break;
			}
			case 13:
			{
				variable = true;
				break;
			}
			default:
				cout << "Option chosen is not valid\n";
				break;
			}
		}
	}
	while (!variable);

	return 0;
}
