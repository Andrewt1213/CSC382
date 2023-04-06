/*
 * Andrew Tapia
 */

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>

using namespace std;
class ProbableText {
    public:
    string theText;
    unordered_map<string , vector<char>> wordMap;
    string randomNgramStart;
    ProbableText (string bookName, int num) {
        theText = makeTheText(bookName);
        wordMap = createMap(theText, num);
        setInitialNgramRandomly();
    }

    //Reads the text into one big string and returns it
    string makeTheText(string fileName) {
        string the_text = "";
        ifstream inFile(fileName);
        string line;
        while (inFile.good()) {
            getline(inFile, line);
            the_text.append(line);
            the_text.append(" ");
        }
        inFile.close();
        return the_text;
    }

    // Returns the map of all possible ngrams and their following characters
    unordered_map<string, vector<char>> createMap(string fileAsString, int ngramSize) {
        unordered_map<string , vector<char>> ngramMap;
        int index = 0;
        while (index < (theText.size() - ngramSize)) {
            string textSnippet = theText.substr(index,ngramSize);
            if (!ngramMap.count(textSnippet)) {
                //key deos not exist. Add vector of chars
                vector<char> following_chars;
                ngramMap.insert({textSnippet, following_chars});
            }
            ngramMap.at(textSnippet).push_back(theText.at(index + ngramSize));
            index++;
        }
        return ngramMap;
    }

    //Chooses a random ngram to start at
    void setInitialNgramRandomly(){
        srand(time(nullptr));
        int stopIndex = rand() % wordMap.size();
        auto itr = wordMap.begin();
        advance(itr, stopIndex);
        randomNgramStart = itr->first;
    }

    //Starts from random ngram and creates text num times
    void printProbable(int num){
        srand(time(nullptr));
        cout << randomNgramStart;
        int characterCount = 0;
        string current_ngram = randomNgramStart;
        for (int i = 0; i < num; i++){
            vector<char> following_char = wordMap.at(current_ngram);
            int random_index = rand() % following_char.size();
            char printed_char = following_char.at(random_index);
            if (printed_char == ' ') {
                if (characterCount > 60) {
                    cout << endl;
                    characterCount = 0;
                }
            }
            cout << printed_char;
            characterCount++;
            current_ngram = current_ngram.substr(1) + printed_char;
        }
    }

};

int main() {
    ProbableText probText{"Alice.txt", 10};
    probText.printProbable(555);
    return 0;
}
