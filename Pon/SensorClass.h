#define AnzahlSensor 34

#define AnzahlMP 2
#define AnzahlProMP 16
#define AnzahlSelectMP 4
#define firstSelectPin 0
#define firstMPPin 0
#define SensorSchwellwert 500

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif


class SensorClass
{
private:
	int SensorWert;
	bool status; //true=becher da; false=beacher weg
	//int MPPin;
	int ID;
	int MPID;
	int E;



public:
	void init(int Imp, int Ie, int i);
	bool SensorLesen();
	int getID();
	void setID(int id);
	void setPin(int pin);
	void setMPID(int mpid);
	void sourceSelect();
	void setE(int e);
};
