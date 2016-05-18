#include<iostream>
#include<fstream>
using namespace std;

template <typename TN>
struct node{
	TN data;
	node* right;
	node* left;
};
template <typename T>
class Tree{
	private:
		node<T>* root;
	public:
		Tree();
		node<T>* createNode(T nodeData);
		void append(T nodeData);
		node<T>* append(node<T>* ptr, T nodeData);
		void deleteNode(T d);
		void deleteNode(node<T>*& ptr, T d);
		void disInOrder();
		void disInOrder(node<T>* ptr);
		void disPreOrder();
		void disPreOrder(node<T>* ptr);
		void disPostOrder();
		void disPostOrder(node<T>* ptr);
		T minimumValue();
		T minimumValue(node<T>* ptr);
		T maximumValue();
		T maximumValue(node<T>* ptr);
};
template <typename T>
Tree<T>::Tree(){
	root = NULL;
}
template <typename T>
node<T>* Tree<T>::createNode(T nodeData){
	node<T> *newNode= new node<T>;
	newNode->data = nodeData;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}
template <typename T>
void Tree<T>::append(T newData){
	root = append(root,newData);
}
template <typename T>
node<T>* Tree<T>::append(node<T>* ptr, T nodeData){
	
	if(ptr == NULL){
		node<T> *newNode = createNode(nodeData);	
		return newNode;
	}
	if(ptr->data > nodeData){
		ptr->left = append(ptr->left,nodeData);
	}
	else if(ptr->data < nodeData){
		ptr->right = append(ptr->right,nodeData);
	}
	return ptr;
}
/* left - root - right */
template <typename T>
void Tree<T>::disInOrder(node<T>* ptr){
	if(ptr == NULL){
		return;
	}
	disInOrder(ptr->left);
	cout << ptr->data << " ";
	disInOrder(ptr->right);
}

template <typename T>
void Tree<T>::disInOrder(){
	if (root == NULL){
		return;
	}
	disInOrder(root);
	cout << endl;
}
/*root - left - right */
template <typename T>
void Tree<T>::disPreOrder(node<T>* ptr){
	if(ptr == NULL){
		return;
	}
	cout << ptr->data << " ";
	disPreOrder(ptr->left);
	disPreOrder(ptr->right);
}

template <typename T>
void Tree<T>::disPreOrder(){
	if (root == NULL){
		return;
	}
	disPreOrder(root);
	cout << endl;
}
/* left - right - root */
template <typename T>
void Tree<T>::disPostOrder(node<T>* ptr){
	if(ptr == NULL){
		return;
	}
	disPostOrder(ptr->left);
	disPostOrder(ptr->right);
	cout << ptr->data << " ";
}
template <typename T>
void Tree<T>::disPostOrder(){
	if (root == NULL){
		return;
	}
	disPostOrder(root);
	cout << endl;
}

template <typename T>
T Tree<T>::minimumValue(node<T>* ptr){
	if(ptr->left == NULL){
		return ptr->data;
	}
	minimumValue(ptr->left);
}
template <typename T>
T Tree<T>::minimumValue(){
	if (root == NULL){
		return NULL;
	}
	return minimumValue(root);
}

template <typename T>
T Tree<T>::maximumValue(node<T>* ptr){
	if(ptr->right == NULL){
		return ptr->data;
	}
	maximumValue(ptr->right);
}
template <typename T>
T Tree<T>::maximumValue(){
	if (root == NULL){
		return NULL;
	}
	return maximumValue(root);
}

template <typename T>
void Tree<T>::deleteNode(T d){
	if(root == NULL) {
		return;
	}
	deleteNode(root,d);
}

template <typename T>
void Tree<T>::deleteNode(node<T>*& ptr, T d){
	if(ptr->data == d){
		if(ptr->left == NULL && ptr->right == NULL) {
			node<T>* p = ptr;
			ptr = NULL;
			delete p;
		}
		else if( ptr->left == NULL) {
			node<T>* p = ptr;
			ptr = ptr->right;
			delete p;
		}
		else if( ptr->right == NULL) {
			node<T>* p = ptr;
			ptr = ptr->left;
			delete p;
		}
		else {
			int x = minimumValue(ptr->right);
			deleteNode(ptr->right,x);
			ptr->data = x;
		}
	}
	else if(ptr->data > d){
		deleteNode(ptr->left,d);
	}
	else if(ptr->data < d){
		deleteNode(ptr->right,d);
	}
}

int main(){
	Tree<int> t;
	t.append(5);
	t.append(2);
	t.append(-4);
	t.append(3);
	t.append(12);
	t.append(9);
	t.append(21);
	t.append(19);
	t.append(25);
	t.deleteNode(12);
	t.disInOrder();
	t.disPreOrder();
	t.disPostOrder();
	cout << t.minimumValue() << endl;
	cout << t.maximumValue() << endl;
}
