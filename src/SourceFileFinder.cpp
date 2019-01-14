#include "SourceFileFinder.h"
#include <string>
#include <iostream>
#include <pcrecpp.h>
#include <sstream>		
#include <algorithm>    
#include <iterator>		
#include <vector>		

using namespace std;

string SourceFileFinder::FindSourceFile()
{
    string sourceFileName;
    string list;
    pcrecpp::RE sourceFileRegex = pcrecpp::RE(R"(([a-zA-Z0-9_\-]+[.]c\s))");
    
    vector<string>fileNameArray;
    vector<string>::iterator iterator;
    vector<string>::iterator uniqueFilename;
    
    while (getline(cin, sourceFileName))
    {
        pcrecpp::StringPiece input(sourceFileName);
        while (sourceFileRegex.FindAndConsume(&input, &sourceFileName))
        {
            uniqueFilename = find(fileNameArray.begin(), fileNameArray.end(), sourceFileName);
            if (uniqueFilename == fileNameArray.end())
            {
                if (list.empty())
                {
                    list += sourceFileName;
                }
                else 
                {
                    list += "\n" + sourceFileName;
                }
                fileNameArray.push_back(sourceFileName);
            }
        }
    }
    return list;
}
