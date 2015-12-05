#include <iostream>
#include <string>
#include <sstream>
//Allows use of basic C++ functions
using namespace std;

//Base class for all classes
class Person
{

protected:
	string m_Name, m_Surname, m_Telephone, m_Email;

public:
	Person() { m_Name = "NoName", m_Surname = "NoSurname", m_Telephone = "", m_Email = ""; }
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

//Inherits from class Person
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

//Inherits from class Person
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

//Inherits from classes Person_with_telephone and Person_and_email
class Person_with_telephone_and_email : public virtual Person_with_telephone, public virtual Person_with_email
{
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

ostream &operator << (ostream &output, Person &p)
{
	//Checks that both 'telephone' and 'email' are initialized to NoNumber and NoEmail respectively. If true, it prints name and surname
	if (p.has_telephone_p() == false && p.has_email_p() == false)
	{
		output << "<person" << " S " << p.get_surname() << " N " << p.get_name() <<" >" <<  endl;
		cout << endl;
		return output;
	}
	//Checks that 'email' is initialized to NoEmail. If true, it prints name, surname, and telephone
	else if (p.has_email_p() == false)
	{
		output << "<person" << " S " << p.get_surname() << " N " << p.get_name() << " T " << p.get_telephone() << " >" << endl;
		cout << endl;
		return output;
	}
	//Checks that 'telephone' is initialized to NoNumber. If true, it prints name, surname, and email
	else if (p.has_telephone_p() == false)
	{
		output << "<person" << " S " << p.get_surname() << " N " << p.get_name() << " E " << p.get_email() << " >" << endl;
		cout << endl;
		return output;
	}
	//Checks to see that all 4 variables are initialized to non default values. If true, it prints all 4 values
	else
	{
		output << "<person" << " S " << p.get_surname() << " N " << p.get_name() << " T " << p.get_telephone() << " E " << p.get_email() << " >" << endl;
		cout << endl;
		return output;
	}
}

//This is called at runtime after object Person is constructed from it's class
istream &operator >> (istream &input, Person &p) 
{
	string s, f;
	cout << "Enter Surname: ";
	input >> s;
	cout << "Enter Name: ";
	input >> f;
	p.set_surname(s);
	p.set_name(f);
	return input;
}

//This is called at runtime after object Person_with_telephone is constructed from it's class
istream &operator >> (istream &input, Person_with_telephone &pwt)
{
	string s, f, t;
	cout << "Enter Surname: ";
	input >> s;
	cout << "Enter Name: ";
	input >> f;
	cout << "Enter Telephone: ";
	input >> t;
	pwt.set_surname(s);
	pwt.set_name(f);
	pwt.set_telephone(t);
	return input;
}

//This is called at runtime after object Person_with_email is constructed from it's class
istream &operator >> (istream &input, Person_with_email &pwe)
{
	string s, f, e;
	cout << "Enter Surname: ";
	input >> s;
	cout << "Enter Name: ";
	input >> f;
	cout << "Enter Email: ";
	input >> e;
	pwe.set_surname(s);
	pwe.set_name(f);
	pwe.set_email(e);
	return input;
}

//This is called at runtime after object Person_with_telephone_and_email is constructed from it's class
istream &operator >> (istream &input, Person_with_telephone_and_email &pwte)
{
	string s, f, t, e;
	cout << "Enter Surname: ";
	input >> s;
	cout << "Enter Name: ";
	input >> f;
	cout << "Enter Telephone: ";
	input >> t;
	cout << "Enter Email: ";
	input >> e;
	pwte.set_surname(s);
	pwte.set_name(f);
	pwte.set_telephone(t);
	pwte.set_email(e);
	return input;
}

//istream& operator>>(istream &is, Person_with_email &p) {
//	string opening, s, surname, f, forename, e, email, closing;
//
//	if (
//		(is >> opening >> s >> surname >> f >> forename >> e >> email >> closing) &&
//		((opening == "<person") && (s == "S") && (f == "F") && (e == "E") && (closing == ">"))) {
//		p = Person_with_email(surname, forename, email);
//	}
//	return is;
//}
//
//istream& operator>>(istream &is, Person_with_telephone &p) {
//	string opening, s, surname, f, forename, t, telephone, closing;
//	if (
//		(is >> opening >> s >> surname >> f >> forename >> t >> telephone >> closing) &&
//		((opening == "<person") &&
//			(s == "S") &&
//			(f == "F") &&
//			(t == "T") &&
//			(closing == ">"))
//		)
//	{
//		p = Person_with_telephone(surname, forename, telephone);
//	}
//	return is;
//}
//
//istream& operator>>(istream &is, Person_with_telephone_and_email &p) {
//	string opening, s, surname, f, forename, t, telephone, e, email, closing;
//
//	if (
//		(is >> opening >> s >> surname >> f >> forename >> t >> telephone >> e >> email >> closing) &&
//		((opening == "<person") &&
//			(s == "S") &&
//			(f == "F") &&
//			(t == "T") &&
//			(e == "E") &&
//			(closing == ">"))
//		)
//	{
//		p = Person_with_telephone_and_email(surname, forename, telephone, email);
//	}
//	return is;
//}

//Person* make_person(istream &stream) {
//	Person *person_pointer = new Person;
//	stream >> *person_pointer;
//	return person_pointer;
//}
//
//Person_with_email* make_person_email(istream &stream) {
//	Person_with_email *person_pointer = new Person_with_email;
//	stream >> *person_pointer;
//	return person_pointer;
//}
//
//Person_with_telephone* make_person_telephone(istream &stream) {
//	Person_with_telephone *person_pointer = new Person_with_telephone;
//	stream >> *person_pointer;
//	return person_pointer;
//}
//
//Person_with_telephone_and_email* make_person_telephone_email(istream &stream) {
//	Person_with_telephone_email *person_pointer = new Person_with_telephone_email;
//	stream >> *person_pointer;
//	return person_pointer;
//}
//
//istream & read_person(istream &in, Person * & p) {
//	string input;
//	getline(in, input);
//	stringstream stream(input);
//	string e = " E ";
//	string t = " T ";
//	bool has_e = false;
//	bool has_t = false;
//
//	if (input.find(e) != std::string::npos) { has_e = true; }
//	if (input.find(t) != string::npos) { has_t = true; }
//
//	if (has_e && has_t) {
//		cout << "e + t\n";
//		Person_with_telephone_email *person_pointer = make_person_telephone_email(stream);
//		p = person_pointer;
//	}
//	else if (has_e) {
//		cout << "e\n";
//		Person_with_email *person_pointer = make_person_email(stream);
//		p = person_pointer;
//	}
//	else if (has_t) {
//		cout << "t \n";
//		Person_with_telephone *person_pointer = make_person_telephone(stream);
//		p = person_pointer;
//	}
//	else {
//		cout << "is person \n";
//		Person *person_pointer = make_person(stream);
//		p = person_pointer;
//	}
//	return in;
//}

int main()
{
	//This creates object Person and takes input to initialize the variables
	cout << "Person"<< endl << endl;
	Person p;
	cout << p;
	cin >> p;
	cout << p;

	//This creates object Person_with_telephone and takes input to initialize the variables
	cout << "Person with telephone" <<endl << endl;
	Person_with_telephone pwt;
	cin >> pwt;
	cout << pwt;

	//This creates object Person_with_email and takes input to initialize the variables
	cout << "Person with email" << endl << endl;
	Person_with_email pwe;
	cin >> pwe;
	cout << pwe;

	//This creates object Person_with_telephone_and_email and takes input to initialize the variables
	cout << "Person with telephone and email" << endl << endl;
	Person_with_telephone_and_email pwte;
	cin >> pwte;
	cout << pwte;

	return 0;
}
