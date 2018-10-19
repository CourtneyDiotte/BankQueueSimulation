/*
*
* @author
* Courtney Diotte June 2018
*
* @version 1.0
* *
* @section DESCRIPTION
* Bank Queue Simulation
*
* @section LICENSE
* *
* Copyright 2018
* Permission to use, copy, modify, and/or distribute this software for
* any purpose with or without fee is hereby granted, provided that the
* above copyright notice and this permission notice appear in all copies.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
* @section Academic Integrity
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*/

#include "Simulator.h"
#include <iostream>
#include <vector>



Simulator::Simulator()
{
}


Simulator::~Simulator()
{
}

void Simulator::runSimulation(int numberOfTellers, int numberOfHours,
	int numberOfCust)
{
	const int secondsInHour = 3600;
	int numberOfServicedCust = 0;
	int totalWait = 0;
	int maxWait = 0;

	
	customer.setNumberOfCustomers(numberOfCust);

	std::queue<Customer> bankLine;
	std::vector<Teller> teller(numberOfTellers);

	int numSecondsInHoursGiven = secondsInHour * numberOfHours;

	for (int time = 0; time < numSecondsInHoursGiven; time++)
	{
		for (int i = 0; i < customer.getNumberOfCustomers(); ++i)
		{
			bankLine.push(Customer(time));
		}
		for (int t = 0; t < numberOfTellers; t++)
		{
			int maxTime = 0;
			if (teller[t].isCurrentlyFree() && !bankLine.empty())
			{
				Customer &customerInFront = bankLine.front();
				numberOfServicedCust++;
				totalWait += time - customerInFront.getArrivalTime();
				maxWait = maxWait < time - customerInFront.getArrivalTime() ? time - customerInFront.getArrivalTime() : maxWait;
				teller[t].addCustomer(customerInFront);
				bankLine.pop();
			}
		}
	}

	totalWait = totalWait / 60;
	_averageWait = (totalWait / numberOfServicedCust);
	_maxWait = (maxWait / 60);


}

void Simulator::title () const
{
	std::cout <<
		"          Bank Simulation \n" <<
		"  ********************************\n\n";
	
}
