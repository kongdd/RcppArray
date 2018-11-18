
<!-- README.md is generated from README.Rmd. Please edit that file -->

# RcppArray

[![Travis build
status](https://travis-ci.org/kongdd/RcppArray.svg?branch=master)](https://travis-ci.org/kongdd/RcppArray)

The goal of RcppArray is to avoid `matrix` or `array` deep copy when
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

## test performance
nrow <- 1e2
ncol <- 1e2
ntime <- 1e3

arr <- array(rnorm(nrow*ncol*ntime), dim = c(nrow, ncol, ntime))
# arr <- aperm(arr, c(2, 1, 3))
mat   <- `dim<-`(arr, c(nrow*ncol, ntime))

n <- 1000
newval <- rnorm(1:n) %>% array(dim = c(n, 100))
newval_3d <- `dim<-`(newval, dim = c(n/10, 10, 100))

fill_r <- function(){
    mat[1:n, 1:100] <- newval  
}

fill_rcpp <- function(){
    fill_matrix_rcpp(mat, newval)
}

fill_arma <- function(){
    fill_matrix_arma(mat, newval)
}

fill_r3d <- function(){
    arr[1:(n/10), 1:10, 1:100] <- newval
}

fill_arma3d <- function(){
    fill_array3d(arr, newval_3d)
}
```

You’ll still need to render `README.Rmd` regularly, to keep `README.md`
up-to-date.

You can also embed plots, for example:

``` r
rbenchmark::benchmark(
    fill_r(),
    fill_rcpp(),
    fill_arma(),
    fill_r3d(),
    fill_arma3d(),
    replications = 100, order='elapsed'
)
#>            test replications elapsed relative user.self sys.self
#> 5 fill_arma3d()          100    0.01        1      0.02     0.00
#> 3   fill_arma()          100    0.14       14      0.13     0.00
#> 2   fill_rcpp()          100    0.66       66      0.60     0.00
#> 1      fill_r()          100    9.71      971      2.74     6.09
#> 4    fill_r3d()          100    9.76      976      3.25     5.60
#>   user.child sys.child
#> 5         NA        NA
#> 3         NA        NA
#> 2         NA        NA
#> 1         NA        NA
#> 4         NA        NA
```
