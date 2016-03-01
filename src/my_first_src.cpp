
// Sys.setenv("PKG_CXXFLAGS" = "-std=c++11")

#include <Rcpp.h>
using namespace Rcpp;

//' @export
// [[Rcpp::export]]
NumericVector times_two_cpp(NumericVector x) {
  return x * 2;
}


//' @export
// [[Rcpp::export]]
double sum_cpp(const std::vector<double>& x) {
  const int sz = static_cast<int>(x.size());
  double sum = 0.0;
  for (int i=0; i!=sz; ++i) sum += x[i];
  return sum;
}



//' @export
// [[Rcpp::export]]
double sum_cpp11(NumericVector x) {
  const double sum
  = std::accumulate(
    std::begin(x),
    std::end(x),
    0.0, // '0' is the initial value
    [](const double sum, const double i)
    {
      return sum + i;
    }
  );
  return sum;
}