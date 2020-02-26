/*//============================================================================
// Name        : Assignment4.cpp
// Author      : Sakshee Roll no : 23244
// Problem Statement : Construct and expression tree from postfix/prefix
                       expression and perform recursive and non- recursive 
					   In-order, pre-order and post-order traversals.
//============================================================================
*/
#include <iostream>
#include <stack>
using namespace std;
template <class T>
class Tnode {
	T data;
	Tnode *left;
	Tnode *right;
	template <class b>
	friend class ExpTree;
};

template <class T>
class ExpTree {

	Tnode<T> *Root;
	public :

		ExpTree() {
			Root = NULL;
		}
		int isEmpty() {
			return(Root==NULL);
		}
		Tnode<T>* create(string);
		void Preorder_rec(Tnode<T>*);
		void Inorder_rec(Tnode<T>*);
		void Postorder_rec(Tnode<T>*);
		void Inorder_it(Tnode<T>*);
		void Preorder_it(Tnode<T>*);
		void Postorder_it(Tnode<T>*);
		Tnode<T>* getroot();
		Tnode<T>* makenode(T);
	
};

template <class T>
Tnode<T>* ExpTree<T> :: getroot()
{
	return Root;
}

template <class T>
Tnode<T>* ExpTree<T> :: makenode(T d)
{
	Tnode<T> *newnode;
	newnode = new Tnode<T>();
	newnode->data = d;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

template <class T>
Tnode<T>* ExpTree<T> :: create(string str)
{
	int i;
	stack<Tnode<T>*> stk;
	Tnode<T> *temp = NULL;
	 
	while(str[i]!='\0') {
		
		temp = makenode(str[i]);
		
		if(isalnum(str[i]))
			stk.push(temp);
		else {
			temp->right = stk.top();
			stk.pop();
			temp->left = stk.top();
			stk.pop();
			stk.push(temp);
		}		
		i++;
	}
	Root = stk.top();
	return Root;
}

template <class T>
void ExpTree<T> :: Preorder_rec(Tnode<T> *root)
{
	if(root!=NULL) {
		cout << " " << root->data << " " ;
		Preorder_rec(root->left);
		Preorder_rec(root->right);
	}
	
}

template <class T>
void ExpTree<T> :: Inorder_rec(Tnode<T> *root)//inorder display
{
	Tnode<T> *temp=NULL;
	temp = root;
    //cout << root->data << "\t";
	if(temp!=NULL) {
		cout << "(";
		Inorder_rec(temp->left);
		cout << " " << temp->data << " "; //displays leaves inorderly
		Inorder_rec(temp->right);
		cout << ")";
	}
}

template <class T>
void ExpTree<T> :: Postorder_rec(Tnode<T> *root)//inorder display
{
	Tnode<T> *temp=NULL;
	temp = root;
    //cout << root->data << "\t";
	if(temp!=NULL) {
		Postorder_rec(temp->left);
		Postorder_rec(temp->right);
		cout << " " << temp->data << " "; //displays leaves inorderly
	}
}

template <class T>
void ExpTree<T> :: Inorder_it(Tnode<T> *root)
{
	stack<Tnode<T>*>s;
	while (root != NULL || s.empty()!=1) { 
        while (root !=  NULL) { 
            s.push(root); 
            root = root->left; 
        } 
        root = s.top(); 
        s.pop(); 
        cout << root->data << " "; 
        root = root->right; 
    } 
}

template <class T>
void ExpTree<T> :: Preorder_it(Tnode<T> *root)
{
    stack<Tnode<T>*>s;
	if (root == NULL) 
       return; 
    // Create an empty stack and push root to it 
    s.push(root); 
    while (!s.empty()) { 
        // Pop the top item from stack and print it 
        root = s.top(); 
        cout << root->data;
        root=s.top();
		s.pop(); 
        // Push right and left children of the popped node to stack 
        if (root->right) 
            s.push(root->right); 
        if (root->left) 
            s.push(root->right); 
    } 
}


template <class T>
void ExpTree<T> :: Postorder_it(Tnode<T> *root)
{
	stack<Tnode<T>*>s;
	Tnode<T> *temp=NULL;
    if (root == NULL) 
        return;   
     while (!s.empty()) {   // Move to leftmost node 
        while (root) { 
            // Push root's right child and then root to stack. 
            if (root->right) 
                s.push(root->right); 
            s.push(root); 
            root = root->left; 
        } 
        root = s.top(); 
        s.pop();
        if (root->right && s.top()==root->right) {   
		    temp=root;
            root=s.top();
			s.pop();  
            s.push(temp);  
		}
        else { 
            cout<<root->data;
            root = NULL; 
        } 
    }  
}


int main()
{
	Tnode<char> *c;
	ExpTree<char> tree;
	string exp;
	int choice,num,i;
	do {
	cout << "\n\tMENU\n1)Create expression tree\n2)Inorder recursive traversal\n3)Inorder non-recursive traversal\n"
	        "4)Preorder recursive traversal\n5)Preorder non-recursive traversal\n6)Postorder recursive traversal\n"
			"7)Postorder non-recursive traversal\n8)Exit\nEnter your choice : ";
	cin >> choice;
	switch(choice)
	{
		case 1 : cout << "\nEnter postfix expression : ";
			     cin >> exp;
			     c = tree.create(exp);
			     c = tree.getroot();
				 break;

		case 2 : cout << "\n\t\t";
				 cout << "Given expression tree in inorder traversal(Recursive) :-  ";
		         tree.Inorder_rec(tree.getroot());
			     break;
			     
		case 3 : cout << "\n\t\t";
				 cout << "Given expression tree in inorder traversal(Non-Recursive) :-  ";
		         tree.Inorder_it(tree.getroot());
			     break;
			     
		case 4 : cout << "\n\t\t";
				 cout << "Given expression tree in preorder traversal(Recursive) :-  ";
		         tree.Preorder_rec(tree.getroot());
			     break;
		
		case 5 : cout << "\n\t\t";
				 cout << "Given expression tree in preorder traversal(Non-Recursive) :-  ";
		         tree.Preorder_it(tree.getroot());
			     break;
			     
		case 6 : cout << "\n\t\t";
				 cout << "Given expression tree in postorder traversal(Recursive) :-  ";
		         tree.Postorder_rec(tree.getroot());
			     break;
			     
    	case 7 : cout << "\n\t\t";
				 cout << "Given expression tree in postorder traversal(Non-Recursive) :-  ";
		         tree.Preorder_it(tree.getroot());
			     break;
			     
		case 8 : return 0;
	}

	}while(1);

}
/*

        MENU
1)Create expression tree
2)Inorder recursive traversal
3)Inorder non-recursive traversal
4)Preorder recursive traversal
5)Preorder non-recursive traversal
6)Postorder recursive traversal
7)Postorder non-recursive traversal
8)Exit
Enter your choice : 1

Enter postfix expression : ab+cd-*

        MENU
1)Create expression tree
2)Inorder recursive traversal
3)Inorder non-recursive traversal
4)Preorder recursive traversal
5)Preorder non-recursive traversal
6)Postorder recursive traversal
7)Postorder non-recursive traversal
8)Exit
Enter your choice : 2

                Given expression tree in inorder traversal(Recursive) :-  ((( a ) + ( b )) * (( c ) - ( d )))
        MENU
1)Create expression tree
2)Inorder recursive traversal
3)Inorder non-recursive traversal
4)Preorder recursive traversal
5)Preorder non-recursive traversal
6)Postorder recursive traversal
7)Postorder non-recursive traversal
8)Exit
Enter your choice : 3

                Given expression tree in inorder traversal(Non-Recursive) :-  a + b * c - d
        MENU
1)Create expression tree
2)Inorder recursive traversal
3)Inorder non-recursive traversal
4)Preorder recursive traversal
5)Preorder non-recursive traversal
6)Postorder recursive traversal
7)Postorder non-recursive traversal
8)Exit
Enter your choice : 4

                Given expression tree in preorder traversal(Recursive) :-   *  +  a  b  -  c  d
        MENU
1)Create expression tree
2)Inorder recursive traversal
3)Inorder non-recursive traversal
4)Preorder recursive traversal
5)Preorder non-recursive traversal
6)Postorder recursive traversal
7)Postorder non-recursive traversal
8)Exit
Enter your choice : 5

                Given expression tree in preorder traversal(Non-Recursive) :-  *  +  a  b  -  c  d
        MENU
1)Create expression tree
2)Inorder recursive traversal
3)Inorder non-recursive traversal
4)Preorder recursive traversal
5)Preorder non-recursive traversal
6)Postorder recursive traversal
7)Postorder non-recursive traversal
8)Exit
Enter your choice : 6

                Given expression tree in postorder traversal(Recursive) :-   a  b  +  c  d  -  *
        MENU
1)Create expression tree
2)Inorder recursive traversal
3)Inorder non-recursive traversal
4)Preorder recursive traversal
5)Preorder non-recursive traversal
6)Postorder recursive traversal
7)Postorder non-recursive traversal
8)Exit
Enter your choice : 7

                Given expression tree in postorder traversal(Non-Recursive) :-  a  b  +  c  d  -  *
        MENU
1)Create expression tree
2)Inorder recursive traversal
3)Inorder non-recursive traversal
4)Preorder recursive traversal
5)Preorder non-recursive traversal
6)Postorder recursive traversal
7)Postorder non-recursive traversal
8)Exit
Enter your choice : 8

--------------------------------
Process exited after 48.77 seconds with return value 0
Press any key to continue . . .
*/
