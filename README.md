# Rust-Gradebook
Translating one of my first C++ projects from school into Rust


## Details

The class was Data Structures and Algorithms I, and I was tasked with creating a gradebook to track student grades, as well as an interface for said gradebook.

I remember thinking this project was the most intense one I had done yet at my university, although looking at the original source code indicates that I was very naive.

It has been about 2 years since this project was done, and now I am a much more confident programmer, especially with C++. 

However, the new kid on the block (Rust) has been giving me the side-eye, and has taken to spreading rumors about the glory of writing Rust, how it is about as fast as C/C++ with much more memory safety, and how it has all these cool features C++ just does not have, like a sane package management system.

So, I've decided to take on Rust and tackle learning it, and I figured there is no better place to really start than with the first C++ program that ever gave me trouble.

## Building

Building the original project is confusing and annoying, since at the time I created the project I was scared of Makefiles. 

If you want to build the original hot garbage, you can `cd` into `cpp_src` and run the following command:
```
g++ -Wall -std=c++11 student/student.cpp gradebook/gradebook.cpp main.cpp -o student_gradebook
```

Building instructions w/ Rust will come once the project is actually complete.
