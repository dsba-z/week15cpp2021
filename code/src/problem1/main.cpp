
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cctype>
#include <algorithm>

int getRandInt(int from, int to)
{
    return int((double)rand() / ((double)RAND_MAX + 1) * (to - from)) + from;
}

int getRandDouble(double from, double to)
{
    return (double)rand() / ((double)RAND_MAX + 1) * (to - from) + from;
}


std::string getRandString(int len) {
    static const char alphanum[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    std::string buffer;
    buffer.reserve(len);

    for (int i = 0; i < len; ++i) {
        buffer += alphanum[getRandInt(0, sizeof(alphanum)-1)];
    }

    return buffer;
}

struct Person
{
    std::string name;
    unsigned int age;

    Person()
    {
        age = getRandInt(20, 60);
        name = getRandString(10);
    }

    // virtual means "can be overwritten in a child class/struct"
    virtual ~Person()
    {

    }

    virtual void print(std::ostream& out) const
    {
        out << "Name: " << std::setw(11) << name << ",  ";
        out << "Age: " << std::setw(2) << age;
    }

    virtual void capitalize(){
        for (int i=0;i<name.size();i++){
            name[i]=std::toupper(name[i]);
        }
    }
};


struct Passenger : public Person
{
    std::string ticket;
    double fare;

    Passenger()
            :Person()
    {
        ticket = getRandString(5);
        fare = getRandDouble(5, 40);
    }

    virtual ~Passenger()
    {

    }

    virtual void print(std::ostream& out) const
    {
        out << "Name: " << std::setw(11) << name << ",  ";
        out << "Age: " << std::setw(2) << age << ",  ";
        out << "Ticket: " << std::setw(6) << ticket << ",  ";
        out << "Fare: " << std::setw(5) << fare;
    }

    virtual void capitalize(){
        std::transform(name.begin(), name.end(), name.begin(), ::toupper);
        std::transform(ticket.begin(), ticket.end(), ticket.begin(), ::toupper);
    }
};


struct Citizen : public Person
{
    std::string city;

    Citizen()
            : Person()
    {
        city = getRandString(7);
    }

    virtual ~Citizen()
    {

    }

    virtual void print(std::ostream& out) const
    {
        out << "Name: " << std::setw(11) << name << ",  ";
        out << "Age: " << std::setw(2) << age << ",  ";
        out << "City: " << std::setw(9) << city;
    }

    virtual void capitalize(){
        std::transform(name.begin(), name.end(), name.begin(), ::toupper);
        std::transform(city.begin(), city.end(), city.begin(), ::toupper);
    }
};

struct Student: public Person{
    std::string university;

    Student(): Person(){
        university= getRandString(5);
    }

    virtual ~Student()
    {

    }

    virtual void print(std::ostream& out) const
    {
        out << "Name: " << std::setw(11) << name << ",  ";
        out << "Age: " << std::setw(2) << age << ",  ";
        out << "City: " << std::setw(9) << university;
    }

    virtual void capitalize(){
        std::transform(name.begin(), name.end(), name.begin(), ::toupper);
        std::transform(university.begin(), university.end(), university.begin(), ::toupper);
    }
};

void capitalize(Person* p){
    p->capitalize();
}

std::ostream& operator<<(std::ostream& out, const Person& p)
{
    p.print(out);
    return out;
}

struct PersonRegistry{
    std::vector<Person*> v;


    ~PersonRegistry(){
        for (Person* a: v)
        {
            delete a;
        }
        v.clear();
    }

    void addPerson(){
        Person* person = new Person();
        v.push_back(person);
    };

    void addPassenger(){
        Person* person = new Person();
        v.push_back(person);
    };

    void addCitizen(){
        Person* person = new Person();
        v.push_back(person);
    };

    void addPStudent(){
        Person* person = new Person();
        v.push_back(person);
    };

    void print(){
        for (const Person* p: v)
        {
            std::cout << *p << std::endl;
        }
    }
};

int main()
{
    std::srand(std::time(nullptr));
    PersonRegistry person_registry;

    while (true)
    {
        std::cout << "Choose next action\n";
        std::cout << "1. Add person\n";
        std::cout << "2. Add passenger\n";
        std::cout << "3. Add citizen\n";
        std::cout << "4. Delete all\n";
        std::cout << "5. Quit\n";

        int n;
        std::cin >> n;

        if (n == 1) {
            person_registry.addPerson();
        }
        else if (n == 2) {
            person_registry.addPassenger();
        }
        else if (n == 3) {
            person_registry.addCitizen();
        }
        else if (n == 4) {
            delete person_registry;
        }
        else if (n == 5) {
            break;
        }
        person_registry.print();

    }


    return 0;
}
