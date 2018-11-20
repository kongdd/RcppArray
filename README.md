
<!-- README.md is generated from README.Rmd. Please edit that file -->

# RcppArray

[![Travis build
status](https://travis-ci.org/kongdd/RcppArray.svg?branch=master)](https://travis-ci.org/kongdd/RcppArray)

The goal of RcppArray is to avoid deep copy in `matrix` and `array` when
assigning new values.

## Installation

``` r
devtools::install_github("kongdd/RcppArray")
```

## Example

This is a basic example which shows you the performance of :

``` r
library(magrittr)
library(RcppArray)
library(bigmemory)
## test performance
nrow <- 1e2
ncol <- 1e2
ntime <- 1e4

arr <- array(rnorm(nrow*ncol*ntime), dim = c(nrow, ncol, ntime))
# arr <- aperm(arr, c(2, 1, 3))
mat     <- `dim<-`(arr, c(nrow*ncol, ntime))
mat_big <- as.big.matrix(mat)

n <- 1000
newval <- rnorm(1:n) %>% array(dim = c(n, ntime))
newval_3d <- `dim<-`(newval, dim = c(n/10, 10, ntime))

fill_r <- function(){
    mat[1:n, 1:ntime] <- newval  
}

fill_r3d <- function(){
    arr[1:(n/10), 1:10, 1:ntime] <- newval
}

fill_arma <- function(){
    fill_matrix_arma(mat, newval)
}

fill_arma3d <- function(){
    fill_array3d(arr, newval_3d)
}

fill_rcpp <- function(){
    fill_matrix_rcpp(mat, newval)
}

fill_bigmemory <- function(){
    mat_big[1:n, 1:ntime] <- newval  
}
```

What matters most is that except `fill_r` and `fill_r3d`, others can
avoid deep copy.

``` r
rbenchmark::benchmark(
    fill_r(),
    fill_r3d(),
    fill_arma(),
    fill_arma3d(),
    fill_rcpp(),
    fill_bigmemory(),
    replications = 20, order='elapsed'
)
#>               test replications elapsed relative user.self sys.self
#> 4    fill_arma3d()           20    0.92    1.000      0.58     0.00
#> 6 fill_bigmemory()           20    2.73    2.967      2.20     0.49
#> 3      fill_arma()           20    2.77    3.011      1.53     0.76
#> 1         fill_r()           20   12.17   13.228      4.22     7.23
#> 2       fill_r3d()           20   15.39   16.728      4.89     8.05
#> 5      fill_rcpp()           20   15.62   16.978     12.47     0.08
#>   user.child sys.child
#> 4         NA        NA
#> 6         NA        NA
#> 3         NA        NA
#> 1         NA        NA
#> 2         NA        NA
#> 5         NA        NA
```
