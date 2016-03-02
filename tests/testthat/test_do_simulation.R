context("test_do_simulation")

## TODO: Rename context
## TODO: Add more tests

test_that("multiplication works", {
  csv_filename <- "/home/richel/GitHubs/experimentr/bin/results.csv"
  experimentr::do_simulation_r(csv_filename)
  result <- read.csv(csv_filename, header = TRUE, sep = ",")
  print(result)
  expected_names <- c("t", "f_ab", "f_aB", "f_Ab", "f_AB")
  print(names(result))
  expect_equal(names(result), expected_names)

  expect_equal(ncol(result), 5)
  expect_equal(nrow(result), 100)
})
