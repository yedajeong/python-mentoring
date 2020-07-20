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
		else { // Student login success (user = studentId벡터 내 index)
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
	string delimeter = "\t"; //.txt file에서 구분자로 쓰일 tab키
	int index = 0, user = 0; //.txt file에서 tab키의 index (업데이트), appliedLC vector의 [행]에 해당하는 user

	while (getline(fin, s)) {

		index = s.find(delimeter); //delimeter를 s에서 찾아 index로 반환하여 index변수에 업데이트
		studentIds.push_back(s.substr(0, index)); //0(처음)부터 index(개) 만큼 s에서 잘라 studentIds벡터 뒤에 추가
		s = s.substr(index + delimeter.length()); //썼던 id는 잘라내고 그 뒤부터 다시 delimeter찾기위해 s 업데이트

		//studentIds 벡터에 id추가했던 것과 동일
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
		appliedLectureCodes.push_back(vector<string>(0)); //학생 수==fin으로부터 읽어오는 s개수 만큼 appliedLC vector의 행에 빈 벡터
		if (stoi(s.substr(0, index)) != 0) { //수강신청과목이 0이 아님->수강신청한 과목이 있음
			s = s.substr(index + delimeter.length()); //찾았던 \t뒤부터가 과목코드니까
			while (s.find(delimeter) != string::npos) {
				index = s.find(delimeter);
				appliedLectureCodes[user].push_back(s.substr(0, index)); //\t찾고 그 앞까지가 한 과목코드
				s = s.substr(index + delimeter.length()); //한 번 입력한 과목코드 뒤부터 \t 찾기
			}
			appliedLectureCodes[user].push_back(s); //제일 마지막에는 s에 \t키 없이 과목코드 하나만 남아있으니까
		}
		//else : 수강신청과목이 0임->수강신청한 과목 없음->크기 0의 벡터 그대로 유지

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

		//readStudentFile에서 delimeter를 찾아 원하는 단어를 끊고 관련 vector 뒤에 단어 추가하는 방식 동일
		index = s.find(delimeter);
		lectureCodes.push_back(s.substr(0, index));
		s = s.substr(index + delimeter.length());

		index = s.find(delimeter);
		lectureNames.push_back(s.substr(0, index));
		s = s.substr(index + delimeter.length());

		index = s.find(delimeter);
		lectureCredits.push_back(stoi(s.substr(0, index))); //lectureCredits과 limits의 원소는 int이기 때문에 stringtoint(stoi)로 type변환
		s = s.substr(index + delimeter.length());

		limits.push_back(stoi(s));

	}

	fin.close();
}

void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes) {

	ofstream fout("students.txt");

	for (unsigned i = 0; i < studentIds.size(); i++) {
		fout << studentIds[i] << "\t" << passwords[i] << "\t" << names[i] << "\t" << credits[i] << "\t";
		if (appliedLectureCodes[i].size() != 0) { //appliedLC벡터의 각 학생([i])별로 벡터 크기가 0이 아님 == 신청한 과목이 있음
			for (unsigned j = 0; j < appliedLectureCodes[i].size(); j++) {
				if (j == appliedLectureCodes[i].size() - 1) {
					fout << appliedLectureCodes[i][j]; //제일 마지막 과목코드 뒤에는 tab키 없음
					break; //아래 문 실행x 가까운 for문 탈출
				}
				fout << appliedLectureCodes[i][j] << "\t"; //마지막 과목코드가 아니라면 tab키 추가해주기
			}
		}
		fout << endl;
	}

	fout.close();
}

void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits) {

	ofstream fout("lectures.txt");

	for (unsigned i = 0; i < lectureCodes.size(); i++) { //lectureCoeds의 벡터 크기만큼 강의가 존재
		fout << lectureCodes[i] << "\t" << lectureNames[i] << "\t" << lectureCredits[i] << "\t" << limits[i] << endl; //각 벡터에서 i번째 과목관련정보 file로 출력
	}

	fout.close();
}

string getInputId() {
	//사용자로부터 키보드로 id입력, return
	string id;
	cout << "아이디: ";
	cin >> id;
	return id;
}

string getInputPassword() {
	//사용자로부터 키보드로 password입력, return
	string password;
	cout << "비밀번호: ";
	cin >> password;
	return password;
}

int studentLogin(const vector<string>& studentIds, const vector<string>& passwords) {
	/* 내부 호출 함수: getInputId(), getInputPassword()*/
	string inputId = getInputId();
	string inputPassword = getInputPassword();

	int studentIdsIndex = findStudentById(studentIds, inputId); //studentIds벡터의 인덱스 or -1

	if (studentIdsIndex != -1) { //studentIds벡터의 인덱스->아이디 존재o
		if (passwords[studentIdsIndex] == inputPassword) //passwords벡터의 studentIdsIndex에 inputPassword존재->비번일치
			return studentIdsIndex; //로그인 성공->학생 index 반환
	}
	return -1; //아이디 존재x->로그인 실패 (-1)
}

bool adminLogin() {
	/* 내부 호출 함수: getInputId(), getInputPassword()*/
	string inputId = getInputId();
	string inputPassword = getInputPassword();

	if (inputId == "admin") {
		if (inputPassword == "admin") //inputId,Password모두 일치하면 true, 아니면 false 반환
			return true;
	}
	return false;
}

int login(const vector<string>& studentIds, const vector<string>& passwords) {
	int input; //1,2,0 중 입력
	unsigned failCount; //실패횟수 카운트
	cout << "----------------------------------------------------" << endl <<
		"1. 학생 로그인" << endl <<
		"2. 관리자 로그인" << endl <<
		"0. 종료" << endl <<
		"----------------------------------------------------" << endl << ">>";

	cin >> input;

	/* 내부 호출 함수: studentLogin(), adminLogin()*/
	if (input == 1) { //학생 로그인
		int stu_result = studentLogin(studentIds, passwords); //반환값 실패:-1 / 성공:학생인덱스
		if (stu_result != -1) //성공 시
			return stu_result;
		else { //else로 넘어오는 순간 이미 한 번 실패, failCount=1부터 시작
			for (failCount = 1; failCount < 3; failCount++) {
				cout << "로그인 " << failCount << "회 실패 (3회 실패시 종료)" << endl;
				stu_result = studentLogin(studentIds, passwords);
				if (stu_result != -1) {
					return stu_result;
					failCount = 0; //failCount는 0으로 초기화
					break;
				}
			}
			cout << "로그인 3회 실패 (3회 실패시 종료)" << endl;
			cout << "3회 실패하여 종료합니다." << endl;
			failCount = 0; //failCount는 0으로 초기화
			return -999;
		}
	}
	else if (input == 2) { //관리자 로그인
		if (adminLogin()) //adminLogin()함수의 return값 true/false
			return -100;
		else {
			for (failCount = 1; failCount < 3; failCount++) {
				cout << "로그인 " << failCount << "회 실패 (3회 실패시 종료)" << endl;
				if (adminLogin()) {
					return -100;
					failCount = 0; //failCount는 0으로 초기화
					break;
				}
			}
			cout << "로그인 3회 실패 (3회 실패시 종료)" << endl;
			cout << "3회 실패하여 종료합니다." << endl;
			failCount = 0; //failCount는 0으로 초기화
			return -999;
		}
	}
	else if (input == 0)
		return -1;
}

void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames,
	const vector<int>& lectureCredits, const vector<int>& limits, const int& user) {
	//user이 -100일 때(관리자) : 개설된 강의들의 목록을 출력 
	//user이 -100이 아닐 때(학생) : 현재 사용자가 신청한 수강과목 목록을 출력
	//user에 입력 안넣어주면 default가 -100이라서 개설된 강의 목록을 출력

	if (user == -100) {
		cout << "----------------------------------------------------" << endl <<
			"과목코드\t강의명\t학점\t수강가능인원" << endl <<
			"----------------------------------------------------" << endl;
		for (unsigned i = 0; i < lectureCodes.size(); i++) {
			cout << lectureCodes[i] << "\t" << lectureNames[i] << "\t" << lectureCredits[i] << "\t" << limits[i] << endl;
		}
		cout << "----------------------------------------------------" << endl;
	}
	else {
		cout << "----------------------------------------------------" << endl <<
			"과목코드\t강의명\t학점\t수강가능인원" << endl <<
			"----------------------------------------------------" << endl;
		if (appliedLectureCodes[user].size() == 0)
			cout << "수강신청한 과목이 없습니다." << endl <<
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
	
	string inputName, inputId, inputPassword; //관리자로부터 학생 정보 입력받음

	cout << "----------------------------------------------------" << endl << "학번 : ";
	cin >> inputId;
	cout << "비밀번호 : ";
	cin >> inputPassword;
	cout << "학생 이름 : ";
	cin >> inputName;
	cout << "----------------------------------------------------" << endl;

	if (findStudentById(studentIds, inputId) != -1) {
		cout << "이미 존재하는 학번입니다." << endl;
	}
	else { //studentIds벡터에 없는 학번일 경우 추가 가능
		studentIds.push_back(inputId);
		passwords.push_back(inputPassword);
		names.push_back(inputName);
		credits.push_back(18);
		appliedLectureCodes.push_back(vector<string>(0));
		cout << "성공적으로 등록되었습니다." << endl;
	}
}

void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	string inputLecCode, inputLecName; //관리자로부터 추가할 강의 정보 입력받음
	int inputLecCredit, inputLimit;

	cout << "----------------------------------------------------" << endl << "과목코드 : ";
	cin >> inputLecCode;
	cout << "과목명 : ";
	cin >> inputLecName;
	cout << "학점 : ";
	cin >> inputLecCredit;
	cout << "수강인원 : ";
	cin >> inputLimit;
	cout << "----------------------------------------------------" << endl;

	if (findLectureByCode(lectureCodes, inputLecCode) != -1) {
		cout << "이미 존재하는 과목코드 입니다." << endl;
	}
	else { //lectureCodes벡터에 없는 학번일 경우 추가 가능
		lectureCodes.push_back(inputLecCode);
		lectureNames.push_back(inputLecName);
		lectureCredits.push_back(inputLecCredit);
		limits.push_back(inputLimit);
		cout << "성공적으로 강의가 개설되었습니다." << endl;
	}
}

void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	/* 내부 호출 함수: printLectures*/
	string inputLecCode; //관리자로부터 삭제할 강의 정보 입력받음

	while (1) { //아무키 누르면 계속 강의 삭제 메뉴에 머무름

		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits); //default -100

		cout << "삭제할 강의 코드 (0: 뒤로가기) >> ";
		cin >> inputLecCode;

		if (inputLecCode == "0") //강의코드 입력받을 때 0누르면 뒤로가기 (while문 빠져나옴)
			break;

		int deleteIndex = findLectureByCode(lectureCodes, inputLecCode);
		int appliedLCIndex;

		if (deleteIndex == -1) {
			cout << "일치하는 코드가 없습니다." << endl;
		}
		else {
			// 그 강의 담았던 애들 싹다 지워야됨->appliedLC[user], credit[user]에서 그과목 정보 삭제해야하니까 그전까진 지우지말기
			// credits, appliedLectureCodes는 학생용 벡터
			// 해당 과목코드 담았던 애들 찾아서 지우기
			for (unsigned i = 0; i < appliedLectureCodes.size(); i++) { //i : 학생인덱스
				if (findLectureByCode(appliedLectureCodes[i], inputLecCode) != -1) { //i번째 학생이 그 과목 신청했으면
					appliedLCIndex = findLectureByCode(appliedLectureCodes[i], inputLecCode); //aLC[i]내의 인덱스 aLCI에 저장
					deleteElement(appliedLectureCodes[i], appliedLCIndex);
					credits[i] += lectureCredits[deleteIndex];
				}
			}
			deleteElement(lectureCodes, deleteIndex);
			deleteElement(lectureNames, deleteIndex);
			lectureCredits.erase(lectureCredits.begin() + deleteIndex);
			limits.erase(limits.begin() + deleteIndex);

			cout << "성공적으로 강의가 폐쇄되었습니다." << endl;
		}

		system("PAUSE");
	}
}

int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	
	int input;

	/* 내부 호출 함수: addStudent, addLecture, deleteLecture*/
	while (1) {

		cout << "----------------------------------------------------" << endl <<
			"1. 학생 추가" << endl <<
			"2. 강의 개설" << endl <<
			"3. 강의 삭제" << endl <<
			"4. 로그아웃" << endl <<
			"0. 종료" << endl <<
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
	//학생메뉴 - 수강신청, 수강현황, 수강철회 메뉴에서 호출
	cout << "----------------------------------------------------" << endl <<
			"학번 : " << studentIds[user] << "\t" << "이름 : " << names[user] << "\t" << "수강가능학점 : " << credits[user] << endl <<
			"----------------------------------------------------" << endl;
}

void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	/* 내부 호출 함수: printStudent, printLectures*/
	printStudent(studentIds, names, credits, user);
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits); //user은 default로 -100->강의목록 출력
	string applyCode;

	while (1) {

		cout << "신청할 과목 코드(0: 뒤로가기) >>";
		cin >> applyCode;

		if (applyCode == "0")
			break; //0이면 뒤로가기->while문 break하고 함수 종료

		int availCredit = credits[user];
		int applyIndex = findLectureByCode(lectureCodes, applyCode);
		int applyCredit = lectureCredits[applyIndex];

		//경우4 : 수강 가능 인원이 0명인 경우->신청 불가능
		if (limits[applyIndex] == 0)
			cout << "수강정원이 꽉 찼습니다." << endl;

		//경우3 : 수강가능학점이 신청하려는 과목의 학점보다 작은 경우->신청 불가능
		else if (availCredit < applyCredit)
			cout << "수강가능학점이 부족합니다." << endl;

		//경우1 : applyCode가 이미 신청한 과목코드 벡터에 있는 경우->신청 불가능
		else if (findLectureByCode(appliedLectureCodes[user], applyCode) != -1)
			cout << "이미 해당 과목을 신청했습니다." << endl;

		//경우2 : applyCode에 해당하는 과목명과 동일한 (다른 코드, 같은 과목명)과목명의 강의 수강하는 경우->신청 불가능
		else if (findLectureByCode(appliedLectureCodes[user], applyCode) == -1) //입력받은 신청과목코드(applyCode)가 사용자의 신청과목코드(appliedLC[user])에 없음
		{
			for (unsigned i = 0; i < lectureNames.size(); i++) {
				if (lectureNames[applyIndex] == lectureNames[i] && applyIndex != i) { //index(applyIndex와 i)가 서로 다른데 lectureNames vector에서의 강의명이 같음
					cout << "이미 동일명의 과목을 신청했습니다." << endl;
					break; // 가까운 for문 탈출
				}
				else if (i == lectureNames.size() - 1) {
					appliedLectureCodes[user].push_back(applyCode);
					credits[user] -= applyCredit;
					limits[findLectureByCode(lectureCodes, applyCode)] -= 1;
					cout << "[" << applyCode << "] " << lectureNames[findLectureByCode(lectureCodes, applyCode)] << "(을)를 성공적으로 신청하였습니다." << endl;
				}
			}
		}

		system("PAUSE");
	}
}

void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	/* 내부 호출 함수: printStudent, printLectures*/
	printStudent(studentIds, names, credits, user);
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);

	string disapplyCode;

	while (1) {

		cout << "철회할 과목 코드(0: 뒤로가기) >>";
		cin >> disapplyCode;

		if (disapplyCode == "0") //0누르면 while문 break하고 다시 학생메뉴로
			break;

		int disapplyStuIndex = findLectureByCode(appliedLectureCodes[user], disapplyCode); //학생이 신청한 과목코드벡터에 입력한 disapplyCode의 인덱스 저장
		int disapplyLecIndex = findLectureByCode(lectureCodes, disapplyCode); //과목코드벡터에 입력한 disapplyCode의 인덱스 저장

		if (disapplyStuIndex != -1) { //신청 했으면
			deleteElement(appliedLectureCodes[user], disapplyStuIndex);
			credits[user] -= lectureCredits[disapplyLecIndex]; //-가 아니라 +로 해야함 ㅜㅜㅜ시벌
			limits[disapplyLecIndex] += 1;
			cout << "[" << lectureCodes[disapplyLecIndex] << "] " << lectureNames[disapplyLecIndex] << "을(를) 철회하였습니다." << endl;
		}
		else //신청 하지 않았으면
			cout << "과목 코드가 올바르지 않습니다." << endl;

		system("PAUSE");
	}
}

void changePassword(vector<string>& passwords, const int& user) {
	string passwordInput;

	cout << "----------------------------------------------------" << endl <<
		"본인 확인을 위해 비밀번호를 한 번 더 입력해주세요." << endl << "비밀번호 : ";
	cin >> passwordInput;
	cout << "----------------------------------------------------" << endl;

	if (passwordInput != passwords[user]) {
		cout << "비밀번호가 일치하지 않습니다." << endl;
	}
	else {
		cout << "----------------------------------------------------" << endl <<
			"새로 설정할 비밀번호를 입력하세요." << endl <<
			"비밀번호 : ";
		cin >> passwordInput;
		passwords[user] = passwordInput;
		cout << "변경되었습니다." << endl <<
			"----------------------------------------------------" << endl;
	}

	system("PAUSE"); //아무키 누르고 학생메뉴로 이동됨
}

int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user) {
	
	int input;

	/* 내부 호출 함수: applyLecture, printStudent, printLectures, disapplyLecture, changePassword*/
	//return 로그아웃(-1), 종료(1)
	while(1) { //5, 0버튼 누르기 전까지 학생메뉴에 머무름

		cout << "----------------------------------------------------" << endl <<
			"1. 수강 신청" << endl <<
			"2. 수강 현황" << endl <<
			"3. 수강 철회" << endl <<
			"4. 비밀번호 변경" << endl <<
			"5. 로그아웃" << endl <<
			"0. 종료" << endl <<
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
			break; //return하면 break쓰지 말라고 함!
		}

		else {
			return 1;
			break;
		}
	}
}