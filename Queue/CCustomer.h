#pragma once

typedef enum eStatus
{
	ARRIVAL,
	START,
	END
}ESTATUS;

typedef struct Customer
{
	ESTATUS		Status;
	int			iArrivalTime;
	int			iServiceTime;
	int			iStartTime;
	int			iEndTime;		//���� �ð� + ���� �ð�.
}CUSTOMERINFO;

class CCustomer
{
private:
	CUSTOMERINFO   CInfo;

public:
	CUSTOMERINFO GetInfo() { return CInfo; }
};
