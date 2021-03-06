class Person;
istream& Read(istream &, Person &);
ostream& Print(ostream &, const Person &);

class Person
{
	friend istream& Read(istream &, Person &);
	friend ostream& Print(ostream &, const Person &);

public:
	Person() = default;
	Person(const string name, const string address) :
		name_(name), address_(address) { }
	Person(istream &is)
	{
		Read(is, *this);
	}

	string get_name() const
	{
		return name_;
	}
	string get_address() const
	{
		return address_;
	}

private:
	string name_;
	string address_;
};

istream& Read(istream &is, Person &obj)
{
	is >> obj.name_ >> obj.address_;
	return is;
}

ostream& Print(ostream &os, const Person &obj)
{
	os << obj.name_ << ' ' << obj.address_ << '\n';
	return os;
}
