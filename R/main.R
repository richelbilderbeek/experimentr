#' @useDynLib experimentr
#' @importFrom Rcpp sourceCpp

#' @export
main <- function()
{
  result <- experimentr::do_simulation()
  print(result)
}
