#' Do a simulation
#' @param csv_filename A CSV filename
#' @return Nothing
#' @export
do_simulation_r <- function(csv_filename)
{
  do_simulation(csv_filename)
  result <- read.csv(csv_filename, header = TRUE, sep = ",")
  result
}


