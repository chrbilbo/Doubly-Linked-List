#include <cstdlib>
#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};

class DoubLinkList{
public:
	DoubLinkList(){
		head = NULL;
		tail = NULL;
	}
	~DoubLinkList();

	bool IsEmpty(){return head == NULL && tail == NULL;}
	Node* insertNode(int index, int data);
	int findNode(int data);
	int delNode(int data);

private:
	Node* head;
	Node* tail;
};


int main(){
	int choice;
	int data;
	int index;

	DoubLinkList doubLinkList;

	do{
		cout << "Doubly Linked List Menu:" << endl;
		cout << "1. Find Data In List." << endl;
		cout << "2. Insert Data Into List" << endl;
		cout << "3. Delete Data From List" << endl;
		cout << "4. Exit." << endl;
		cout << "\nPlease Enter Your Choice --> " << endl;
		cin >> choice;

		switch (choice){
		case 1:
			cout << "Enter the data you would like to find --> " << endl;
			cin >> data;
			doubLinkList.findNode(data);
			cout << endl;
			break;
		case 2:
			cout << "Enter the data you would like to insert --> " << endl;
			cin >> data;
			cout << "Enter the index you would like to add it at --> " << endl;
			cin >> index;
			doubLinkList.insertNode(index, data);
			cout << endl;
			break;
		case 3:
			cout << "Enter the data you would like to delete --> " << endl;
			cin >> data;
			doubLinkList.delNode(data);
			cout << endl;
			break;
		case 4:
			exit(1);
		default:
			cout << "That is not a valid choice." << endl;
		}
	} while (choice != 4);

	return 0;
}

Node* DoubLinkList::insertNode(int index, int data) {
	//checks if list is empty and returns NULL if empty list
	if (index < 0){
		cout << "This list is empty" << endl;
		return NULL;
	}

	int currIndex = 1;//initializes current indext to = 1

	Node* currNode = head;//creates node and makes it equal to head

	while (currNode && index > currIndex) {//loop runs as long as the current node and index are > than the current index
		currNode = currNode->next; //current node points to the next node
		currIndex++;	//adds one to index
	}
	if (index > 0 && currNode == NULL){// checks if list is empty
		cout << "This list is empty" << endl;
		return NULL;
	}

	//if list is not empty a new node is created
	Node* newNode = new	Node;
	newNode->data = data;	//data is stored in new node

	if (index == 0) { //if index = 0 then the new node is the head node
		newNode->next = head;
		head = newNode;
	}
	else {//otherwise insert node after the current node
		Node* currNode = head;	//set curr node = to head of list

		int i = 0;

		for (i = 0; i < index; i++){//runs loop as long adding one to i as long as i is < index
			currNode = currNode->next;	// curr node points to next node

			if (currNode == NULL){	//if curr node is NULL than the list does not have as many elements as the index would need
				cout << "There are less than " << index << " elements in this list." << endl;
				return 0;
			}
		}

		if (newNode->next == NULL){	//checks if the node after new node is null
			newNode->next = currNode;	//curr node is after new node
			currNode->next = NULL;	//curr node = NULL
			currNode->prev = tail; //node previoous to curr nodde is the tail
			tail = newNode;//tail = new node
		}
		else {//otherwise
			currNode->next = newNode->next;	//node after curr node = node after new node
			(currNode->next)->prev = currNode;	//node  prev to node after curr node = curr node
			newNode->next = currNode;	//node after newNode = curr node
			currNode->prev = newNode;	//node before curr node = new node
		}
	}
	return newNode;	//returns new node
}

int DoubLinkList::findNode(int data){
	Node* currNode = head;	//sets current node = to head

	int currIndex = 1;	//initializes current index to 1

	//loop runs through list as long as the  data stored in current node do not equal data searching for
	while (currNode && currNode->data != data) {
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode) return currIndex; //if data searching for is found, returns it's index
	return 0;

}

int DoubLinkList::delNode(int data) {
	Node* prevNode = NULL; //sets prev node to null
	Node* currNode = head; //sets current node = to head
	Node* lastNode = tail;

	int currIndex = 1;	//initializes current index to 1

	//loop runs through list as long as the  data stored in current node do not equal data searching for
	while (currNode && currNode->data != data) {
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode) { //if the current node stores the data searching for
		if (prevNode) {	//checks for prev node
			prevNode->next = currNode->next; //makes next node after prev now link to next node after current node
			delete currNode; //delets current node
		}
		else {//otherswise
			head = currNode->next;	//has head point to next node after curr node
			delete currNode;	//deletes curr node
		}
		return currIndex; //returns index of deleted node
	}
	return 0;
}
