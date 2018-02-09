set(UPDATE_TYPE "true")

set(CTEST_PROJECT_NAME "cmocka")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

<<<<<<< HEAD
set(CTEST_DROP_METHOD "https")
=======
set(CTEST_DROP_METHOD "http")
>>>>>>> ffbf144e3c4a58b24ec6db8182fec4746d50d9a9
set(CTEST_DROP_SITE "mock.cryptomilk.org")
set(CTEST_DROP_LOCATION "/submit.php?project=${CTEST_PROJECT_NAME}")
set(CTEST_DROP_SITE_CDASH TRUE)

