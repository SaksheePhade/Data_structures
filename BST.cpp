#include "BST.h"
#include <bits/stdc++.h>
using namespace std;

template <class T>
BST<T>::BST() {
	root = NULL;
}

template <class T>
BST<T>::~BST() {

}

// Non-Recursion Private Functions
template <class T>
void BST<T> :: inorder(){					// DONE
	stack<Node<T>*> s;
	Node<T>* curr = root; 

    while (curr != NULL || s.empty() == false) { 
        while (curr !=  NULL){ 
            s.push(curr); 
            curr = curr->left; 
        } 
 
        curr = s.top(); 
        s.pop(); 

        cout << curr->data << " "; 
        curr = curr->right;  
    }
}

template <class T>
void BST<T> :: preorder() {
	Node<T>* q = root;
	stack<Node<T>*> s;
	while (true) {
		while (q != NULL) {
			cout << q -> data << " ";
			s.push(q);
			q = q->left;
		}
		
		if (s.empty()) {
			return;
		}
		
		q = s.top();
		s.pop();
		q = q->right;
	}
}

template <class T>
Node<T>* BST<T> :: deleteR(Node<T>* q, T data) {

    if (q == NULL) return root; 

    if (data < q->data) 
        q->left = deleteR(q->left, data); 
 
    else if (data > q->data) 
        q->right = deleteR(q->right, data); 
  
    else
    { 
        if (q->left == NULL) 
        { 
            Node<T> *temp = q->right; 
            free(q); 
            return temp; 
        } 
        else if (q->right == NULL) 
        { 
            Node<T> *temp = q->left; 
            free(q); 
            return temp; 
        } 
  
        Node<T>* temp = minValueNode(q->right); 
  
        // Copy the inorder successor's content to this node 
        q->data = temp->data; 
  
        // Delete the inorder successor 
        q->right = deleteR(q->right, temp->data); 
    } 
    return q; 
}

template <class T>
Node<T>* BST<T> :: minValueNode(Node<T>* node){ 
    Node<T>* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

template <class T>
void BST<T> :: postorder() {
	Node<T>* q = root;
	stack<Node<T>*> s;

	while(true){
		while(q != NULL){
			s.push(q);
			s.push(q);
			q = q -> left;
		}

		if(s.empty()) return;
		q = s.top();
		s.pop();

		if(!s.empty() && s.top() == q)
			q = q -> right;
		else{
			cout << q -> data << " ";
			q = NULL;
		}
	}
}

template <class T>
void BST<T> :: levelorder() {									// DONE
	int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i); 
}

template <class T>
void BST<T> :: printGivenLevel(Node<T>* q, int level) { 		// DONE
	if (q == NULL)  
        return;  
    if (level == 1)  
        cout << q->data << " ";
    else if (level > 1)  	
    {  
        printGivenLevel(q->left, level-1);  
        printGivenLevel(q->right, level-1);
    }
}

template <class T>
int BST<T> :: height(Node<T>* q) {						// DONE
	if (q == NULL)  
        return 0;  
    else{  
        int lheight = height(q->left);  
        int rheight = height(q->right);  

        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
}

template <class T>
void BST<T> :: mirrorR(Node<T>* node){
	if (node == NULL)  
        return;  
    else
    { 
        Node<T>* temp; 
          
        mirrorR(node->left); 
        mirrorR(node->right); 

        temp     = node->left; 
        node->left = node->right; 
        node->right = temp; 
    }
    root = node;
}

// Non-Recursion Public Functions
template <class T>
void BST<T> :: insert(T data) { 					// DONE
	Node<T> *temp = new Node<T>;
	temp -> data = data;
	if(root == NULL){
		root = temp;
		cout << "\n" << data << " has been Set as Root Node";
		return;
	}
	Node<T> *p=root;
	while(true){
		if(p -> data > temp -> data)
			if(p->left == NULL){
				p->left = temp;
				cout << "\n" << data << " Inserted";
				return;
			}
			else
				p = p -> left;
		else if(p->data < temp -> data)
			if(p->right == NULL){
				p->right = temp;
				cout<< "\n" << data <<" Inserted";
				return;
			}
			else
				p = p->right;
		else{
			cout<<"\n"<<data<<" already exists in BST";
			return;
		}
	}
} 

template <class T>								// DONE
void BST<T> :: create(){						// create tree //
	int n, var;
	cout << "How many elements you want to enter: ";
	cin >> n;
	for(int i=0; i<n; i++){
		cout << "\nEnter the value of Node: "; 
		cin >> var;
		insert(var);
	}
}

template <class T>									// DONE
void BST<T> :: search(T data){						// search the element in tree //
	int depth = 0;
	Node<T>* temp = root;
	
	while(temp != NULL){
		depth++;
		if(temp->data == data){
			cout<<"\nData found at depth: "<<depth << "\n";
			return;
		}
		
		else if(temp->data > data)
			temp = temp->left;
		else
			temp = temp->right;
	}
 
	cout<<"\nData not found\n";
	return;
}

template <class T>
void BST<T> :: disleafs(){							// DONE
	cout << "\n1) Inorder Display";
	cout << "\n2) Preorder Display";
	cout << "\n3) Postorder Display";
	cout << "\n4) Levelorder Display";
	cout << "\n Enter Choice: ";
	int val;
	cin >> val;

	switch(val){
		case 1:
			cout << "\nInorder: ";
			inorder();
			break;
		case 2: 
			cout << "\nPreorder: ";
			preorder(); 
			break;
		case 3:
			cout << "\nPostorder: ";
			postorder(); 
			break;
		case 4:
			cout << "\nLevelorder: ";
			levelorder(); 
			break;	
		default:
			cout << "Enter Valid Number";
	}
}

template <class T>
void BST<T> :: deleteNode(T val){
	deleteR(root, val);
}

template <class T>
void BST<T> :: mirror(){
	mirrorR(root);
	cout << "\nInorder: ";
	inorder();
}