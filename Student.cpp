#include<iostream>
#include "student.h"
using namespace std;

void Student::copyStudent(const Student& other)
{
	FN = other.FN;
	firstName = new char[strlen(other.firstName) + 1];
	strcpy_s(firstName, strlen(other.firstName) + 1, other.firstName);
	lastName = new char[strlen(other.lastName) + 1];
	strcpy_s(lastName, strlen(other.lastName) + 1, other.lastName);
	grade = other.grade;
}

void Student::free()
{
	delete[] firstName;
	delete[] lastName;
}

Student::Student()
{
	FN = 10000;
	firstName = nullptr;
	lastName = nullptr;
	grade = 2;
}

Student::Student(int FN, const char* firstName, const char* lastName, int grade)
{
	this->FN = FN;
	this->firstName = new char[strlen(firstName) + 1];
	strcpy_s(this->firstName, strlen(firstName) + 1, firstName);
	this->lastName = new char[strlen(lastName) + 1];
	strcpy_s(this->lastName, strlen(lastName) + 1, lastName);
	if (grade < 2 || grade>6)
		this->grade = 2;
	else
		this->grade = grade;
}

Student::Student(const Student& other)
{
	copyStudent(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		free();
		copyStudent(other);
	}
	return *this;
}

Student::~Student()
{
	free();
}

ostream& operator<< (ostream& os, const Student& st)
{
	return os << st.FN << " " << st.firstName << " " << st.lastName << " " << st.grade << "\n";
}

istream& operator>> (istream& is, Student& st) {
	delete[] st.firstName;
	delete[] st.lastName;
	char firstName[64], lastName[64];
	is >> st.FN >> firstName >> lastName >> st.grade;
	st.firstName = new char[strlen(firstName) + 1];
	strcpy_s(st.firstName, strlen(firstName) + 1, firstName);
	st.lastName = new char[strlen(lastName) + 1];
	strcpy_s(st.lastName, strlen(lastName) + 1, lastName);
	return is;
}

int Student::getFN()const
{
	return FN;
}

void Student::setGrade(int grade)
{
	if (grade < 2 || grade>6)
		grade = 2;
	else
		this->grade = grade;
}