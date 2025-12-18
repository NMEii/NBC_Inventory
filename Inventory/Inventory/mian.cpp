#include <iostream>
#include <string>

using namespace std;

class item
{
private:
	string itemName;
	int price;

public:
	item(string name = "", int _price = 0) :
		itemName(std::move(name)),
		price(_price)
	{

	}

	void Print() const
	{
		cout << "[ 이름 : " << itemName << ", 가격 : " << price << "G ]" << endl;
	}
};

template<typename T>
class Inventory
{
private:
	T* pItem;
	int capacity;
	int size;

public:
	Inventory(int _capacity = 10) :
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

	for (int i = 0; i < 10; i++)
	{
		item _item= item("item", i * 100);
		itemInventory->AddItem(_item);
	}
	itemInventory->removeLastItem();

	itemInventory->PrintItem();
	
	
	delete itemInventory;
	itemInventory = nullptr;

	return 0;
}