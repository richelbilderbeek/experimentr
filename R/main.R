#' @useDynLib experimentr
#' @importFrom Rcpp sourceCpp

#' @export
main <- function()
{
  d <- experimentr::createTwo()

  result <- experimentr::do_simulation()
  print(result)
}


