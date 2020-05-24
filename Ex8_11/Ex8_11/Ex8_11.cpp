// Ex8_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Perfect forwarding

#include <iostream>
#include <utility>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Name
{
public:
	Name(const string& aName) : name{ aName }
	{
		cout << "Lvalue Name constructor." << endl;
	}

	Name(string&& aName) : name{ std::move(aName) }
	{
		cout << "Rvalue Name constructor." << endl;
	}

	const string& getName() const { return name; }

private:
	string name;
};

class Person
{
public:
	// Constructor template
	template<typename T1, typename T2>
	Person(T1&& first, T2&& second) : 
		// firstname {std::forward>(first)}, secondname {std::forward<T2>(second)} {}
		firstname {first}, secondname {second} {}

	// Access the name
	string getName() const
	{
		return firstname.getName() + " " + secondname.getName();
	}
private:
	Name firstname;
	Name secondname;
};

int main()
{
	cout << "Creating Person{string{\"Ivor\"}, string{\"Horton\"}} - rvalue arguments:"
		<< endl;
	Person me{ string{"Ivor"}, string{"Horton"} };
	cout << "Person is " << me.getName() << endl << endl;
	
	string first{ "Fred" };
	string second{ "Fernackerpan" };
	cout << "Creating Person{first, second} - lvalue argument" << endl;
	Person other{ first, second };
	cout << "Person is " << other.getName() << endl << endl;
	
	cout << "Creating Person{first, string{\"Bloggs\"}} - lvalue, rvalue arguments:"
		<< endl;
	Person brother{ first, string{"Bloggs"} };
	cout << "Person is " << brother.getName() << endl << endl;
	
	cout << "Creating Person{\"Richard\", \"Horton\"} - rvalue const char* arguments:"
		<< endl;
	Person another{ "Richard", "Horton" };
	cout << "Person is " << another.getName() << endl << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
