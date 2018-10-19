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

#include <iostream>
#include "Simulator.h"
#include "Customer.h"
#include "Teller.h"


int main()
{
	Simulator mySim;
	int numberOfTellers = 0;
	int numberOfHours = 0;
	int numberOfCust = 0;
	char cont = ' ';

	do {
		system("cls");
		mySim.title();

		std::cout << "Customers per hour: ";
		std::cin >> numberOfCust;

		std::cout << "Number of tellers: ";
		std::cin >> numberOfTellers;

		std::cout << "Length of simulation (hr): ";
		std::cin >> numberOfHours;

		mySim.runSimulation(numberOfTellers, numberOfHours,
			numberOfCust);


		std::cout << "\nAverage wait: "
			<< mySim.getAverageWait() << " min." << std::endl;

		std::cout << "\Max wait: "
			<< mySim.getMaxWait() << " min." << std::endl;


		std::cout << "\nRun another simulation? (y/n) ";
		std::cin >> cont;

	} while ((cont != 'N' || cont != 'n') && (cont == 'Y' || cont == 'y'));

	
}