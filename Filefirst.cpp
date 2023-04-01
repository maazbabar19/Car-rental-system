#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    string model;
    int year;
    bool available;
};

int main() {
    Car cars[5];
    cars[0].model = "Toyota Camry";
    cars[0].year = 2020;
    cars[0].available = true;

    cars[1].model = "Honda Civic";
    cars[1].year = 2018;
    cars[1].available = true;

    cars[2].model = "Ford Mustang";
    cars[2].year = 2022;
    cars[2].available = true;

    cars[3].model = "Chevrolet Tahoe";
    cars[3].year = 2021;
    cars[3].available = true;

    cars[4].model = "Jeep Wrangler";
    cars[4].year = 2019;
    cars[4].available = true;

    int choice;
    do {
        cout << "Enter 1 to rent a car" << endl;
        cout << "Enter 2 to return a car" << endl;
        cout << "Enter 3 to exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            int model_choice;
            do {
                cout << "Select a car model to rent:" << endl;
                for (int i = 0; i < 5; i++) {
                    if (cars[i].available) {
                        cout << i+1 << ". " << cars[i].model << " (" << cars[i].year << ")" << endl;
                    }
                }
                cin >> model_choice;
            } while (model_choice < 1 || model_choice > 5 || !cars[model_choice-1].available);

            cars[model_choice-1].available = false;
            cout << "You rented a " << cars[model_choice-1].model << " (" << cars[model_choice-1].year << ")" << endl;
            break;
        case 2:
            int return_choice;
            do {
                cout << "Select a car model to return:" << endl;
                for (int i = 0; i < 5; i++) {
                    if (!cars[i].available) {
                        cout << i+1 << ". " << cars[i].model << " (" << cars[i].year << ")" << endl;
                    }
                }
                cin >> return_choice;
            } while (return_choice < 1 || return_choice > 5 || cars[return_choice-1].available);

            cars[return_choice-1].available = true;
            cout << "You returned a " << cars[return_choice-1].model << " (" << cars[return_choice-1].year << ")" << endl;
            break;
        case 3:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 3);

    return 0;
}

