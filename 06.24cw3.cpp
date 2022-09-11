#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class UniversalContainerInterface {
public:
	virtual int getElement(size_t n)=0;
	virtual int getFirst()=0;
	virtual ~UniversalContainerInterface() {
	}
};

class VectorContainer: public UniversalContainerInterface {
	vector<int> data;
public:
	VectorContainer(vector<int> data) {
		this->data = data;
	}
	int getElement(size_t n) {
		return this->data[n];
	}
	int getFirst() {
		return this->data[0];
	}
};

class ListContainer: public UniversalContainerInterface {
	list<int> data;
public:
	ListContainer(list<int> data) {
		this->data = data;
	}
	int getElement(size_t n) {
		auto it = this->data.begin();
		for (int i = 0; i < n; i++, it++)
			;
		return *it;
	}
	int getFirst() {
		return *(this->data.begin());
	}
};

int main() {
	list<int> lst(10);
	vector<int> vec(10);
	generate(lst.begin(), lst.end(), []() {
		return rand();
	});
	generate(vec.begin(), vec.end(), []() {
		return rand();
	});
	VectorContainer vc(vec);
	ListContainer lc(lst);
	cout << vc.getFirst() << " " << vc.getElement(5) << endl;
	cout << lc.getFirst() << " " << lc.getElement(5) << endl;
	return 0;
}
