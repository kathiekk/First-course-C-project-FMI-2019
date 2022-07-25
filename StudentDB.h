#pragma once
#include<iostream>
#include "student.h"
#include<vector>

class StudentDB {
	vector<Student> studentList;
	int findByFN(int FN);
public:
	StudentDB();
	~StudentDB();
	bool create(int fn, const char * firstName, const char * lastName, int grade);
	int sequentialSearch(int FN);
	void update(int FN, int grade);
	void deleteStudent(int FN);
};


