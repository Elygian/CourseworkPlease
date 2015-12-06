#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Parent class for inheritance heirarchy
class Person
{
protected:
	string m_Name, m_Surname, m_Telephone, m_Email;
public:
	Person() {}
	Person(string &s, string &f) : m_Surname(s), m_Name(f)
	{
		m_Name = "NoName", m_Surname = "NoSurname", m_Telephone = "", m_Email = "";
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
			//cout << "NoNumber" << endl;
			return false;
		}
		else
		{
			//cout << "Your phone number is now registered"<< endl;
			return true;
		}
	}

	virtual bool has_email_p()
	{
		if (m_Email.empty())
		{
			//cout << "NoEmail" << endl;
			return false;
		}
		else
		{
			//cout << "Your email is now registered" << endl;
			return true;
		}
	}
};

class Person_with_telephone : public virtual Person
{
protected:
	string telephone = m_Telephone;
public:
	Person_with_telephone() {}
	Person_with_telephone(string &s, string &f, string &t) : Person(s, f), telephone(t) {}

	void set_telephone(string &telephone)
	{
		m_Telephone = telephone;
	}
};

class Person_with_email : public virtual Person
{
protected:
	string email = m_Email;
public:
	Person_with_email() {}
	Person_with_email(string &s, string &f, string &e) :Person(s, f), email(e) {}

	void set_email(string &e)
	{
		m_Email = e;
	}
};

class Person_with_telephone_email : public virtual Person_with_telephone, public virtual Person_with_email
{
public:
	Person_with_telephone_email() {}
	Person_with_telephone_email(string &s, string &f, string &t, string &e) : Person(s, f), Person_with_telephone(s, f, t), Person_with_email(s, f, e) {}
};

ostream &operator << (ostream &output, Person &p)
{
	//Checks that both 'telephone' and 'email' are initialized to NoNumber and NoEmail respectively. If true, it prints name and surname
	if (p.has_telephone_p() == false && p.has_email_p() == false)
	{
		output << "<person" << " S " << p.get_surname() << " N " << p.get_name() << " >" << endl;
		return output;
	}
	//Checks that 'email' is initialized to NoEmail. If true, it prints name, surname, and telephone
	else if (p.has_email_p() == false)
	{
		output << "<person" << " S " << p.get_surname() << " N " << p.get_name() << " T " << p.get_telephone() << " >" << endl;
		return output;
	}
	//Checks that 'telephone' is initialized to NoNumber. If true, it prints name, surname, and email
	else if (p.has_telephone_p() == false)
	{
		output << "<person" << " S " << p.get_surname() << " N " << p.get_name() << " E " << p.get_email() << " >" << endl;
		return output;
	}
	//Checks to see that all 4 variables are initialized to non default values. If true, it prints all 4 values
	else
	{
		output << "<person" << " S " << p.get_surname() << " N " << p.get_name() << " T " << p.get_telephone() << " E " << p.get_email() << " >";
		return output;
	}
}

//Here we overload the operator>> so we can pass class Person through make_person

istream& operator>>(istream &is, Person)
{
	return is;
}

istream& operator>>(istream &is, Person_with_email)
{
	return is;
}

istream& operator>>(istream &is, Person_with_telephone)
{
	return is;
}

istream& operator>>(istream &is, Person_with_telephone_email)
{
	return is;
}

//Here we create the pointers to the objects
Person* make_person(istream &stream)
{
	Person *person_pointer = new Person;
	stream >> *person_pointer;
	return person_pointer;
}

Person_with_email* make_person_email(istream &stream)
{
	Person_with_email *person_pointer = new Person_with_email;
	stream >> *person_pointer;
	return person_pointer;
}

Person_with_telephone* make_person_telephone(istream &stream)
{
	Person_with_telephone *person_pointer = new Person_with_telephone;
	stream >> *person_pointer;
	return person_pointer;
}

Person_with_telephone_email* make_person_telephone_email(istream &stream)
{
	Person_with_telephone_email *person_pointer = new Person_with_telephone_email;
	stream >> *person_pointer;
	return person_pointer;
}

// read_person looks at the input data and creates the appropriate object from the class

istream &read_person(istream &in, Person * & p)
{
	string input;
	stringstream stream(input);
	getline(in, input);
	cout << "input:\n" << input;
	string s = " S ";
	string e = " E ";
	string t = " T ";
	bool is_valid_person = false;
	bool has_t = false;
	bool has_e = false;

	if (input.find(e) != string::npos) { has_e = true; }
	if (input.find(t) != string::npos) { has_t = true; }
	if (input.find(s) != string::npos) { is_valid_person = true; }


	if (has_e && has_t)
	{
		cout << "e + t\n";
		p = make_person_telephone_email(stream);

	}
	else if (has_e)
	{
		cout << "e\n";
		p = make_person_email(stream);;
	}
	else if (has_t)
	{
		cout << "t \n";
		p = make_person_telephone(stream);

	}
	else if (is_valid_person)
	{
		cout << "is person \n";
		p = make_person(stream);
	}
	else
	{
		cout << "\nInvalid input.\n";
	}
	return in;
}

// Modified read_person test to take stringstream
int main()
{
	Person *p = 0;
	string ss = "<person S Smith N Tom >\n<person S Smith N Dick T +49.921.1434 >\n<person S Smith N Harry E hsmith@gmail.com >\n<person S Smith N Mary T +39.921.1434 E msmith@gmail.com >\n<person S John N John T + 33.921.1434 E jjohn@gmail.com >\n";
	stringstream iss(ss);
	while (read_person(iss, p) && p)
		cout << *p << endl;
	return 0;
}
