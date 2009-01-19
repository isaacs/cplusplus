#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main (int argc, char** argv) {
	
	cout << "Please enter your name: ";
	string name;
	cin >> name;
	const string greeting = "Hello, " + name + "!";
	const int pad = 1;
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;
	
	
	for (int r = 0; r < rows; r++) {
	
		cout << endl;
		string::size_type c = -1;
		
		while (
			++c < cols
		) if (
			r == pad + 1 && c == pad + 1
		) {
			cout << greeting;
			c += greeting.size() - 1;
		} else cout << ((
			r == 0 || r == rows - 1 ||
			c == 0 || c == cols - 1
		) ? "*" : " ");
	}
	return 0;
}
