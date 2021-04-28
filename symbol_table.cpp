/*
* @author Georgi Lefterov 40492743
* Last Modification 29.04.2021
* That's the Part A from the Programming Fundamentals second coursework. It reads a file, outputs some info in the console and outputs a file with symbol table.
*/


#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

class identifierShow
{
public:
    int differentScopes;
    string name;
    string currentScope;
    string type;
    string typeOfIdent;
    int line;
    int referencedNum;
};

int main()
{
    bool alreadyInArray=0;
    int funcStatus=0;
    int varNum=0;
    int currentLine=0;
    int ifNum=0;
    int funcNum=0;
    int forNum=0;
    int whileNum=0;
    identifierShow arrayOfClass[100];
    string line;
    string token;
    string lastToken;
    string grandLastToken;
    string currentScope;
    ifstream fin("test4.c");
    ofstream fout("identifiers.txt");
    while(getline(fin,line))
    {
        currentLine++;
        stringstream stream(line);
        while(stream >> token)
        {
                                        for(int i=0; i<100; i++){
                    if(token == arrayOfClass[i].name  ){
                        arrayOfClass[i].referencedNum++;
                        if(arrayOfClass[i].currentScope != currentScope && arrayOfClass[i].typeOfIdent != "function" ){
                           arrayOfClass[i].referencedNum--;
                        }
                    }
                }

            if(grandLastToken=="char" || grandLastToken=="short" ||grandLastToken=="int" ||grandLastToken=="long" || grandLastToken=="float" ||grandLastToken=="double" || grandLastToken=="char*" || grandLastToken=="short*" ||grandLastToken=="int*" ||grandLastToken=="long*" || grandLastToken=="float*" || grandLastToken=="void")
            {
                if(token == "(")
            {
                    currentScope = lastToken;
                    varNum--;
                    funcNum++;
                    funcStatus=1;


            }

                varNum++;

                for(int i=0; i<varNum+funcNum; i++)
                {
                if(arrayOfClass[i].name==lastToken && arrayOfClass[i].currentScope == currentScope){
                    arrayOfClass[i].referencedNum++;
                    alreadyInArray=1;
                }
                if(arrayOfClass[i].name==lastToken && arrayOfClass[i].currentScope != currentScope){
                arrayOfClass[i].differentScopes=1;
                }
                }
                if(alreadyInArray==0){
                    arrayOfClass[varNum+funcNum].name = lastToken;
                    arrayOfClass[varNum+funcNum].currentScope = currentScope;
                    arrayOfClass[varNum+funcNum].referencedNum = 0;
                    arrayOfClass[varNum+funcNum].line = currentLine;
                    arrayOfClass[varNum+funcNum].type = grandLastToken;
                    if(funcStatus==1){
                    arrayOfClass[varNum+funcNum].typeOfIdent = "function";
                    funcStatus=0;
                    }else{
                    arrayOfClass[varNum+funcNum].typeOfIdent = "variable";
                    }

                }

                //cout << "VarNum=" << varNum;
            }

            if(token=="if")
            {
                ifNum++;


            }
            if(token=="for")
            {
                forNum++;


            }
            if(token=="while")
            {
                whileNum++;


            }


            if((token+lastToken)=="longlong")
            {
                varNum--;
            }

            grandLastToken = lastToken;
            lastToken = token;

        }
    }
for(int i=1; i<=varNum+funcNum; i++){
    cout << arrayOfClass[i].differentScopes<< " " << arrayOfClass[i].name<< " " <<arrayOfClass[i].currentScope << endl;
    if(arrayOfClass[i].differentScopes==1){
        fout << arrayOfClass[i].name <<"(" << arrayOfClass[i].currentScope << ")" <<", line: " << arrayOfClass[i].line << ", " << arrayOfClass[i].typeOfIdent <<", "<< arrayOfClass[i].type << ", referenced: " << arrayOfClass[i].referencedNum<<endl;
    }else{
    fout << arrayOfClass[i].name <<  ", line: " << arrayOfClass[i].line << ", " << arrayOfClass[i].typeOfIdent <<", "<< arrayOfClass[i].type << ", referenced: " << arrayOfClass[i].referencedNum<<endl;
}
}
    fin.close();
    fout.close();
    cout << "Variables:"<<varNum<<endl;
    cout << "Functions:"<<funcNum<<endl;
    cout << "If statements:"<<ifNum<<endl;
    cout << "For loops:"<<forNum<<endl;
    cout << "While loops:"<<whileNum<<endl;
    return 0;
}

