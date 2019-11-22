#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>

using namespace std;

#ifndef EXERCISES_FORMAT_DURATION_H
#define EXERCISES_FORMAT_DURATION_H

const int minuteLength = 60;
const int hourLength = 3600;
const int dayLength = 86400;
const int yearLength = 31536000;

string format_duration(int input);

int find_even_index (vector <int> numbers);

vector<int> snail(vector<vector<int>> snail_map);

int sockMerchant(int n, vector<int> ar);

int countingValleys(int n, string s);

int jumpingOnClouds(vector<int> c);

long repeatedString(string s, long n);

int read();

int hourglassSum(vector<vector<int>> arr);

vector<int> rotLeft(vector<int> a, int d);

void solve(double meal_cost, int tip_percent, int tax_percent);

void minimumBribes(vector<int> q);

void numbers();

void binary();



#endif //EXERCISES_FORMAT_DURATION_H
