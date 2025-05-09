#pragma once
#ifndef GUARD_Studnet_info
#define GUARD_Studnet_info
// Studnet_info.h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student_info{
private:
	string name;
	double midterm, final;
	vector<double> homework;
public:
	// 생성자!
	Student_info(); // 빈 Student_info 객체 생성
	Student_info(istream&); // 스트림을 읽어 Student_info 객체를 생성

	string get_name() const { return name; }
	void set_name(string n) { name = n; } // 에런 추가

	bool valid() const { return !homework.empty(); }
	istream& read(istream&);
	double grade() const;
};

bool compare(const Student_info&, const Student_info&);
#endif
