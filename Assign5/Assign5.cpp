
/*
=========================================================================
Assignment : BINARY SEARCH TREE
Name : 23244
class : SE 10
Batch : G 10
Problem Statement:
	Implement binary search tree and perform following operations:
		a. Insert
		b. Delete
		c. Search
		d. Mirror image
		e. Display
		f. Display level wise
=========================================================================
*/

#include <iostream>
#include "BST.cpp"

using namespace std;

void menu(){
	cout << "\nMENU";
	cout << "\n1) Create The Tree";
	cout << "\n2) Insert a single Node";
	cout << "\n3) Delete a Node From tree";
	cout << "\n4) Display leaf Node of the Tree";
	cout << "\n5) Create a mirror Image of the tree";
	cout << "\n6) Search a element in Tree";
	cout << "\n7) Exit";
	cout << "\nEnter Choice: ";
}

int main() {

	BST<int> bst;
	int ch, val;
	bool enter = true;
	
	while(enter){
		menu();
		cin >> ch;
		switch(ch){
			case 1:
				bst.create();
				break;
			case 2: 
				cout << "Enter Value to be inserted: ";
				cin >> val;
				bst.insert(val);
				break;
			case 3: 
				cout << "Enter Value to be deleted: ";
				cin >> val;
				bst.deleteNode(val);
				cout << val << " DELETED SUCCESSFULLY";
				break;
			case 4: 
				bst.disleafs();
				break;
			case 5: 
				cout << "\nMirror Image of Tree: \n";
				bst.mirror();
				break;
			case 6:
				cout << "\nEnter element to be searched: ";
				cin >> val;
				bst.search(val);
				break;
			case 7: 
				enter = false;
				break;			
			default: 
				cout << "Enter Valid choice: ";
		}
	}	
	return 0;
}

/*
OUTPUT: 
MENU :
1) Create The Tree
2) Insert a single Node
3) Delete a Node From tree
4) Display leaf Node of the Tree
5) Create a mirror Image of the tree
6) Search a element in Tree
7) Exit
Enter Choice: 1
How many elements you want to enter: 5
Enter the value of Node: 12
12 has been Set as Root Node
Enter the value of Node: 23
23 Inserted
Enter the value of Node: 65
65 Inserted
Enter the value of Node: 34
34 Inserted
Enter the value of Node: 4 
4 Inserted
MENU :
1) Create The Tree
2) Insert a single Node
3) Delete a Node From tree
4) Display leaf Node of the Tree
5) Create a mirror Image of the tree
6) Search a element in Tree
7) Exit
Enter Choice: 2
Enter Value to be inserted: 6
6 Inserted
MENU :
1) Create The Tree
2) Insert a single Node
3) Delete a Node From tree
4) Display leaf Node of the Tree
5) Create a mirror Image of the tree
6) Search a element in Tree
7) Exit
Enter Choice: 3
Enter Value to be deleted: 65
65 DELETED SUCCESSFULLY
MENU :
1) Create The Tree
2) Insert a single Node
3) Delete a Node From tree
4) Display leaf Node of the Tree
5) Create a mirror Image of the tree
6) Search a element in Tree
7) Exit
Enter Choice: 4
1) Inorder Display
2) Preorder Display
3) Postorder Display
4) Levelorder Display
 Enter Choice: 1
Inorder: 4 6 12 23 34 
Preorder: 12 4 6 23 34 
Postorder: 6 4 34 23 12 
Levelorder: 12 4 23 6 34 
MENU :
1) Create The Tree
2) Insert a single Node
3) Delete a Node From tree
4) Display leaf Node of the Tree
5) Create a mirror Image of the tree
6) Search a element in Tree
7) Exit
Enter Choice: 5
Mirror Image of Tree: 
Inorder: 34 23 12 6 4 
MENU :
1) Create The Tree
2) Insert a single Node
3) Delete a Node From tree
4) Display leaf Node of the Tree
5) Create a mirror Image of the tree
6) Search a element in Tree
7) Exit
Enter Choice: 6
Enter element to be searched: 2
Data not found
Enter element to be searched: 34
Data found at the depth of: 4
MENU :
1) Create The Tree
2) Insert a single Node
3) Delete a Node From tree
4) Display leaf Node of the Tree
5) Create a mirror Image of the tree
6) Search a element in Tree
7) Exit
Enter Choice: 7
*/
