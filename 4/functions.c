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

int main () {
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name <<  "!" << endl;
	
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;
	cout << "Enter all your homework grades, followed by EOF: ";
	vector<double> homework;
	read_hw(cin, homework);

	try {
		streamsize prec = cout.precision();
		double g = grade(midterm, final, homework);
		cout << "Your final grade is " << setprecision(3)
			<< g << setprecision(prec) << endl;
	} catch (domain_error) {
		cout << endl << "You must enter your grades.  "
			"Please try again." << endl;
		return 1;
	}
	
	return 0;
}