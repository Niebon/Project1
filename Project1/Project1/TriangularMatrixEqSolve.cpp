#include "Header.h"

vec TriMaEqSo(vec a, vec b, vec c, vec d) {
	vec beta;
	vec delta;
	double epsilon;
	int n = b.size();


	//Algorithm 1 (row reduction)
	//Decleares new values for beta and delta

	beta = { b[0] };
	delta = { d[0] };

	for (int i = 1; i < n; i++) {
		epsilon = a[i - 1] / beta[i - 1];
		beta.push_back(b[i] - epsilon * c[i - 1]);
		delta.push_back(d[i] - epsilon * delta[i - 1]);
	}


	//Algorithm 2 (Solve linear equations)
	vec v;
	v = { delta[n-1]/ beta[n - 1] };
	for (int i = n-2; i >= 0; i--) {
		v.insert(v.begin(),((delta[i + 1] - c[i] * v[0]) / beta[i]));
	}

	return v;
}