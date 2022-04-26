#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>

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
    
    void print(std::ostream& out) const
    {
        out << "Name: " << std::setw(11) << name << ",  ";
        out << "Age: " << std::setw(2) << age << ",  ";
        out << "Ticket: " << std::setw(6) << ticket << ",  ";
        out << "Fare: " << std::setw(5) << fare;
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
    
    void print(std::ostream& out) const
    {
        out << "Name: " << std::setw(11) << name << ",  ";
        out << "Age: " << std::setw(2) << age << ",  ";
        out << "City: " << std::setw(9) << city;
    }
};

std::ostream& operator<<(std::ostream& out, const Person& p)
{
    p.print(out);
    return out;
}

int main()
{
    std::srand(std::time(nullptr));
    std::vector<Person*> v;
    
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
            Person* person = new Person();
            v.push_back(person);
        }
        else if (n == 2) {
            Passenger* passenger = new Passenger();
            v.push_back(passenger);
        }
        else if (n == 3) {
            Citizen* citizen = new Citizen();
            v.push_back(citizen);
        }
        else if (n == 4) {
            for (Person* a: v)
            {
                delete a;
            }
            v.clear();
        }
        else if (n == 5) {
            break;
        }
        for (const Person* a: v)
        {
            std::cout << *a << std::endl;
        }
        
    }
    
    
    return 0;
}
