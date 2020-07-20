#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

// Utils
int findStudentById(vector<string> studentIds, string id);
int findLectureByCode(vector<string> lectureCodes, string code);
void deleteElement(vector<string>& v, int index);

// File read
void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);

// File write
void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes);
void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits);

// Get user input
string getInputId();
string getInputPassword();

// Login
int studentLogin(const vector<string>& studentIds, const vector<string>& passwords);
bool adminLogin();
int login(const vector<string>& studentIds, const vector<string>& passwords);

// Common
void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user = -100);

// Admin
void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);
void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);

// User
void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user);
void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user);
void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user);
void changePassword(vector<string>& passwords, const int& user);
int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user);

int main() {
	int user = -1; //user index
	int status = -1;

	// Student Info
	vector<string> studentIds;
	vector<string> passwords;
	vector<string> names;
	vector<int> credits;
	vector<vector<string>> appliedLectureCodes;

	// Lecture Info
	vector<string> lectureCodes;
	vector<string> lectureNames;
	vector<int> lectureCredits;
	vector<int> limits;

	// Read from files
	readStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
	readLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

	// Login phase
	while (status == -1) {
		user = login(studentIds, passwords);

		if (user == -999) { // Login fail
			break;
		}
		else if (user == -1) { // Exit command
			break;
		}
		else if (user == -100) { // Admin login success
			status = runAdmin(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits);
		}
		else { // Student login success (user = studentId���� �� index)
			status = runStudent(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		}
	}



	// Write to files
	writeStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
	writeLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

	return 0;
}

int findStudentById(vector<string> studentIds, string id) {
	for (unsigned i = 0; i < studentIds.size(); i++) {
		if (studentIds[i] == id)
			return i;
	}
	return -1;
}

int findLectureByCode(vector<string> lectureCodes, string code) {
	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		if (lectureCodes[i] == code)
			return i;
	}
	return -1;
}

void deleteElement(vector<string>& v, int index) {
	v.erase(v.begin() + index);
}

void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	ifstream fin("students.txt");
	string s;
	string delimeter = "\t"; //.txt file���� �����ڷ� ���� tabŰ
	int index = 0, user = 0; //.txt file���� tabŰ�� index (������Ʈ), appliedLC vector�� [��]�� �ش��ϴ� user

	while (getline(fin, s)) {

		index = s.find(delimeter); //delimeter�� s���� ã�� index�� ��ȯ�Ͽ� index������ ������Ʈ
		studentIds.push_back(s.substr(0, index)); //0(ó��)���� index(��) ��ŭ s���� �߶� studentIds���� �ڿ� �߰�
		s = s.substr(index + delimeter.length()); //��� id�� �߶󳻰� �� �ں��� �ٽ� delimeterã������ s ������Ʈ

		//studentIds ���Ϳ� id�߰��ߴ� �Ͱ� ����
		index = s.find(delimeter);
		passwords.push_back(s.substr(0, index));
		s = s.substr(index + delimeter.length());

		index = s.find(delimeter);
		names.push_back(s.substr(0, index));
		s = s.substr(index + delimeter.length());

		index = s.find(delimeter);
		credits.push_back(stoi(s.substr(0, index)));
		s = s.substr(index + delimeter.length());

		index = s.find(delimeter);
		appliedLectureCodes.push_back(vector<string>(0)); //�л� ��==fin���κ��� �о���� s���� ��ŭ appliedLC vector�� �࿡ �� ����
		if (stoi(s.substr(0, index)) != 0) { //������û������ 0�� �ƴ�->������û�� ������ ����
			s = s.substr(index + delimeter.length()); //ã�Ҵ� \t�ں��Ͱ� �����ڵ�ϱ�
			while (s.find(delimeter) != string::npos) {
				index = s.find(delimeter);
				appliedLectureCodes[user].push_back(s.substr(0, index)); //\tã�� �� �ձ����� �� �����ڵ�
				s = s.substr(index + delimeter.length()); //�� �� �Է��� �����ڵ� �ں��� \t ã��
			}
			appliedLectureCodes[user].push_back(s); //���� ���������� s�� \tŰ ���� �����ڵ� �ϳ��� ���������ϱ�
		}
		//else : ������û������ 0��->������û�� ���� ����->ũ�� 0�� ���� �״�� ����

		user++; //appliedLectureCode[0]->[1]->[2] ...
	}

	fin.close();
}

void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	ifstream fin("lectures.txt");
	string s;
	string delimeter = "\t";
	int index = 0;

	while (getline(fin, s)) {

		//readStudentFile���� delimeter�� ã�� ���ϴ� �ܾ ���� ���� vector �ڿ� �ܾ� �߰��ϴ� ��� ����
		index = s.find(delimeter);
		lectureCodes.push_back(s.substr(0, index));
		s = s.substr(index + delimeter.length());

		index = s.find(delimeter);
		lectureNames.push_back(s.substr(0, index));
		s = s.substr(index + delimeter.length());

		index = s.find(delimeter);
		lectureCredits.push_back(stoi(s.substr(0, index))); //lectureCredits�� limits�� ���Ҵ� int�̱� ������ stringtoint(stoi)�� type��ȯ
		s = s.substr(index + delimeter.length());

		limits.push_back(stoi(s));

	}

	fin.close();
}

void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes) {

	ofstream fout("students.txt");

	for (unsigned i = 0; i < studentIds.size(); i++) {
		fout << studentIds[i] << "\t" << passwords[i] << "\t" << names[i] << "\t" << credits[i] << "\t";
		if (appliedLectureCodes[i].size() != 0) { //appliedLC������ �� �л�([i])���� ���� ũ�Ⱑ 0�� �ƴ� == ��û�� ������ ����
			for (unsigned j = 0; j < appliedLectureCodes[i].size(); j++) {
				if (j == appliedLectureCodes[i].size() - 1) {
					fout << appliedLectureCodes[i][j]; //���� ������ �����ڵ� �ڿ��� tabŰ ����
					break; //�Ʒ� �� ����x ����� for�� Ż��
				}
				fout << appliedLectureCodes[i][j] << "\t"; //������ �����ڵ尡 �ƴ϶�� tabŰ �߰����ֱ�
			}
		}
		fout << endl;
	}

	fout.close();
}

void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits) {

	ofstream fout("lectures.txt");

	for (unsigned i = 0; i < lectureCodes.size(); i++) { //lectureCoeds�� ���� ũ�⸸ŭ ���ǰ� ����
		fout << lectureCodes[i] << "\t" << lectureNames[i] << "\t" << lectureCredits[i] << "\t" << limits[i] << endl; //�� ���Ϳ��� i��° ����������� file�� ���
	}

	fout.close();
}

string getInputId() {
	//����ڷκ��� Ű����� id�Է�, return
	string id;
	cout << "���̵�: ";
	cin >> id;
	return id;
}

string getInputPassword() {
	//����ڷκ��� Ű����� password�Է�, return
	string password;
	cout << "��й�ȣ: ";
	cin >> password;
	return password;
}

int studentLogin(const vector<string>& studentIds, const vector<string>& passwords) {
	/* ���� ȣ�� �Լ�: getInputId(), getInputPassword()*/
	string inputId = getInputId();
	string inputPassword = getInputPassword();

	int studentIdsIndex = findStudentById(studentIds, inputId); //studentIds������ �ε��� or -1

	if (studentIdsIndex != -1) { //studentIds������ �ε���->���̵� ����o
		if (passwords[studentIdsIndex] == inputPassword) //passwords������ studentIdsIndex�� inputPassword����->�����ġ
			return studentIdsIndex; //�α��� ����->�л� index ��ȯ
	}
	return -1; //���̵� ����x->�α��� ���� (-1)
}

bool adminLogin() {
	/* ���� ȣ�� �Լ�: getInputId(), getInputPassword()*/
	string inputId = getInputId();
	string inputPassword = getInputPassword();

	if (inputId == "admin") {
		if (inputPassword == "admin") //inputId,Password��� ��ġ�ϸ� true, �ƴϸ� false ��ȯ
			return true;
	}
	return false;
}

int login(const vector<string>& studentIds, const vector<string>& passwords) {
	int input; //1,2,0 �� �Է�
	unsigned failCount; //����Ƚ�� ī��Ʈ
	cout << "----------------------------------------------------" << endl <<
		"1. �л� �α���" << endl <<
		"2. ������ �α���" << endl <<
		"0. ����" << endl <<
		"----------------------------------------------------" << endl << ">>";

	cin >> input;

	/* ���� ȣ�� �Լ�: studentLogin(), adminLogin()*/
	if (input == 1) { //�л� �α���
		int stu_result = studentLogin(studentIds, passwords); //��ȯ�� ����:-1 / ����:�л��ε���
		if (stu_result != -1) //���� ��
			return stu_result;
		else { //else�� �Ѿ���� ���� �̹� �� �� ����, failCount=1���� ����
			for (failCount = 1; failCount < 3; failCount++) {
				cout << "�α��� " << failCount << "ȸ ���� (3ȸ ���н� ����)" << endl;
				stu_result = studentLogin(studentIds, passwords);
				if (stu_result != -1) {
					return stu_result;
					failCount = 0; //failCount�� 0���� �ʱ�ȭ
					break;
				}
			}
			cout << "�α��� 3ȸ ���� (3ȸ ���н� ����)" << endl;
			cout << "3ȸ �����Ͽ� �����մϴ�." << endl;
			failCount = 0; //failCount�� 0���� �ʱ�ȭ
			return -999;
		}
	}
	else if (input == 2) { //������ �α���
		if (adminLogin()) //adminLogin()�Լ��� return�� true/false
			return -100;
		else {
			for (failCount = 1; failCount < 3; failCount++) {
				cout << "�α��� " << failCount << "ȸ ���� (3ȸ ���н� ����)" << endl;
				if (adminLogin()) {
					return -100;
					failCount = 0; //failCount�� 0���� �ʱ�ȭ
					break;
				}
			}
			cout << "�α��� 3ȸ ���� (3ȸ ���н� ����)" << endl;
			cout << "3ȸ �����Ͽ� �����մϴ�." << endl;
			failCount = 0; //failCount�� 0���� �ʱ�ȭ
			return -999;
		}
	}
	else if (input == 0)
		return -1;
}

void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames,
	const vector<int>& lectureCredits, const vector<int>& limits, const int& user) {
	//user�� -100�� ��(������) : ������ ���ǵ��� ����� ��� 
	//user�� -100�� �ƴ� ��(�л�) : ���� ����ڰ� ��û�� �������� ����� ���
	//user�� �Է� �ȳ־��ָ� default�� -100�̶� ������ ���� ����� ���

	if (user == -100) {
		cout << "----------------------------------------------------" << endl <<
			"�����ڵ�\t���Ǹ�\t����\t���������ο�" << endl <<
			"----------------------------------------------------" << endl;
		for (unsigned i = 0; i < lectureCodes.size(); i++) {
			cout << lectureCodes[i] << "\t" << lectureNames[i] << "\t" << lectureCredits[i] << "\t" << limits[i] << endl;
		}
		cout << "----------------------------------------------------" << endl;
	}
	else {
		cout << "----------------------------------------------------" << endl <<
			"�����ڵ�\t���Ǹ�\t����\t���������ο�" << endl <<
			"----------------------------------------------------" << endl;
		if (appliedLectureCodes[user].size() == 0)
			cout << "������û�� ������ �����ϴ�." << endl <<
			"----------------------------------------------------" << endl;
		else {
			for (unsigned i = 0; i < appliedLectureCodes[user].size(); i++) {
				int index = findLectureByCode(lectureCodes, appliedLectureCodes[user][i]);
				cout << lectureCodes[index] << "\t" << lectureNames[index] << "\t" << lectureCredits[index] <<
					"\t" << limits[index] << endl;
			}
			cout << "----------------------------------------------------" << endl;
		}
	}
}

void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	
	string inputName, inputId, inputPassword; //�����ڷκ��� �л� ���� �Է¹���

	cout << "----------------------------------------------------" << endl << "�й� : ";
	cin >> inputId;
	cout << "��й�ȣ : ";
	cin >> inputPassword;
	cout << "�л� �̸� : ";
	cin >> inputName;
	cout << "----------------------------------------------------" << endl;

	if (findStudentById(studentIds, inputId) != -1) {
		cout << "�̹� �����ϴ� �й��Դϴ�." << endl;
	}
	else { //studentIds���Ϳ� ���� �й��� ��� �߰� ����
		studentIds.push_back(inputId);
		passwords.push_back(inputPassword);
		names.push_back(inputName);
		credits.push_back(18);
		appliedLectureCodes.push_back(vector<string>(0));
		cout << "���������� ��ϵǾ����ϴ�." << endl;
	}
}

void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	string inputLecCode, inputLecName; //�����ڷκ��� �߰��� ���� ���� �Է¹���
	int inputLecCredit, inputLimit;

	cout << "----------------------------------------------------" << endl << "�����ڵ� : ";
	cin >> inputLecCode;
	cout << "����� : ";
	cin >> inputLecName;
	cout << "���� : ";
	cin >> inputLecCredit;
	cout << "�����ο� : ";
	cin >> inputLimit;
	cout << "----------------------------------------------------" << endl;

	if (findLectureByCode(lectureCodes, inputLecCode) != -1) {
		cout << "�̹� �����ϴ� �����ڵ� �Դϴ�." << endl;
	}
	else { //lectureCodes���Ϳ� ���� �й��� ��� �߰� ����
		lectureCodes.push_back(inputLecCode);
		lectureNames.push_back(inputLecName);
		lectureCredits.push_back(inputLecCredit);
		limits.push_back(inputLimit);
		cout << "���������� ���ǰ� �����Ǿ����ϴ�." << endl;
	}
}

void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	/* ���� ȣ�� �Լ�: printLectures*/
	string inputLecCode; //�����ڷκ��� ������ ���� ���� �Է¹���

	while (1) { //�ƹ�Ű ������ ��� ���� ���� �޴��� �ӹ���

		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits); //default -100

		cout << "������ ���� �ڵ� (0: �ڷΰ���) >> ";
		cin >> inputLecCode;

		if (inputLecCode == "0") //�����ڵ� �Է¹��� �� 0������ �ڷΰ��� (while�� ��������)
			break;

		int deleteIndex = findLectureByCode(lectureCodes, inputLecCode);
		int appliedLCIndex;

		if (deleteIndex == -1) {
			cout << "��ġ�ϴ� �ڵ尡 �����ϴ�." << endl;
		}
		else {
			// �� ���� ��Ҵ� �ֵ� �ϴ� �����ߵ�->appliedLC[user], credit[user]���� �װ��� ���� �����ؾ��ϴϱ� �������� ����������
			// credits, appliedLectureCodes�� �л��� ����
			// �ش� �����ڵ� ��Ҵ� �ֵ� ã�Ƽ� �����
			for (unsigned i = 0; i < appliedLectureCodes.size(); i++) { //i : �л��ε���
				if (findLectureByCode(appliedLectureCodes[i], inputLecCode) != -1) { //i��° �л��� �� ���� ��û������
					appliedLCIndex = findLectureByCode(appliedLectureCodes[i], inputLecCode); //aLC[i]���� �ε��� aLCI�� ����
					deleteElement(appliedLectureCodes[i], appliedLCIndex);
					credits[i] += lectureCredits[deleteIndex];
				}
			}
			deleteElement(lectureCodes, deleteIndex);
			deleteElement(lectureNames, deleteIndex);
			lectureCredits.erase(lectureCredits.begin() + deleteIndex);
			limits.erase(limits.begin() + deleteIndex);

			cout << "���������� ���ǰ� ���Ǿ����ϴ�." << endl;
		}

		system("PAUSE");
	}
}

int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	
	int input;

	/* ���� ȣ�� �Լ�: addStudent, addLecture, deleteLecture*/
	while (1) {

		cout << "----------------------------------------------------" << endl <<
			"1. �л� �߰�" << endl <<
			"2. ���� ����" << endl <<
			"3. ���� ����" << endl <<
			"4. �α׾ƿ�" << endl <<
			"0. ����" << endl <<
			"----------------------------------------------------" << endl << ">>";
		cin >> input;

		if (input == 1) {
			addStudent(studentIds, passwords, names, credits, appliedLectureCodes);
			system("PAUSE");
		}
		else if (input == 2) {
			addLecture(lectureCodes, lectureNames, lectureCredits, limits);
			system("PAUSE");
		}
		else if (input == 3) {
			deleteLecture(lectureCodes, lectureNames, lectureCredits, limits, credits, appliedLectureCodes);
		}
		else if (input == 4) {
			return -1;
			break;
		}
		else {
			return 1;
			break;
		}
	}
}

void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user) {
	//�л��޴� - ������û, ������Ȳ, ����öȸ �޴����� ȣ��
	cout << "----------------------------------------------------" << endl <<
			"�й� : " << studentIds[user] << "\t" << "�̸� : " << names[user] << "\t" << "������������ : " << credits[user] << endl <<
			"----------------------------------------------------" << endl;
}

void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	/* ���� ȣ�� �Լ�: printStudent, printLectures*/
	printStudent(studentIds, names, credits, user);
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits); //user�� default�� -100->���Ǹ�� ���
	string applyCode;

	while (1) {

		cout << "��û�� ���� �ڵ�(0: �ڷΰ���) >>";
		cin >> applyCode;

		if (applyCode == "0")
			break; //0�̸� �ڷΰ���->while�� break�ϰ� �Լ� ����

		int availCredit = credits[user];
		int applyIndex = findLectureByCode(lectureCodes, applyCode);
		int applyCredit = lectureCredits[applyIndex];

		//���4 : ���� ���� �ο��� 0���� ���->��û �Ұ���
		if (limits[applyIndex] == 0)
			cout << "���������� �� á���ϴ�." << endl;

		//���3 : �������������� ��û�Ϸ��� ������ �������� ���� ���->��û �Ұ���
		else if (availCredit < applyCredit)
			cout << "�������������� �����մϴ�." << endl;

		//���1 : applyCode�� �̹� ��û�� �����ڵ� ���Ϳ� �ִ� ���->��û �Ұ���
		else if (findLectureByCode(appliedLectureCodes[user], applyCode) != -1)
			cout << "�̹� �ش� ������ ��û�߽��ϴ�." << endl;

		//���2 : applyCode�� �ش��ϴ� ������ ������ (�ٸ� �ڵ�, ���� �����)������� ���� �����ϴ� ���->��û �Ұ���
		else if (findLectureByCode(appliedLectureCodes[user], applyCode) == -1) //�Է¹��� ��û�����ڵ�(applyCode)�� ������� ��û�����ڵ�(appliedLC[user])�� ����
		{
			for (unsigned i = 0; i < lectureNames.size(); i++) {
				if (lectureNames[applyIndex] == lectureNames[i] && applyIndex != i) { //index(applyIndex�� i)�� ���� �ٸ��� lectureNames vector������ ���Ǹ��� ����
					cout << "�̹� ���ϸ��� ������ ��û�߽��ϴ�." << endl;
					break; // ����� for�� Ż��
				}
				else if (i == lectureNames.size() - 1) {
					appliedLectureCodes[user].push_back(applyCode);
					credits[user] -= applyCredit;
					limits[findLectureByCode(lectureCodes, applyCode)] -= 1;
					cout << "[" << applyCode << "] " << lectureNames[findLectureByCode(lectureCodes, applyCode)] << "(��)�� ���������� ��û�Ͽ����ϴ�." << endl;
				}
			}
		}

		system("PAUSE");
	}
}

void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	/* ���� ȣ�� �Լ�: printStudent, printLectures*/
	printStudent(studentIds, names, credits, user);
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);

	string disapplyCode;

	while (1) {

		cout << "öȸ�� ���� �ڵ�(0: �ڷΰ���) >>";
		cin >> disapplyCode;

		if (disapplyCode == "0") //0������ while�� break�ϰ� �ٽ� �л��޴���
			break;

		int disapplyStuIndex = findLectureByCode(appliedLectureCodes[user], disapplyCode); //�л��� ��û�� �����ڵ庤�Ϳ� �Է��� disapplyCode�� �ε��� ����
		int disapplyLecIndex = findLectureByCode(lectureCodes, disapplyCode); //�����ڵ庤�Ϳ� �Է��� disapplyCode�� �ε��� ����

		if (disapplyStuIndex != -1) { //��û ������
			deleteElement(appliedLectureCodes[user], disapplyStuIndex);
			credits[user] -= lectureCredits[disapplyLecIndex]; //-�� �ƴ϶� +�� �ؾ��� �̤̤̽ù�
			limits[disapplyLecIndex] += 1;
			cout << "[" << lectureCodes[disapplyLecIndex] << "] " << lectureNames[disapplyLecIndex] << "��(��) öȸ�Ͽ����ϴ�." << endl;
		}
		else //��û ���� �ʾ�����
			cout << "���� �ڵ尡 �ùٸ��� �ʽ��ϴ�." << endl;

		system("PAUSE");
	}
}

void changePassword(vector<string>& passwords, const int& user) {
	string passwordInput;

	cout << "----------------------------------------------------" << endl <<
		"���� Ȯ���� ���� ��й�ȣ�� �� �� �� �Է����ּ���." << endl << "��й�ȣ : ";
	cin >> passwordInput;
	cout << "----------------------------------------------------" << endl;

	if (passwordInput != passwords[user]) {
		cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
	}
	else {
		cout << "----------------------------------------------------" << endl <<
			"���� ������ ��й�ȣ�� �Է��ϼ���." << endl <<
			"��й�ȣ : ";
		cin >> passwordInput;
		passwords[user] = passwordInput;
		cout << "����Ǿ����ϴ�." << endl <<
			"----------------------------------------------------" << endl;
	}

	system("PAUSE"); //�ƹ�Ű ������ �л��޴��� �̵���
}

int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user) {
	
	int input;

	/* ���� ȣ�� �Լ�: applyLecture, printStudent, printLectures, disapplyLecture, changePassword*/
	//return �α׾ƿ�(-1), ����(1)
	while(1) { //5, 0��ư ������ ������ �л��޴��� �ӹ���

		cout << "----------------------------------------------------" << endl <<
			"1. ���� ��û" << endl <<
			"2. ���� ��Ȳ" << endl <<
			"3. ���� öȸ" << endl <<
			"4. ��й�ȣ ����" << endl <<
			"5. �α׾ƿ�" << endl <<
			"0. ����" << endl <<
			"----------------------------------------------------" << endl << ">>";
		cin >> input;

		if (input == 1) {
			applyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		}

		else if (input == 2) {
			printStudent(studentIds, names, credits, user);
			printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
			system("PAUSE");
		}
		
		else if (input == 3) {
			disapplyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		}

		else if (input == 4) {
			changePassword(passwords, user);
		}

		else if (input == 5) {
			return -1;
			break; //return�ϸ� break���� ����� ��!
		}

		else {
			return 1;
			break;
		}
	}
}