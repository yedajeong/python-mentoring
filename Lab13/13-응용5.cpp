#include <iostream>
using namespace std;

//응용05
template <class T>
class Queue {
private:
	T *p_list; //정수형 변수들을 가지는 배열
	int size; //현재 저장된 변수들의 개수
	int MAX_SIZE; //최대로 저장할 수 있는 p_list의 크기
public:
	Queue(int _MAX_SIZE = 1000) {
		p_list = new T[_MAX_SIZE];
		MAX_SIZE = _MAX_SIZE;
		size = 0;
	}
	~Queue() {
		delete[] p_list;
	}
	int find_index(T _item) {
		for (int i = 0; i < size; i++) {
			if (p_list[i] == _item)
				return i;
		}
		return -1;
	}
	void Enqueue(T _item) {
		if (find_index(_item) == -1) {
			if ((size + 1) <= MAX_SIZE) {
				p_list[size] = _item;
				size++;
			}
			else
				cout << "Error: out of memory" << endl;
		}
	}
	T Dequeue(){
		if (size != 0) {
			T deletItem = get_item(0);
			for (int i = 0; i < size; i++) {
				p_list[i] = p_list[i + 1];
			}
			size--;
			return deletItem;
		}
		else
			cout << "Error: No item exists in the list" << endl;
		//else면 return값 없는데?
	}
	void print() const {
		cout << "Items in the list : ";
		for (int i = 0; i < size; i++)
			cout << '\t' << p_list[i];
		cout << endl;			
	}
	int get_size() {
		return size;
	}
	T get_item(int _index) {
		return p_list[_index];
	}
};

int main() {
	Queue<int> int_queue;
	Queue<float> float_queue;
	Queue<char> char_queue;

	int_queue.Enqueue(1);
	int_queue.Enqueue(2);
	int_queue.Enqueue(2);
	int_queue.Enqueue(5);

	float_queue.Enqueue(4.3);
	float_queue.Enqueue(2.5);
	float_queue.Enqueue(3.7);
	float_queue.Enqueue(3.7);

	char_queue.Enqueue('b');
	char_queue.Enqueue('b');
	char_queue.Enqueue('c');
	char_queue.Enqueue('a');

	cout << "<Before Dequeue>" << endl;
	int_queue.print();
	float_queue.print();
	char_queue.print();

	int_queue.Dequeue();
	float_queue.Dequeue();
	float_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();

	cout << "<After Dequeue>" << endl;
	int_queue.print();
	float_queue.print();
	char_queue.print();
	
	return 0;
}