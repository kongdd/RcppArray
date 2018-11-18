context("test-fill_matrix")

test_that("multiplication works", {
    ## 1. small int -> large double
    mat    <- matrix(1, 6, 6)
    newmat <- matrix(1:16, 4, 4)
    fill_matrix_rcpp(mat, newmat)
    
    mat2 <- matrix(1, 6, 6); mat2[1:4,1:4] <- 1:16
    expect_equal(mat, mat)
    
    ## 2.large int -> small double
    mat <- matrix(1, 6, 6)
    newmat <- matrix(1:16, 4, 4)*1.0
    fill_matrix_rcpp(newmat, mat)
    expect_equal(newmat, matrix(1, 4, 4))
    
    ## RcppArmadillo version
    ## 1. small int -> large double
    mat <- matrix(1, 6, 6)
    newmat <- matrix(1:16, 4, 4)
    fill_matrix_arma(mat, newmat)
    expect_equal(mat, mat)
    
    ## 2.large int -> small double
    mat <- matrix(1, 6, 6)
    newmat <- matrix(1:16, 4, 4)*1.0
    fill_matrix_arma(newmat, mat)
    expect_equal(newmat, matrix(1, 4, 4))
})
