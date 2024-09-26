#include <iostream>
#include "process.h"
#include "input.h"


void menu() {
    using namespace std;
    while(true) {
        cout << "Press:" << endl << "  1 to turn .json string into struct" << endl
             << "  2 to turn struct into .json string" << endl
             << "  0 to exit" << endl;
        unsigned int choise = input::getUnsgnInt();

        switch (choise) {
            case 0: {
                return;
            }
            case 1: {
                cout << "Enter the string" << endl;
                string input = input::inputString();
                Part p = process::stringToStruct(input);
                cout << "struct:" << endl << "id: " << p.id << endl << "name: " << p.name << endl << "count: "
                     << p.count << endl;

                break;
            }
            case 2: {
                Part p;
                try {
                    cout << "Enter the struct" << endl;
                    p = input::inputStruct();
                } catch(std::runtime_error &e) {
                    throw e;
                }
                string output = process::structToString(p);
                cout << output << endl;

                break;
            }
            default: {
                cout << "Try again" << endl;

                break;
            }
        }
    }
}


int main() {
    try {
        menu();
    } catch(std::runtime_error &e) {
        std::cerr << e.what();
    }
    return 0;
}
