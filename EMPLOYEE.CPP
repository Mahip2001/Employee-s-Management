#include<iostream.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>

class LINES
{
	public:
		 void LINE_HOR(int, int, int, char);
		 void LINE_VER(int, int, int, char);
		 void BOX(int, int, int, char);
		 void CLEARUP(void);
		 void CLEARDOWN(void);
};

class MENU
{
	public:
		void MAIN_MENU(void);
	private:
		void EDIT_EDIT(void);
		void INTRODUCTION(void);
};

class EMPLOYEE
{
	public:
		void NEW_EMPLOYEE(void);
		void MODIFICATION(void);
		void DELETION(void);
		void LIST(void);
		void SALARY_SLIP(void);
	private:
		void ADD_RECORD(int, char[], char[], char[], int, int, int, char[], char, char, char, float, float);
		void MODIFY_RECORD(int, char[], char[], char[], char[], char, char, char, float, float);
		void DELETE_RECORD(int);
		int LASTCODE(void);
		int CODEFOUND(int);
		int RECORDNO(int);
		int FOUND_CODE(int);
		void DISPLAY_RECORD(int);
		int VALID_DATE(int, int, int);

		int code, dd, mm, yy;
		char name[26], address[31], phone[10], desig[16];
		char grade, house, convense;
		float loan, basic;
};

void MENU :: MAIN_MENU(void)
{
	char ch;
	LINES L;
	L.CLEARUP();
	while(1)
	{
		clrscr();
		L.BOX(28,7,51,9,218);
		L.BOX(10,5,71,21,218);
		L.BOX(11,6,70,20,219);
		gotoxy(31,8);
		cout<<"RAJ SONS PVY> LTD";
		gotoxy(30,11);
		cout<<"1. NEW EMPLOYEE";
		gotoxy(30,12);
		cout<<"2. DISPLAY EMPLOYEE";
		gotoxy(30,13);
		cout<<"3. LIST OF EMPLOYEE";
		gotoxy(30,14);
		cout<<"4. SALARY SLIP";
		gotoxy(30,15);
		cout<<"5. EDIT";
		gotoxy(30,16);
		cout<<"0. QUIT";
		gotoxy(30,18);
		cout<<"ENTER YOUR CHOICE = ";
		ch =getch();

		if(ch==27 || ch = '0')
			break;
		else
		if(ch=='1')
		{
			EMPLOYEE E;
			E.NEW_EMPLOYEE();
		}
		else
		if (ch=='2')
		{
			EMPLOYEE E;
			E.DISPLAY();
		}
		else
		if (ch=='3')
		{
			EMPLOYEE E;
			E.LIST();
		}
		else
		if (ch=='4')
		{
			EMPLOYEE E;
			E.SALARY_SLIP();
		}
		else
		if (ch=='5')
		{
			EDIT_MENU();
		}
	}
	L.CLEARUP();
}

void MENU :: EDIT_MENU(void)
{
	char ch;
	LINES L;
	L.CLEARDOWN();
	while(1)
	{
		clrscr();
		L.BOX(28,7,51,9,218);
		L.BOX(10,5,71,21,218);
		L.BOX(11,6,70,20,219);
		gotoxy(31,9);
		cout<<"E D I T  M E N U";
		gotoxy(30,13);
		cout<<"1. DELETE RECORD";
		gotoxy(30,14);
		cout<<"2. MODIFY RECORD";
		gotoxy(30,15);
		cout<<"0. EXIT";
		gotoxy(30,17);
		cout<<"ENTER YOUR CHOICE = ";
		ch =getch();

		if(ch==27 || ch = '0')
			break;
		else
		if(ch=='1')
		{
			EMPLOYEE E;
			E.DELETION();
		}
		else
		if (ch=='2')
		{
			EMPLOYEE E;
			E.MODIFICATION();
		}
	}
	L.CLEARDOWN();
}

void LINES :: LINE_HOR(int column1, int column2, int row, char c);
{
	for(column1;column1<=column2;column1++);
	{
		gotoxy(column1,row);
		cout<<c;
	}
}

void LINES :: LINE_VER(int cloumn1, int row1, int column2, int row2, char c)
{
	for(row1; row1<=row2; row1++)
	{
		gotoxy(column,row1);
		cout<<c;
	}
}

void LINES :: BOX(int column1, int row1, int column2, int row2, char c)
{
	char c=218;
	char c1, c2, c3, c4;
	char l1=196, l2=179;
	if(c == ch)
	{
		c1=218;
		c2=191;
		c3=192;
		c4=217;
		l1=196;
		l2=179;
	}
	else
	{
		c1=c;
		c2=c;
		c3=c;
		c4=c;
		l1=c;
		l2=c;
	}
	gotoxy(column1,row1);
	cout<<c1;
	gotoxy(column2,row1);
	cout<<c2;
	gotoxy(column1,row2);
	cout<<c3;
	gotoxy(column2,row2);
	cout<<c4;
	column1++;
	column2--;
	LINE_HOR(column1, column2, row1, l1);
	LINE_HOR(column1, column2, row2, l1);
	column1++;
	column2--;
	row1++;
	row2--;
	LINE_VER(column1, column2, row1, l1);
	LINE_VER(column1, column2, row2, l1);
}

void LINES :: CLEARDOWN(void)
{
	for(int i=25; i>=1;