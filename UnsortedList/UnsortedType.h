#ifndef UNSORTEDTYPE_H_INCLUDED
#define UNSORTEDTYPE_H_INCLUDED
#include <string>
using namespace std;
template<class ItemType>
class UnsortedType
{
struct NodeType
{
ItemType info;
NodeType*next;
};
public:
    UnsortedType();
    ~UnsortedType();
    bool IsFull();
    int LengthIs();
    void MakeEmpty();
    void InsertItem(ItemType);
    void DeleteItem(string);
	bool search(string);
	ItemType* GetNextItem();
	void ResetList();
	void print();
private:
    NodeType * listData;
    int length;
	NodeType *currentPos;
};


#endif // UNSORTEDTYPE_H_INCLUDED
