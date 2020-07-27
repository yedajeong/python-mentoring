#include <iostream>
#include <string>
#include <vector>
using namespace std;

//응용 03
class Student {
private:
	string name;
	int Id;
	string depart;
	vector<string> vecLecture;
	vector<char> vecGrade;

public:
	Student(string _name = "default", int _Id = 0, string _depart = "depart")
		:name(_name), Id(_Id), depart(_depart) {}
	
	void setName(string _name) {
		name = _name;
	}
	void setId(int _Id) {
		Id = _Id;
	}
	void setDpt(string _depart) {
		depart = _depart;
	}
	void print() {
		cout << name << "\t" << Id << "\t" << depart << endl;
	}
	void addGrade(string lecture, char grade) {
		vecLecture.push_back(lecture);
		vecGrade.push_back(grade);
	}
	void printGrades() {
		for (unsigned i = 0; i < vecLecture.size(); i++) {
			cout << vecLecture[i] << "\t" << vecGrade[i] << endl;
		}
		cout << "GPA : " << getGPA() << endl;
	}
	float getGPA() {
		float score = 0;
		for (char elem : vecGrade) {
			if (elem == 'A')
				score += 4.0f;
			else if (elem == 'B')
				score += 3.0f;
			else if (elem == 'C')
				score += 2.0f;
			else if (elem == 'D')
				score += 1.0f;
			else if (elem == 'F')
				score += 0.0f;
		}
		return score / float(vecGrade.size());
	}
	void getYear(int year) {
		int iphak = int(float(Id) / 1000000);

		if (year - iphak == 0)
			cout << "Freshmen(1학년)" << endl;
		else if (year - iphak == 1)
			cout << "Sophomore(2학년)" << endl;
		else if (year - iphak == 2)
			cout << "Junior(3학년)" << endl;
		else if (year - iphak == 3)
			cout << "Senior(4학년)" << endl;
		else if (year - iphak >= 4)
			cout << "About to graduate(5학년 이상)" << endl;
	}
};

int main() {
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";

	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setId(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Machine Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";

	return 0;
}