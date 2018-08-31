#include "Header.h"
#include <iostream>

//Analytic solution
double uanalytic(double x);

//Right hand side
double RHS(double x);

vec TriMaEqSo(vec a, vec b, vec c, vec d);
vec SpecialTriMaEqSo(vec d);

int main() {
	int n = 100;
	double h = 1.0 / (n+1);
	vec x;
	vec a (n - 1, -1);
	vec b (n,2);
	vec c (n - 1,-1);
	vec f;
	vec d;



	//creating RHS
	for (int i = 0; i < n+2; i++) {
		x.push_back(i*h);
		d.push_back(RHS(x[i])*h*h);
	}

	//creating v
	vec v = TriMaEqSo(a, b, c, d);
	//vec v = SpecialTriMaEqSo(d);
	v.insert(v.begin(), 0.0);
	v.push_back(0.0);


	//comparison
	double s = 0;
	for (int i = 0; i < n + 2; i++) {
		std::cout << abs((uanalytic(x[i]) - v[i])/ uanalytic(x[i])) << std::endl;
		//s = s + (uanalytic(x[i]) - v[i])*(uanalytic(x[i]) - v[i]);
	}
	s = s / n;
	//std::cout << s << std::endl;

	std::cin.get();

}