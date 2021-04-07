#include <iostream>
#include <string>

#include "gradebook.h"

// Levi Shaffer
// COP 3014

using namespace std;

void gradebook::__classinit__() {
	stuCount = 0;
	// classAvg = 0.0;
	for (int i = 0; i < maxStudents; i++) {
		students[i] = student();
	}
	return;
}

gradebook::gradebook() {
	className = "<noname>";
	__classinit__();
}

gradebook::gradebook(string name) {
	className = name;
	__classinit__();
}

void gradebook::studentOverwrite(student s, int n) {
	students[n] = s;
}

void gradebook::setName(string name) {
	className = name;
}

bool gradebook::addStudent(student stud) {
	if(stuCount >= maxStudents) {
		cout << "Cannot take anymore students" << endl;
		return false;
	}
	students[stuCount++] = stud;
	getClassAvg();
	return true;
}

bool gradebook::deleteStudent(int n) {
	if(n > stuCount || n < 0) {
		return false;
	}
	student empty = student();
	for(int i = stuCount - 1; i >= n; i--) {
		student s = students[i];
		students[i] = empty;
		empty = s;
	}
	stuCount--;

	return true;
}

int gradebook::getNumStudents() {
	return stuCount;
}

student gradebook::getStudent(int n) {
	return students[n];
}

string* gradebook::getStudentNames() {
	static string names[15];
	for (int i = 0; i < maxStudents; i++) {
		names[i] = students[i].getName();
	}
	return names;
}

bool gradebook::deleteStudent(string name) {
	for(int i = 0; i < stuCount; i++) {
		if (students[i].getName() == name) {
			bool status = deleteStudent(i);
			return status;
		}
	}
	return false;
}

double gradebook::getClassAvg() {
	if (stuCount <= 0) {
		return -1.0;
	}
	double classAvg = 0.0;
	for (int i = 0; i < stuCount; i++) {
		classAvg += students[i].getAverages();
	}	
	classAvg = static_cast<double>(classAvg / stuCount);
	return classAvg;
}

double gradebook::getExamAvg() {
	if (stuCount <= 0) {
		return -1.0;
	}
	double classAvg = 0.0;
	for (int i = 0; i < stuCount; i++) {
		classAvg += students[i].getExamAverage();
	}
	classAvg = (classAvg / stuCount);
	return classAvg;
}

double gradebook::getQuizAvg() {
	if (stuCount <= 0) {
		return -1.0;
	}
	double classAvg = 0.0;
	for (int i = 0; i < stuCount; i++) {
		classAvg += students[i].getQuizAverage();
	}
	classAvg = (classAvg / stuCount);
	return classAvg;
}

double gradebook::getHWAvg() {
	if (stuCount <= 0) {
		return -1.0;
	}
	double classAvg = 0.0;
	for (int i = 0; i < stuCount; i++) {
		classAvg += students[i].getHWAverage();
	}
	classAvg = (classAvg / stuCount);
	return classAvg;
}

void gradebook::printStudents(bool sub) {
	for(int i = 0; i < stuCount; i++) {
		cout << i+1 << ' ';
		students[i].print(sub);
	}
}

void gradebook::printStudent(string stuName, bool sub) {
	for (int i = 0; i < stuCount; i++) {
		if (students[i].getName() == stuName) {
			students[i].print(sub);
		}
	}
}

void gradebook::print() {
	cout << "Class: " << className << endl;
	cout << "\tClass Average: " << getClassAvg() << endl;
	cout << "\tStudents: " << endl;
	for(int i = 0; i < stuCount; i++) {
		students[i].print(true);
	}
}

