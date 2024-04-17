#pragma once
#include "iostream"

using namespace std;

bool ImportData(const string& inputFilePath,
                size_t& n,
                double& S,
                double*& w,
                double*& r);

double Portfolio(size_t& n,
                 double& S,
                 double*& w,
                 double*& r);
double rateReturn(double& S,
                  double& Portfolio);
bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  double& S,
                  double*& w,
                  double*& r,
                  double& rateReturn,
                  double& Portfolio
                  );
