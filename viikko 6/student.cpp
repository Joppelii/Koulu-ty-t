#include "student.h"

Student::Student(string nimi, int ika)
{
    Name = nimi;
    Age = ika;
}


void Student::setAge(int ika)
{
    Age = ika;
}

void Student::setName(string nimi)
{
    Name = nimi;;
}

string Student::getName()
{
    return Name;
}

int Student::getAge()
{
    return Age;
}

void Student::printStudentinfo()
{
    cout << "Oppilaan nimi: " <<Name << " Oppilaan ika: " << Age << endl;
}
