// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// fill_array3d
void fill_array3d(arma::cube& mat, const arma::cube& newmat, int32_t i_start, int32_t j_start, int32_t k_start);
RcppExport SEXP _RcppArray_fill_array3d(SEXP matSEXP, SEXP newmatSEXP, SEXP i_startSEXP, SEXP j_startSEXP, SEXP k_startSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube& >::type mat(matSEXP);
    Rcpp::traits::input_parameter< const arma::cube& >::type newmat(newmatSEXP);
    Rcpp::traits::input_parameter< int32_t >::type i_start(i_startSEXP);
    Rcpp::traits::input_parameter< int32_t >::type j_start(j_startSEXP);
    Rcpp::traits::input_parameter< int32_t >::type k_start(k_startSEXP);
    fill_array3d(mat, newmat, i_start, j_start, k_start);
    return R_NilValue;
END_RCPP
}
// fill_matrix_rcpp
void fill_matrix_rcpp(NumericMatrix mat, NumericMatrix newmat, int32_t i_start, int32_t j_start);
RcppExport SEXP _RcppArray_fill_matrix_rcpp(SEXP matSEXP, SEXP newmatSEXP, SEXP i_startSEXP, SEXP j_startSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type mat(matSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type newmat(newmatSEXP);
    Rcpp::traits::input_parameter< int32_t >::type i_start(i_startSEXP);
    Rcpp::traits::input_parameter< int32_t >::type j_start(j_startSEXP);
    fill_matrix_rcpp(mat, newmat, i_start, j_start);
    return R_NilValue;
END_RCPP
}
// fill_matrix_arma
void fill_matrix_arma(arma::mat& mat, arma::mat newmat, int32_t i_start, int32_t j_start);
RcppExport SEXP _RcppArray_fill_matrix_arma(SEXP matSEXP, SEXP newmatSEXP, SEXP i_startSEXP, SEXP j_startSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type mat(matSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type newmat(newmatSEXP);
    Rcpp::traits::input_parameter< int32_t >::type i_start(i_startSEXP);
    Rcpp::traits::input_parameter< int32_t >::type j_start(j_startSEXP);
    fill_matrix_arma(mat, newmat, i_start, j_start);
    return R_NilValue;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_RcppArray_fill_array3d", (DL_FUNC) &_RcppArray_fill_array3d, 5},
    {"_RcppArray_fill_matrix_rcpp", (DL_FUNC) &_RcppArray_fill_matrix_rcpp, 4},
    {"_RcppArray_fill_matrix_arma", (DL_FUNC) &_RcppArray_fill_matrix_arma, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_RcppArray(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
