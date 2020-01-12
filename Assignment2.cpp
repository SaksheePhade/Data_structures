//============================================================================
// Name        : Assignment2.cpp
// Author      : Sakshee
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Pri_Queue.cpp"
#include "Pri_Queue.h"
using namespace std;

class Patient
{
	public :
	string name;
	int id;
	string disease;
	string phone;
	void displayP();
	int getPriority(string);
};

class Database
{
	Patient P;
	Pri_Queue<Patient> Q;
	public :
		void getData();
		void display();
		void serve_patient();
		//void getPriority();
};

void Patient :: displayP()
{
	cout << "\t\t==========================================================================" << endl;
	cout << endl << "\t\tNAME\t\tI.D.\t\tDISEASE\t\tPHONE NO." << endl;
	cout << "\t\t--------------------------------------------------------------------------" << endl;
	cout << "\t\t" << name << "\t\t" << id  << "\t\t" << disease << "\t\t" << phone << endl;
	cout << "\t\t--------------------------------------------------------------------------" << endl << endl;
}

void Database :: getData()
{
	cout << "\nEnter name : ";
	cin >> P.name;
	cout << "\nEnter id : ";
	cin >> P.id;
	cout << "\nEnter disease : ";
	cin >> P.disease;
	cout << "\nEnter phone no. : ";
	cin >> P.phone;
	Q.enqueue(P);
}

void Database :: display()
{
	cout << endl;
	cout << "\t\t=========================================================================" << endl;
	cout << "\t\tSR NO\t\tNAME\t\tI.D.\t\tDISEASE\t\tPHONE NO." << endl;
	cout << "\t\t-------------------------------------------------------------------------" << endl;
	Q.display();
	cout << "\t\t-------------------------------------------------------------------------" << endl << endl;	
}

void Database :: serve_patient()
{
	Q.dequeue().displayP();
	cout << "\t\nPatient is served.\n";
	Q.display();
}

int Patient :: getPriority(string dis)
{
	if(dis=="Cancer" || dis=="Rabies" || dis=="CardiacArrest") return 3;
	else if(dis=="Malaria" || dis=="Cholera" || dis=="Typhoid") return 2;
	else return 1;
}

int main()
{
	int n,i,choice;
	Database db;
	do{
	cout << "\n\tMENU:-\n1)Add record\n2)Display database\n3)Serve the patient according to priority\n4)Exit\nEnter your choice : ";
	cin >> choice;
	switch(choice)
	{
		case 1 : cout << "\nEnter no of patients : ";
				 cin >> n;
				 for(i=0; i<n; i++) {
					db.getData();
				 }
				 break;

		case 2 : db.display();
				 break;

		case 3 : db.serve_patient();
				 break;

		case 4 : return 0;

	}
     }while(1);
	return 0;
}
/*

        MENU:-
1)Add record
2)Display database
3)Serve the patient according to priority
4)Exit
Enter your choice : 1

Enter no of patients : 5

Enter name : AAA

Enter id : 1

Enter disease : CardiacArrest

Enter phone no. : 2222222222

Enter name : BBB

Enter id : 2

Enter disease : Fever

Enter phone no. : 8888888888

Enter name : CCC

Enter id : 3

Enter disease : Malaria

Enter phone no. : 4444444444

Enter name : DDD

Enter id : 4

Enter disease : Typhoid

Enter phone no. : 3333333333

Enter name : EEE

Enter id : 5

Enter disease : Cancer

Enter phone no. : 7777777777

        MENU:-
1)Add record
2)Display database
3)Serve the patient according to priority
4)Exit
Enter your choice : 2

                =========================================================================
                SR NO           NAME            I.D.            DISEASE         PHONE NO.
                -------------------------------------------------------------------------
                1               AAA             1               CardiacArrest           2222222222
                2               BBB             2               Fever           8888888888
                3               CCC             3               Malaria         4444444444
                4               DDD             4               Typhoid         3333333333
                5               EEE             5               Cancer          7777777777
                -------------------------------------------------------------------------


        MENU:-
1)Add record
2)Display database
3)Serve the patient according to priority
4)Exit
Enter your choice : 3
                ==========================================================================

                NAME            I.D.            DISEASE         PHONE NO.
                --------------------------------------------------------------------------
                AAA             1               CardiacArrest           2222222222
                --------------------------------------------------------------------------
Patient is served.
				--------------------------------------------------------------------------
                1               BBB             2               Fever           8888888888
                2               CCC             3               Malaria         4444444444
                3               DDD             4               Typhoid         3333333333
                4               EEE             5               Cancer          7777777777
				--------------------------------------------------------------------------
        MENU:-
1)Add record
2)Display database
3)Serve the patient according to priority
4)Exit
Enter your choice : 3
                ==========================================================================

                NAME            I.D.            DISEASE         PHONE NO.
                --------------------------------------------------------------------------
                EEE             5               Cancer          7777777777
                --------------------------------------------------------------------------
Patient is served.
				--------------------------------------------------------------------------
                1               BBB             2               Fever           8888888888
                2               CCC             3               Malaria         4444444444
                3               DDD             4               Typhoid         3333333333
                --------------------------------------------------------------------------
        MENU:-
1)Add record
2)Display database
3)Serve the patient according to priority
4)Exit
Enter your choice : 3
                ==========================================================================

                NAME            I.D.            DISEASE         PHONE NO.
                --------------------------------------------------------------------------
                CCC             3               Malaria         4444444444
                --------------------------------------------------------------------------
Patient is served.
				--------------------------------------------------------------------------
                1               BBB             2               Fever           8888888888
                2               DDD             4               Typhoid         3333333333
                --------------------------------------------------------------------------

        MENU:-
1)Add record
2)Display database
3)Serve the patient according to priority
4)Exit
Enter your choice : 2

                =========================================================================
                SR NO           NAME            I.D.            DISEASE         PHONE NO.
                -------------------------------------------------------------------------
                1               BBB             2               Fever           8888888888
                2               DDD             4               Typhoid         3333333333
                -------------------------------------------------------------------------


        MENU:-
1)Add record
2)Display database
3)Serve the patient according to priority
4)Exit
Enter your choice : 4

--------------------------------
Process exited after 158 seconds with return value 0
Press any key to continue . . .
*/



