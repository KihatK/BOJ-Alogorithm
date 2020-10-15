#include <iostream>

class CTest {
public:
	CTest() {
		n_pData = new int(5);
	}
	CTest(const CTest& rhs) {
		//this->n_pData = rhs.n_pData;
		this->n_pData = new int(*rhs.n_pData);
	}
	~CTest() {
		delete n_pData;
	}
private:
	int* n_pData = nullptr;
};

int copy(void) {
	CTest a;
	CTest b(a);

	return 0;
}