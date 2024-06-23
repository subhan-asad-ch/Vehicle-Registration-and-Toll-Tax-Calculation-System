#include <iostream>
#include <fstream>
using namespace std;

void save_data(string detail[10][5], int balance[10][1], int number_of_cars_registered) {
    ofstream outFile("vehicle_data.txt");
    outFile << number_of_cars_registered << endl;
    for (int i = 0; i < number_of_cars_registered; i++) {
        for (int j = 0; j < 5; j++) {
            outFile << detail[i][j] << endl;
        }
        outFile << balance[i][0] << endl;
    }
    outFile.close();
}

void load_data(string detail[10][5], int balance[10][1], int &number_of_cars_registered) {
    ifstream inFile("vehicle_data.txt");
    if (inFile.is_open()) {
        inFile >> number_of_cars_registered;
        for (int i = 0; i < number_of_cars_registered; i++) {
            for (int j = 0; j < 5; j++) {
                inFile >> detail[i][j];
            }
            inFile >> balance[i][0];
        }
        inFile.close();
    } else {
        number_of_cars_registered = 0;
    }
}

void registration(string detail[10][5], int balance[10][1], int row) {
    cout << "Enter the details of the new vehicle:" << endl;
    cout << "Enter your CNIC no. in the format xxxxx-xxxxxxx-x: ";
    cin >> detail[row][0];
    cout << "Enter your vehicle type (Car, Truck, etc.): ";
    cin >> detail[row][1];
    cout << "Enter your vehicle no. in the format xxx-xxxx: ";
    cin >> detail[row][2];
    cout << "Enter your phone no. in the format xxxx-xxxxxxx: ";
    cin >> detail[row][3];
    balance[row][0] = 0;
    cout << endl;
    cout << "CNIC NO.       : " << detail[row][0] << endl;
    cout << "Vehicle Type   : " << detail[row][1] << endl;
    cout << "Vehicle No.    : " << detail[row][2] << endl;
    cout << "Phone No.      : " << detail[row][3] << endl;
    cout << "Balance        : " << balance[row][0] << endl;
}

void balance_recharge(string detail[10][5], int balance[10][1], string vehicle_num) {
    int serial_num = -1;
    int current_balance, recharge;
    for (int index = 0; index < 10; index++) {
        if (vehicle_num == detail[index][2]) {
            serial_num = index;
            break;
        }
    }
    if (serial_num != -1) {
        cout << "Enter the amount you want to recharge: ";
        cin >> recharge;
        current_balance = balance[serial_num][0];
        current_balance += recharge;
        balance[serial_num][0] = current_balance;
        cout << endl;
        cout << "CNIC NO.       : " << detail[serial_num][0] << endl;
        cout << "Vehicle Type   : " << detail[serial_num][1] << endl;
        cout << "Vehicle No.    : " << detail[serial_num][2] << endl;
        cout << "Phone No.      : " << detail[serial_num][3] << endl;
        cout << "Balance        : " << balance[serial_num][0] << endl;
    } else {
        cout << "Vehicle not registered." << endl;
    }
}

void match_vehicle(string detail[10][5], int balance[10][1], string vehicle_num) {
    int vehicle_matched = 0;
    for (int index = 0; index < 10; index++) {
        if (vehicle_num == detail[index][2]) {
            vehicle_matched = 1;
            cout << "CNIC NO.       : " << detail[index][0] << endl;
            cout << "Vehicle Type   : " << detail[index][1] << endl;
            cout << "Vehicle No.    : " << detail[index][2] << endl;
            cout << "Phone No.      : " << detail[index][3] << endl;
            cout << "Balance        : " << balance[index][0] << endl;
            break;
        }
    }
    if (vehicle_matched == 1) {
        cout << "Vehicle verified." << endl;
    } else {
        cout << "Vehicle not found." << endl;
    }
}

void toll_tax(string detail[10][5], int balance[10][1], int tax_chart[14][14]) {
    int i, j, z = -1, tax, vehicle_matched = 0, current_balance;
    string vehicle_num;
    cout << "Enter your vehicle no.: ";
    cin >> vehicle_num;
    for (int index = 0; index < 10; index++) {
        if (vehicle_num == detail[index][2]) {
            z = index;
            vehicle_matched = 1;
            break;
        }
    }
    if (vehicle_matched == 1) {
        cout << "Enter the toll plaza number from where you entered:" << endl;
        cout << "1- Islamabad" << endl;
        cout << "2- Fateh Jhang" << endl;
        cout << "3- AWT Sangjani" << endl;
        cout << "4- Brahma Bahatar" << endl;
        cout << "5- Burhan" << endl;
        cout << "6- Hazara/Segregation toll plaza" << endl;
        cout << "7- Ghazi" << endl;
        cout << "8- Chach" << endl;
        cout << "9- Swabi" << endl;
        cout << "10- Kernal Sherkhan" << endl;
        cout << "11- Wali interchange" << endl;
        cout << "12- Rashaki" << endl;
        cout << "13- Charsada" << endl;
        cout << "14- Peshawar" << endl;
        cin >> i;

        cout << "Enter the toll plaza number from where you exit:" << endl;
        cout << "1- Islamabad" << endl;
        cout << "2- Fateh Jhang" << endl;
        cout << "3- AWT Sangjani" << endl;
        cout << "4- Brahma Bahatar" << endl;
        cout << "5- Burhan" << endl;
        cout << "6- Hazara/Segregation toll plaza" << endl;
        cout << "7- Ghazi" << endl;
        cout << "8- Chach" << endl;
        cout << "9- Swabi" << endl;
        cout << "10- Kernal Sherkhan" << endl;
        cout << "11- Wali interchange" << endl;
        cout << "12- Rashaki" << endl;
        cout << "13- Charsada" << endl;
        cout << "14- Peshawar" << endl;
        cin >> j;
        tax = tax_chart[i - 1][j - 1];
        cout << "The toll tax of your journey is: " << tax << endl;
        current_balance = balance[z][0];
        current_balance -= tax;
        balance[z][0] = current_balance;
        cout << "CNIC NO.       : " << detail[z][0] << endl;
        cout << "Vehicle Type   : " << detail[z][1] << endl;
        cout << "Vehicle No.    : " << detail[z][2] << endl;
        cout << "Phone No.      : " << detail[z][3] << endl;
        cout << "Balance        : " << balance[z][0] << endl;
    } else {
        cout << "Vehicle not registered." << endl;
    }
}

int main() {
    int task;
    string Detail[10][5]; 
    int Balance[10][1];
    int number_of_cars_registered = 0;

    load_data(Detail, Balance, number_of_cars_registered);

    int Tax_chart[14][14];
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            if (i == j) {
                Tax_chart[i][j] = 0;
            } else if (i < j) {
                Tax_chart[i][j] = 30 + (j - i) * 10;
            } else {
                Tax_chart[i][j] = 30 + (i - j) * 10;
            }
        }
    }

    while (true) {
        cout << "Enter the task you want to perform." << endl;
        cout << "1. Register your vehicle" << endl;
        cout << "2. Balance Recharge" << endl;
        cout << "3. Match Vehicle" << endl;
        cout << "4. Toll Tax Calculation" << endl;
        cin >> task;
        if (task == 1) {
            registration(Detail, Balance, number_of_cars_registered);
            number_of_cars_registered++;
            save_data(Detail, Balance, number_of_cars_registered);
        } else if (task == 2) {
            string vehicle_num;
            cout << "Enter your vehicle no.: ";
            cin >> vehicle_num;
            balance_recharge(Detail, Balance, vehicle_num);
            save_data(Detail, Balance, number_of_cars_registered);
        } else if (task == 3) {
            string vehicle_num;
            cout << "Enter your vehicle no.: ";
            cin >> vehicle_num;
            match_vehicle(Detail, Balance, vehicle_num);
        } else if (task == 4) {
            toll_tax(Detail, Balance, Tax_chart);
            save_data(Detail, Balance, number_of_cars_registered);
        }
    }
    return 0;
}
