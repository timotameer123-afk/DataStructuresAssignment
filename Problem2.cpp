#include <iostream>
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
public:
    vector<Patient> patients;

    void insertPatients(const Patient& patient) {
        this->patients.push_back(patient);
        BuildHeap();
    }

    void Heapify(const int n, const int i) {
        int largest = i;

        const int left = 2 * i + 1;
        const int right = 2 * i + 2;

        if (
            left < n &&
            patients[left].severity > patients[largest].severity
            ) {
            largest = left;
        }
        if (
            right < n &&
            patients[right].severity > patients[largest].severity
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

    void EmergencyOrder() const {
        for (const Patient& patient : patients) {
            cout << patient << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    HeapSort heapSort;
    for (int i = 0; i < n; i++) {
        Patient patient;
        cin >> patient.id;
        cin >> patient.name;
        cin >> patient.severity;
        heapSort.insertPatients(patient);
    }
    heapSort.EmergencyOrder();
    return 0;
}