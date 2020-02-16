#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "MyQueue.h"

int main() {
	int SIMULATION_MINUTES = 120;
	int MAX_ARRIVAL = 4;
	int MIN_ARRIVAL = 1;

	cout << "\nCheckout line simulation machine problem by Sean Robenalt.";
	cout << "\nThis program simulates " << SIMULATION_MINUTES << " minutes or 2 hours at a checkout line.\n\n";
	MyQueue lineOfCustomers(4);

	int waitTime = rand() % MAX_ARRIVAL + MIN_ARRIVAL;
	lineOfCustomers.enqueue(waitTime);
	cout << "\nBegin..\n\n" << "First customer enters line w/ a wait time of " << waitTime << "\n\n";

	int minutesPassed = 0;

	while(minutesPassed <= SIMULATION_MINUTES)
	{
		cout << "\n\n" << minutesPassed << " minutes passed in the line.";

		int nextServedMinute = rand() % MAX_ARRIVAL + MIN_ARRIVAL + minutesPassed;
		lineOfCustomers.enqueue(nextServedMinute);
		cout << "\nNext customer enters line and is waiting " << nextServedMinute-minutesPassed << " minutes.";

		if (minutesPassed == waitTime) {
			cout << "\n\nFirst customer arrived and waited " << waitTime << " minutes. Customer is removed from the queue.";
		} else if (minutesPassed % nextServedMinute) {
			cout << "\n\nNext customer has arrived and waited " << nextServedMinute-minutesPassed << " minutes. Customer is removed from the queue.";
			lineOfCustomers.dequeue();
		}

		cout << "\nThere are now " << lineOfCustomers.size() << " customers in line.";

		minutesPassed++;
	}

	cout << "\n\n120 minutes have passed, simulation has ended.\n";

	return 0;
}
