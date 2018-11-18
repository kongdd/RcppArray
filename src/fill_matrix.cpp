#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;

//' @name fill_matrix
//' @title fill_matrix
//' 
//' Replace sub matrix in rcpp format.
//' 
//' @rdname fill_matrix
//' @inheritParams fill_array3d
//' @param mat A matrix.
//' @param newmat A matrix to fill \code{mat}.
//' 
//' @examples
//' # mat   : ones matrix
//' # newmat: 1:16 matrix
//' 
//' ## 1. rcpp version
//' mat <- matrix(1, 6, 6)
//' newmat <- matrix(1:16, 4, 4)*1.0
//' fill_matrix_rcpp(mat, newmat)
//' mat
//' 
//' ## 2. RcppArmadillo version
//' mat <- matrix(1, 6, 6)
//' newmat <- matrix(1:16, 4, 4)
//' fill_matrix_arma(mat, newmat)
//' mat


//' @rdname fill_matrix
//' @export
// [[Rcpp::export]]
void fill_matrix_rcpp(NumericMatrix mat, NumericMatrix newmat, 
    int32_t i_start = 1, int32_t j_start = 1)
{    
    // R format subindex convert to cpp, [0, ..., n-1]
    i_start -= 1;
    j_start -= 1;

    int32_t nrow = newmat.nrow();
    int32_t ncol = newmat.ncol();
    
    int32_t i_end = std::min(mat.nrow(), i_start + nrow) - 1;
    int32_t j_end = std::min(mat.ncol(), j_start + ncol) - 1;
    
    // Rprintf("i_end = %d, j_end = %d\n", i_end, j_end);
    // Rcout << i_end << <<j_end << std::endl;
    for (int32_t i = i_start; i <= i_end; i++){
        for (int32_t j = j_start; j <= j_end; j++){
            mat(i, j) = newmat(i - i_start, j - j_start);
        }
    }
    
    // mat.submat( 0,0, 2,2) = newmat.submat( 3,3, 5,5 );
    // Rcpp::Rcout << mat << std::endl;
    // return mat;
}

//' @rdname fill_matrix
//' @export
// [[Rcpp::export]]
void fill_matrix_arma(arma::mat& mat, arma::mat newmat, 
    int32_t i_start = 1, int32_t j_start = 1)
{    
    // R format subindex convert to cpp, [0, ..., n-1]
    i_start -= 1;
    j_start -= 1;

    uword nrow  = newmat.n_rows;
    uword ncol  = newmat.n_cols;
    
    uword i_end = std::min(mat.n_rows, i_start + nrow) - 1;
    uword j_end = std::min(mat.n_cols, j_start + ncol) - 1;
    
    // Rprintf("i_end = %d, j_end = %d\n", i_end, j_end);
    // Rcout << i_end << <<j_end << std::endl;
   
    // make sure newmat not larger than mat
    mat.submat(i_start, j_start, i_end, j_end) = 
        newmat.submat(0, 0, i_end - i_start, j_end - j_start);
    // Rcpp::Rcout << mat << std::endl;
    // return mat;
}

/*** R
# mat   : ones matrix
# newmat: 1:16 matrix

## 1. rcpp version
mat <- matrix(1, 6, 6)
newmat <- matrix(1:16, 4, 4)*1.0
submatrix_rcpp(mat, newmat)
mat

## 2. RcppArmadillo version
mat <- matrix(1, 6, 6)
newmat <- matrix(1:16, 4, 4)
submatrix_arma(mat, newmat)
mat

*/
