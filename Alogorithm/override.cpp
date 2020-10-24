#include <iostream>

using namespace std;

static class CMyData {
public:
	virtual void GetData() {
		cout << "CMyData GetData" << endl;
	}
};

static class CmyDataEx : public CMyData {
public:
	void GetData() override {
		cout << "CMyDataEx GetData" << endl;
	}
};

int override(void) {
	CMyData a;
	CmyDataEx b;

	CMyData* pData = new CmyDataEx;

	a.GetData();
	pData->GetData();

	delete pData;

	return 0;
}