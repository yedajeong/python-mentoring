#include <iostream>
#include <iomanip>
using namespace std;

//����01
int command() {

	int num;

	cout << "\n\t---- menu ----" << endl;
	cout << "\t1. ����Ʈ �߰�" << endl;
	cout << "\t2. ����Ʈ ����" << endl;
	cout << "\t3. ����Ʈ ���" << endl;
	cout << "\t4. ���α׷� ����" << endl;
	cout << "\n\t�Է� -->";
	cin >> num;
	return num;
}

template <typename T>
class CList {
public:
	CList();
	~CList();

	bool IsEmpty(); //list�� ��� ������ 1, �ƴϸ� 0
	bool IsFull(); //list�� �� �� ������ 1, �ƴϸ� 0

	void Add(T data); //list�� ������ �߰�
	void Delete(T data); //list�� ������ ����
	void Print(); //list�� ������ ���

private:
	T m_Array[5]; //�����͸� ������ ����
	int m_Length; //list�� �ִ� ������ ��
};

template <typename T>
CList<T>::CList() {
	m_Length = 0;
}

template <typename T>
CList<T>::~CList() {}

template <typename T>
bool CList<T>::IsEmpty() {
	if (m_Length == 0)
		return 1;
	else
		return 0;
}

template <typename T>
bool CList<T>::IsFull() {
	if (m_Length == 5)
		return 1;
	else
		return 0;
}

template <typename T>
void CList<T>::Add(T data) {
	int jungbok = 0;
	if (IsFull())
		cout << "\tList is full" << endl;

	else {
		if (IsEmpty()) {
			m_Array[0] = data;
			m_Length++;
		}
		else {

			for (int i = 0; i < m_Length; i++) {
				if (m_Array[i] == data) {
					cout << "\t�ߺ��� �����Ͱ� �����մϴ�." << endl;
					jungbok = 1;
					break;
				}
			}

			if (!jungbok) {
				m_Array[m_Length] = data;
				m_Length++;
				for (int j = (m_Length - 1); j != 0; j--) {
					if (m_Array[j] < m_Array[j - 1]) {
						T temp = m_Array[j];
						m_Array[j] = m_Array[j - 1];
						m_Array[j - 1] = temp;
					}
				}
			}
		}
	}
}

template <typename T>
void CList<T>::Delete(T data) {
	if (IsEmpty())
		cout << "\tList is empty." << endl;
	else {
		for (int i = 0; i < m_Length; i++) {
			if (m_Array[i] == data) {
				T temp = data;
				for (i; i < 4; i++)
					m_Array[i] = m_Array[i + 1];
				m_Length--;
				break;
			}
		}
	}
}

template <typename T>
void CList<T>::Print() {
	cout << "�� Current List\n" << endl;
	for (int i = 0; i < m_Length; i++)
		cout << setw(4) << m_Array[i];
}

int main() {

	CList<int> list; //type������ list ����
	int input; //list�� �Է��� ������
	int com; //������ ���
	while (1) {
		com = command(); //����� ����
		switch (com) {
		case 1: //�߰�
			cout << "\n�߰��� ������ : ";
			cin >> input;
			list.Add(input);
			break;
		case 2: //����
			cout << "\n������ ������ : ";
			cin >> input;
			list.Delete(input);
			break;
		case 3: //���
			list.Print();
			break;
		case 4: //���α׷� ����
			cout << "\n\t���α׷��� �����մϴ�\n";
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}