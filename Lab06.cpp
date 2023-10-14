// Chad Huntebrinker
// crh92d@umsystem.edu
// 10/1/20
// CS201L Lab 06

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

double calcDistance(double x1, double x2, double y1, double y2, double z1, double z2);

int main() {
	vector<int> vectorX;
	vector<int> vectorY;
	vector<int> vectorZ;
	vector<double> vectorTotal;
	double x1, x2, y1, y2, z1, z2, totalAnswer, temp;
	int i, j, totalElements = 0;
	ifstream fin("input.txt");
	ofstream fout("output_before_sorted.txt");
	ofstream finalOut("output_sorted.txt");

	/* 
	This while loop will continue executing until it runs out of file input lines.
	The int totalElements is calculated twice to get the total number of elements on each line in the file (2 elements per line).
	If file line is empty, then the output file will read 0. 
	*/

	while (fin.good()) {
		x1 = 0, x2 = 0, y1 = 0, y2 = 0, z1 = 0, z2 = 0;
		fin >> x1;
		fin >> y1;
		fin >> z1;
		++totalElements;
		fin >> x2;
		fin >> y2;
		fin >> z2;
		++totalElements;
		vectorX.push_back(x1);
		vectorX.push_back(x2);
		vectorY.push_back(y1);
		vectorY.push_back(y2);
		vectorZ.push_back(z1);
		vectorZ.push_back(z2);
	}
	i = 0;
	/* 
	This while loop feeds into the calDistance function.
	i is incremented twice so that it gets both x, y, and z values per line (2 values per line).
	After the function calculates it's answer, the function will store the answer in the double totalAnswer which
	then stores it in the vector named vectorTotal.
	*/
	while (i < totalElements) {
		totalAnswer = 0;
		x1 = vectorX.at(i);
		y1 = vectorY.at(i);
		z1 = vectorZ.at(i);
		++i;
		x2 = vectorX.at(i);
		y2 = vectorY.at(i);
		z2 = vectorZ.at(i);
		++i;
		totalAnswer = calcDistance(x1, x2, y1, y2, z1, z2);
		vectorTotal.push_back(totalAnswer);
	}
	// This for loop outputs the vectorTotal elements into the file "output_before_sorted.txt".

	for (i = 0; i < totalElements / 2; ++i) {
		fout << vectorTotal.at(i) << endl;
	}
	
	/* 
	These loops do the sorting via Insertion Sort.
	It is sorted smallest near the front of the vector in places like 0 or 1 and bigger values
	near the back of the vector in places like 4 or 5.
	*/
	for (i = 1; i < totalElements / 2; ++i) {
		j = i;
			while (j > 0 && vectorTotal.at(j) < vectorTotal.at(j - 1)) {
				temp = vectorTotal.at(j);
				vectorTotal.at(j) = vectorTotal.at(j - 1);
				vectorTotal.at(j - 1) = temp;
				--j;
			}
	}
	// This for loop outputs the vectorTotal elements into the file "output_sorted.txt"
	for (i = 0; i < totalElements / 2; ++i) {
		finalOut << vectorTotal.at(i) << endl;
	}
	return 0;
}
/* 
This function calculates the distance with the parameter values x1, x2, y1, y2, z1, and z2 from the main().
It firsts subtracts both values, then it squares them by multiplying it by itself (totalX * totalX).
It then takes the square root of the answer and puts that value back into the function.
*/
double calcDistance(double x1, double x2, double y1, double y2, double z1, double z2) {
	double totalX, totalY, totalZ, answer;
	totalX = x1 - x2;
	totalY = y1 - y2;
	totalZ = z1 - z2;
	
	totalX = totalX * totalX;
	totalY = totalY * totalY;
	totalZ = totalZ * totalZ;

	answer = totalX + totalY + totalZ;
	answer = sqrt(answer);
	return answer;

}