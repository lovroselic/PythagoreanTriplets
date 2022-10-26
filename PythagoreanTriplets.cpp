// https://www.codeabbey.com/index/task_view/pythagorean-triples
// https://algoexplode.wordpress.com/2013/07/24/special-pythagorean-triplet-project-euler-problem-9/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include <cmath>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION 1

using namespace std;

long long int PythagoreanTriplets(long long int s);

int main()
{
	cout << "PythagoreanTriplets v" << VERSION << "!\n\n";
	//string path = "TestData.txt";
	string path = "ProblemData.txt";
	vector<string> raw_data = loadData(path);
	//printVector(raw_data);
	vector<long long int> solution;
	for (int i = 1; i < raw_data.size(); i++) {
		solution.push_back(PythagoreanTriplets(stoi(raw_data.at(i))));
	}
	string finalSolution = joinVector(solution, " ");
	cout << "solution: " << finalSolution << endl;
}

long long int PythagoreanTriplets(long long int s) {
	for (long long int a = 2; a < s; a++) {
		if ((s * s - 2 * s * a) % (2 * s - 2 * a) == 0) {
			long long int b = (s * s - 2 * s * a) / (2 * s - 2 * a);
			return a * a + b * b;
		}
	}

	return 0;
}

