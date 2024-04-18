#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "algorithm"

using namespace std;

bool ImportAll(const string &inputFilePath, unsigned int Sum, size_t &n,
               double *&w, double *&r)
{

    //OPEN FILE

    ifstream file;
    file.open(inputFilePath);

        if (file.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }

    //GET SUM OF MONEY AND LENGHT OF VECTORS

    string line;

    while (!file.eof())
    {
        getline(file,line);

        if(line[0]=="S")
            line.erase(remove(line.begin(),line.end(), 'S;'),line.end());
        Sum = int(line);

        if(line[0]=="n")
            line.erase(remove(line.begin(),line.end(), 'n;'),line.end());
        n = int(line);

    }

    //GET VECTORS

    while (!file.eof())
    {
        getline(file,line);
        unsigned int i = 0;
        //if(line[i]!=";")



    }

}

double PortFolioReturn(const unsigned int Sum, const size_t &n,
                       const double * const &w, const double * const &r)
{

    unsigned int portfolioreturn = 0;
    double rate = 0;

    for(unsigned int i = 0; i < n; i++)
        rate += w[i] * r[i];

    portfolioreturn = Sum + ( 1 + rate);

    return portfolioreturn;

}

bool ExportResult(const string &outputFilePath, const size_t &n, const double * const &w,
                  const double * const &r, const double &PortFolioReturn)

{

    ofstream file;
   file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << "S = " << Sum << ",n = " << n << endl;

    file << "w = [ ";
    for(unsigned int i = 0; i < n; i++)
        file << w[i] << " ";
    file << "]" << endl;

    file << "r = [ ";
    for(unsigned int i = 0; i < n; i++)
        file << r[i] << " ";
    file << "]" << endl;

    file << "Rate of return of the portfolio: " << rate << endl;
    file << "V: " << portfolioreturn << endl;

    file.close();
    return true;

}






