#include <fstream>
#include <iostream>

using namespace std;

double calcInsurance(string, double);

int main() {
  string firstName, lastName, damType;
  int policyNum, carWorth, insurance;
  ofstream outputfile;

  outputfile.open("clientinfo.txt");

  cout << "This program calculates insurance payout based on what kind of "
          "damage carowner has.\n\n";

  cout << "What kind of damage did you have on your car?" << endl;
  cout << "Examples: Fire, Theft, Vandalism, or Accidental" << endl;
  cin >> damType;

  cout << "How much is your car worth?" << endl;
  cin >> carWorth;

  insurance = calcInsurance(damType, carWorth);

  cout << "Enter your first name: ";
  cin >> firstName;

  cout << "Enter your last name: ";
  cin >> lastName;

  cout << "Enter policy number: ";
  cin >> policyNum;

  outputfile << "Name: " << firstName << " " << lastName << endl
             << "Policy Number: " << policyNum << endl
             << "House worth (INR): " << carWorth << endl
             << "Damage: " << damType << endl
             << "Insured amount:" << insurance << endl;

  outputfile.close();

  return 0;
}

double calcInsurance(string damType, double carWorth) {
  double insurance;
  double percentage[] = {.5, .6, .7, .5,};

  if (damType == "Fire" || damType == "fire") {
    insurance = percentage[0] * carWorth;
  } else if (damType == "Theft" || damType == "theft") {
    insurance = percentage[1] * carWorth;
  } else if (damType == "Accidental" || damType == "accidental") {
    insurance = percentage[2] * carWorth;
  } else if (damType == "Vandalism" || damType == "vandalism") {
    insurance = percentage[3] * carWorth;
  } else {
    cout << "Invalid damage type" << endl;
    return 1;  // end of program due to invalid damage type
  }
  return insurance;
}