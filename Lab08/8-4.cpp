#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

//04
bool is_prime(int num) {
	if (num < 2)
		return false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) // 소수는 1과 자기자신만을 약수로 가지니까
			return false;
		else
			continue;
	}
	return true;
}

// return값이 vertor<int>인 함수
vector<int> primes(int lower, int upper) {
	vector<int> v;
	for (int i = lower; i <= upper; i++) {
		if (is_prime(i))
			v.push_back(i);
		else
			continue;
	}
	return v; 
}

int main() {
	int lower = 10, upper = 100;
	vector<int> vec = primes(lower, upper);
	for (int elem : vec)
		cout << elem << setw(5);
	cout << endl;

	return 0;
}