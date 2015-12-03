#include <iostream>
#include <string>

//Allows use of basic C++ functions
using namespace std;

//Base class for all classes
class Person
{

protected:
	string m_Name = "NoName", m_Surname = "NoSurname", m_Telephone = "NoNumber", m_Email = "NoEmail";

public:
	Person() {}
	Person(string &s, string &f)
	{
		set_surname(s);
		set_name(f);
	}

	void set_name(string &f)
	{
		m_Name = f;
	}

	void set_surname(string &s)
	{
		m_Surname = s;
	}

	virtual string get_name()
	{
		return m_Name;
	}

	virtual string get_surname()
	{
		return m_Surname;
	}

	virtual string get_telephone()
	{
		return m_Telephone;
	}

	virtual string get_email()
	{
		return m_Email;
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
	Person_with_telephone(string &s, string &f, string &telephone)
	{
		set_surname(s);
		set_name(f);
		set_telephone(telephone);
	}

	void set_telephone(string &telephone)
	{
		m_Telephone = telephone;
	}

};

class Person_with_email : public virtual Person
{
protected:

public:
	Person_with_email() {}
	Person_with_email(string &s, string &f ,string &email)
	{
		set_surname(s);
		set_name(f);
		set_email(email);
	}

	void set_email(string &email)
	{
		m_Email = email;
	}

};

class Person_with_telephone_and_email : public virtual Person_with_telephone, public virtual Person_with_email
{
protected:

public:
	Person_with_telephone_and_email() {}
	Person_with_telephone_and_email(string &s, string &f, string &telephone, string &email)
	{
		set_surname(s);
		set_name(f);
		set_telephone(telephone);
		set_email(email);
	}
};

ostream& operator<<(ostream &os, Person &p)
{
	if (p.has_email_p() && p.has_telephone_p())
	{
		cout << "<person" << " S " << p.get_surname() << " F " << p.get_name() << " T " << p.get_telephone() << " E " << p.get_email()  << " >";
	}
	else if (p.has_email_p())
	{
		cout << "<person" << " S " << p.get_surname() << " F " << p.get_name() << " E " << p.get_email() << " >";
	}
	else if (p.has_telephone_p())
	{
		cout << "<person" << " S " << p.get_surname() << " F " << p.get_name() << " T " << p.get_telephone() << " >";
	}
	else
	{
		cout << "<person" << " S " << p.get_surname() << " F " << p.get_name() << " >";
	}
	return os;
}

int main()
{
	string s, f, t, e;

	//Creates Person object and after input returns name and surname
	Person person(s,f);
	cout << "Person Created" << endl;
	cout << person.get_name() << " " << person.get_surname() << endl << endl;

	cout << "Type your name: ";
	getline(cin, f), person.set_name(f);

	cout << "Type your Surname: ";
	getline(cin, s), person.set_surname(s);

	cout << "Your name is: " << person.get_name() << " " << person.get_surname() << endl << endl;

	//Creates Person with telephone object
	Person_with_telephone pwt(s,f,t);
	cout << "Person with telephone Created" << endl;
	cout << pwt.has_telephone_p() << endl << endl << "Type Phonenumber: ";
	getline(cin, t), pwt.set_telephone(t); //User inputs value of telephone number into t and pwt.set_telephone takes that as a parameter
	cout << pwt.has_telephone_p() << endl << endl << "Your Phonenumber is: " << pwt.get_telephone() << endl;

	cout << "Type your name: ";
	getline(cin, f), pwt.set_name(f); //User inputs value of name into f and pwt.set_name takes that as a parameter

	cout << "Type your surname: ";
	getline(cin, s), pwt.set_surname(s); //User inputs value of surname into s and pwt.set_surname takes that as a parameter

	//Print name and surname using the methods from Person_with_telephone
	cout << "Your name is: " << pwt.get_name() << " " << pwt.get_surname();
	cout << "your number is: " << pwt.get_telephone() << endl << endl;

	//Creates Person with email object
	Person_with_email email(s,f,e);
	cout << email.has_email_p() << endl << endl << "Type email: ";
	getline(cin, e), email.set_email(e);
	cout << email.has_email_p() << endl << endl << "Your email is: " << email.get_email() << endl << endl;

	//Creates Person with telephone
	Person_with_telephone_and_email pwtae(s,f,t,e);
	cout << pwtae.has_telephone_p() << endl << endl << "Type Phonenumber: ";
	getline(cin, t), pwtae.set_telephone(t); //User inputs value of telephone number into t and pwtae.set_telephone takes that as a parameter
	cout << pwtae.has_telephone_p() << endl << endl << "Your Phonenumber is: " << pwtae.get_telephone() << endl; //Boolean function runs and value of telephone number is printed

	cout << pwtae.has_email_p() << endl << endl << "Type email: ";
	getline(cin, e), pwtae.set_email(e);
	cout << pwtae.has_email_p() << endl << endl << "Your email is: " << pwtae.get_email() << endl;

	return 0;
}
