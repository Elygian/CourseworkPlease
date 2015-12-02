#include <iostream>
#include <string>

using namespace std;


class Person
{

protected:
	string m_Name, m_Surname, m_Telephone, m_Email;

public:
	Person() {}
	Person(string f, string s)
	{
		m_Name = "NoName";
		m_Surname = "NoSurname";
		m_Telephone = "";
		m_Email = "";
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

	virtual bool has_telephone_p()
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

	virtual bool has_email_p()
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

class Person_with_telephone : public virtual Person
{

protected:

public:
	Person_with_telephone() {}
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

class Person_with_email : public virtual Person
{
protected:

public:
	Person_with_email() {}
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

class Person_with_telephone_and_email : public virtual Person_with_telephone, public virtual Person_with_email
{
protected:

public:
	Person_with_telephone_and_email() {}
	Person_with_telephone_and_email(string telephone, string email)
	{
		set_telephone(telephone);
		set_email(email);

	 bool has_telephone(); {}
	}

	virtual bool has_telephone()
	{
		Person_with_telephone::has_telephone();
	}
};

int main()
{
	string f, s, t, e;

	//Creates Person object and after input returns name and surname
	Person person(f,s);
	cout << "Person Created" << endl;
	cout << person.get_name() << " " << person.get_surname() << endl << endl;

	cout << "Type your name: ";
	getline(cin, f), person.set_name(f);

	cout << "Type your Surname: ";
	getline(cin, s), person.set_surname(s);

	cout << "Your name is: " << person.get_name() << " " << person.get_surname() << endl << endl;

	//Creates Person with telephone object and after input returns telephone, name, surname and if you have a telephone number
	Person_with_telephone pwt(t);
	cout << "Person with telephone Created" << endl;
	cout << pwt.has_telephone_p() << endl << endl << "Type Phonenumber: ";
	getline(cin, t), pwt.set_telephone(t);
	cout << pwt.has_telephone_p() << endl << endl << "Your Phonenumber is: " << pwt.get_telephone() << endl;

	cout << "Type your name: ";
	getline(cin, f), pwt.set_name(f);

	cout << "Type your surname: ";
	getline(cin, s), pwt.set_surname(s);

	cout << "Your name is: " << pwt.get_name() << " " << pwt.get_surname();
	cout << "your number is: " << pwt.get_telephone() << endl << endl;

	//Creates Person with email object and after input returns email
	Person_with_email email(e);
	cout << email.has_email_p() << endl << endl << "Type email: ";
	getline(cin, e), email.set_email(e);
	cout << email.has_email_p() << endl << endl << "Your email is: " << email.get_email() << endl << endl;

	//Creates Person with telephone and email and returns telephone and email
	Person_with_telephone_and_email pwtae("","");
	cout << pwtae.Person_with_telephone::has_telephone_p() << endl << endl << "Type Phonenumber: ";
	getline(cin, t), pwtae.set_telephone(t);
	cout /*<< pwtae.has_telephone_p()*/ << endl << endl << "Your Phonenumber is: " << pwtae.get_telephone() << endl;

	cout /*<< pwtae.has_email_p*/ << endl << endl << "Type email: ";
	getline(cin, e), pwtae.set_email(e);
	cout /*<< pwtae.has_email_p() */<< endl << endl << "Your email is: " << pwtae.get_email() << endl;

	return 0;
}
