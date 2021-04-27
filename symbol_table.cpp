#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
int varNum=0;
int ifNum=0;
int funcNum=0;
int forNum=0;
int whileNum=0;
    string line;
    string token;
    string lastToken;
    string grandLastToken;
    ifstream fin("test4.c");
    while(getline(fin,line)){
        stringstream stream(line);
cout<<endl;
    while(stream >> token){

            if(token=="char" || token=="short" ||token=="int" ||token=="long" || token=="float" ||token=="double" || token=="char*" || token=="short*" ||token=="int*" ||token=="long*" || token=="float*"){
                varNum++;
                cout << "VarNum=" << varNum;
            }
            if(token=="if"){
                ifNum++;


            }
            if(token=="for"){
                forNum++;


            }
            if(token=="while"){
                whileNum++;


            }
            if(token == "(") {
                    if(grandLastToken=="char" || grandLastToken=="short" ||grandLastToken=="int" ||grandLastToken=="long" ||grandLastToken=="float" ||grandLastToken=="double" || grandLastToken=="char*" || grandLastToken=="short*" ||grandLastToken=="int*" ||grandLastToken=="long*" ||grandLastToken=="float*" ||grandLastToken=="double*" || grandLastToken == "void"){
                    varNum--;
                    funcNum++;
                    if(grandLastToken=="void"){
                        varNum++;
                    }
                    }
                }

            if((token+lastToken)=="longlong"){
                    varNum--;
                }

                grandLastToken = lastToken;
                lastToken = token;

cout <<  token << " ";
    }
    }
cout << endl;
cout << endl;
cout << endl;
fin.close();
cout << "Variables:"<<varNum<<endl;
cout << "Functions:"<<funcNum<<endl;
cout << "If statements:"<<ifNum<<endl;
cout << "For loops:"<<forNum<<endl;
cout << "While loops:"<<whileNum<<endl;
return 0;
}
