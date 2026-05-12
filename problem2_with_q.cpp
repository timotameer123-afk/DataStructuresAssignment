#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/* Priority Queue Based Emergency Room System
   
1. Severity 
2. Arrival Time
3. ID (lower is priority)
*/

struct Patient {
    int id;
    string name;
    int severity;
    int arrivalTime;

    friend ostream& operator<<(ostream& out, const Patient& patient) {
        out << "ID: " << patient.id
            << " | Name: " << patient.name
            << " | Severity: " << patient.severity
            << " | Arrival Time: " << patient.arrivalTime;
        return out;
    }
};

struct PatientComparator {
    bool operator()(const Patient& a, const Patient& b) const {
        if (a.severity != b.severity) {
            return a.severity < b.severity;  
        }
        if (a.arrivalTime != b.arrivalTime) {
            return a.arrivalTime > b.arrivalTime;   
        }
        return a.id > b.id;  
    }
};

class EmergencyRoom {
private:
    int nextId = 1;
    vector<Patient> patients;  
    priority_queue<Patient, vector<Patient>, PatientComparator> pq;  

public:
  
    void rebuildPriorityQueue() {
        while (!pq.empty()) {
            pq.pop();
        }
        for (const auto& p : patients) {
            pq.push(p);
        }
    }
    Patient& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(patients.size())) {
            throw out_of_range("Invalid patient index!");
        }
        return patients[index];
    }

    const Patient& operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(patients.size())) {
            throw out_of_range("Invalid patient index!");
        }
        return patients[index];
    }

    
    void addPatient(Patient patient) {
        patient.id = nextId++;
        patients.push_back(patient);
        pq.push(patient);
    }

    
    void updateSeverity(int patientId, int newSeverity) {
        for (auto& p : patients) {
            if (p.id == patientId) {
                p.severity = newSeverity;
                break;
            }
        }
        rebuildPriorityQueue();
    }


    void updateByIndex(int index, int newSeverity) {
        (*this)[index].severity = newSeverity;
        rebuildPriorityQueue();
    }

    
    void viewNextPatient() const {
        if (pq.empty()) {
            cout << "No patients currently in the emergency room." << endl;
            return;
        }
        cout << "Next patient to be treated -> " << pq.top() << endl;
    }

    
    void displayAllInOrder() const {
        auto tempQ = pq;
        cout << "\n=== Emergency Treatment Order ===" << endl;
        while (!tempQ.empty()) {
            cout << tempQ.top() << endl;
            tempQ.pop();
        }
    }


    int getSize() const {
        return static_cast<int>(patients.size());
    }
};

int main() {
    int n;
    cin >> n;
    EmergencyRoom room;

    for (int i = 0; i < n; i++) {
        Patient patient;
        cout << "Enter patient #" << (i + 1) << " information:" << endl;
        cout << "Name: ";
        cin >> patient.name;
        cout << "Severity (1-10): ";
        cin >> patient.severity;
        cout << "Arrival Time: ";
        cin >> patient.arrivalTime;
        room.addPatient(patient);
    }

    
    cout << "\n--- First patient (index 0): " << room[0] << endl;
    
    
    cout << "Updating severity of patient at index 0..." << endl;
    room[0].severity = 10;
    room.rebuildPriorityQueue();

    cout << "\nNext patient after update: ";
    room.viewNextPatient();

    room.updateSeverity(4, 8);
    
    room.displayAllInOrder();
    
    return 0;
}