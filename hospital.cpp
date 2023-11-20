#include <iostream>
#include <string>
#include <iomanip>
#include <D:\Coding\header\hospital.h>
using namespace std;

int main() {
    string name, speciality;
    int day, month, year, patientID, age;
    double medicine;

    cout << "Enter doctor's name\t\t\t\t: ";
    getline(cin, name);
    cout << "Enter doctor's speciality\t\t\t: ";
    getline(cin, speciality);
    doctorType doctor(name, speciality);

    cout << "Enter patient's name\t\t\t\t: ";
    getline(cin, name);
    cout << "Enter patient's ID\t\t\t\t: ";
    cin >> patientID;
    cout << "Enter patient's age\t\t\t\t: ";
    cin >> age;
    cout << "Enter patient's date of birth (day month year)\t: ";
    cin >> day >> month >> year;

    dateType date(day, month, year);
    patientType patient(name, patientID, age, date, doctor);

    cout << "Enter medicine charges (Dollar)\t\t\t: ";
    cin >> medicine;
    cout << endl;

    billType bill(patientID, medicine);

    cout << "**********************************" << endl;
    cout << "********* Hospital Bill **********" << endl;
    cout << "**********************************" << endl;
    cout << endl;

    cout << "**********************************" << endl;
    cout << "**********************************" << endl;
    cout << "********* Doctor Details *********" << endl;
    cout << "**********************************" << endl;
    cout << "   Dr. Name\t: " << patient.getDoctor().getName()  << endl; 
    cout << "   Specialty\t: " << patient.getDoctor().getSpeciality() << endl;
    cout << "**********************************" << endl;
    cout << "**********************************" << endl;
    cout << endl;

    cout << "**********************************" << endl;
    cout << "**********************************" << endl;
    cout << "********* Patient Details ********" << endl;
    cout << "**********************************" << endl;
    cout << "   Patient Name\t: " << patient.getName() << endl;
    cout << "   Patient ID\t: " << patient.getPatientID() << endl;
    cout << "   Age\t\t: " << patient.getAge() << endl;
    cout << "   Date Of Birth: ";
    patient.getBirth().printDate();
    cout << endl;
    cout << "**********************************" << endl;
    cout << "**********************************" << endl;
    cout << endl;

    cout << "**********************************" << endl;
    cout << "**********************************" << endl;
    cout << "********* Billing Details ********" << endl;
    cout << "**********************************" << endl;
    cout << "   Medicine Cost: $" << bill.getMedicine() << fixed << setprecision(0) << endl;
    cout << "   Doctor Fee\t: $" << bill.doctorFee() << fixed << setprecision(0) << endl;
    cout << "   Room Charges\t: $" << bill.roomCharges() << fixed << setprecision(0) << endl; 
    cout << "   Total pay\t: $" << bill.getMedicine() + bill.doctorFee() + bill.roomCharges() << fixed << setprecision(0) << endl;
    cout << "**********************************" << endl;
    cout << "**********************************" << endl;

    return 0;
}
