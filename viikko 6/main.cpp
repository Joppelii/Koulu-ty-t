#include "student.h"
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
    string opiskelijaNimi = " ";
    int OppilasIka = 0;
    int selection =0;
2;
    vector<Student>studentList;
    vector<Student>::iterator it;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
        {
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            cout << "Student name? "<< endl;
            cin >> opiskelijaNimi;
            cout << "Student Age? " << endl;
            cin >> OppilasIka;
            // Lisää uusi student StudentList vektoriin.

            Student Oppilas(opiskelijaNimi, OppilasIka);

            studentList.push_back(Oppilas);

            break;
        }
        case 1:
        {
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            for(auto& student : studentList)
                cout << student.getName() << " " << endl;

            break;
        }
        case 2:
        {
            sort(studentList.begin(), studentList.end(), [](Student & a, Student & b)
                {
                return a.getName()<b.getName();

                });

            for (auto& student : studentList)
                student.printStudentinfo();

            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            break;
        }

        case 3:

        {
            sort(studentList.begin(), studentList.end(), [](Student & a, Student & b)
                 {
                     return a.getAge()<b.getAge();

                 });

            for (auto& student : studentList)
                student.printStudentinfo();
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            break;
        }

        case 4:
        {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.


            cin >> opiskelijaNimi;

            auto it = find_if(studentList.begin(), studentList.end(),
                              [opiskelijaNimi](Student& s) {
                                  return s.getName() == opiskelijaNimi;
                              });

            if (it != studentList.end())
            {
                it->printStudentinfo();
            }
            else
            {
                cout << "Ei loytynyt." << endl;
            }
            break;
        }

    default:
        cout<< "Wrong selection, stopping..."<<endl;
        break;
    }
}while(selection < 5);

return 0;
}
