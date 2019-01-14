#include <string>
#include <iostream>
#include "SourceFileFinder.h"
#include "SourceFileFinderTest.h"

using namespace std;

int main(int argc, char **argv) {
    CPPUNIT_TEST_SUITE_REGISTRATION(SourceFileFinderTest);

    if (argc >= 2) {
        if (strcmp(argv[1], "-t\n") || strcmp(argv[1], "--test\n")) {
            CppUnit::Test *test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
            CppUnit::TextTestRunner runner;
            runner.addTest(test);

            runner.run();

            exit(0);
        }
    }

    SourceFileFinder Finder;
    cout << Finder.FindSourceFile() << endl;
    return 0;
}
