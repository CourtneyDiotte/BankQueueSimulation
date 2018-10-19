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

#pragma once
#include <random>

class Customer
{
public:
	
	
	static const int TRANS_MEAN_TIME = 120;
	static const int TRANS_SDEV = 60;
	static const int TRANS_MIN_TIME = 30;
	static const int TRANS_MAX_TIME = 600;
	static const int SECONDS_IN_HR = 3600;

	Customer(int arrivedAt = 0) : processTime(getTimeToProcess()),
								  arrivalTime(arrivedAt),
								  _numberOfCustomers(0)
								  
	{
		std::default_random_engine generator(rd());
	}

	// order by arrival time
	bool operator< (const Customer& other) const
	{
		return arrivalTime < other.arrivalTime;
	}

	// is transaction finished
	bool isFinished() 
	{
		return --processTime < 0;
	}

	//get customer arrival time
	int getArrivalTime() const;
	
	//use normal distribution to get time to process customer
	int getTimeToProcess();

	//use poisson distribution to get number of customers per time slice
	int getNumberOfCustomers();

	//set customer arrival time
	void setNumberOfCustomers(int numCustomers);


private:
	int arrivalTime;
	int processTime;
	std::default_random_engine rd;
	std::default_random_engine generator;
	int _numberOfCustomers;
	
};

