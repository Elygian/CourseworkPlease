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
	Person() { m_Name = "NoName", m_Surname = "NoSurname", m_Telephone = "NoNumber", m_Email = "NoEmail"; }
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

	friend ostream &operator<<(ostream &output, Person &p);
	friend istream &operator>>(istream &input, Person &p);

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

ostream &operator << (ostream &output, Person &p)
{
	if (p.m_Telephone == "NoNumber" && p.m_Email == "NoEmail")
	{
		output << "<person" << " S " << p.get_surname() << " N " << p.get_name() <<" >" <<  endl;
		return output;
	}
	else if (p.m_Email == "NoEmail")
	{
		output << "<person" << " S " << p.get_surname() << " N " << p.get_name() << " T " << p.get_telephone() << " >" << endl;
		return output;
	}
	else if (p.m_Telephone == "NoNumber")
	{
		output << "<person" << " S " << p.get_surname() << " N " << p.get_name() << " E " << p.get_email() << " >" << endl;
		return output;
	}
	else
	{
		output << "<person" << " S " << p.get_surname() << " N " << p.get_name() << " T " << p.get_telephone() << " E " << p.get_email() << " >" << endl;
		return output;
	}
}

istream &operator >> (istream &input, Person &p) 
{
	string s, f;
	input >> s;
	input >> f;
	p.set_surname(s);
	p.set_name(f);
	return input;
}

istream &operator >> (istream &input, Person_with_telephone &pwt)
{
	string s, f, t;
	input >> s;
	input >> f;
	input >> t;
	pwt.set_surname(s);
	pwt.set_name(f);
	pwt.set_telephone(t);
	return input;
}

istream &operator >> (istream &input, Person_with_email &pwe)
{
	string s, f, e;
	input >> s;
	input >> f;
	input >> e;
	pwe.set_surname(s);
	pwe.set_name(f);
	pwe.set_email(e);
	return input;
}

istream &operator >> (istream &input, Person_with_telephone_and_email &pwte)
{
	string s, f, t, e;
	input >> s;
	input >> f;
	input >> t;
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
	cout << "Person"<<endl;
	Person p;
	cin >> p;
	cout << p;

	cout << "Person with telephone" <<endl;
	Person_with_telephone pwt;
	cin >> pwt;
	cout << pwt;

	cout << "Person with email" << endl;
	Person_with_email pwe;
	cin >> pwe;
	cout << pwe;

	cout << "Person with telephone and email" << endl;
	Person_with_telephone_and_email pwte;
	cin >> pwte;
	cout << pwte;


	return 0;
}
