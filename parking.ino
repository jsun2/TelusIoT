#define numofspots 10
const int pins []= {1,2,3,4,5,6,7,8,9,10};

class ParkingSpot{
  private:
    int spotnumber;
    bool occupied = false;
    bool booked = false;
    String bookedby ="";
    int pin;
  
  public:
    // Contructor; takes in a spot number and an input number
    ParkingSpot(int spot, int pin){
      spotnumber = spot;
      this->pin = pin;
    }

  // checks the pins for if the spot is physically occupied  
  void checkOccupied(){
    
  }
  //Gives in the string for the name of the booker
  void setBooked(String bookedby){
    booked = true;
    this->bookedby = bookedby;
  }
  //Removes the booking from the parking spot
  void setUnbooked(){
    booked = false;
    bookedby = "";
  }

  bool alarm(){
    if (!booked && occupied){
      return true;
    }
    return false;
  }
  String booker(){
    return bookedby;
  }
  
};
ParkingSpot *parkinglot[numofspots];

// checks and updates the status for all parking spots
void updateAllStatus(){
  for (int i = 0; i < numofspots; i++){
    parkinglot[i]->checkOccupied();
  }
}

// initializes the parking lot
void InitializeParkingLot(){
 for (int i = 0; i < numofspots; i++){
    parkinglot[i] = new ParkingSpot (i, pins[i]);
  }
}

void setup() {
  InitializeParkingLot();
  updateAllStatus();
}

boolean checkAlarm(){
  for (int i = 0; i < numofspots; i++){
    if (parkinglot[i]->alarm())
      return true;
  }
  return false;
}

void loop() {
  

}
