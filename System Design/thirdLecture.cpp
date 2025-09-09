// INHERITANCE


// #include <iostream>
// #include <string>

// using namespace std;

// class Car {
//     protected:
//         string brand;
//         string model;
//         bool isEngineOn;
//         int currentSpeed;

//     public:
//         Car(string b, string m) {
//             this->brand = b;
//             this->model = m;
//             isEngineOn = false;
//             currentSpeed = 0;
//         }

//         // Common methods for all cars
//         void startEngine() {
//             isEngineOn = true;
//             cout << brand << " " << model << " : Engine started." << endl;
//         }

//         void stopEngine() {
//             isEngineOn = false;
//             currentSpeed = 0;
//             cout << brand << " " << model << " : Engine turned off." << endl;
//         }

//         void accelerate() {
//             if(!isEngineOn) {
//                 cout << brand << " " << model << " : Engine turned off, can't accelerate"<<endl;
//                 return;
//             }
//             currentSpeed += 20;
//             cout << brand << " " <<model<< " : Current Speed after acceleration is "<<currentSpeed<<" km/hr"<<endl;
//         }

//         void brake() {
//             currentSpeed -= 20;
//             if(currentSpeed<0) currentSpeed = 0;
//             cout << brand << " " <<model<<" : Current Speed after applying brake is "<<currentSpeed<<" km/hr" <<endl;
//         }

//         virtual ~Car() {

//         }
// };

// class ManualCar : public Car {
//     private:
//         int currentGear;

//     public:
//         ManualCar(string b, string m) : Car(b,m) {
//             currentGear = 0;
//         }

//         void shiftGear(int gear) {
//             currentGear = gear;
//             cout<<brand<<" "<<model<<" : Current Gear shifted to "<<currentGear<<endl;
//         }
// };

// class ElectricCar : public Car {
//     private:
//         int batteryLevel;

//     public:
//         ElectricCar(string b,string m) : Car(b,m) {
//             batteryLevel=100;
//         }

//         void chargeBattery() {
//             batteryLevel = 100;
//             cout<<brand<<" "<<model<<" : Battery fully charged!"<<endl;
//         }
// };




// int main() {
//     ManualCar* myManualCar = new ManualCar("Maruti Suzuki","WagonR");
//     myManualCar->startEngine();
//     myManualCar->shiftGear(1);
//     myManualCar->accelerate();
//     myManualCar->brake();
//     myManualCar->stopEngine();
//     delete myManualCar;

//     cout<<"------------------------------------------------"<<endl;

//     ElectricCar* myElectricCar = new ElectricCar("Tesla","Model S");
//     myElectricCar->chargeBattery();
//     myElectricCar->startEngine();
//     myElectricCar->accelerate();
//     myElectricCar->brake();
//     myElectricCar->stopEngine();
//     delete myElectricCar;

//     return 0;
// }



// // POLYMORPHISM
// // DYNAMIC POLYMORPHISM

// #include <iostream>
// #include <string>

// using namespace std;

// class Car {
//     protected:
//         string brand;
//         string model;
//         bool isEngineOn;
//         int currentSpeed;

//     public:
//         Car(string b, string m) {
//             this->brand = b;
//             this->model = m;
//             isEngineOn = false;
//             currentSpeed = 0;
//         }

//         // Common methods for all cars
//         void startEngine() {
//             isEngineOn = true;
//             cout << brand << " " << model << " : Engine started." << endl;
//         }

//         void stopEngine() {
//             isEngineOn = false;
//             currentSpeed = 0;
//             cout << brand << " " << model << " : Engine turned off." << endl;
//         }

//         virtual void accelerate() = 0;          // Abstract Method for Dynamic Polymorphism
//         virtual void brake() = 0;               // Abstract Method for Dynamic Polymorphism
//         virtual ~Car() {}               // Virtual destructor
// };

// class ManualCar : public Car {
//     private:
//         int currentGear;

//     public:
//         ManualCar(string b, string m) : Car(b,m) {
//             currentGear = 0;
//         }

//         void shiftGear(int gear) {
//             currentGear = gear;
//             cout<<brand<<" "<<model<<" : Current Gear shifted to "<<currentGear<<endl;
//         }

//         // Overriding accelerate (Dynamic Polymorphism)
//         void accelerate() {
//             if(!isEngineOn) {
//                 cout << brand << " " << model << " : Engine turned off, can't accelerate"<<endl;
//                 return;
//             }
//             currentSpeed += 20;
//             cout << brand << " " <<model<< " : Current Speed after acceleration is "<<currentSpeed<<" km/hr"<<endl;
//         }

//         // Overriding brake (Dynamic Polymorphism)
//         void brake() {
//             currentSpeed -= 20;
//             if(currentSpeed<0) currentSpeed = 0;
//             cout << brand << " " <<model<<" : Current Speed after applying brake is "<<currentSpeed<<" km/hr" <<endl;
//         }
// };

// class ElectricCar : public Car {
//     private:
//         int batteryLevel;

//     public:
//         ElectricCar(string b,string m) : Car(b,m) {
//             batteryLevel=100;
//         }

//         void chargeBattery() {
//             batteryLevel = 100;
//             cout<<brand<<" "<<model<<" : Battery fully charged!"<<endl;
//         }

//         // Overriding accelerate (Dynamic Polymorphism)
//         void accelerate() {
//             if(!isEngineOn) {
//                 cout << brand << " " << model << " : Engine turned off, can't accelerate"<<endl;
//                 return;
//             }

//             if(batteryLevel<=0){
//                 cout << brand << " " << model << " : Battery dead, can't accelerate"<<endl;
//                 return;
//             }
//             batteryLevel-=10;
//             currentSpeed += 15;
//             cout << brand << " " <<model<< " : Current Speed after acceleration is "<<currentSpeed<<" km/hr. Battery at : "<<batteryLevel<<"%"<<endl;
//         }

//         // Overriding brake (Dynamic Polymorphism)
//         void brake() {
//             currentSpeed -= 15;
//             if(currentSpeed<0) currentSpeed = 0;
//             cout << brand << " " <<model<<" : Current Speed after applying brake is "<<currentSpeed<<" km/hr" <<endl;
//         }
// };




// int main() {
//     ManualCar* myManualCar = new ManualCar("Maruti Suzuki","WagonR");
//     myManualCar->startEngine();
//     myManualCar->shiftGear(1);
//     myManualCar->accelerate();
//     myManualCar->brake();
//     myManualCar->stopEngine();
//     delete myManualCar;

//     cout<<"------------------------------------------------"<<endl;

//     ElectricCar* myElectricCar = new ElectricCar("Tesla","Model S");
//     myElectricCar->chargeBattery();
//     myElectricCar->startEngine();
//     myElectricCar->accelerate();
//     myElectricCar->brake();
//     myElectricCar->stopEngine();
//     delete myElectricCar;

//     return 0;
// }



// STATIC POLYMORPHISM
#include <iostream>
#include <string>

using namespace std;

class ManualCar {
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

    public:
        ManualCar(string brand,string model) {
            this->brand = brand;
            this->model = model;
            this->isEngineOn=false;
            this->currentGear=0;
            this->currentSpeed=0;
        }

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
                cout << brand << " " << model << " : Can't Accelerate, Engine off." << endl;
                return;
            }
            currentSpeed+=20;
            cout << brand << " " << model << " : Accelerating to : "<<currentSpeed<<" km/hr" << endl;
        }

        void accelerate(int speed) {
            if(!isEngineOn) {
                cout << brand << " " << model << " : Can't Accelerate, Engine off." << endl;
                return;
            }
            currentSpeed+=speed;
            cout << brand << " " << model << " : Accelerating to : "<<currentSpeed<<" km/hr" << endl;
        }

        void brake() {
            currentSpeed -= 20;
            if(currentSpeed<0) currentSpeed = 0;
            cout << brand << " " <<model<<" : Current Speed after applying brake is "<<currentSpeed<<" km/hr" <<endl;
        }


        void shiftGear(int gear) {
            currentGear = gear;
            cout << brand << " " <<model<<" : Shifted to gear "<<currentGear<<endl;
        }
};

int main() {
    ManualCar* myManualCar = new ManualCar("Maruti Suzuki","WagonR");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate(40);
    myManualCar->brake();
    myManualCar->stopEngine();

    // CleanUp
    delete myManualCar;

    return 0;
}