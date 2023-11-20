#include <iostream>
#include <string>
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
