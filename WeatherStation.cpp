// WeatherStation.cpp : Defines the entry point for the application.
//

#include "WeatherStation.h"
#include <thread>

using namespace std;

void printMenu();

int main()
{
    SensorManager manager;
    char choice = ' ';
    atomic<bool> running(true);

    // Add sensors
    manager.AddSensor("Temp", "Temp Sensor 1", "Ethernet", "Sensor", "192.168.50.28", 2000);
    manager.AddSensor("Wind", "Wind Sensor 1", "Ethernet", "Sensor", "192.168.50.28", 2001);
    manager.AddSensor("Humidity", "Humidity Sensor 1", "Ethernet", "Sensor", "192.168.50.28", 2002);
    manager.AddSensor("Barometric", "Barometric Sensor 1", "Ethernet", "Sensor", "192.168.50.28", 2003);
    manager.AddSensor("Rain", "Rain Sensor 1", "Ethernet", "Sensor", "192.168.50.28", 2004);

    while (running) {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 'a':
        case 'A': {
            string type, name, connType, dataType, ipAddress;
            int port;
            cout << "Enter Sensor Type: ";
            cin >> type;
            cout << "Enter Sensor Name: ";
            cin >> name;
            cout << "Enter Connection Type: ";
            cin >> connType;
            cout << "Enter Data Type: ";
            cin >> dataType;
            cout << "Enter IP Address: ";
            cin >> ipAddress;
            cout << "Enter Port: ";
            cin >> port;
            manager.AddSensor(type, name, connType, dataType, ipAddress, port);
            break;
        }
        case 'd':
        case 'D': {
            string name;
            cout << "Enter Sensor Name: ";
            cin >> name;
            manager.DelSensor(name);
            break;
        }
        case 'i':
        case 'I': {
            manager.SetUnit(false);
            cout << "Units set to Imperial" << endl;
            break;
        }
        case 'p':
        case 'P': {
            manager.PrintSensors();
            break;
        }
        case 's':
        case 'S': {
            manager.StartCollection();
            break;
        }
        case 'm':
        case 'M': {
            manager.SetUnit(true);
            cout << "Units set to Metric" << endl;
            break;
        }
        case 'o':
        case 'O': {
            manager.StopCollection();
            break;
        }
        case 'q':
        case 'Q': {
            manager.StopCollection();
            running = false;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}

// Print the application menu
void printMenu() {
	cout << "Weather Station Menu" << endl;
	cout << "A: Add Sensor" << endl;
	cout << "D: Delete Sensor" << endl;
	cout << "I: Change Units to US" << endl;
	cout << "O: Stop Collection" << endl;
	cout << "P: Print Sensors" << endl;
	cout << "S: Start Collection" << endl;
	cout << "Q: Quit" << endl;
	cout << "M: Change Units to Metric" << endl;
	cout << "Enter choice: ";
}