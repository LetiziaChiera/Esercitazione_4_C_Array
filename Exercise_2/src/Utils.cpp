#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include "sstream"
#include <iomanip>
#include <string>
using namespace std;
bool ImportData(const string& inputFilePath,
                size_t& n,
                double& S,
                double*& w,
                double*& r)
{
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "l'apertura del file file è fallita"<<endl;
        return false;
    }
    int i = 0;
    int k = 0;
    string line;
    while (!file.eof())
    {
       getline(file, line); // prende prima riga dal file e la memorizza in line
       i++;
        if (i ==1)
       {

        istringstream convertS;
        convertS.str(line.substr(2)); // line.substr(2) restituisce line dal terzo carattere
        convertS >> S;
        }

        else if (i == 2)
        {

            istringstream convertn;
            convertn.str(line.substr(2)); // line.substr(2) restituisce line dal terzo carattere
            convertn >> n;
            r = new double [n];
            w = new double [n];
        }
        else if (line[0] != 'w'){
            istringstream convert;
            convert.str(line);
            char delimiter;
            convert >> w[k] >> delimiter >> r[k]; // delimiter = legge ; e lo salta
            k++;
        }

    }
        file.close();
        return true;
}

// Calcolo il valore del portafoglio V += w[i]*(1+r[i])*S
double Portfolio(size_t& n,
                  double& S,
                  double*& w,
                  double*& r){
    double V = 0;
    for (int i = 0; i< n; i++){
        V += w[i]*(1+r[i])*S;
    }
    return V;
}

// Calcolo il tasso di rendimento del portafoglio (V/S)-1
double rateReturn(double& S,
                  double& Portfolio){
    double R = (Portfolio/S)-1;
    return R;
}


bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  double& S,
                  double*& w,
                  double*& r,
                  double& rateReturn,
                  double& Portfolio
                  )
{
    // Open file
    ofstream file;
    file.open(outputFilePath);
    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    };

    //Stampo prime tre righe

    file << "S = "<<setprecision(4)<< S << ", n = " <<setprecision(4)<< n << endl;

    file << "w = [ " ;
    for (int i = 0; i< n; ++i){
        file<<w[i]<<" ";
    }
    file << "]" << endl;

    file << "r = [ " ;
    for (int i = 0; i< n; ++i){
        file<<r[i]<<" ";
    }
    file << "]" << endl;

    //Stampo il tasso di rendimento del portafoglio (V/S)-1
    file << "Rate of return of the portfolio: " << rateReturn << endl;

    // Stampo il valore del portafoglio V += w[i]*(1+r[i])*S
    file << "V: " <<setprecision(4)<< Portfolio << endl;

    // Close file
    file.close();
    return true;

}
