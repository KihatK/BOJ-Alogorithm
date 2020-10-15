#include <iostream>

using namespace std;

class CMyData {
public:
	CMyData() {

	}
	~CMyData() {

	}
	CMyData(const CMyData& rhs) {
		m_nData = rhs.m_nData;
		cout << "기본 생성자" << endl;
	}
	CMyData(const CMyData&& rhs) {
		m_nData = rhs.m_nData;
		cout << "&&" << endl;
	}
	explicit CMyData(int nParam) {
		m_nData = nParam;
		cout << "number" << endl;
	}
	operator int(void) {
		return m_nData;
	}
	CMyData& operator= (const CMyData& rhs) {
		SetData(rhs.GetData());
		return *this;
	}
	CMyData& operator= (const CMyData&& rhs) {
		SetData(rhs.GetData());
		cout << "&&" << endl;
		return *this;
	}
	CMyData& operator= (int nParam) {
		SetData(nParam);
		return *this;
	}
	CMyData operator+ (const CMyData& rhs) {
		//더하기를 해서 임시 객체에 담을 것이기 때문에 새로운 객체 선언
		cout << "+" << endl;
		return CMyData(this->m_nData + rhs.m_nData);
	}
	int GetData() const {
		return m_nData;
	}

	void SetData(int nParam) {
		m_nData = nParam;
	}
private:
	int m_nData = 0;
};

int class_operator(void) {
	/*
	a,b,c 선언에서 number 3번 출력
	b + c에서 + 출력
	b + c 도중에 새로운 객체를 만들어 number 1번 출력
	나온 결과가 임시 객체에 담겨 && 출력
	*/
	CMyData a(0);
	CMyData b(3);
	CMyData c(4);

	a = b + c;

	printf("%d\n", c.GetData());

	return 0;
}