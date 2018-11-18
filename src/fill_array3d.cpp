#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;

// [[Rcpp::depends(RcppArmadillo)]]

//' fill_array3d
//' 
//' This function is just for Rcmip5 package when combine 3d array.
//' 
//' Note that if data types of \code{mat} and \code{newmat} are different, 
//' values in \code{mat} will be \strong{not replaced.}
//' 
//' @param mat A 3d Array.
//' @param newmat A 3d Array to fill \code{mat}.
//' @param i_start Integer, row of \code{mat} starting to fill.
//' @param j_start Integer, col of \code{mat} starting to fill.
//' @param k_start Integer, slice of \code{mat} starting to fill.
//' 
//' @references
//' [1] https://stackoverflow.com/questions/30969799/column-means-3d-matrix-cube-rcpp \cr
//' [2] https://stackoverflow.com/questions/34161593/how-to-replace-elements-of-a-matrix-in-c-with-values-from-another-matrix-usin \cr
//' 
//' @examples
//' mat    <- array(2, dim = c(3, 3, 3))
//' newmat <- array(1, dim = c(3, 3, 3))
//' fill_array3d(mat, newmat)
//' mat
//' 
//' @export
// [[Rcpp::export]]
void fill_array3d(arma::cube& mat, 
                const arma::cube& newmat,
                int32_t i_start = 1, int32_t j_start = 1, int32_t k_start = 1) 
{
    // R format subindex convert to cpp, [0, ..., n-1]
    i_start -= 1;
    j_start -= 1;
    k_start -= 1;
    
    uword nrow  = newmat.n_rows;
    uword ncol  = newmat.n_cols;
    uword ntime = newmat.n_slices;
    
    uword i_end = std::min(mat.n_rows, i_start + nrow) - 1;
    uword j_end = std::min(mat.n_cols, j_start + ncol) - 1;
    uword k_end = std::min(mat.n_slices, k_start + ntime) - 1;

    // Rprintf("dim = [%d, %d, %d]\n", nrow, ncol, ntime);
    // Rcout << mat(1, 1, 1) << std::endl;
    
    mat(span(i_start, i_end), span(j_start, j_end), span(k_start, k_end)) = 
        newmat(span(0, i_end-i_start), span(0, j_end-j_start), 
            span(0, k_end-k_start));
    // Rcout << mat << std::endl;
    // return arma::pow(x, 2);
}

/*** R
# m1 <- matrix(1, 6, 6)
# m2 <- matrix(1:16, 4, 4)
# submatrix(m1, m2)
# m1
mat    <- array(NA_real_, dim = c(3, 3, 3))
newmat <- array(1, dim = c(2, 2, 2))
subarray3d(mat, newmat)
mat

## 2. different type works
mat    <- array(NA_real_, dim = c(3, 3, 3))
newmat <- array(1L, dim = c(2, 2, 2))
subarray3d(mat, newmat)
mat

## 3. double to int not work
mat    <- array(0L, dim = c(3, 3, 3))
newmat <- array(NA_real_, dim = c(2, 2, 2))
subarray3d(mat, newmat)
mat

## 4. large newmat replacing
mat    <- array(0L, dim = c(3, 3, 3))
newmat <- array(NA_real_, dim = c(2, 2, 2))
subarray3d(newmat, mat)
newmat
*/
