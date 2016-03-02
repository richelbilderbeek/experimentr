// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// times_two_cpp
NumericVector times_two_cpp(NumericVector x);
RcppExport SEXP experimentr_times_two_cpp(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    __result = Rcpp::wrap(times_two_cpp(x));
    return __result;
END_RCPP
}
// sum_cpp
double sum_cpp(const std::vector<double>& x);
RcppExport SEXP experimentr_sum_cpp(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< const std::vector<double>& >::type x(xSEXP);
    __result = Rcpp::wrap(sum_cpp(x));
    return __result;
END_RCPP
}
// sum_cpp11
double sum_cpp11(NumericVector x);
RcppExport SEXP experimentr_sum_cpp11(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    __result = Rcpp::wrap(sum_cpp11(x));
    return __result;
END_RCPP
}
// do_simulation
void do_simulation(const std::string csv_filename);
RcppExport SEXP experimentr_do_simulation(SEXP csv_filenameSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< const std::string >::type csv_filename(csv_filenameSEXP);
    do_simulation(csv_filename);
    return R_NilValue;
END_RCPP
}
// create_data_frame_cpp
Rcpp::DataFrame create_data_frame_cpp();
RcppExport SEXP experimentr_create_data_frame_cpp() {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    __result = Rcpp::wrap(create_data_frame_cpp());
    return __result;
END_RCPP
}
// createTwo
DataFrame createTwo();
RcppExport SEXP experimentr_createTwo() {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    __result = Rcpp::wrap(createTwo());
    return __result;
END_RCPP
}
