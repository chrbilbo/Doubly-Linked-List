//http://cplusplus.happycodings.com/data-structures/code26.html


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

	void findData(int foundData);
	void insertData(int newData);
	void deleteNode(int delData);
private:
	Node* head;
	Node* tail;
};

/*void DoubLinkList::findData(int foundData){
	bool found = false;

	//checks if list is empty
	if (head == NULL && tail == NULL){
		cout << "There is no data in this list." << endl;
		return;
	}
	else{//if list is not empty curr node is the head node
		Node* curr;
		curr = head;

		while (curr != NULL){
			if (curr->data = foundData){
				found = true;
			}
			else if(foundData < curr->data && curr->next == tail->next){
				cout << "The data you are looking for is not found in this list" << endl;
				return;
			}
		}
	}

}

void DoubLinkList::insertData(int newData){
	//checks if the list is empty
	if (head == NULL && tail == NULL){

		Node* temp = new Node;	//if list is empty, inserts data into new node
		temp->next = NULL;
		temp->prev = NULL;
		temp->data = newData;
	}
	else{	//if the list is not empty, the curr node is the head node
		Node* curr;
		curr = head;

		//loop runs as long as the new data is greater than the data in the curr node and the next node is not the tail
		while (newData > curr->data && curr->next != tail->next){
			curr = curr->next;

			//checks if curr node is equal to the head node
			if (curr == head){

				Node* temp = new Node;	//if data is equal, a new temp node is made  
				temp->data = newData;	//the data is stored in that node 
				temp->prev = curr;
				temp->next = NULL;	
				head->next = temp;	
				tail = temp;	//data is stored after the first element
			}
			//checks if curr node is equal to the tail node and data to be inserted is greater than the data in tail node
			else if(curr == tail && newData > tail->data){
				tail->next = new Node;	//new node is created for new data
				(tail->next)->prev = tail;
				tail = tail->next;
				tail = NULL;
				tail->data = newData; //new data is inserted at the end of the list
			}
			else {
				Node* temp = new Node;	//new temp node is created
				temp->data = newData;	//new data is stored in that temp node
				temp->next = curr;	//curr node is the next node
				(curr->prev)->next = temp;	//the curr node becomes the next node instead of previous node
				temp->prev = curr->prev;	
				curr->prev = temp;	//data is stored before the curr element
			}
		}
	}
}

void DoubLinkList::deleteNode(int delData){
	bool found = false;

	//checks if list is empty
	if (head == NULL && tail == NULL){
		cout << "There is no data in this list." << endl;
		return;
	}
	else{//if list is not empty curr node is the head node
		Node* curr;
		curr = head;

		while (delData > curr->data && curr->next != tail->next){
			if (curr->data = delData){
				found = true;
			}
			else if (delData < curr->data && curr->next == tail->next){
				cout << "The data you are looking for is not found in this list" << endl;
				return;
			}
		}
	}
}*/

void DoubLinkList::insertData( int data)
{
	Node* curr;
	curr = head;
	/* Iterate through the list till we encounter the last node.*/
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	/* Allocate memory for the new node and put data in it.*/
	curr->next = (Node*)malloc(sizeof(node));
	(curr->next)->prev = pointer;
	curr = curr->next;
	curr->data = data;
	curr->next = NULL;
}
int find(node *pointer, int key)
{
	pointer = pointer->next; //First node is dummy node.
	/* Iterate through the entire linked list and search for the key. */
	while (pointer != NULL)
	{
		if (pointer->data == key) //key is found.
		{
			return 1;
		}
		pointer = pointer->next;//Search in the next node.
	}
	/*Key is not found */
	return 0;
}*/
void delete(node *pointer, int data)
{
	/* Go to the node for which the node next to it has to be deleted */
	while (pointer->next != NULL && (pointer->next)->data != data)
	{
		pointer = pointer->next;
	}
	if (pointer->next == NULL)
	{
		printf("Element %d is not present in the list\n", data);
		return;
	}
	/* Now pointer points to a node and the node next to it has to be removed */
	node *temp;
	temp = pointer->next;
	/*temp points to the node which has to be removed*/
	pointer->next = temp->next;
	temp->prev = pointer;
	/*We removed the node which is next to the pointer (which is also temp) */
	free(temp);
	/* Beacuse we deleted the node, we no longer require the memory used for it .
	free() will deallocate the memory.
	*/
	return;
}