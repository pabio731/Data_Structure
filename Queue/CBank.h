#pragma once
#include"Cqueue.h"

class CBank
{
private:
	CQueue* ReservationQueue;
	CQueue* ArrivalQueue;

public:
	CBank();
};
