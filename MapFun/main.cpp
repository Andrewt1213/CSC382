/**
 * CSC 382
 * nGram Map Assignment
 * Author: Andrew Tapia
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <map>

using namespace std;

// Read all lines in the book and append them to the one big string object.
// A space is added at the end of each line to avoid having the last word
// on a line be appended to the first word on the next line.
string makeTheText(string fileName) {
    string the_text = "";
    ifstream inFile("Alice.txt");
    string line;
    while (inFile.good()) {
        getline(inFile, line);
        the_text.append(line);
        the_text.append(" ");
    }
    inFile.close();
    return the_text;
}

// Return a vector of all characters in theText that immediately
// follow the ngram. For example, if ngram is "th" and theText is
// "the true try the truth", the return vector should have the
// characters 'e' and 'e'. Stop looking ngram.length()
// characters from the end to avoid an exception.
vector<char> followers(string ngram, const string &theText) {
    vector<char> following_chars;
    int index = 0;
    while (index < (theText.size() - ngram.size())) {
        if (theText.substr(index, ngram.size()) == ngram) {
            following_chars.push_back(theText.at(index + ngram.size()));
        }
        index++;
    }
    return following_chars;
}



int main() {
    string theBook = makeTheText("Alice.txt");
    vector<char> followersOfAlic = followers("Alic", theBook);
    vector<char> followersOfpic = followers("pic", theBook);
    vector<char> followersOfeel = followers("eel", theBook);


    unordered_map<string, vector<char>> followers;
    followers.insert({"pic", followersOfpic});
    followers.insert({"eel", followersOfeel});
    followers.insert({"Alic", followersOfAlic});
    cout << "The map: " << endl;

    for (auto itr = followers.begin(); itr != followers.end(); itr++) {
        cout << itr->first << ": ";
        for (auto letter: itr->second) {
            cout << letter << ", ";
        }
        cout << endl;
    }
    return 0;
}
