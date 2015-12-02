#include <iostream>
#include <string>

using namespace std;

class Person
{

protected:
	string m_FirstName, m_LastName;

public:
	Person() {}
	Person(const string& firstName, const string& lastName) :
		m_FirstName(firstName), m_LastName(lastName)
	{}

	string get_name() const
	{
		return m_FirstName;
	}
	string get_surname() const
	{
		return m_LastName;
	}
};

class Person_with_telephone : public Person
{

protected:
	string m_telephone;

public:
	Person_with_telephone() {}
	Person_with_telephone(const string& telephone) : m_telephone(telephone)
	{}

	bool has_telephone_p()
	{

		if (m_telephone == "")
		{
			cout << "You have no phone number registered" << endl;
			return false;
		}

		else
		{
			cout << "Your number is: " << m_telephone << endl;
			return true;
		}

	}

	string get_telephone() const
	{
		return m_telephone;
	}

	string set_telephone()
	{
		cout << "Input telephone number: " << endl;
		cin >> m_telephone;
	}



};

int main()
{
	string f, l, ph;

	cout << "Enter fist name: ";
	cin >> f;
	cout << "Enter Last name: ";
	cin >> l;
	cout << "Enter telephone number: ";
	//cin >> ph;
	//Person p(f, l);
	Person_with_telephone pwt(/*f, l,*/ ph);
	pwt.get_telephone();
	//cout << "Your name is: " << p.get_name() << " " << p.get_surname() << endl;
	//cout << "Has telephone? " << pwt.has_telephone_p() << endl << " Your number is: " << pwt.get_telephone() << endl;

	return 0;
}
