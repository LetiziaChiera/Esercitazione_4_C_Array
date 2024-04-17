#include <iostream>
#include<fstream>
#include<sstream>
#include "Utils.hpp"

using namespace std;

// (1) Calcolare il valore del portafoglio V += w[i]*(1+r[i])*S
// (2) Calcolare il tasso di rendimento del portafoglio (V/S)-1

int main()
{
    string inputFileName = "data.csv";
    size_t n = 0;
    double S = 0;
    double* w = nullptr;
    double* r = nullptr;

    if(!ImportData(inputFileName, n, S, w, r)){
        cerr << "Something goes wrong with import"<< endl;
            return -1;
    }
    else
        cout << "Import successful" << endl;

    string outputFileName = "result.txt";
    double V = Portfolio(n,S,w,r);
    double tasso = rateReturn(S,V);


    if (!ExportResult(outputFileName, n, S, w, r, tasso, V))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] w;
    delete[] r;


  return 0;
}

