#include "Lending.h"
#include <iostream>
#include <ostream> //to access files

//SETS

void Lending::setLendNumber(int LendNumber){
	lendNumber=LendNumber;
}

void Lending::setInfoChoice(int InfoChoice){
	infoChoice=InfoChoice;
}

void Lending::setBookID(string bookID){
	BookID=bookID;
}

void Lending::setMemberID(string memberID){
	MemberID=memberID;
}

void Lending::setChoice(string choice){
	Choice=choice;
}

void Lending::setOverDue(string overDue){
	OverDue=overDue;
}

void Lending::setHead(BookLend** Head){
	head=Head;
}

void Lending::setNode(BookLend* Node){
	node=Node;
}

void Lending::setLoanDay(int loanDay){
	LoanDay=loanDay;
}

void Lending::setLoanMonth(int loanMonth){
	LoanMonth=loanMonth;
}

void Lending::setLoanYear(int loanYear){
	LoanYear=loanYear;
}

void Lending::setDueDay(int dueDay){
	DueDay=dueDay;
}

void Lending::setDueMonth(int dueMonth){
	DueMonth=dueMonth;
}

void Lending::setDueYear(int dueYear){
	DueYear=dueYear;
}

void Lending::setReturnDay(int returnDay){
	ReturnDay=returnDay;
}

void Lending::setReturnMonth(int returnMonth){
	ReturnMonth=returnMonth;
}

void Lending::setReturnYear(int returnYear){
	ReturnYear=returnYear;
}

//GETS

int Lending::getLendNumber(){
	return lendNumber;
}

int Lending::getInfoChoice(){
return infoChoice;	
}

string Lending::getBookID(){
	return BookID;
}

string Lending::getMemberID(){
	return MemberID;
}

string Lending::getChoice(){
	return Choice;
}

string Lending::getOverDue(){
	return OverDue;
}

BookLend** Lending::getHead(){
	return head;
}

BookLend* Lending::getNode(){
	return node;
}

int Lending::getLoanDay(){
	return LoanDay;
}

int Lending::getLoanMonth(){
	return LoanMonth;
}

int Lending::getLoanYear(){
	return LoanYear;
}

int Lending::getDueDay(){
	return DueDay;
}

int Lending::getDueMonth(){
	return DueMonth;
}

int Lending::getDueYear(){
	return DueYear;
}

int Lending::getReturnDay(){
	return ReturnDay;
}

int Lending::getReturnMonth(){
	return ReturnMonth;
}

int Lending::getReturnYear(){
	return ReturnYear;
}

//Functions

//Add function
void Lending::addLend(){
	BookLend* new_BookLend=new BookLend();
	new_BookLend->BookID=BookID;
	new_BookLend->MemberID=MemberID;
	new_BookLend->LoanDay=LoanDay;
	new_BookLend->LoanMonth=LoanMonth;
	new_BookLend->LoanYear=LoanYear;
	new_BookLend->DueDay=DueDay;
	new_BookLend->DueMonth=DueMonth;
	new_BookLend->DueYear=DueYear;
	new_BookLend->ReturnDay=ReturnDay;
	new_BookLend->ReturnMonth=ReturnMonth;
	new_BookLend->ReturnYear=ReturnYear;
	
	if(ReturnYear>DueYear || ReturnYear == DueYear && ReturnMonth > DueMonth || ReturnYear == DueYear && ReturnMonth == DueMonth && ReturnDay > DueDay){
		new_BookLend->OverDue="Overdue!";
	}
		
	new_BookLend->next=(*head);
	new_BookLend->prev=NULL;

//Checking if the list is null; if null add the new lending details as the head		
	if(*head!=NULL)
		(*head)->prev=new_BookLend;
		
		(*head)=new_BookLend;
	}

//Printing function
void Lending::printLendList(){
	BookLend* last;
	if(node==NULL){
		cout<<"\t\t\t\t""Empty!"<<endl;
	}
	int i=0;
	while(node!=NULL){
		i++;
		cout<<"\t\t\t\t"<<i<<")"<<node->BookID<<" "<<endl;
		last=node;
		node=node->next; //iterating by passing the pointer to next untill it reaches null
	}
	cout<<endl;
}

//Delete function
void Lending::deleteLend(BookLend** head_ref,BookLend* del){
	if(*head_ref==NULL||del==NULL)
	return;
	
	if(*head_ref==del)
		*head_ref=del->next;
		
		if(del->next!=NULL)
		del->next->prev=del->prev;
		
		if(del->prev!=NULL)
		del->prev->next=del->next; //removing the node from the list
		
		delete del;
	}
	
void Lending::removeLend(){
	
	
		if (*head==NULL)
		return;
	
		BookLend* temp=*head;
		
		for(int i=1;temp!=NULL&&i<lendNumber;i++)  //Iterating through the list
			temp=temp->next;
	
		if(temp==NULL)
		return;
 	
		deleteLend(head,temp);		//passes the head and the value to deleteLend function
		
	}
	
//Search function
void Lending::searchLend(){

	BookLend* temp=*head;
	bool found=false;

	while(temp != NULL){
		if(temp->BookID==Choice||temp->MemberID==Choice){//if the book id or the member id is same as user input it will print the node using the header pointer (temp)
			found=true;
			cout<<endl;
			cout<<"\t\t\t\t""Book ID:"<<temp->BookID<<" "<<endl;
			cout<<"\t\t\t\t""Member ID:"<<temp->MemberID<<" "<<endl;
			cout<<"\t\t\t\t""Loaned Date:"<<temp->LoanDay<<"/"<<temp->LoanMonth<<"/"<<temp->LoanYear<<endl;
			cout<<"\t\t\t\t""Due Date:"<<temp->DueDay<<"/"<<temp->DueMonth<<"/"<<temp->DueYear<<endl;
			cout<<"\t\t\t\t""Return Date:"<<temp->ReturnDay<<"/"<<temp->ReturnMonth<<"/"<<temp->ReturnYear<<endl;
			cout<<"\t\t\t\t"<<temp->OverDue;
			cout<<endl;
		}
		temp=temp->next;
}
		if(found==false){
		cout<<"\t\t\t\t""Not found!"<<endl;
	}
		else if(found==true){
		cout<<"\t\t\t\t""Found!"<<endl;
}
}

//Edit function
void Lending::editLend(){
	BookLend* temp = *head;
	bool found=false;

	while(temp != NULL){
	if(temp->BookID==Choice||temp->MemberID==Choice){ //uses the same technique as seach function but edits the components instead of user input
	found=true;
	if(infoChoice==1){
	temp->BookID=BookID;
	}
	else if(infoChoice==2){
	temp->MemberID=MemberID;
	}
	else if(infoChoice==3){
	temp->LoanDay=LoanDay;
	temp->LoanMonth=LoanMonth;
	temp->LoanYear=LoanYear;
	}
	else if(infoChoice==4){
	temp->DueDay=DueDay;
	temp->DueMonth=DueMonth;
	temp->DueYear=DueYear;
	}
	else if(infoChoice==5){
	temp->ReturnDay=ReturnDay;
	temp->ReturnMonth=ReturnMonth;
	temp->ReturnYear=ReturnYear;
	}
	}
		temp=temp->next;
	}
	if(found==false){
	cout<<"\t\t\t\t""Not found!"<<endl;
	}
	if(found==true){
	cout<<"\t\t\t\t""Updated!"<<endl;
}
	}
	
	void Lending::printTofile(ostream& os){ //same as printing function but prints to txt file instead
	BookLend* last;
	os<<"\t"<<"List of lending info"<<" "<<endl;
	if(node==NULL){
		os<<"\t\t\t\t""Empty!"<<endl;
	}

	while(node!=NULL){

		os<<endl;
		os<<"\t"<<"Book ID:"<<node->BookID<<" "<<endl;
		os<<"\t"<<"Member ID:"<<node->MemberID<<endl;
		os<<"\t""Loaned Date:"<<node->LoanDay<<"/"<<node->LoanMonth<<"/"<<LoanYear<<endl;
		os<<"\t"<<"Due Date:"<<node->DueDay<<"/"<<node->DueMonth<<"/"<<DueYear<<endl;
		os<<"\t"<<"Return Date:"<<node->ReturnDay<<"/"<<node->ReturnMonth<<"/"<<ReturnYear<<endl;
		os<<"\t"<<node->OverDue;		
		last=node;
		node=node->next;
	}
	os<<endl;
		}
	
