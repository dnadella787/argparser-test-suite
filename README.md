A separate testing area that I am working on to add more tests and debug code as needed. It uses googletest with cmake to run the tests. The version of argparse.h that it uses is slightly altered to have some of the private variables be public instead of private so the tests can check for proper setup. That version, argparser-test-version.h is included in this repo under argparser and in the Argparse-for-CPP repo in run-tests/argparser

All the tests are are included in Argparse-for-CPP and there is a tests target there to run all 96 tests automatically.

