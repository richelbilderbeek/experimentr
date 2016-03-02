#' Do a simulation
#' @param csv_filename A CSV filename
#' @return Nothing
#' @export
do_simulation_r <- function(csv_filename)
{
  exe_filename <- "/home/richel/GitHubs/experimentr/bin/main"
  #csv_filename <- "/home/richel/GitHubs/experimentr/bin/results.csv"
  if (!file.exists(exe_filename))
  {
    stop("File '", exe_filename, "'not found")
  }
  cmd <- paste(exe_filename, " ", csv_filename, sep = "")
  system(cmd)

  if (!file.exists(csv_filename))
  {
    stop("File '", csv_filename, "'not found")
  }

  result <- read.csv(csv_filename, header = TRUE, sep = ",")
  result
}


