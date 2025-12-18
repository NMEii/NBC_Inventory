#include <iostream>
#include <string>

using namespace std;

class item
{
private:
	string type;
	string itemName;
	int price;

public:
	item(string name = "", int _price = 0) :
		type("기타"),
		itemName(std::move(name)),
		price(_price)
	{

	}

	void PrintType()	// 해당 인벤토리 카테고리 출력
	{
		cout << "[  " << type << "  ]" << endl;

	}

	void Print() const
	{
		cout << "[ 이름 : " << itemName << ", 가격 : " << price << "G ]" << endl;
	}
};

class Weapon 
{
private:
	string type;
	string weaponName;
	int price;

public:
	Weapon(string name = "", int _price = 0) :
		type("장비"),
		weaponName(name),
		price(_price)
	{

	}
	
	void PrintType()	// 해당 인벤토리 카테고리 출력
	{
		cout << "[  " << type << "  ]" << endl;

	}

	void Print() const
	{
		cout << "[ 이름 : " << weaponName << ", 가격 : " << price << "G ]" << endl;
	}
};

class Potion 
{
private:
	string type;
	string potionName;
	int price;

public:
	Potion(string name = "", int _price = 0) :
		type("포션"),
		potionName(name),
		price(_price)
	{

	}

	void PrintType()	// 해당 인벤토리 카테고리 출력
	{
		cout << "[  " << type << "  ]" << endl;

	}

	void Print() const
	{
		cout << "[ 이름 : " << potionName << ", 가격 : " << price << "G ]" << endl;
	}
};


template<typename T>
class Inventory
{
private:
	string invenType;
	T* pItem;
	int capacity;
	int size;

public:
	Inventory(int _capacity = 10) :	// 생성자에서 최대용량(capacity) 10 지정
		invenType(""),
		pItem(new T[_capacity]),
		capacity(_capacity),
		size(0)						// 초기화 리스트로 멤버 변수 초기화
	{

	}
	~Inventory()					// 소멸자에서 동적 메모리 해제 및 nullptr로 초기화
	{
		delete[] pItem;
		pItem = nullptr;
	}
	void AddItem(const T& item)		// 인벤토리에 아이템 추가
	{
		if(size < capacity) 
		{ 
			pItem[size] = item;
			size++;					// 아이템 추가 후현재용량(size) +1
		}
	}

	void removeLastItem()			// 제일 최근에 추가된 아이템 삭제
	{
		if (size > 0) { size--; }	// 아이템 삭제 후 현재용량(size) -1
	}

	int getSize() const { return size; }	// getter

	int getCapacity() const { return capacity; }	// getter

	void PrintInvenType() const				// 인벤토리 카테고리 출력함수 호출
	{
		pItem->PrintType();
	}

	void PrintItem() const					// 현재 보유 아이템 모두 출력
	{
		for (int i = 0; i < size; ++i)
		{
			pItem[i].Print();
		}
	}

};

int main()
{
	Inventory<item>* itemInventory = new Inventory<item>();
	Inventory<Weapon>* weaponInventory = new Inventory<Weapon>();
	Inventory<Potion>* potionInventory = new Inventory<Potion>();

	item _item = item("나무", 30);				// 기타 타입 아이템 추가
	itemInventory->AddItem(_item);
	
	Weapon _weapon = Weapon("롱소드", 350);		// 장비 타입 아이템 추가
	weaponInventory->AddItem(_weapon);
	
	Potion _potion = Potion("회복포션", 50);	// 포션 타입 아이템 추가
	potionInventory->AddItem(_potion);

	itemInventory->PrintInvenType();	// 인벤토리 타입 출력
	itemInventory->PrintItem();			// 기타 타입 아이템 모두 출력
	
	weaponInventory->PrintInvenType();	
	weaponInventory->PrintItem();		// 장비 타입 아이템 모두 출력
	
	potionInventory->PrintInvenType();	
	potionInventory->PrintItem();		// 포션 타입 아이템 모두 출력

	delete itemInventory;				// 메모리 할당 해제
	delete weaponInventory;
	delete potionInventory;

	itemInventory = nullptr;			// nullptr로 초기화

	return 0;
}