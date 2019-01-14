#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "SourceFileFinder.h"

using namespace std;

class SourceFileFinderTest : public CppUnit::TestCase
{
    public:
        void TestFindSourceFile();
        
        CPPUNIT_TEST_SUITE( SourceFileFinderTest );
        CPPUNIT_TEST( TestFindSourceFile );
        CPPUNIT_TEST_SUITE_END();
};