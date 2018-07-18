
#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char** argv){
	
	ifstream readFile;
	ofstream writeFile;
	readFile.open(argv[1]);											//declares to ifstream to open a text file		
	writeFile.open(argv[2]);										//declares to open up an output file	
	int intNum, max = 0, counter = 0;
	int* intArray;							
	
	if (argc != 3) {
        cerr << "Only specify an input and output text file. Try again..\n"<<endl;
        exit(1);
    }
	
	while(!readFile.eof()){												//reads the file until no integer left
		readFile >> intNum; 
		if(intNum < 0){													//error occurs when there exist a negative integer
			cout<<"Only positive integers!! Try again..."<<endl;		//outputs warning to user
			return 0;													//ends the program
		}
		else if(intNum > max){
			max = intNum;
		}
	}
	
	intArray = new int[max+1]();
	readFile.seekg(0, readFile.beg);
	
	while(!readFile.eof()){												//storing the count of each distinct integer into the dynamic array
		readFile >> intNum;												//retrieves the input integer
		++intArray[intNum];												//value stored at this array address is incremented by 1
	}	
	
	
	for(int i = 0; i < max+1; i++){										//traverses through the dynamic array
		writeFile << i << "\t" << intArray[i] <<endl;					//writes the count of each integer into an output file
	}
	
	readFile.close();
	writeFile.close();
	delete [] intArray;
	
	return 0;
	
}
