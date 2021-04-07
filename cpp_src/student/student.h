#pragma once
#include <string>
using namespace std;

// Levi Shaffer
// COP 3014

class student {
	public:
		student();
		student(string name);
		bool addExamGrade(double grade);
		bool addHWGrade(double grade);
		bool addQuizGrade(double grade);
		double getAverages();
		void setName(string name);
		string getName();
		void print(bool sub=false);
		double* getExamGrades();
		double* getHWGrades();
		double* getQuizGrades();
		inline int getExamCount() {return examCount;};
		inline int getQuizCount() {return quizCount;};
		inline int getHWCount() {return hwCount;};
		inline int getMaxExams() {return maxExamGrades;};
		inline int getMaxHWs() {return maxHWGrades;};
		inline int getMaxQuizs() {return maxQuizGrades;};
		inline double getExamAverage() {return eAvg;};
		inline double getQuizAverage() {return qAvg;};
		inline double getHWAverage() {return hAvg;};
		void directExamChange(int pos, double grade);
		void directQuizChange(int pos, double grade);
		void directHWChange(int pos, double grade);
		void overwriteWeights(double hw, double quiz, double exam);

	private:
		double examWeight;
		double quizWeight;
		double homeworkWeight;
		static const int maxExamGrades = 3;
		static const int maxHWGrades = 5;
		static const int maxQuizGrades = 5;
		double avg;
		double eAvg;
		double qAvg;
		double hAvg;
		int examCount;
		int hwCount;
		int quizCount;
		void calcAverages();
		string name;
		double examGrades[maxExamGrades];
		double quizGrades[maxQuizGrades];
		double HWGrades[maxHWGrades];
	
};
