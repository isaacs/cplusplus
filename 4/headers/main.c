#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "median.h"
#include "Student_info.h"
#include "grade.h"

using std::cin;
using std::cout;
using std::istream;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::domain_error;
using std::max;



int main () {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	sort(students.begin(), students.end(), compare);
	
	for (
		vector<Student_info>::size_type i = 0;
		i != students.size();
		i++
	) {
		cout << students[i].name <<
			string(maxlen + 1 - students[i].name.size(), ' ');
		try {
			streamsize prec = cout.precision();
			double g = grade(
				students[i].midterm, students[i].final, students[i].homework
			);
			cout << setprecision(3) << g << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
			// return 1;
		}
		cout << endl;
	}
	return 0;
}