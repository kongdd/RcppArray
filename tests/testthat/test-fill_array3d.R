context("test-fill_array3d")

test_that("fill_array3d works", {
    ## 1. small double -> large double
    mat    <- array(NA_real_, dim = c(3, 3, 3))
    newmat <- array(1, dim = c(2, 2, 2))
    fill_array3d(mat, newmat)
    
    mat2 <- array(NA_real_, dim = c(3, 3, 3)); mat2[1:2, 1:2, 1:2] <- 1
    expect_equal(mat, mat2)
    
    ## 2. small int -> large double
    mat    <- array(NA_real_, dim = c(3, 3, 3))
    newmat <- array(1L, dim = c(2, 2, 2))
    fill_array3d(mat, newmat)
    expect_equal(mat, mat2)
    
    ## 3. small double -> large int (not work)
    mat      <- array(0L, dim = c(3, 3, 3))
    mat_zero <- array(0L, dim = c(3, 3, 3))
    newmat <- array(NA_real_, dim = c(2, 2, 2))
    fill_array3d(mat, newmat)
    expect_equal(mat, mat_zero)
    
    ## 4. large int -> small double
    mat    <- array(0L, dim = c(3, 3, 3))
    newmat <- array(NA_real_, dim = c(2, 2, 2))
    fill_array3d(newmat, mat)
    expect_equal(newmat, array(0, dim = c(2, 2, 2)))
})
