#include <iostream>
#include <string>

using namespace std;

class Car {
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;

    public:
        Car(string b, string m) {
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
        }

        // Common methods for all cars
        void startEngine() {
            isEngineOn = true;
            cout << brand << " " << model << " : Engine started." << endl;
        }

        void stopEngine() {
            isEngineOn = false;
            currentSpeed = 0;
            cout << brand << " " << model << " : Engine turned off." << endl;
        }

        void accelerate() {
            if(!isEngineOn) {
                cout << brand << " " << model << " : Engine turned off, can't accelerate"<<endl;
                return;
            }
            currentSpeed += 20;
            cout << brand << " " <<model<< " : Current Speed after acceleration is "<<currentSpeed<<" km/hr"<<endl;
        }

        void brake() {
            currentSpeed -= 20;
            if(currentSpeed<0) currentSpeed = 0;
            cout << brand << " " <<model<<" : Current Speed after applying brake is "<<currentSpeed<<" km/hr" <<endl;
        }

        virtual ~Car() {

        }
};

class ManualCar : public Car {
    private:
        int currentGear;

    public:
        ManualCar(string b, string m) : Car(b,m) {
            currentGear = 0;
        }

        void shiftGear(int gear) {
            currentGear = gear;
            cout<<brand<<" "<<model<<" : Current Gear shifted to "<<currentGear<<endl;
        }
};

class ElectricCar : public Car {
    private:
        int batteryLevel;

    public:
        ElectricCar(string b,string m) : Car(b,m) {
            batteryLevel=100;
        }

        void chargeBattery() {
            batteryLevel = 100;
            cout<<brand<<" "<<model<<" : Battery fully charged!"<<endl;
        }
};




int main() {
    ManualCar* myManualCar = new ManualCar("Maruti Suzuki","WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout<<"------------------------------------------------"<<endl;

    ElectricCar* myElectricCar = new ElectricCar("Tesla","Model S");
    myElectricCar->chargeBattery();
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;

    return 0;
}