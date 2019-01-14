UniqueSourceFileNameFinder.  
Usage:  
```
export CPPUNIT_HOME=PATH-TO-CPPUNIT-DIR
make
./main < file
```  
Program make tests automatically during build process.  
And you can run them yourself, just run:  
```
make test
```
For run SH script that do the same as the program run:  
```
./main.sh file
```  
For compare the result of SH script and C++ program run:
```
make compare
```