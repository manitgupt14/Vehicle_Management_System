#include<bits/stdc++.h>
using namespace std;
// Vehicle Class
class Vehicle{
// protected data members and protected methods
  protected:
  string vehicleID;
  void setVehicleID(string vehicleID)
    {
      this->vehicleID=vehicleID;
    }
  string getVehicleID()
    {
      return this->vehicleID;
    }
  public: // access Modifiers
  /* Data Members of Vehicle Class start  */
  string fueltype; // FuelType of Vehicle
  bool isUsed=false; // It ensures whether the Vehicle is new or used.
  bool isMadeInIndia=false; // It ensures whether it is Made In India or not.
  /* Virtual function which is used to override in the child class */
  
  virtual void display(){
     
  };
};
// Car Class which inherit the Vehicle class with public access Modifiers
class Car:public Vehicle{
  public:
  // Data Members
  string carName; // It stores Name of Car
  Car()
  {
      // Constructor with no arguments
  }
  // OVERLOADED Constructor 
  Car(string carName,bool isUsed,bool isMadeInIndia,string fueltype)
  {
      // this is used to point the variable of class which hidden by local variable
      // initialising the values to  data Members
      this->carName=carName;
      this->isUsed=isUsed;
      this->isMadeInIndia=isMadeInIndia;
      this->fueltype=fueltype;
  }
  //  setter and getter methods to set and get vehicleID
  void setID(string ID)
  {
      this->setVehicleID(ID);
  }
  string getID()
  {
      return this->getVehicleID();
  }
  // overriden function 
  // Function used to display the Details of CAR
  void display()
  {
    cout<<"Car Details"<<endl;
    cout<<"Car ID:"<<this->getID()<<endl;
    cout<<"Car Name :"<<carName<<endl;
    cout<<"Fueltype :"<<fueltype<<endl;
    if(isUsed)
    cout<<carName<<" is Used. "<<endl;
    else
    cout<<carName<<" is new. "<<endl;
    if(isMadeInIndia)
    cout<<carName<<" is MadeInIndia."<<endl;
    else
    cout<<carName<<" is import Vehicle."<<endl;
  }
};
// Bike Class which inherit the Vehicle class with public access Modifiers
class Bike:public Vehicle{
    public:
    string bikeName;
    Bike()
    {
        // Constructor of Bike Class
    }
    // Overloaded Bike Class
    Bike(string bikeName,bool isUsed,bool isMadeInIndia,string fueltype)
    {
      this->bikeName=bikeName;
      this->isUsed=isUsed;
      this->isMadeInIndia=isMadeInIndia;
      this->fueltype=fueltype;
    }
    //  setter and getter methods to set and get vehicleID
    void setID(string ID)
    {
      this->setVehicleID(ID);
    }
    string getID()
    {
      return this->getVehicleID();
    }
    // Overriden display function 
    // It displays the Details of BIKE
    void display()
    {
    
    cout<<"Bike Details"<<endl; // Display heading
    cout<<"Bike ID:"<<this->getID()<<endl;
    cout<<"Bike Name :"<<bikeName<<endl; // Display Bike Name
    cout<<"Fueltype :"<<fueltype<<endl; // Display fueltype
    // Below statement prints whether the bike is new or used and it is imported or MadeInIndia.
    if(isUsed)
    cout<<bikeName<<" is Used. "<<endl;
    else
    cout<<bikeName<<" is new. "<<endl;
    if(isMadeInIndia)
    cout<<bikeName<<" is MadeInIndia."<<endl;
    else
    cout<<bikeName<<" is import Vehicle."<<endl;
    } 
};
// Person class
class Person{
    // Private members which store PersonID
    private:
    string PersonID;
    public:
    // Public Data Members of Person Class
    string name; // Name of Person
    string gender; // Gender of Person
    int numberOfVehicles; // Takes an integer that determine number of vehicles  that the person have.
    vector<Vehicle *> listOfVehicle; // It stores the Vehicle details in the address.
    // Member functions start
    Person()
    {
        // Constructor of Person Class
    }
    // Overloaded Constructor
    Person(string name,string gender,int numberOfVehicles,vector<Vehicle *> listOfVehicle){
        // initialising values
        this->name=name; 
        this->gender=gender;
        this->numberOfVehicles=numberOfVehicles;
        this->listOfVehicle=listOfVehicle;
    }
    // setter and getter function to store PersonID
    void setPersonID(string PersonID)
    {
        this->PersonID=PersonID;
    }
    string getPersonID()
    {
        return this->PersonID;
    }
    //  display function
    void display()
    {
        cout<<"------------------------Details of Persons------------------------------"<<endl;
        cout<<"Person ID:"<<this->getPersonID()<<endl;
        cout<<"The name of Person: "<<this->name<<endl; // Display Name of Person
        cout<<"Person is male: "<<this->gender<<endl; // Display the Gender of Person
        cout<<"Person has "<<this->numberOfVehicles<<" vehicles"<<endl; // Display the numberOfVehicles that Person have
        cout<<endl;
        cout<<"Following are details of vehicles:"<<endl;
        // This for loop traverse the address present in the list and displays their values.
        for(auto &it:this->listOfVehicle)
        {
            it->display();
            cout<<endl;
        }
    }
};
// MAIN FUNCTION STARTS 
int main()
{
    int noOfPersons; // It takes noOfPersons present in the area
    cin>>noOfPersons; // Takes values of noOfPersons
    for(int count=1;count<=noOfPersons;count++)
    {
    // This loop takes values of the Persons
    
    string name,gender;
    int numberOfVehicles;
    cin>>name>>gender>>numberOfVehicles; // Takes Name,Gender,numberOfVehicles that Person have.
    vector<Vehicle *> listOfVehicle(numberOfVehicles); // This is Dynamic array of Vehicles.
    for(int index=0;index<numberOfVehicles;index++)
    {
        string vehicleType,name,fueltype;
        bool isUsed,isMadeInIndia;
        cin>>vehicleType>>name>>isUsed>>isMadeInIndia>>fueltype; //Takes VehicleType ,Name,isUsed ,isMadeInIndia
        string ID=vehicleType.substr(0,2);
        ID+="00";
        ID+=name.substr(0,2);
        ID+="00";
        ID+=to_string(index);
        // Vehicle ID structure   First two char from vehicleType + "00" + First two char from vehiclename + "00"+index
        if(vehicleType=="Car")
        {
            Car *vc;
            vc=new Car(name,isUsed,isMadeInIndia,fueltype);
            vc->setID(ID);
            listOfVehicle[index]=vc;
        }
        else if(vehicleType=="Bike")
        {
            Bike *vc;
            vc=new Bike(name,isUsed,isMadeInIndia,fueltype);
            vc->setID(ID);
            listOfVehicle[index]=vc;
        }
    }
    Person P(name,gender,numberOfVehicles,listOfVehicle);
    string ID=name.substr(1,3);
    ID+="00";
    ID+=to_string(count);
    // Person ID structure Second and third and fourth char from Persons_Name +"00"+count 
    P.setPersonID(ID);
    P.display();// This call the display method of Person class
    }
    return 0;
}