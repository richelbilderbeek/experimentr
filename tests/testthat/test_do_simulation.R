context("test_do_simulation")

## TODO: Rename context
## TODO: Add more tests

test_that("multiplication works", {
  experimentr::do_simulation("test.csv")
  result <- read.csv("test.csv", header = TRUE, sep = ",")
  print(result)
  expect_equal(nrow(result), 5)
  expect_equal(ncol(result), 100)
})
