context("my_first_tests")

test_that("Test times_two_cpp", {
  x <- experimentr::times_two_cpp(2)

  expect_equal(length(x), 1)
  expect_equal(x, 4)

  x <- times_two_cpp(c(1,2))

  expect_equal(length(x), 2)
  expect_equal(x, c(2,4))

})

test_that("Test sum_cpp11", {
  x <- experimentr::sum_cpp(c(1.1,2.2))
  expect_equal(length(x), 1)
  expect_equal(x, 3.3)

  x <- experimentr::sum_cpp11(c(1.1,2.2))
  expect_equal(length(x), 1)
  expect_equal(x, 3.3)
})



test_that("Crash me", {
  skip("Today")
  expect_equal(TRUE, FALSE)
})


test_that("test_createTwo", {
  skip("Today")
  x <- createTwo()
  expect_equal(ncol(x), 2)
  expect_equal(nrow(x), 3)
  expected_names <- c("a", "b")
  expect_equal(names(x), expected_names)

})

test_that("test_create_dateframe_cpp", {
  skip("Today")
  x <- create_data_frame_cpp()
  expect_equal(ncol(x), 2)
  expect_equal(nrow(x), 3)
  expected_names <- c("x", "y")
  expect_equal(names(x), expected_names)

})
