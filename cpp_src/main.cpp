#include <iostream>
#include <string>

#include "gradebook/gradebook.h"

// Levi Shaffer
// COP 3014

using namespace std;

#ifdef _WIN32 // Determine what OS is running to determine how to clear screen
	const bool isWindows = true;
#elif _WIN64
	const bool isWindows = true;
#else
	const bool isWindows = false;
#endif

// Helper functions
void printHeader(string s);
void pause();
int studentSelect(gradebook& gb);
void clear();
void error(string msg);

// Menu functions
void nameChange(gradebook& gb);
bool studentAdd(gradebook& gb);
bool studentDelete(gradebook& gb);
void gradeChanging(gradebook& gb);
void changeWeights(gradebook& gb);
void classAverages(gradebook& gb, bool sub=false);
void report(gradebook& gb);

int main () {
	gradebook gb = gradebook();
	while (true) {
		int choice;
		printHeader(gb.getName());
		cout << "1. Add a student" << endl;
		cout << "2. Delete a student" << endl;
		cout << "3. Change a student's grade" << endl;
		cout << "4. Change group weights" << endl;
		cout << "5. Change gradebook name" << endl;
		cout << "6. Display class averages" << endl;
		cout << "7. Display full report" << endl;
		cout << "0. QUIT" << endl;
		cout << endl << "Enter an action: ";
		cin >> choice;
		switch (choice) {
			case 1: {
				bool t = studentAdd(gb);
				if(!t) {
					error("Could not add student");
				}
				break;
			}
			case 2: {
				studentDelete(gb);
				break;
			}
			case 3: {
				gradeChanging(gb);
				break;
			}
			case 4: {
				changeWeights(gb);
				break;
			}
			case 5: {
				nameChange(gb);
				break;
			}
			case 6: {
				classAverages(gb);
				break;
			}
			case 7: {
				report(gb);
				break;
			}
			case 0:
			default: {
				clear();
				return 0;
			}
		}
	}
	return 0;
}

void printHeader(string s) {
	clear();
	cout << "-=| " << s << " |=-" << endl << endl;
}

void pause() {
	cout << endl << "Press ENTER to continue to next screen." << endl;
	cin.ignore(1,'\n');
	cin.get();
	return;
}

int studentSelect(gradebook& gb) {
	string menuName = "Select student";
	printHeader(menuName);
	string* names = gb.getStudentNames();
	int count = gb.getNumStudents();
	if (count > 0) {
		for (int i = 0; i < count; i++) {
			if(*(names + i) != "<noname>")
				cout << i+1 << ". " << *(names + i) << endl;
		}
		int choice;
		cout << endl << "Please enter a student to select (# next to their name): ";
		cin >> choice;
		return --choice;
	} else {
		error("No students to be selected");
		return -1;
	}
}

void clear() {
	if(isWindows) {
		system("cls");
	} else {
		cout << "\x1B[2J\x1B[H";
	}
}

void error(string msg) {
	string menuName = "ERROR";
	printHeader(menuName);
	cout << msg << endl;
	pause();
	return;
}

void nameChange(gradebook &gb) {
	string menuName = "Change gradebook name";
	string name;
	printHeader(menuName);
	cout << "Please enter a new name for the gradebook: ";
	cin >> name;
	gb.setName(name);
	printHeader(menuName);
	cout << "Name changed to " << name << endl;
	pause();
	return;
}

bool studentAdd(gradebook &gb) {
	string menuName = "Add student";
	string first;
	string last;
	printHeader(menuName);
	cout << "Please enter a first name for the student (q to go back): ";
	cin >> first;
	if (first == "q") {
		return false;
	}
	cout << "Please enter a last name for the student: ";
	cin >> last;
	last.insert(0,1,' ');
	string name = first.append(last);
	student s = student(name);
	bool status = gb.addStudent(s);
	return status;
}

bool studentDelete(gradebook& gb) {
	int choice = studentSelect(gb);
	if(choice >= 0) {
		bool status = gb.deleteStudent(choice);
		return status;
	} else {
		return false;
	}
}

void gradeChanging(gradebook& gb) {
	int stuChoice = studentSelect(gb);
	if(stuChoice < 0) {
		return;
	}
	string menuName = "Changing grade";
	printHeader(menuName);

	cout << "1. Exam grades" << endl;
	cout << "2. Quiz grades" << endl;
	cout << "3. Homework grades" << endl << endl;
	cout << "Please input which grade to change: ";
	int choice;
	cin >> choice;
	student stu = gb.getStudent(stuChoice);
	printHeader(menuName);
	switch(choice) {
		case 1: {
			double* grades = stu.getExamGrades();
			for(int i = 0; i < stu.getMaxExams(); i++) {
				if(*(grades+i) >= 0.0)
					cout << i+1 << ". " << *(grades+i) << endl;
				else
					cout << i+1 << ". <ungraded>" << endl;
			}
			cout << "Please enter the grade to change: ";
			int choice;
			cin >> choice;
			printHeader(menuName);
			cout << "Please enter the value to set (< 0 for it to be ungraded): ";
			double newGrade;
			cin >> newGrade;
			stu.directExamChange(--choice,newGrade);
			printHeader(menuName);
			cout << "Awesome! Student's exam average is now: " << stu.getExamAverage() << "\%"<< endl;
			break;
		}
		case 2: {
			double* grades = stu.getQuizGrades();
			for(int i = 0; i < stu.getMaxQuizs(); i++) {
				if(*(grades+i) >= 0.0)
					cout << i+1 << ". " << *(grades+i) << endl;
				else
					cout << i+1 << ". <ungraded>" << endl;
			}
			cout << "Please enter the grade to change: ";
			int choice;
			cin >> choice;
			printHeader(menuName);
			cout << "Please enter the value to set (< 0 for it to be ungraded): ";
			double newGrade;
			cin >> newGrade;
			stu.directQuizChange(--choice,newGrade);
			printHeader(menuName);
			cout << "Awesome! Student's quiz average is now: " << stu.getQuizAverage() << "\%"<< endl;
			break;
		}
		case 3: {
			double* grades = stu.getHWGrades();
			for(int i = 0; i < stu.getMaxHWs(); i++) {
				if(*(grades+i) >= 0.0)
					cout << i+1 << ". " << *(grades+i) << endl;
				else
					cout << i+1 << ". <ungraded>" << endl;
			}
			cout << "Please enter the grade to change: ";
			int choice;
			cin >> choice;
			printHeader(menuName);
			cout << "Please enter the value to set (< 0 for it to be ungraded): ";
			double newGrade;
			cin >> newGrade;
			stu.directHWChange(--choice,newGrade);
			printHeader(menuName);
			cout << "Awesome! Student's homework average is now: " << stu.getHWAverage() << "\%"<< endl;
			break;
		}
		default:
			return;
	}
	gb.studentOverwrite(stu,stuChoice);
}

void changeWeights(gradebook &gb) {
	string menuName = "Change weights";
	printHeader(menuName);

	cout << "Please enter the new weights in order of exam,quiz, and homework, with each separated by a space.";
	cout << " Remember, the combined total must equal 1" << endl;
	double sum;
	double qWeight;
	double eWeight;
	double hWeight;
	cin >> eWeight >> qWeight >> hWeight;
	sum = eWeight + qWeight + hWeight;
	if(sum == 1.0) {
		for (int i = 0; i < gb.getNumStudents(); i++) {
			student s = gb.getStudent(i);
			s.overwriteWeights(hWeight,qWeight,eWeight);
		}
		printHeader(menuName);
		cout << "Weights changed!" << endl;
		pause();
		return;
	} else {
		error("Totals do not add up to 1. Try again...");
		changeWeights(gb);
	}
}

void classAverages(gradebook& gb, bool sub) {
	if(!sub) {
		string menuName = "Class Averages";
		printHeader(menuName);
	}
	int count = gb.getNumStudents();
	if(count > 0) {
		double eAvg = gb.getExamAvg();
		double hAvg = gb.getHWAvg();
		double qAvg = gb.getQuizAvg();
		cout << "Class Exam Average: " << gb.getExamAvg() << "\% " << endl;
		cout << "Class Quiz Average: " << gb.getQuizAvg() << "\% " << endl;
		cout << "Class Homework Average: " << gb.getHWAvg() << "\% " << endl;
		cout << "\nClass Overall Average: " << (eAvg+hAvg+qAvg)/3.0 << "\% " << endl;
	} else {
		cout << "Class Exam Average: 0\%"<< endl;
		cout << "Class Quiz Average: 0\%" << endl;
		cout << "Class Homework Average: 0\%" << endl;
		cout << "\nClass Overall Average: 0\%" << endl;
	}
	if(!sub)
		pause();
	return;
}

void report(gradebook& gb) {
	string menuName = "Report";
	printHeader(menuName);
	cout << "Course: " << gb.getName() << endl;
	classAverages(gb, true);
	int count = gb.getNumStudents();
	if (count > 0) {
		cout << "Name\t|\tHomework grades\t|\tQuiz grades\t|\tExam grades" << endl;
		for (int i = 0; i < count; i++) {
			student stu = gb.getStudent(i);
			if(stu.getName() == "<noname>") {
				continue;
			}
			cout << stu.getName() << "\t|\t";
			double* hgrades = stu.getHWGrades();
			for (int j = 0; j < stu.getMaxHWs(); j++) {
				if(*(hgrades + j) >= 0.0)
					cout << *(hgrades + j) << " ";
				else
					cout << "UG ";
				
			}
			delete hgrades;
			cout << "\t|\t";
			double* qgrades = stu.getQuizGrades();
			for (int j = 0; j < stu.getMaxQuizs(); j++) {
				if(*(qgrades + j) >= 0.0)
					cout << *(qgrades + j) << " ";
				else
					cout << "UG ";
				
			}
			delete qgrades;
			cout << "\t|\t";
			double* egrades = stu.getExamGrades();
			for (int j = 0; j < stu.getMaxExams(); j++) {
				if(*(egrades + j) >= 0.0)
					cout << *(egrades + j) << " ";
				else
					cout << "UG ";
				
			}
			delete egrades;
			cout << endl;
		}
	} else {
		cout << "\nThere are no students in the gradebook. Please add them using the \'Add Students\' menu" << endl;
	}
	pause();
	return;
}