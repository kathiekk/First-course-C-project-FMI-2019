#include <iostream>
#include<fstream>
#include "StudentDB.h"
using namespace std;

StudentDB::StudentDB()
{
	ifstream in("StudentsGrades.db", ios::in);
	if (in) {
		Student s;
		while (in >> s) {
			studentList.push_back(s);
		}
	}
}

StudentDB::~StudentDB()
{
	ofstream out("StudentsGrades.db", ios::out);
	for (int i = 0; i < studentList.size(); ++i) {
		out << studentList[i];
	}
}

int StudentDB::findByFN(int FN)
{
	for (int i = 0; i < studentList.size(); ++i)
	{
		if (studentList[i].getFN() == FN) return i;
	}
	return -1;
}

bool StudentDB::create(int FN, const char* firstName, const char* lastName, int grade)
{
	if (FN < 10000 || FN > 99999) return false;

	if (findByFN(FN) != -1) return false;

	studentList.push_back(Student(FN, firstName, lastName, grade));
	return true;
}

int StudentDB::sequentialSearch(int FN)
{
	int ind = findByFN(FN);
	if (ind != -1) cout << studentList[ind];
	else cout << "Record not found!\n";

	return ind;
}

void StudentDB::update(int FN, int grade)
{
	int indOfStudent = findByFN(FN);
	if (indOfStudent != -1)
	{
		studentList[indOfStudent].setGrade(grade);
		cout << "Record saved!" << endl;
	}
}

void StudentDB::deleteStudent(int FN)
{
	int indOfStudent = findByFN(FN);
	if (indOfStudent != -1)
	{
		studentList.erase(studentList.begin() + indOfStudent);
		cout << "Record deleted!" << endl;
	}
}
