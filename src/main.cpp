#include <cassert>
#include <fstream>
#include <iterator>
#include <iostream>
#include <vector>
#include "simulation.h"

  //Rcpp::DataFrame d = create_data_frame_cpp();


///Determines if a filename is a regular file
///From http://www.richelbilderbeek.nl/CppIsRegularFile.htm
bool IsRegularFile(const std::string& filename)
{
  std::fstream f;
  f.open(filename.c_str(),std::ios::in);
  return f.is_open();
}

///FileToVector reads a file and converts it to a std::vector<std::string>
///From http://www.richelbilderbeek.nl/CppFileToVector.htm
std::vector<std::string> FileToVector(const std::string& filename)
{
  assert(IsRegularFile(filename));
  std::vector<std::string> v;
  std::ifstream in(filename.c_str());
  for (int i=0; !in.eof(); ++i)
  {
    std::string s;
    std::getline(in,s);
    v.push_back(s);
  }
  return v;
}

//Just for testing the C++ code
int main()
{
  try
  {
    do_simulation("temp.csv");
    const auto v = FileToVector("temp.csv");
    std::copy(std::begin(v),std::end(v),std::ostream_iterator<std::string>(std::cout,"\n"));

    assert(!"OKAY!");
  }
  catch (...)
  {
    assert(!"Should not get here");
  }
}
