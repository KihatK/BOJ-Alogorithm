#include <iostream>

class CPerson {
public:
	CPerson() {

	}
	~CPerson() {

	}
	void SetData(int n) {
		price = n;
	}
	int GetData(void) {
		return price;
	}
	virtual void SetPrice(void) = 0;
private:
	int price = 0;
};

class CAdult : public CPerson {
public:
	void SetPrice(void) {
		CPerson::SetData(1100);
	}
};

class CTeen : public CPerson {
public:
	void SetPrice(void) {
		CPerson::SetData(900);
	}
};

class CKid : public CPerson {
public:
	void SetPrice(void) {
		CPerson::SetData(500);
	}
};

int pure_virtual(void) {
	int choice;
	CPerson* p = nullptr;

	printf("1. 어른, 2. 청소년, 3. 어린이\n");
	scanf_s("%d", &choice);

	switch (choice) {
		case 1:
			p = new CAdult;
			break;
		case 2:
			p = new CTeen;
			break;
		case 3:
			p = new CKid;
			break;
		default:
			break;
	}

	p->SetPrice();

	printf("당신은 %d원을 내야합니다.\n", p->GetData());

	return 0;
}