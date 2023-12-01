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
	int			iEndTime;		//시작 시간 + 서비스 시간.
}CUSTOMERINFO;

class CCustomer
{
private:
	CUSTOMERINFO   CInfo;

public:
	CUSTOMERINFO GetInfo() { return CInfo; }
};
