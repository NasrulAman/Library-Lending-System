#ifndef LENDING_H
#define LENDING_H
#include <string>
using namespace std;

struct BookLend{
	string BookID;
	string MemberID;
	int LoanDay;
	int LoanMonth;
	int LoanYear;
	int DueDay;
	int DueMonth;
	int DueYear;
	int ReturnDay;
	int ReturnMonth;
	int ReturnYear;
	string OverDue;
	BookLend* next;
	BookLend* prev;
};
class Lending{
	private:
	int lendNumber;
	int infoChoice;
	int LoanDay;
	int LoanMonth;
	int LoanYear;
	int DueDay;
	int DueMonth;
	int DueYear;
	int ReturnDay;
	int ReturnMonth;
	int ReturnYear;
	string BookID;
	string MemberID;
	string Choice;
	string OverDue;
	BookLend** head;
	BookLend* node;
	BookLend* temp;
	BookLend* del;

	public:
	
//SETS
	void setLendNumber(int LendNumber);
	void setInfoChoice(int InfoChoice);
	void setBookID(string bookID);
	void setMemberID(string memeberID);
	void setChoice(string choice);
	void setOverDue(string overDue);
	void setHead(BookLend** Head);
	void setNode(BookLend* Node);
	void setDel(BookLend* Del);
	void setTemp(BookLend* Temp);
	void setLoanDay(int loanDay);
	void setLoanMonth(int loanMonth);
	void setLoanYear(int loanYear);
	void setDueDay(int dueDay);
	void setDueMonth(int dueMonth);
	void setDueYear(int dueYear);
	void setReturnDay(int returnDay);
	void setReturnMonth(int returnMonth);
	void setReturnYear(int returnYear);
	
//GETS	
	int getLendNumber();
	int getInfoChoice();
	int getLoanDay();
	int getLoanMonth();
	int getLoanYear();
	int getDueDay();
	int getDueMonth();
	int getDueYear();
	int getReturnDay();
	int getReturnMonth();
	int getReturnYear();
	string getBookID();
	string getMemberID();
	string getChoice();
	string getOverDue();
	BookLend** getHead();
	BookLend* getNode();
	BookLend* getDel();
	BookLend** getHeadRef();
	BookLend* getTemp();

//FUNCTIONS
	void addLend();
	void printLendList();
	void deleteLend(BookLend** head_ref,BookLend* del);
	void removeLend();
	void searchLend();
	void editLend();
    void printTofile(ostream& os);
};

#endif
