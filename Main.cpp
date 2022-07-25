#include<iostream>
#include"StudentDB.h"
using namespace std;

int main()
{
	StudentDB db;
	cout << "Instructions:\n";
	cout << "write command:\ncreate\nsequentialSearch\nupdate\ndelete\nexit\n";
	char command[32];
	while (true)
	{
		cin >> command;
		if (!strcmp(command, "create"))
		{
			int fn, grade;
			char firstName[64], lastName[64];
			cout << "Enter FN: ";
			cin >> fn;
			cout << "Enter first name: ";
			cin >> firstName;
			cout << "Enter last name: ";
			cin >> lastName;
			cout << "Enter grade: ";
			cin >> grade;
			if (db.create(fn, firstName, lastName, grade)) cout << "Record saved!\n";
			else cout << "Not valid information!\n";
		}
		if (!strcmp(command, "sequentialSearch"))
		{
			int fn;
			cout << "Enter FN: ";
			cin >> fn;
			db.sequentialSearch(fn);
		}
		if (!strcmp(command, "update"))
		{
			int fn;
			int grade;
			cout << "Enter FN: ";
			cin >> fn;
			cout << "Enter grade: ";
			cin >> grade;
			db.update(fn, grade);
		}
		if (!strcmp(command, "delete"))
		{
			int fn;
			cout << "Enter FN: ";
			cin >> fn;
			db.deleteStudent(fn);
		}
		if (!strcmp(command, "exit"))
		{
			return 0;
		}
	}

}