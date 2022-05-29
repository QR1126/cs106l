#include <string>
#include <iostream>
#include <cmath> //gives us pow and sqrt!

using std::string; using std::cout;
using std::cin; using std::pow;
using std::sqrt; using std::endl;

//want: a function names quadratic that will take in 3 doubles and return
//a combination of: does a solution exist, and if so, what is it?
std::pair<bool, std::pair<double, double>> quadratic(double a, double b, double c){
	//get radical, test if negative, return indicating no roots
	//otherwise get roots and return
	auto delta = pow(b, 2) - (4.0 * a * c);
	if (delta < 0) {
		return std::make_pair(false, std::make_pair(0, 0));
	}
	auto root1 = (-1 * b + sqrt(delta)) / (2.0 * a);
	auto root2 = (-1 * b - sqrt(delta)) / (2.0 * a);
	return std::make_pair(true, std::make_pair(root1, root2));
}

int main(){
	//get 3 doubles (ax^2 + bx + c)
	double a, b, c;
	cout << "Give me 3 coefficients: " << endl;

	//This line gets 3 numbers from user input and stores them in a, b and c 
	//we will learn more about cin on Thursday
	cin >> a >> b >> c;
	//get roots if they exist
	//some call to quadratic function!
	// std::pair<bool, std::pair<double, double>> res = quadratic(a, b, c);
	auto res = quadratic(a, b, c);
	if (!res.first) {
		cout << "No solutions exist!" << endl;
	} else {
		cout << "Solutions are " << res.second.first << " " << res.second.second << endl;
	}
	return 0;
}