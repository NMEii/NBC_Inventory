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

	void PrintType()
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
	
	void PrintType()
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

	void PrintType()
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
	Inventory(int _capacity = 10) :
		invenType(""),
		pItem(new T[_capacity]),
		capacity(_capacity),
		size(0)
	{

	}
	~Inventory()
	{
		delete[] pItem;
		pItem = nullptr;
	}
	void AddItem(const T& item)	
	{
		if(size < capacity) 
		{ 
			pItem[size] = item;
			size++;				
		}
	}

	void removeLastItem() 
	{
		if (size > 0) { size--; }
	}

	int getSize() const { return size; }

	int getCapacity() const { return capacity; }

	void PrintInvenType() const
	{
		pItem->PrintType();
	}

	void PrintItem() const
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

	item _item = item("나무", 30);
	itemInventory->AddItem(_item);
	
	Weapon _weapon = Weapon("롱소드", 350);
	weaponInventory->AddItem(_weapon);
	
	Potion _potion = Potion("회복포션", 50);
	potionInventory->AddItem(_potion);

	itemInventory->PrintInvenType();	// 인벤토리 타입 출력
	itemInventory->PrintItem();
	
	weaponInventory->PrintInvenType();
	weaponInventory->PrintItem();
	
	potionInventory->PrintInvenType();
	potionInventory->PrintItem();

	delete itemInventory;
	delete weaponInventory;
	delete potionInventory;

	itemInventory = nullptr;

	return 0;
}