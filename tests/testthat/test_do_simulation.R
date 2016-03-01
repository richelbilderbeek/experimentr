context("test_do_simulation")

## TODO: Rename context
## TODO: Add more tests

test_that("multiplication works", {
  result <- experimentr::do_simulation()

  expect_equal(length(result), 100)
})
