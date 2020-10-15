#include <iostream>

class CTest2 {
public:
	CTest2() {
		m_pData = new int(0);
	}
	CTest2(const CTest2& rhs) {
		m_pData = new int(*rhs.m_pData);  //±Ì¿∫ ∫πªÁ
	}
	explicit CTest2(int nParam) {
		m_pData = new int(nParam);
	}
	CTest2& operator = (const CTest2& rhs) {
		//*m_pData = *rhs.m_pData;
		m_pData = new int(*rhs.m_pData);
		return *this;
	}
	operator int(void) {
		return *m_pData;
	}
	void getData() {
		printf("%d\n", *m_pData);
	}
	void editData(int n) {
		*m_pData = n;
	}
	~CTest2() {
		delete m_pData;
	}
private:
	int* m_pData = nullptr;
};

int class_2(void) {
	CTest2 a(10);

	CTest2 b;

	b = a;

	std::cout << a << std::endl;

	return 0;
}