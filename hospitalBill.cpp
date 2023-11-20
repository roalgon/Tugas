#include <iostream>
#include <string>
#include <iomanip>
#include <D:\Coding\header\hospital.h>
using namespace std;

class personType {
public:
    personType(string newName = "") {
        name = newName;
    }

    string getName() {
        return name;
    }

private:
    string name;
};

class dateType {
public :
    dateType(int newDay = 1, int newMonth = 1, int newYear = 2000) {
        day = newDay;
        month = newMonth;
        year = newYear;
    }

    void printDate() {
        cout << day << "-" << month << "-" << year;
    }

private :
    int day, month, year;
};

class doctorType : public personType {
public :
    doctorType(string newName = "", string newSpeciality = "") : personType(newName) {
        speciality = newSpeciality;
    }

    string getSpeciality() {
        return speciality;
    }

private :
    string speciality;
};

class billType {
public :
    billType(int newPatientID = 0, float newMedicine = 0) {
        patientID = newPatientID;
        medicine = newMedicine;
    }

    int getPatientID() {
        return patientID;
    }

    float getMedicine() {
        return medicine;
    }

    int roomCharges() {
        return 50;
    }

    int doctorFee() {
        return 100;
    }

private :
    int patientID;
    double medicine;
};

class patientType : public personType {
public :
    patientType(string newName = "", int newPatientID = 0, int newAge = 0, dateType newDateOfBirth = dateType(), doctorType newDoctor = doctorType()) 
    : personType(newName) {
        patientID = newPatientID;
        age = newAge;
        dateOfBirth = newDateOfBirth;
        doctor = newDoctor;
    }

    int getPatientID() {
        return patientID;
    }

    int getAge() {
        return age;
    }

    dateType getBirth() {
        return dateOfBirth;
    }

    doctorType getDoctor() {
        return doctor;
    }
    
private :
    int patientID, age;
    dateType dateOfBirth;
    doctorType doctor;
};

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
