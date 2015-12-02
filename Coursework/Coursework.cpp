#include <iostream>
#include <string>

using namespace std;


class Person
{

protected:
	string m_Name, m_Surname;
	//change

public:
	Person() {}
	Person(string f, string s) : m_Name(f), m_Surname(s)
	{
		m_Name = "NoName";
		m_Surname = "NoSurname";
		set_name(f);
		set_surname(s);
	}

	void set_name(string f)
	{
		m_Name = f;
	}

	void set_surname(string s)
	{
		m_Surname = s;
	}

	string get_name()
	{
		return m_Name;
	}
	string get_surname()
	{
		return m_Surname;
	}
};

class Person_with_telephone : public Person
{

protected:
	string m_telephone;

public:
	Person_with_telephone(string telephone)
	{
		set_telephone(telephone);
	}

	void set_telephone(string telephone)
	{
		m_telephone = telephone;
	}

	string get_telephone()
	{
		return m_telephone;
	}

	bool has_telephone_p()
	{

		if (m_telephone == "")
		{
			cout << "You have no phone number registered" << endl;
			return false;
		}

		else
		{
			cout << "Your phone number is now registered"<< endl;
			return true;
		}

	}

};

int main()
{
	string f, s, t;

	Person person("NoName","NoSurname");
	cout << "Person Created" << endl;
	cout << person.get_name() << " " << person.get_surname() << endl << endl;

	cout << "Type your name: ";
	cin >> f, person.set_name(f);

	cout << "Type your Surname: ";
	cin >> s, person.set_surname(s);

	cout << "Your name is: " << person.get_name() << " " << person.get_surname() << endl << endl;

	Person_with_telephone pwt("");
	cout << pwt.has_telephone_p() << endl << endl << "Type Phonenumber: ";
	cin >> t, pwt.set_telephone(t);
	cout << pwt.has_telephone_p() << endl << endl << "Your Phonenumber is: " << pwt.get_telephone() << endl;

	return 0;
}
