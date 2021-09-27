#define AnzahlRinge 22 
#define AnzahlLEDproRing 24

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif

class RingClass
{
private:
	bool status;
	int ID;
  
public:
	void init();
	void rot();
	void gruen();
	bool getstatus();
};
