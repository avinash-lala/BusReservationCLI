#include "Bus.h"

Bus::Bus(
  int busN,
  std::string drName,
  std::string src,
  std::string dest,
  std::string dep,
  std::string arr
)
:
reservedSeatCount(0),
busNo(busN),
source(src),
destination(dest) {
  for(int i = 0; i < 32; i++) {
    seats.push_back(new Seat(i));
  }
  departure = new Date(dep);
  arrival = new Date(arr);
};

std::string Bus::GetDepartureTime() const {
  return departure -> GetTime();
};

void Bus::GetSeatStatus() const {
  for (auto seat = seats.begin(); seat != seats.end(); ++seat) {
    std::cout << "Seat No: " << (*seat) -> number << " Reserved: " << (*seat) -> reserved;
    if((*seat) -> reserved) {
      std::cout << " Occupant: " << (*seat) -> occupant;
    }
    std::cout << std::endl;
  }
};

void Bus::ReserveSeat(int seatNum, std::string name) {
  if(reservedSeatCount == 32) {
    std::cout << "No seats Vacant" << std::endl;
    return;
  }
  int ctr = 0;
  for(auto seat = seats.begin(); seat != seats.end(); ++seat) {
    if((ctr + 1) == seatNum) {
      (*seat) -> reserved = true;
      (*seat) -> occupant = name;
      break;
    }
  }
  reservedSeatCount++;
  std::cout << "Count: " << reservedSeatCount << std::endl;
}