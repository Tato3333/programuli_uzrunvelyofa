#include <iostream>
#include <fstream>

using namespace std;
class Logger {
public:
    static void Log(const string& message) {
        Validate(message);
        cout << message << endl;
    }

    static void LogToFile(const string& message) {
        ofstream file("filename.txt");
        if (!file.is_open()) {
            throw runtime_error("Failed to open file.");
        }
        file << message;
    }

private:
    static void Validate(const string& message) {
        if (message.empty()) {
            throw invalid_argument("Message is empty.");
        }

        for (char c : message) {
            if (!(isalpha(c) || c == ' ')) {
                throw invalid_argument("Message contains invalid symbols.");
            }
        }
    }
};

int main() {
    try {
        Logger::Log("something is good thing");
        Logger::LogToFile("something is good thing");
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
}