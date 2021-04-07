#include <iostream>
#include <string>

#include "student.h"

using namespace std;

// Levi Shaffer
// COP 3014

const bool DEBUG = false;


student::student() {
	name = "<noname>";
	examCount = 0;
	hwCount = 0;
	quizCount = 0;
	avg = 0.0;
	eAvg = 0.0;
	qAvg = 0.0;
	hAvg = 0.0;
	for (int i = 0; i < maxExamGrades; i++) {
		examGrades[i] = -1.1;
	}
	for (int i = 0; i < maxQuizGrades; i++) {
		quizGrades[i] = -1.1;
	}
	for (int i = 0; i < maxHWGrades; i++) {
		HWGrades[i] = -1.1;
	}
}

student::student(string name) {
	this->name = name;
	avg = 0.0;
	eAvg = 0.0;
	qAvg = 0.0;
	hAvg = 0.0;
	examCount = 0;
	hwCount = 0;
	quizCount = 0;
	for (int i = 0; i < maxExamGrades; i++) {
		examGrades[i] = -1.1;
	}
	for (int i = 0; i < maxQuizGrades; i++) {
		quizGrades[i] = -1.1;
	}
	for (int i = 0; i < maxHWGrades; i++) {
		HWGrades[i] = -1.1;
	}
}

bool student::addExamGrade(double grade) {
	if(grade < 0 || grade > 100) {
		return false;
	}
	for (int i = 0; i < maxExamGrades; i++) {
		if(examGrades[i] < 0) {
			examGrades[i] = grade;
			if(DEBUG) {
				cout << "\tAdding " << grade << " at " << i << "th position" << endl;
			}
			examCount++;
			calcAverages();
			return true; // we don't need to do this but once
		}
	}
}
bool student::addHWGrade(double grade) {
	if(grade < 0 || grade > 100) {
		return false;
	}
	for (int i = 0; i < maxHWGrades; i++) {
		if(HWGrades[i] < 0) {
			HWGrades[i] = grade;
			if(DEBUG) {
				cout << "\tAdding " << grade << " at " << i << "th position" << endl;
			}
			hwCount++;
			calcAverages();
			return true; // we don't need to do this but once
		}
	}
}

void student::overwriteWeights(double hw, double quiz, double exam) {
	examWeight = exam;
	homeworkWeight = hw;
	quizWeight = quiz;
	calcAverages();
}

bool student::addQuizGrade(double grade) {
	if(grade < 0 || grade > 100) {
		return false;
	}
	for (int i = 0; i < maxQuizGrades; i++) {
		if(quizGrades[i] < 0) {
			quizGrades[i] = grade;
			if(DEBUG) {
				cout << "\tAdding " << grade << " at " << i << "th position" << endl;
			}
			quizCount++;
			calcAverages();
			return true; // we don't need to do this but once
		}
	}
}

void student::directExamChange(int pos, double grade) {
	examGrades[pos] = grade;
	if(examCount < maxExamGrades) {
		examCount++;
	}
	if(DEBUG) {
		cout << examGrades[pos] << endl;
		examGrades[pos] = grade;
		cout << examGrades[pos] << endl;
		cout << pos << endl;
	}
	calcAverages();
}
void student::directQuizChange(int pos, double grade) {
	quizGrades[pos] = grade;
	if(quizCount < maxQuizGrades) {
		quizCount++;
	}
	calcAverages();
}
void student::directHWChange(int pos, double grade) {
	HWGrades[pos] = grade;
	if(hwCount < maxHWGrades) {
		hwCount++;
	}
	calcAverages();
}

void student::setName(string name) {
	this->name = name;
}

double* student::getExamGrades() {
	static double r[maxExamGrades];
	for (int i = 0; i < maxExamGrades; i++) {
		r[i] = examGrades[i];
	}
	return r;
}

double* student::getQuizGrades() {
	static double r[maxQuizGrades];
	for (int i = 0; i < maxQuizGrades; i++) {
		r[i] = quizGrades[i];
	}
	return r;
}

double* student::getHWGrades() {
	static double r[maxHWGrades];
	for (int i = 0; i < maxHWGrades; i++) {
		r[i] = HWGrades[i];
	}
	return r;
}

void student::calcAverages() {
	avg = 0.0; // zero it all out to be sure results are correct
	eAvg = 0.0;
	qAvg = 0.0;
	hAvg = 0.0;
	double count = 0.0;
	for (int i = 0; i < maxExamGrades; i++) {
		if(examGrades[i] >= 0) {
			eAvg += examGrades[i];
			count += 1.0;
		}
	}
	// cout << "eAvg = " << eAvg << endl;
	//eAvg = static_cast<double>(eAvg/examCount);
	eAvg = (examCount > 0) ? (eAvg/count) : 100;
	count = 0.0;
	for (int i = 0; i < maxQuizGrades; i++) {
		if(quizGrades[i] >= 0) {
			qAvg += quizGrades[i];
			count += 1.0;
		}
	}
	// cout << "qAvg = " << qAvg << endl;
	//qAvg = static_cast<double>(qAvg/quizCount);
	qAvg = (quizCount > 0) ? (qAvg/count) : 100;
	count = 0.0;
	for (int i = 0; i < maxHWGrades; i++) {
		if(HWGrades[i] >= 0) {
			hAvg += HWGrades[i];
			count += 1.0;
		}
	}
	// cout << "hAvg = " << hAvg << endl;
	//hAvg = static_cast<double>(hAvg/hwCount);
	hAvg = (hwCount>0) ? (hAvg/count) : 100;
	delete &count;
	avg = (eAvg * examWeight) + (hAvg * homeworkWeight) + (qAvg * quizWeight);
	if (DEBUG)
		cout << "\t(calcAverage) eAvg = " << eAvg << ", qAvg = " << qAvg << ", hAvg = " << hAvg << endl;
}

double student::getAverages() {
	return avg;
}

string student::getName() {
	return name;
}

void student::print(bool sub) {
	if(sub) {
		cout << "\t\tStudent: " << name << endl;
		cout << "\t\tAverage: " << avg << endl;
		cout << "\t\t\tExam: " << eAvg << endl;
		cout << "\t\t\tQuiz: " << qAvg << endl;
		cout << "\t\t\tHome: " << hAvg << endl;
		return;
	}
	cout << "Student: " << name << endl;
	cout << "Average: " << avg << endl;
	cout << "\tQuiz: " << qAvg << endl;
	cout << "\tExam: " << eAvg << endl;
	cout << "\tHome: " << hAvg << endl;
}

