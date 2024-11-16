#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <QDebug>
using namespace std;

class JsonParser {
public:
    static vector<string> parseWordsFromJson(const string& filePath) {
        ifstream file(filePath);
        if (!file.is_open()) {
            qDebug() << "File not found at" << QString::fromStdString(filePath);
            return {};
        }

        vector<string> words;
        string line, word;
        bool inKey = false;

        while (getline(file, line)) {
            for (char ch : line) {
                if (ch == '"') {
                    inKey = !inKey;
                    if (!inKey && !word.empty()) {
                        words.push_back(word);
                        word.clear();
                    }
                } else if (inKey) {
                    word += ch;
                }
            }
        }

        return words;
    }
};

#endif // JSONPARSER_H
