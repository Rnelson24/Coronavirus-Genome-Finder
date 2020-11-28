#include <iostream>
#include <fstream> //filestream
#include <vector>
#include <algorithm>
using namespace std;

long lcs_lengths(string x, string y, long m, long n) {

    //let c[0..m, 0..n] be new tables
    //for i = 1 to m
    //   c[i,0] = 0
    //for j = 0 to n
    //   c[0,j] = 0
    //for i = 1 to m
    //   for j = 1 to n
    //       if xi == yj
    //          c[i,j] = c[i-1, j-1] + 1
    //       else if c[i-1, j] >= c[i, j-1]
        //          c[i,j] = c[i-1,j]
        //       else c[i,j] = c[i,j-1]
    //return the length of LCS

    std::vector<std::vector<int>> c;
    c.resize(m + 10, std::vector<int>(n + 10, 0));
    
    std::ofstream ofs("LCS-output.txt");
        for (int i = 0 ; i<= m ; i++){
            ofs << endl;
            for (int j =0; j<=n; j++){
                ofs << c[i][j] << " ";
            }
        }

    return 0; 
}


int main(int argc, const char* argv[]) {
    long size_str1, size_str2;

    //reads file content into string
    std::ifstream dataFile("sequence1.txt"); // replace the file name with other sequences
    std::string string1((std::istreambuf_iterator<char>(dataFile)),
        (std::istreambuf_iterator<char>()));

    std::ifstream dataFile2("coronavirus_genome.txt");
    std::string string2((std::istreambuf_iterator<char>(dataFile2)),
        (std::istreambuf_iterator<char>()));

    //remove new line and other white spaces from string
    string1.erase(std::remove(string1.begin(), string1.end(), '\n'), string1.end());
    string1.erase(std::remove(string1.begin(), string1.end(), '\r'), string1.end());
    string1.erase(std::remove(string1.begin(), string1.end(), ' '), string1.end());
    string2.erase(std::remove(string2.begin(), string2.end(), '\n'), string2.end());
    string2.erase(std::remove(string2.begin(), string2.end(), '\r'), string2.end());
    string2.erase(std::remove(string2.begin(), string2.end(), ' '), string2.end());


   
    size_str1 = string1.size() - 1;
    size_str2 = string2.size() - 1;

    
    cout << "Length of the first string is: " << size_str1 << endl;
    cout << "Length of the second string is: " << size_str2 << endl;
    cout << "LCS of the first and second string is: ";

    cout << lcs_lengths(string1, string2, size_str1, size_str2) << endl;

    return 0;
}
