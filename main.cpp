#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Animal 클래스
class Animal {
public:
	virtual void makeSound() = 0;
	virtual void move() = 0;
};

//	Animal 클래스 오버라이딩해서 Dog 클래스 구현
class Dog : public Animal {
public:
	void makeSound() override {
		cout << "Woof! Woof!" << endl;
	}
	void move() override {
		cout << "The dog move" << endl;
	}

};

// Animal 클래스 오버라이딩해서 Cat 클래스 구현
class Cat : public Animal {
public:
	void makeSound() override {
		cout << "Meow! Meow!" << endl;
	}
	void move() override {
		cout << "The cat move" << endl;
	}

};

//	Animal 클래스 오버라이딩해서 Cow 클래스 구현
class Cow : public Animal {
public:
	void makeSound() override {
		cout << "Moo! Moo!" << endl;
	}
	void move() override {
		cout << "The cow move" << endl;
	}

};

// 랜덤으로 동물을 추가하는 함수
Animal* createRandomAnimal() {
	int randomChoice = rand() % 3;		// rand()함수를 사용하여 0,1,2 값중 하나 랜덤으로 생성

	if (randomChoice == 0) {			// 0일때 Dog 객체 추가
		return new Dog();
	}
	else if (randomChoice == 1) {		// 1일때 Cat 객체 추가
		return new Cat();
	}
	else {
		return new Cow();				// 2일때 Cow 객체 추가
	}
}

//	Zoo 클래스
class Zoo {
private:
	Animal* animals[10]; // 동물 객체를 저장하는 포인터 배열
	int index = 0;		 // 현재 동물 수
public:
	//	동물을 추가하는 함수
	void addAnimal(Animal* animal) {
		if (index < 10) {
			animals[index++] = animal;		// 현재 수의 인덱스에 추가하고, index값을 1증가시킴
		}
		else {
			cout << "동물원이 꽉 찼습니다" << endl;		// 동물원 배열의 값 10을 초과했을때 출력시키는 문구
		}
	}
	// 현재 동물의 수만큼 반복하며 동물들 소리를내고 움직인다.
	void performActions() {
		for (int i = 0; i < index; i++) {
			animals[i]->makeSound();		// 소리를 내는 함수 접근
			animals[i]->move();				// 움직이는 함수 접근
		}
	}

	// Zoo 클래스 소멸자
	~Zoo() {
		// 동물 객체 메모리 해체
		for (int i = 0; i < index; ++i) {
			delete animals[i];
		}
	}
};

int main() {

	srand(time(0));  // 난수 생성 시드 초기화

	Zoo zoo;  // Zoo 객체 생성

	// 랜덤 동물들을 동물원에 추가
	for (int i = 0; i < 10; ++i) {
		zoo.addAnimal(createRandomAnimal());
	}

	// 동물원에 있는 동물들의 행동을 실행
	zoo.performActions();

	zoo.addAnimal(createRandomAnimal()); // 자리가 꽉찼지만 추가해서 문구가 제대로 출력되는지 확인

	// Zoo 소멸자가 호출되어 동물 객체의 메모리가 해제됩니다.

	return 0;
}