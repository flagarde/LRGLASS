#ifndef ANALYSIS_h
#define ANALYSIS_h

#include "OutFileRoot.hh"
#include "TGraphErrors.h"
#include <string>
#include <vector>
#include <map>
#include "TObject.h"
#include "Chambers.h"
#include "Reader.h"
using namespace std;

class Analysis
{
public:
  Analysis(OutFileRoot& out_,Reader& read_,Chambers& cham_):out(out_),read(read_),cham(cham_){};
  Analysis()=delete;
  ~Analysis(){};
  int Loop();
  void writeObject(std::string& dirName, TObject *object);
private:
  OutFileRoot& out;
  Reader& read;
  Chambers& cham;
  void ShiftTimes();
  double TimeMax;
  //void WriteMe();
  void Construct_Plot();
  std::map<std::string,std::pair<double,double>>Eff_ErrorEff(std::string& inputFileName);  
};
#endif
