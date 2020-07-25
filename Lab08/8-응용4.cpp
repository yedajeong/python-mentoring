#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

//응용 04
int inputGrade(float grade) {
	cin >> grade;
	// 0이상 100이하의 정수 아니면 프로그램 종료
	if ((grade - (int)grade) != 0.0 || grade < 0 || grade>100) {
		cout << "invalid input!!!" << endl;
		exit(EXIT_FAILURE);
	}
	else
		return (int)grade;
}
//return type은 int형 변수를 가리키는 포인터
const int* topGrade(const vector<int> &grade) {
	const int *tg;
	if (grade[0] > grade[1]) {
		if (grade[0] > grade[2])
			tg = &grade[0];
		else
			tg = &grade[2];
	}
	else if (grade[1] < grade[2])
		tg = &grade[2];
	else
		tg = &grade[1];
	return tg;
}

int main() {
	vector<int> grades;
	float _grade = 0 ; // 입력받을 사용자의 점수 초기화
	for (int i = 0; i < 3; i++) { 
		cout << "Input" << i << "-th grade(0-100):";
		int grade = inputGrade(_grade);
		grades.push_back(grade);
	}

	const int result = *topGrade(grades);
	cout << "Top Grade: " << result;
	return 0;
}