// ABSTRACTION

// #include <iostream>
// #include <string>

// using namespace std;

// class Car {
//     public:
//         virtual void startEngine() = 0;         //Virtual here means we are just declaring it, not defining it. The responsibility of defining it will be of it's child class, whoever will extend or inherit it.
//         virtual void shiftGear(int gear) = 0;
//         virtual void accelerate() = 0;
//         virtual void brake() = 0;
//         virtual void stopEngine() = 0;
//         virtual ~Car() {}
// };

// class SportsCar : public Car {
//     public:
//         string brand;
//         string model;
//         bool isEngineOn;
//         int currentSpeed;
//         int currentGear;

//         SportsCar(string b,string m) {
//             this->brand = b;
//             this->model = m;
//             isEngineOn = false;
//             currentSpeed = 0;
//             currentGear = 0;
//         }

//         void startEngine() {
//             isEngineOn = true;
//             cout<<brand<<" "<<model<<" : Engine starts with a roar"<<endl;
//         }

//         void shiftGear(int gear) {
//             if(!isEngineOn) {
//                 cout<<brand<<" "<<model<<" : Engine is off! Cannot shift gear."<<endl;
//                 return;
//             }
//             currentGear = gear;
//             cout << brand << " " << model << " : Shifted to gear"<<currentGear<<endl;
//         }


//         void accelerate() {
//             if(!isEngineOn) {
//                 cout<<brand<<" "<<model<<" : Engine is off! Cannot accelerate."<<endl;
//                 return;
//             }
//             currentSpeed += 20;
//             cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" km/h"<<endl;
//         }

//         void brake() {
//             currentSpeed -= 20;
//             if(currentSpeed < 0) currentSpeed = 0;
//             cout <<brand<<" "<<model<<" : Braking! Speed is now "<<currentSpeed<<" km/h"<<endl;
//         }

//         void stopEngine() {
//             isEngineOn = false;
//             currentGear = 0;
//             currentSpeed = 0;
//             cout<<brand<<" "<<model<< " : Engine turned off."<<endl;
//         }
// };

// int main() {
//     Car* myCar = new SportsCar("Ford","Mustang");

//     myCar->shiftGear(1);
//     myCar->startEngine();
//     myCar->shiftGear(1);
//     myCar->accelerate();
//     myCar->shiftGear(2);
//     myCar->accelerate();
//     myCar->brake();
//     myCar->stopEngine();

//     return -1;
// }


// ENCAPSULATION

#include <iostream>
#include <string>

using namespace std;


class SportsCar{
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
        string tyre;


    public:
        SportsCar(string b,string m) {
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
            tyre = "MRF";
        }

        // Getters and setters
        int getCurrentSpeed() {
            return this->currentSpeed;
        }

        string getTyre() {
            return this->tyre;
        }

        void setTyre(string tyre) {
            this->tyre = tyre;
        }

        void startEngine() {
            isEngineOn = true;
            cout<<brand<<" "<<model<<" : Engine starts with a roar"<<endl;
        }

        void shiftGear(int gear) {
            if(!isEngineOn) {
                cout<<brand<<" "<<model<<" : Engine is off! Cannot shift gear."<<endl;
                return;
            }
            currentGear = gear;
            cout << brand << " " << model << " : Shifted to gear"<<currentGear<<endl;
        }


        void accelerate() {
            if(!isEngineOn) {
                cout<<brand<<" "<<model<<" : Engine is off! Cannot accelerate."<<endl;
                return;
            }
            currentSpeed += 20;
            cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" km/h"<<endl;
        }

        void brake() {
            currentSpeed -= 20;
            if(currentSpeed < 0) currentSpeed = 0;
            cout <<brand<<" "<<model<<" : Braking! Speed is now "<<currentSpeed<<" km/h"<<endl;
        }

        void stopEngine() {
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            cout<<brand<<" "<<model<< " : Engine turned off."<<endl;
        }
};

int main() {
    SportsCar* mySportsCar = new SportsCar("Ford","Mustang");

    mySportsCar->shiftGear(1);
    mySportsCar->startEngine();
    mySportsCar->shiftGear(1);
    mySportsCar->accelerate();
    mySportsCar->shiftGear(2);
    mySportsCar->accelerate();
    mySportsCar->brake();
    mySportsCar->stopEngine();

    // Setting arbitrary value to speed
    // mySportsCar->currentSpeed=500;

    cout<<"Current Speed of my sports car is set to "<<mySportsCar->getCurrentSpeed()<<" km/hr"<<endl;

    cout<<"Tyre Company : "<<mySportsCar->getTyre()<<endl;
    mySportsCar->setTyre("Apollo");
    cout<<"Tyre Company : "<<mySportsCar->getTyre()<<endl;

    delete mySportsCar;

    return 0;
}