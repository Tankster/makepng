// makepng.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <Windows.h>
#include "opencv2\opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	Mat input;
	std::string myFile, fileEnd, newFile;
	fileEnd = ".png";
	
	//Settings for saving PNG images. use Max compression
	vector<int> compr_params;
    compr_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compr_params.push_back(9);

	//Go through all files in argv[]
	for (int i = 1; i < argc; i++)
	{
		myFile = argv[i];
		//Load file as grayscale image
		cout << "Loading Image from: " << myFile << endl;
		input = imread(myFile, CV_LOAD_IMAGE_GRAYSCALE );

		//Remove file ending
		myFile.erase(myFile.end()-4,myFile.end());

		//Append new file ending (.png)
		newFile = myFile + fileEnd;

		//Save file as png (should now be true 1-channel 8-bit grayscale)
		cout << "Saving image as: " << newFile << endl;
		imwrite(newFile, input, compr_params);
	}

	return 0;
}

