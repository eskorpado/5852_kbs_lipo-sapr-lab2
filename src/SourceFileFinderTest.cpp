#include <pcrecpp.h>	
#include <iostream>		
#include "SourceFileFinder.h"
#include "SourceFileFinderTest.h"

void SourceFileFinderTest::TestFindSourceFile()
{
    SourceFileFinder Finder;
    string List = Finder.FindSourceFile();
    string ExpectedList = "conftest.c \nmain.c ";
    CPPUNIT_ASSERT_EQUAL(ExpectedList, List);
}
