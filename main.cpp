#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Animal Ŭ����
class Animal {
public:
	virtual void makeSound() = 0;
	virtual void move() = 0;
};

//	Animal Ŭ���� �������̵��ؼ� Dog Ŭ���� ����
class Dog : public Animal {
public:
	void makeSound() override {
		cout << "Woof! Woof!" << endl;
	}
	void move() override {
		cout << "The dog move" << endl;
	}

};

// Animal Ŭ���� �������̵��ؼ� Cat Ŭ���� ����
class Cat : public Animal {
public:
	void makeSound() override {
		cout << "Meow! Meow!" << endl;
	}
	void move() override {
		cout << "The cat move" << endl;
	}

};

//	Animal Ŭ���� �������̵��ؼ� Cow Ŭ���� ����
class Cow : public Animal {
public:
	void makeSound() override {
		cout << "Moo! Moo!" << endl;
	}
	void move() override {
		cout << "The cow move" << endl;
	}

};

// �������� ������ �߰��ϴ� �Լ�
Animal* createRandomAnimal() {
	int randomChoice = rand() % 3;		// rand()�Լ��� ����Ͽ� 0,1,2 ���� �ϳ� �������� ����

	if (randomChoice == 0) {			// 0�϶� Dog ��ü �߰�
		return new Dog();
	}
	else if (randomChoice == 1) {		// 1�϶� Cat ��ü �߰�
		return new Cat();
	}
	else {
		return new Cow();				// 2�϶� Cow ��ü �߰�
	}
}

//	Zoo Ŭ����
class Zoo {
private:
	Animal* animals[10]; // ���� ��ü�� �����ϴ� ������ �迭
	int index = 0;		 // ���� ���� ��
public:
	//	������ �߰��ϴ� �Լ�
	void addAnimal(Animal* animal) {
		if (index < 10) {
			animals[index++] = animal;		// ���� ���� �ε����� �߰��ϰ�, index���� 1������Ŵ
		}
		else {
			cout << "�������� �� á���ϴ�" << endl;		// ������ �迭�� �� 10�� �ʰ������� ��½�Ű�� ����
		}
	}
	// ���� ������ ����ŭ �ݺ��ϸ� ������ �Ҹ������� �����δ�.
	void performActions() {
		for (int i = 0; i < index; i++) {
			animals[i]->makeSound();		// �Ҹ��� ���� �Լ� ����
			animals[i]->move();				// �����̴� �Լ� ����
		}
	}

	// Zoo Ŭ���� �Ҹ���
	~Zoo() {
		// ���� ��ü �޸� ��ü
		for (int i = 0; i < index; ++i) {
			delete animals[i];
		}
	}
};

int main() {

	srand(time(0));  // ���� ���� �õ� �ʱ�ȭ

	Zoo zoo;  // Zoo ��ü ����

	// ���� �������� �������� �߰�
	for (int i = 0; i < 10; ++i) {
		zoo.addAnimal(createRandomAnimal());
	}

	// �������� �ִ� �������� �ൿ�� ����
	zoo.performActions();

	zoo.addAnimal(createRandomAnimal()); // �ڸ��� ��á���� �߰��ؼ� ������ ����� ��µǴ��� Ȯ��

	// Zoo �Ҹ��ڰ� ȣ��Ǿ� ���� ��ü�� �޸𸮰� �����˴ϴ�.

	return 0;
}