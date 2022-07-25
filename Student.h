#pragma once
#include<iostream>
using namespace std;

class Student
{
	int FN;
	char* firstName;
	char* lastName;
	int grade;
	void copyStudent(const Student& other);
	void free();
public:
	void setGrade(int grade);
	Student();
	Student(int FN, const char* firstName, const char* lastName, int grade);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();
	int getFN()const;
	friend ostream& operator<<(ostream& os, const Student& st);
	friend istream& operator>>(istream& is,Student& st);
};
