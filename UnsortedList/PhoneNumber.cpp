#include "PhoneNumber.h"

PhoneNumber::PhoneNumber()
{

}

PhoneNumber::PhoneNumber(string mobileNumber, string numberOperator)
{
	add_phone_number(mobileNumber, numberOperator);
}


PhoneNumber::~PhoneNumber()
{

}

void PhoneNumber::add_phone_number(string mobileNumber, string numberOperator)
{
	NumberInfo  number(mobileNumber, numberOperator);
	if (numberList.LengthIs() == 15)
	{
		cout << "Already have 15 numbers!" << endl;
	}
	else
	{
		numberList.InsertItem(number);
	}
}

void PhoneNumber::remove_phone_number(string mobileNumber)
{
	NumberInfo  number(mobileNumber, "");
	if (numberList.LengthIs() == 1)
	{
		numberList.MakeEmpty();
	}
	else
	{
		numberList.DeleteItem(mobileNumber);
	}
}

bool PhoneNumber::search_mobile_number(string mobileNumber)
{
	return numberList.search(mobileNumber);
}

bool PhoneNumber::change_operator(string mobileNumber, string newOperator)
{
	NumberInfo *temp;
	int length = numberList.LengthIs();
	numberList.ResetList();
	while (length--)
	{
			temp = numberList.GetNextItem();
			if (temp->get_mobile_number().compare(mobileNumber) == 0)
			{
				temp->set_number_operator(newOperator);
				return true;
			}
	}
	return false;

}

int PhoneNumber::get_length()
{
	return numberList.LengthIs();
}

void PhoneNumber::print()
{
	numberList.print();
	cout << endl;
}

