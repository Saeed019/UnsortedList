#include"UnsortedType.h"
#include "CustomerData.h"
#include "NumberInfo.h"
#include <string>
#include<iostream>
#include <exception>
using namespace std;
template class UnsortedType<NumberInfo>;
template class UnsortedType<CustomerData>;

template<class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length=0;
    listData=NULL;
	currentPos = NULL;
}
template<class ItemType>
int UnsortedType<ItemType>::LengthIs()
{
    return length;
}
template<class ItemType>
bool UnsortedType<ItemType>::IsFull()
{
  NodeType* location;
  try
  {
      location = new NodeType;
      delete location;
      return false;
  }
  catch(bad_alloc exception)
  {
      return true;
  }
}
template<class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
{
 NodeType* location;
 location = new NodeType;
 location->info=item;
 location->next=listData;
 listData = location;
 length++;
}
template<class ItemType>
void UnsortedType<ItemType>::DeleteItem(string item)
{
    NodeType* location = listData;
    NodeType* tempLocation = NULL;
    if((listData->info.is_equal(item)))
    {
        tempLocation = location;
        listData = listData->next;
		delete tempLocation;
    }
    else
    {
        while(!(location->next->info.is_equal(item)))
        {
			tempLocation = location;
            location = location->next;
        }
		if (location->next != NULL)
			location->next = location->next->next;
		else
			location->next = NULL;
        delete tempLocation;
        length--;
    }
}

template<class ItemType>
bool UnsortedType<ItemType>::search(string item)
{
	NodeType* temp;
	temp = listData;
	while (temp != NULL)
	{
		if (temp->info.is_equal(item))
			return true;
		temp = temp->next;
	}
	return false;
}

template<class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
    NodeType* tempPtr;
    while(listData!=NULL)
    {
		currentPos = NULL;
        tempPtr = listData;
        listData= listData->next;
        delete tempPtr;
    }
}

template<class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{

}

template<class ItemType>
void UnsortedType<ItemType>::print()
{
    NodeType *temp =listData;
   while(temp!=NULL)
   {
       temp->info.print();
       temp=temp->next;
   }
}
template<class ItemType>
void UnsortedType<ItemType>::ResetList()
{
	currentPos = NULL;
}
template<class ItemType>

ItemType* UnsortedType<ItemType>::GetNextItem()
{
	if (currentPos == NULL)
	{
		currentPos = listData;
	}
	else
		currentPos = currentPos->next;
	return &(currentPos->info);
}

