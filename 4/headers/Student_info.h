#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <string>
#include <iostream>
#include <vector>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare (const Student_info&, const Student_info&);
std::istream& read (std::istream&, Student_info&);
std::istream& read_hw (std::istream&, std::vector<double>&);

#endif
