#include <iostream>
#include <string>

using namespace std;


class Person
{

protected:
	string m_Name, m_Surname, m_Telephone, m_Email;

public:
	Person() {}
	Person(string f, string s) : m_Name(f), m_Surname(s)
	{
		m_Name = "NoName";
		m_Surname = "NoSurname";
		m_Telephone = "";
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

	bool has_telephone_p()
	{

		if (m_Telephone.empty())
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

	bool has_email_p()
	{

		if (m_Email.empty())
		{
			cout << "You have no email registered" << endl;
			return false;
		}

		else
		{
			cout << "Your email is now registered" << endl;
			return true;
		}

	}

};

class Person_with_telephone : public Person
{

protected:

public:
	Person_with_telephone(string telephone)
	{
		set_telephone(telephone);
	}

	void set_telephone(string telephone)
	{
		m_Telephone = telephone;
	}

	string get_telephone()
	{
		return m_Telephone;
	}

};

class Person_with_email : public Person
{
protected:

public:
	Person_with_email(string email)
	{
		set_email(email);
	}

	void set_email(string email)
	{
		m_Email = email;
	}

	string get_email()
	{
		return m_Email;
	}
};

int main()
{
	string f, s, t, e;

	Person person("NoName","NoSurname");
	cout << "Person Created" << endl;
	cout << person.get_name() << " " << person.get_surname() << endl << endl;

	cout << "Type your name: ";
	getline(cin,f), person.set_name(f);

	cout << "Type your Surname: ";
	getline(cin,s), person.set_surname(s);

	cout << "Your name is: " << person.get_name() << " " << person.get_surname() << endl << endl;

	Person_with_telephone pwt("");
	cout << pwt.has_telephone_p() << endl << endl << "Type Phonenumber: ";
	getline(cin,t), pwt.set_telephone(t);
	cout << pwt.has_telephone_p() << endl << endl << "Your Phonenumber is: " << pwt.get_telephone() << endl;

	Person_with_email email("");
	cout << email.has_email_p() << endl << endl << "Type email: ";
	getline(cin, e), email.set_email(e);
	cout << email.has_email_p() << endl << endl << "Your email is: " << email.get_email() << endl;

	return 0;
}
