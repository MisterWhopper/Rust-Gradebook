GXX=g++
CFLAGS=-Wall -std=c++11

main : 
	$(CXX) $(CFLAGS) student/student.cpp gradebook/gradebook.cpp main.cpp -o student_gradebook

student : student/student.o
	$(CXX) $(CFLAGS) -c student/student.cpp -o student/student.o

gradebook : gradebook/gradebook.o
	$(CXX) $(CFLAGS) -c gradebook/gradebook.cpp -o gradebook/gradebook.o
