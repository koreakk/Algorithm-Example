#include <iostream>
using ull = unsigned long long;

/* O(N^0.5) */
ull phi(ull n) {
	ull ret = n;
	for (ull i = 2; i*i <= n; ++i) {
		if (n%i == 0) {
			ret -= ret / i;
			while (n%i == 0) {
				n /= i;
			}
		}
	}
	if (n != 1) {
		ret -= ret / n;
	}
	return ret;
}