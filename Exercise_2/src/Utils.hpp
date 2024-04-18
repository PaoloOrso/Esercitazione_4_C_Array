#pragma once
#include <iostream>

using namespace std;

bool ImportAll(const string& inputFilePath, unsigned int Sum, size_t& n,
               double*& w, double*& r);

double PortFolioReturn(const unsigned int Sum, const size_t& n,
                       const double* const& w, const double* const& r);

bool ExportResult(const string& outputFilePath, const size_t& n,
                         const double* const& w, const double* const& r,
                            const double& PortFolioReturn);




