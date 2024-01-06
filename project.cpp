#include <iostream>

using namespace std;

int main() {
	int TimeUpChoice;
	int TimeDownChoice;
	int TicketsToBuy;
	int UpIndex;
	int DownIndex;
	float JourneyCost;
	char choice;
	bool ValidTime;
	const int TicketPrice = 25; // Fixed ticket price
	int TrainuptimeUp[] = {900, 1100, 1300, 1500};
	int TrainuptimeDown[] = {1000, 1200, 1400, 1600};
	int TrainUpseets[] = {480, 480, 480, 480};
	int TrainDownseets[] = {480, 480, 480, 640};
	int TotalPassengersUp[] = {0, 0, 0, 0};
	int TotalPassengersDown[] = {0, 0, 0, 0};
	float TotalAmountUp[] = {0, 0, 0, 0};
	float TotalAmountDown[] = {0, 0, 0, 0};
	int TotalPassengers = 0;
	float TotalAmount = 0;
	float TotalJourneyCost = 0;
	float OverallSumJourneyCost = 0; // Variable to accumulate the sum of all journey costs
	int MostPassengersJourney;
	int MostPassengersCount = 0;
	cout<<"*******************************************************************************"<<endl;
	cout<<"   Electric Mountain Railway Time Shedule     "<<endl;
	cout<<"*******************************************************************************"<<endl;

	cout << "(Train Times)\t\t(Seats)\t\t(Total Passengers)\t(Total Amount)" << endl;

	for (int i = 0; i < 4; ++i) {
		cout << TrainuptimeUp[i] << "\t\t\t" << TrainUpseets[i] << "\t\t\t\t" << TotalPassengersUp[i] << "\t\t" << TotalAmountUp[i] << endl;
	}

	for (int i = 0; i < 4; ++i) {
		cout << TrainuptimeDown[i] << "\t\t\t" << TrainDownseets[i] << "\t\t\t\t" << TotalPassengersDown[i] << "\t\t" << TotalAmountDown[i] << endl;
	}


	do {
		cout << "\n  Do you want to sell tickets? (Y/N)" << endl;
		cin >> choice;

		if (choice == 'Y' || choice == 'y') {
			ValidTime = false;

			do {
				cout << "Enter time to go up the mountain (0900, 1100, 1300, 1500): ";
				cin >> TimeUpChoice;

				ValidTime = false;

				for (int i = 0; i < 4; ++i) {
					if (TimeUpChoice == TrainuptimeUp[i]) {
						UpIndex = i;
						ValidTime = true;
						break;
					}
				}

				if (!ValidTime) {
					cout << "Invalid up time. Please Re-Enter time." << endl;
				}
			} while (!ValidTime);

			do {
				cout << "Enter time to go down the mountain (1000, 1200, 1400, 1600): ";
				cin >> TimeDownChoice;

				ValidTime = false;

				for (int i = 0; i < 4; ++i) {
					if (TimeDownChoice == TrainuptimeDown[i]) {
						DownIndex = i;
						ValidTime = true;
						break;
					}
				}

				if (!ValidTime) {
					cout << "Invalid down time. Please Re-Enter time." << endl;
				}
			} while (!ValidTime);

			cout << endl;
			cout << "You can purchase return tickets only. The cost of each ticket is $" << TicketPrice << " for up time and $" << TicketPrice << " for down time." << endl;
			cout << "Group Discount is available on every 10th Ticket with a maximum of 88 persons per coach." << endl;
			cout << endl;

			cout << "How many tickets do you want to buy? ";
			cin >> TicketsToBuy;

			if (TicketsToBuy > min(TrainUpseets[UpIndex], TrainDownseets[DownIndex])) {
				cout << "The tickets opted to buy are more than the available seats (" << min(TrainUpseets[UpIndex], TrainDownseets[DownIndex]) << "). Please enter as per availability: ";
				cin >> TicketsToBuy;
			}

			if (TicketsToBuy > 0) {

				TrainUpseets[UpIndex] -= TicketsToBuy;
				TrainDownseets[DownIndex] -= TicketsToBuy;

				if (TicketsToBuy >= 10 && TicketsToBuy <= 80) {
					int disJourneyCost = TicketPrice * (TicketsToBuy / 10.0);
					JourneyCost = (TicketPrice * TicketsToBuy) - disJourneyCost;
					cout << "Congratulations, you have availed (" << TicketsToBuy / 10 << " Seat) Discount." << endl;
					cout << "Your total cost for one journey is: $" << JourneyCost * 2 << endl;
				} else {
					JourneyCost = TicketPrice * TicketsToBuy;
					cout << "Your total cost for one journey is: $" << JourneyCost << endl;
				}

				TotalPassengersUp[UpIndex] += TicketsToBuy;
				TotalPassengersDown[DownIndex] += TicketsToBuy;
				TotalAmountUp[UpIndex] += JourneyCost;
				TotalAmountDown[DownIndex] += JourneyCost;

				TotalPassengers += TicketsToBuy;
				TotalAmount += JourneyCost;

				TotalJourneyCost += JourneyCost;
				OverallSumJourneyCost += JourneyCost;

				if (TotalPassengersUp[UpIndex] > MostPassengersCount) {
					MostPassengersCount = TotalPassengersUp[UpIndex];
					MostPassengersJourney = UpIndex;
				}

				if (TotalPassengersDown[DownIndex] > MostPassengersCount) {
					MostPassengersCount = TotalPassengersDown[DownIndex];
					MostPassengersJourney = DownIndex;
				}

			} else {
				cout << "No tickets purchased. Exiting program." << endl;
				break;
			}

		} else {
			cout << "No tickets purchased. Exiting program." << endl;
			break;
		}

	} while (true);
	cout<<"\n\n*******************************************************************************"<<endl;
	cout<<"   TICKETS SOLD SUMMARY PER TRAIN PER JOURNY      "<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout << "(Train Times)\t\t(Seats)\t\t(Total Passengers)\t(Total Amount)" << endl;

	for (int i = 0; i < 4; ++i) {
		cout << TrainuptimeUp[i] << "\t\t\t" << TrainUpseets[i] << "\t\t\t\t" << TotalPassengersUp[i] << "\t\t" << TotalAmountUp[i] << endl;
	}

	for (int i = 0; i < 4; ++i) {
		cout << TrainuptimeDown[i] << "\t\t\t" << TrainDownseets[i] << "\t\t\t\t" << TotalPassengersDown[i] << "\t\t" << TotalAmountDown[i] << endl;
	}


	cout << "\n\nTotal Passengers for the day: " << TotalPassengers*2 << endl;



	if (TotalPassengersUp[MostPassengersJourney] > TotalPassengersDown[MostPassengersJourney]) {
		cout << "Up train has more passengers with " << TotalPassengersUp[MostPassengersJourney] << " passengers at time " << TrainuptimeUp[MostPassengersJourney] << " (Up)." << endl;
	} else if (TotalPassengersUp[MostPassengersJourney] < TotalPassengersDown[MostPassengersJourney]) {
		cout << "Down train has more passengers with " << TotalPassengersDown[MostPassengersJourney] << " passengers at time " << TrainuptimeDown[MostPassengersJourney] << " (Down)." << endl;
	} else {
		cout << "Most passenger of the day are in with train  " << TotalPassengersUp[MostPassengersJourney] << " passengers at time " << TrainuptimeUp[MostPassengersJourney] << " (Up) and " << TrainuptimeDown[MostPassengersJourney] << " (Down)." << endl;
	}

	cout << "Sum of all Journey Costs for the day: $" << (TotalJourneyCost*2) << endl;

	cout<<"\n\n\t/*******THANKS FOR USING THE ELECTRIC MOUNTAIN TRAIN TICKETS BOOKING SERVICES....*******/"<<endl;


	return 0;
}
