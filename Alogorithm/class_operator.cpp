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
		cout << "�⺻ ������" << endl;
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
		//���ϱ⸦ �ؼ� �ӽ� ��ü�� ���� ���̱� ������ ���ο� ��ü ����
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
	a,b,c ���𿡼� number 3�� ���
	b + c���� + ���
	b + c ���߿� ���ο� ��ü�� ����� number 1�� ���
	���� ����� �ӽ� ��ü�� ��� && ���
	*/
	CMyData a(0);
	CMyData b(3);
	CMyData c(4);

	a = b + c;

	printf("%d\n", c.GetData());

	return 0;
}