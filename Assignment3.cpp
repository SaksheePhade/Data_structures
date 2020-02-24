/*//============================================================================
// Name        : Assignment3.cpp
// Author      : Sakshee Roll no : 23244
// Problem Statement : Create Binary tree and perform following operations:
						a. Insert
						b. Display
						c. Depth of a tree
						d. Display leaf-nodes
						e. Create a copy of a tree
//============================================================================
*/
#include <iostream>
using namespace std;

template <class T>
struct Tnode {
	T data;
	Tnode *left;
	Tnode *right;
};

template <class T>
class BinTree {

	Tnode<T> *Root;
	public :

		BinTree() {
			Root = NULL;
		}
		int isEmpty() {
			return(Root==NULL);
		}
		Tnode<T>* create();
		void displayLeaf(Tnode<T>*);
		Tnode<T>* getroot();
		int countLeaf(Tnode<T>*);
		int depthTree(Tnode<T>*);
		Tnode<T>* copyTree(Tnode<T>*);
		Tnode<T>* makenode();
		Tnode<T>* insert(Tnode<T>*);
		void displayCopy(Tnode<T>*);//member functions
};

template <class T>
Tnode<T>* BinTree<T> :: getroot()
{
	return Root;
}

template <class T>
Tnode<T>* BinTree<T> :: makenode()
{
	T x;
	Tnode<T> *newnode;
	newnode = new Tnode<T>();
	cout << "\nEnter data for node : " ;
    cin >> x;
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

template <class T>
Tnode<T>* BinTree<T> :: insert(Tnode<T>* root)
{
	int ch;
	T x;
	Tnode<T> *temp = NULL;
	if(root==NULL) { //if tree is empty, create its root
	     Root = makenode();
		 return Root;
	}
	else {
		temp = root;//insert the given node at any position
		cout << "\nInsertion at :-\n1)Left\n2)Right\nEnter your choice : ";
		cin >> ch;
		if(ch==1) {
			if(temp->left==NULL) {
				temp->left = makenode();
				return temp;
			}
			else {
				while(temp->left!=NULL) {
					temp = temp->left;
				}
				temp->left = makenode();
			}	
		}
		if(ch==2) {
			if(temp->right==NULL) {
				temp->right = makenode();
				return temp;
			}
			else {
				while(temp->right!=NULL) {
					temp = temp->right;
				}
				temp->right = makenode();
			}	
		}
	}
}

template <class T>
void BinTree<T> :: displayLeaf(Tnode<T> *root)//inorder display
{
	Tnode<T> *temp=NULL;
	temp = root;
    //cout << root->data << "\t";
	if(temp!=NULL) {
		displayLeaf(temp->left);
		cout << " " << temp->data << " "; //displays leaves inorderly
		displayLeaf(temp->right);
	}
}

template <class T>
int BinTree<T> :: countLeaf(Tnode<T> *root)
{
	if(root==NULL)
		return 0;
	else{
		if(root->left==NULL && root->right==NULL)
			return 1;
		else
			return(countLeaf(root->left)+countLeaf(root->right));
	}
}

template <class T>
int BinTree<T> :: depthTree(Tnode<T> *root)
{
	Tnode<T> *temp;
	int dtl,dtr;
	temp = root;
	if(temp==NULL)
		return 0;
	else {
		dtl = depthTree(temp->left)+1;
		dtr = depthTree(temp->right)+1;
	}
	if(dtl>dtr)
		return dtl;
	else
		return dtr;

}

template <class T>
Tnode<T>* BinTree<T> :: copyTree(Tnode<T> *root)
{
	Tnode<T> *temp=NULL;
	if(root!=NULL) {
		temp = new Tnode<T>;
		temp = root;
		temp->data = root->data;
		temp->left = copyTree(root->left);
		temp->right = copyTree(root->right);
	}
	return temp;
}

template <class T>
void BinTree<T> :: displayCopy(Tnode<T>* firstRoot)
{
	Root = copyTree(firstRoot);
	displayLeaf(Root);
}

int main()
{
	Tnode<int>* copyroot=NULL;
	BinTree<int> tree;
	BinTree<int> copy;
	int choice,num,i;
	do {
	cout << "\n\tMENU\n1)Create binary tree\n2)Display tree\n3)Count number of leaf nodes\n"
			"4)Depth of the tree\n5)Copy binary tree.\n6)Exit\nEnter your choice : ";
	cin >> choice;
	switch(choice)
	{
		case 1 : cout << "\nHow many nodes do you want to add ? ";
			     cin >> num;
			     for(i=0;i<num;i++) 
				 	tree.insert(tree.getroot());
				 break;

		case 2 : cout << "\n\t\t";
				 cout << "Given binary tree :-  ";
		         tree.displayLeaf(tree.getroot());
			     break;

		case 3 : cout << "\n\t\tNumber of leaves in given tree are : " << tree.countLeaf(tree.getroot()) << endl;
				 break;

		case 4 : cout << "\n\t\tDepth of the tree is : " << tree.depthTree(tree.getroot()) - 1 <<endl;
				 break;

		case 5 : copyroot = copy.getroot();
				 copyroot = tree.copyTree(tree.getroot());
				 cout << "\n\t\tGiven tree is copied into another tree.";
				 cout << "\n\t\tThe copied tree is :-  ";
				 copy.displayCopy(tree.getroot());
				 break;

		case 6 : return 0;
	}

	}while(1);

}
/*


        MENU
1)Create binary tree
2)Display tree
3)Count number of leaf nodes
4)Depth of the tree
5)Copy binary tree.
6)Exit
Enter your choice : 1

How many nodes do you want to add ?
4

Enter data for node : 1

Insertion at :-
1)Left
2)Right
Enter your choice : 1

Enter data for node : 2

Insertion at :-
1)Left
2)Right
Enter your choice : 2

Enter data for node : 3

Insertion at :-
1)Left
2)Right
Enter your choice : 1

Enter data for node : 4

        MENU
1)Create binary tree
2)Display tree
3)Count number of leaf nodes
4)Depth of the tree
5)Copy binary tree.
6)Exit
Enter your choice : 2

                Given binary tree :-   4  2  1  3
        MENU
1)Create binary tree
2)Display tree
3)Count number of leaf nodes
4)Depth of the tree
5)Copy binary tree.
6)Exit
Enter your choice : 3

                Number of leaves in given tree are : 2

        MENU
1)Create binary tree
2)Display tree
3)Count number of leaf nodes
4)Depth of the tree
5)Copy binary tree.
6)Exit
Enter your choice : 4

                Depth of the tree is : 2

        MENU
1)Create binary tree
2)Display tree
3)Count number of leaf nodes
4)Depth of the tree
5)Copy binary tree.
6)Exit
Enter your choice : 1

How many nodes do you want to add ? 1

Insertion at :-
1)Left
2)Right
Enter your choice : 2

Enter data for node : 5

        MENU
1)Create binary tree
2)Display tree
3)Count number of leaf nodes
4)Depth of the tree
5)Copy binary tree.
6)Exit
Enter your choice : 5

                Given tree is copied into another tree.
                The copied tree is :-   4  2  1  3  5
        MENU
1)Create binary tree
2)Display tree
3)Count number of leaf nodes
4)Depth of the tree
5)Copy binary tree.
6)Exit
Enter your choice : 6

*/


