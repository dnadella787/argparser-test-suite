I originally wrote the testing module separate from the argparse header library I wrote in Argparse-for-CPP so that I could test out all my code for proper behavior. I figured that it would be good to add all the tests directly to the library repo rather than have it separate so it is now included inside of Argparse-for-CPP. The testing module uses gooogletest with cmake to build and run all 96 tests. The version of argparse.h that it uses is slightly altered to have some of the private variables be public instead of private so the tests can check for proper setup. That version, argparser-test-version.h is included in this repo under argparser and in the Argparse-for-CPP repo in run-tests/argparser

All the tests are are included in Argparse-for-CPP and there is a tests target in the makefile there to run all 96 tests automatically.
