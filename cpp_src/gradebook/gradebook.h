#pragma once
#include <string>
#include "../student/student.h"

// Levi Shaffer
// COP 3014

using namespace std;

class gradebook {
	public:
		gradebook();
		gradebook(string name);
		void print();
		inline string getName() { return className; };
		double getClassAvg();
		bool addStudent(student stud);
		void printStudents(bool sub=false);
		bool deleteStudent(int n);
		bool deleteStudent(string name);
		void setName(string name);
		void printStudent(string stuName,bool sub=false);
		string* getStudentNames();
		int getNumStudents();
		student getStudent(int n);
		double getQuizAvg();
		double getExamAvg();
		double getHWAvg();
		void studentOverwrite(student s, int n);
	private:
		int stuCount;
		void __classinit__();
		const static int maxStudents = 15;
		string className;
		student students[maxStudents];
};
