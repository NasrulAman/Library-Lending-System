#include <iostream>
#include <string>
#include <ostream>//to access files
#include <fstream>//to access files
#include "Lending.h"
using namespace std;

int main() {
	Lending len;
	BookLend* lendAbook=NULL;
	string bookID;
	string memberID;
	string choice;
	string overDue;
	int list_choice;
	int menu;
	int infoChoice;
	int loanDay;
	int loanMonth;
	int loanYear;
	int dueDay;
	int dueMonth;
	int dueYear;
	int returnDay;
	int returnMonth;
	int returnYear;
	char slash_dummy;
		
	//MENU
	do{
	cout<<"\t\t\t\t"">>>>>>>>> WELCOME TO LIBRARY'S LENDING SYSTEM <<<<<<<<<"<<endl;
	cout<<"\t\t\t\t""(1)View List"<<endl;
	cout<<"\t\t\t\t""(2)Add an info"<<endl;
	cout<<"\t\t\t\t""(3)Delete an info"<<endl;
	cout<<"\t\t\t\t""(4)Search the list"<<endl;
	cout<<"\t\t\t\t""(5)Edit the list"<<endl;
	cout<<"\t\t\t\t""(6)Print lending list to text file"<<endl;
	cout<<"\t\t\t\t""(0)Exit"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t""Choose an option:";
	cin>>menu;
	cout<<endl;
	
	if(menu==1){
	system("CLS"); //Clears the terminal
	cout<<"\t\t\t\t"">>>>>>>>> List of Lend Books <<<<<<<<<"<<endl;
	len.setNode(lendAbook);
	len.printLendList();
}

else if(menu==2){
		do{
		system("CLS");
		cout<<"\t\t\t\t"">>>>>>>>> Add an info <<<<<<<<<"<<endl;		
		cin.ignore();
		cout<<"\t\t\t\t""Enter Book ID:";
		getline(cin, bookID);
		len.setBookID(bookID);

		cout<<"\t\t\t\t""Enter member ID:";
		getline(cin, memberID);
		len.setMemberID(memberID);

		while(true){
		cout<<"\t\t\t\t""Enter loan date(DD/MM/YYYY):";
		cin>>loanDay>>slash_dummy>>loanMonth>>slash_dummy>>loanYear;
		len.setLoanDay(loanDay);
		len.setLoanMonth(loanMonth);
		len.setLoanYear(loanYear);
		
		if(loanDay>31 || loanMonth>12){
			cout<<"\t\t\t\t""Invalid day and/or month!"<<endl;
			continue; 
		}
		break;
	}

		while(true){
		cout<<"\t\t\t\t""Enter due date(DD/MM/YYYY):";
		cin>>dueDay>>slash_dummy>>dueMonth>>slash_dummy>>dueYear;
		len.setDueDay(dueDay);
		len.setDueMonth(dueMonth);
		len.setDueYear(dueYear);
		
		if(dueDay>31 || dueMonth>12){
			cout<<"\t\t\t\t""Invalid day and/or month!"<<endl;
			continue;
		}
		break;
	}
	
		while(true){
		cout<<"\t\t\t\t""Enter return date(DD/MM/YYYY):";
		cin>>returnDay>>slash_dummy>>returnMonth>>slash_dummy>>returnYear;
		len.setReturnDay(returnDay);
		len.setReturnMonth(returnMonth);
		len.setReturnYear(returnYear);
		
		if(returnDay>31 || returnMonth>12){
			cout<<"\t\t\t\t""Invalid day and/or month!"<<endl;
			continue;
		}
		break;
	}
	
		//Error handling

		//Invalid due date check
		if(loanYear>dueYear){
			cout<<"\t\t\t\t""Invalid due date!";
			return 0;
		}
		else if(loanYear>=dueYear&&loanMonth>dueMonth){
			cout<<"\t\t\t\t""Invalid due date!";
			return 0;			
		}
		else if(loanMonth>=dueMonth&&loanDay>dueDay){
			cout<<"\t\t\t\t""Invalid due date!";
			return 0;		
		}

		len.setHead(&lendAbook); //passing the address of pointer;
		len.addLend();
		len.setNode(lendAbook);//passing the pointer
		cin.ignore();
		cout<<"\t\t\t\t""Do you want to add a new lending info?(y/n):";
		getline(cin,choice);
		cout<<endl;
	}
	while(choice=="Y"||choice=="y");
}

//Delete
else if(menu==3){
	cout<<"\t\t\t\t"">>>>>>>>> Delete an info <<<<<<<<<"<<endl;
	system("CLS");
	cout<<"\t\t\t\t"">>>>>>>>> List of Lend Books <<<<<<<<<"<<endl;
	len.setNode(lendAbook);
	len.printLendList();
	
	cout<<"\t\t\t\t""Enter the number to remove (0 to Exit):";
	cin>>list_choice;
	if(list_choice==0){
		return 0;
	}
	len.setLendNumber(list_choice);
	len.setHead(&lendAbook);
	len.removeLend();
	
	cout<<endl;
	cout<<"\t\t\t\t"">>>>>>>>> List of Lend Books <<<<<<<<<<"<<endl;
	len.setNode(lendAbook);
	len.printLendList();
}

//Searching
else if(menu==4){
	system("CLS");
	cout<<"\t\t\t\t"">>>>>>>>> Search <<<<<<<<<"<<endl;
	cout<<"\t\t\t\t""Enter BookID or MemberID:";
	cin>>choice;
	len.setChoice(choice);
	len.setHead(&lendAbook);
	len.searchLend();
}

//Editing
else if(menu==5){
	system("CLS");
	cout<<"\t\t\t\t"">>>>>>>>> Editing an info <<<<<<<<<"<<endl;
	cout<<"\t\t\t\t""Enter Book ID or MemberID to edit:";
	cin>>choice;
	len.setChoice(choice);

	cout<<endl;
	cout<<"\t\t\t\t""1.Book ID"<<endl;
	cout<<"\t\t\t\t""2.Member ID"<<endl;
	cout<<"\t\t\t\t""3.Loan Date"<<endl;
	cout<<"\t\t\t\t""4.Due Date"<<endl;
	cout<<"\t\t\t\t""5.Return Date"<<endl;
	cout<<"\t\t\t\t""Enter info number to edit (0 to Exit):";

	cin>>infoChoice;

	if(infoChoice==0){
		return 0;
	}
	len.setInfoChoice(infoChoice);
	cin.ignore();

	len.setNode(lendAbook);
	if(infoChoice==1){
		cout<<"\t\t\t\t""Enter new book ID:";
		getline(cin, bookID);
		len.setBookID(bookID);
	}
	else if(infoChoice==2){
		cout<<"\t\t\t\t""Enter new member ID:";
		getline(cin, memberID);
		len.setMemberID(memberID);
	}
	else if(infoChoice==3){
		cout<<"\t\t\t\t""Enter new loan date(DD/MM/YYYY):";
		cin>>loanDay>>slash_dummy>>loanMonth>>slash_dummy>>loanYear;
		len.setLoanDay(loanDay);
		len.setLoanMonth(loanMonth);
		len.setLoanYear(loanYear);
	}
	else if(infoChoice==4){

		cout<<"\t\t\t\t""Enter new due date(DD/MM/YYYY):";
		cin>>dueDay>>slash_dummy>>dueMonth>>slash_dummy>>dueYear;
		len.setDueDay(dueDay);
		len.setDueMonth(dueMonth);
		len.setDueYear(dueYear);
	}
	else if(infoChoice==5){
		cout<<"\t\t\t\t""Enter new return date:";
		cin>>returnDay>>slash_dummy>>returnMonth>>slash_dummy>>returnYear;
		len.setReturnDay(returnDay);
		len.setReturnMonth(returnMonth);
		len.setReturnYear(returnYear);
	}
		len.editLend();
}

//Printing
else if(menu==6){
	system("CLS");
	ofstream ofs("list of lending info.txt");
	len.printTofile(ofs);
	cout<<"\t\t\t\t"">>>>>>>>> Printed Sucessfully <<<<<<<<<"<<endl;
}
}
while(menu!=0);

	return 0;
}
