#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

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

class HeapSort {
private:
    int id = 1;
public:
    vector<Patient> patients;

    bool hasHigherPriority(const Patient& a, const Patient& b) const {
        if (a.severity != b.severity) {
            return a.severity > b.severity; // Higher severity comes first
        }
        if (a.arrivalTime != b.arrivalTime) {
            return a.arrivalTime < b.arrivalTime; // If severity is equal, earlier arrival time comes first
        }
        return a.id < b.id; // If both are equal, smaller ID comes first
    }

    void insertPatients(Patient& patient) {
        patient.id = id++;
        this->patients.push_back(patient);
        BuildHeap();
    }

    void Heapify(const int n, const int i) {
        int largest = i;

        const int left = 2 * i + 1;
        const int right = 2 * i + 2;

        if (
            left < n &&
            hasHigherPriority(patients[left], patients[largest])
            ) {
            largest = left;
        }
        if (
            right < n &&
            hasHigherPriority(patients[right], patients[largest])
            ) {
            largest = right;
        }
        if (largest != i) {
            swap(patients[i], patients[largest]);
            Heapify(n,largest);
        }
    }

    void BuildHeap() {
        const int size = static_cast<int>(patients.size());
        for (int i = size / 2 - 1; i >= 0; i--) {
            Heapify(size, i);
        }
    }

    void sortTheHeap() {
        const int size = static_cast<int>(patients.size());
        for (int i = size - 1; i >= 0; i--) {
            swap(patients[0], patients[i]);
            Heapify(i, 0);
        }
    }

    void ViewNextPatient() {
        if (patients.empty()) {
            cout << "No patients currently in the emergency room." << endl;
            return;
        }
        cout << "Next patient to be treated -> " << patients[0] << endl;
    }

    void updateSeverity(const int ID, const int severity) {
        bool foundPatient = false;
        for (Patient& patient : patients) {
            if (patient.id == ID) {
                foundPatient = true;
                patient.severity = severity;
            }
        }
        if (!foundPatient) {
            if (this->id > ID) {
                cout << "The patient with id: " << ID << " was probably treated.\n";
            }else {
                cout << "The patient with id: " << ID << " doesn't exist.\n";
            }
        } else {
            BuildHeap(); // Restore the heap structure after modifying a patient's severity
        }
    }

    void EmergencyOrder() {
        sortTheHeap();
        const int size = static_cast<int>(patients.size() - 1);
        for (int i = size; i >= 0; i--) {
            cout << patients[i] << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    HeapSort heapSort;
    for (int i = 0; i < n; i++) {
        Patient patient;
        cout << "Enter patient #" << (i + 1) << " information:" << endl;
        cout << "Name: ";
        cin >> patient.name;
        cout << "Severity (1-10): ";
        cin >> patient.severity;
        cout << "Arrival Time: ";
        cin >> patient.arrivalTime;
        heapSort.insertPatients(patient);
    }
    heapSort.ViewNextPatient();
    heapSort.updateSeverity(4, 10);
    heapSort.EmergencyOrder();
    return 0;
}