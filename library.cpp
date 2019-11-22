#include "library.h"

string format_duration(int input) {
    if (input == 0) return "now";
    int lastIndex = 0;
    int values[5];
    string keys[5] = {"year", "day", "hour", "minute", "second"};

    *values = input / yearLength;

    if (*values != 0) {
        *(values + 1) = (input % (*values * yearLength)) / dayLength;
    } else {
        *(values + 1) = input / dayLength;
    }

    if (((*(values + 1) * dayLength) + (*values * yearLength)) != 0) {
        *(values + 2) = (input % ((*(values + 1) * dayLength) + (*values * yearLength))) / hourLength;
    } else {
        *(values + 2) = input / hourLength;
    }

    if (((*(values + 2) * hourLength) + (*(values + 1) * dayLength) + (*values * yearLength)) != 0) {
        *(values + 3) = (input % ((*(values + 2) * hourLength) + (*(values + 1) * dayLength) + (*values * yearLength))) / minuteLength;
    } else {
        *(values + 3) = input / minuteLength;
    }

    if (((*(values + 3) * minuteLength) + (*(values + 2) * hourLength) + (*(values + 1) * dayLength) + (*values * yearLength)) != 0) {
        *(values + 4) = (input % ((*(values + 3) * minuteLength) + (*(values + 2) * hourLength) + (*(values + 1) * dayLength) + (*values * yearLength)));
    } else {
        *(values + 4) = input;
    }

    for (int i = 0; i < 5; i++) {
        if (*(values+i) > 0) {
            lastIndex = i;
        }
    }

    string result;
    for (int i = 0; i < 5; i++) {
        int value = *(values + i);
        if (value != 0) {
            if (!result.empty() && lastIndex == i) {
                result += " and ";
            } else if (!result.empty()) {
                result += ", ";
            }
            result += to_string(value) + " " + *(keys + i);
            if (value > 1) result += "s";
        }
    }

    return result;
}


int find_even_index (const vector <int> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        int end = numbers.size() - i;
        int first = accumulate(numbers.begin(), numbers.end() - end, 0);
        int last = accumulate(numbers.begin() + i + 1, numbers.end(), 0);
        if (first == last) return i;
    }
    return -1;
}

vector<int> snail(vector<vector<int>> snail_map) {
    vector<int> ret;

    if (snail_map.empty()) {
        return ret;
    } else if (snail_map.size() == 1) {
        return snail_map.at(0);
    } else {
        ret.insert(ret.end(), snail_map.at(0).begin(), snail_map.at(0).end());

        for (int i = 1; i < snail_map.size() - 1; i++) {
            vector<int> inner = snail_map.at(i);
            ret.insert(ret.end(), inner.at(inner.size()-1));
        }

        reverse(snail_map.at(snail_map.size() - 1).begin(), snail_map.at(snail_map.size() - 1).end());
        ret.insert(ret.end(), snail_map.at(snail_map.size() - 1).begin(), snail_map.at(snail_map.size() - 1).end());

        for (int i = snail_map.size() - 2; i > 0; i--) {
            vector<int> inner = snail_map.at(i);
            ret.insert(ret.end(), inner.at(0));
        }
        vector<vector<int>> dummy;
        for (int i = 1; i < snail_map.size() - 1; i++) {
            vector<int>::const_iterator first = snail_map.at(i).begin() + 1;
            vector<int>::const_iterator last = snail_map.at(i).begin() + snail_map.at(i).size() - 1;
            vector<int> newVec(first, last);
            dummy.insert(dummy.end(), newVec);
        }

        vector<int> inner_ret = snail(dummy);

        ret.insert(ret.end(), inner_ret.begin(), inner_ret.end());
    }

    return ret;
}

int sockMerchant(int n, vector<int> ar) {
    map<int, int> values;
    int result = 0;
    for (auto number : ar) {
        if (values.count(number)) {
            values[number]++;
        } else {
            values.insert(pair<int, int>(number, 1));
        }
    }
    for (auto value : values) {
        result += value.second / 2;
    }
    return result;
}

int countingValleys(int n, string s) {
    int level = 0;
    int result = 0;
    bool is_mnt = false;
    for (char ch : s) {
        is_mnt = level > 0;
        if (ch == 'U') level++;
        if (ch == 'D') level--;
        if (level == 0 && !is_mnt) result++;
    }

    return result;
}

int jumpingOnClouds(vector<int> c) {
    int result = 0;
    for (int i = 0; i < c.size(); i++) {
        if (c[i] != 1 && i != 0) result++;
        if (i < c.size()-2 && c[i+2] != 1) {
            i++;
        }
    }
    return result;
}

long repeatedString(string s, long n) {
    int length = s.length();
    int count = 0;
    int tailCount = 0;
    string tail = s.substr(0, n % length);
    for (char ch : s) {
        if (ch == 'a') count ++;
    }
    for (char ch : tail) {
        if (ch == 'a') tailCount ++;
    }

    return (n / length) * count + tailCount;
}

int read() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";


    // Declare second integer, double, and String variables.
    int i2;
    double d2;
    string s2;


    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    cin >> i2;
    cin >> d2;
    getline(cin >> ws, s2);

    // Print the sum of both integer variables on a new line.
    cout << i + i2 << endl;
    // Print the sum of the double variables on a new line.
    printf("%.1lf\n",d+d2);
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout << s + s2;
    return 0;
}

int hourglassSum(vector<vector<int>> arr) {
    int result = -100;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            int dummy = arr.at(i).at(j) + arr.at(i).at(j+1) + arr.at(i).at(j+2)
                        + arr.at(i+1).at(j+1)
                        + arr.at(i+2).at(j) + arr.at(i+2).at(j+1) + arr.at(i+2).at(j+2);

            if (dummy > result) result = dummy;
        }
    }

    return result;
}

vector<int> rotLeft(vector<int> a, int d) {
    vector<int> result;
    result.insert(result.begin(), a.begin() + d, a.end());
    result.insert(result.end(), a.begin(), a.begin() + d);
    return result;
}

void solve(double meal_cost, int tip_percent, int tax_percent) {
    cout << nearbyint(meal_cost + (meal_cost * (tip_percent / 100.0)) + (meal_cost * (tax_percent / 100.0)));
}

void minimumBribes(vector<int> q) {
    vector<int> dummy = {0};
    for (int i = 0; i < q.size(); i++) {
        if (q.at(i) - i - 1 > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
    }

    set<int> s;
    vector<int> countSmaller;
    for (int i = q.size() - 1; i >= 0; i--) {
        s.insert(q[i]);
        auto it = s.lower_bound(q[i]);
        countSmaller.insert(countSmaller.end(), distance(s.begin(), it));
    }

    cout << accumulate(countSmaller.begin(), countSmaller.end(), 0) << endl;
}

void numbers() {
    map<string, string> numbers;
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; i++) {
        string name, number;
        cin >> name;
        cin >> number;
        numbers.insert(pair<string, string>(name, number));
    }

    string line;
    while(getline(cin >> ws,line))
    {
        if (line.empty())
            break;
        if (numbers.find(line) == numbers.end()) {
            cout << "Not found" << endl;
        } else {
            std::cout << numbers.find(line)->first << "=" << numbers.find(line)->second << endl;
        }
    }
}

void binary() {
    int n = 0;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int max = 0;
    int current = 0;

    while (n > 0) {
        if (n % 2) {
            current++;
        } else {
            current = 0;
        }
        if (current > max) max = current;
        n /= 2;
    }

    cout << max << endl;
}
