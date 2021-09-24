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
