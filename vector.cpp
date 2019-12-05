#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> myVector;
	int i;
	for(i=0;i<5;i++){
		myVector.push_back(i);
	}
	cout << "\nVector : ";
	for(i=0;i<myVector.size();i++){
		cout << myVector.at(i) << " ";
	}
	myVector.insert(myVector.begin()+1,77);
	cout << endl;
	for(i=0;i<myVector.size();i++){
		cout << myVector.at(i) << " ";
	}
	cout << endl;
	myVector.erase(myVector.begin());
	for(i=0;i<myVector.size();i++){
		cout << myVector.at(i) << " ";
	}
	cout << "\nMAX : " << std :: *max_element (myVector.begin(),myVector.end());
	return 0;
}
