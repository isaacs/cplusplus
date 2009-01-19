#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

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


struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
};
istream& read_hw (istream& in, vector<double>& hw) {
	if (!in) return in;
	hw.clear();
	double x;
	while (
		in >> x
	) hw.push_back(x);
	in.clear();
	return in;
}
istream& read (istream& is, Student_info& s) {
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}


bool compare (const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}

double median (vector<double> vec) {
	typedef vector<double>::size_type vec_sz;
	
	vec_sz size = vec.size();
	if (
		size == 0
	) throw domain_error("median of empty vector");
	
	sort( vec.begin(), vec.end() );
	vec_sz mid = size / 2;
	return size % 2 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}
double grade (double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade (double midterm, double final, const vector<double>& homework) {
	if (
		homework.size() == 0
	) throw domain_error("no homework!");
	return grade(midterm, final, median(homework));
}
double grade (Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}

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
			return 1;
		}
		cout << endl;
	}
	return 0;
}