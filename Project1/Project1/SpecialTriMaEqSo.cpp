#include "Header.h"

vec SpecialTriMaEqSo(vec d) {

	vec delta;
	double epsilon = 0.5;
	int n = d.size();


	//Algorithm 1 (row reduction)
	//Decleares new values for delta
	delta = { d[0] };
	for (int i = 1; i < n; i++) {
		delta.push_back(d[i] - epsilon * delta[i - 1]);
	}


	//Algorithm 2 (Solve linear equations)
	vec v;
	v = { delta[n - 1] / 3 };
	for (int i = n - 2; i >= 0; i--) {
		v.insert(v.begin(), ((delta[i + 1] + v[0]) / 3));
	}

	return v;
}