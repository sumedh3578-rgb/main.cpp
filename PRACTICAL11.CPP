#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Student {
    int id;
    std::string name;
    float marks;
};

// 1. Write Student Records to CSV
void writeCSV(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream outFile(filename, std::ios::out);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing!\n";
        return;
    }

    // CSV Header
    outFile << "ID,Name,Marks\n";

    // Write Records
    for (const auto& student : students) {
        outFile << student.id << "," << student.name << "," << student.marks << "\n";
    }

    outFile.close();
    std::cout << "Successfully written " << students.size() << " records to " << filename << "\n";
}

// 2. Read Student Records from CSV
void readCSV(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::in);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading!\n";
        return;
    }

    std::string line;
    // Skip Header
    std::getline(inFile, line);

    std::cout << "\n--- Student Records Read from CSV ---\n";
    std::cout << "ID\tName\t\tMarks\n";
    std::cout << "-----------------------------------\n";

    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string idStr, name, marksStr;

        if (std::getline(ss, idStr, ',') &&
            std::getline(ss, name, ',') &&
            std::getline(ss, marksStr, ',')) {

            int id = std::stoi(idStr);
            float marks = std::stof(marksStr);
            std::cout << id << "\t" << name << "\t\t" << marks << "\n";
        }
    }

    inFile.close();
}

// 3. Demonstrate seekg(), seekp(), tellg(), and tellp()
void demonstrateFilePointers(const std::string& demoFilename) {
    std::cout << "\n===================================\n";
    std::cout << " Demonstrating File Position Pointers\n";
    std::cout << "===================================\n";

    // --- Output Stream (tellp and seekp) ---
    std::ofstream outFile(demoFilename, std::ios::out | std::ios::trunc);
    std::cout << "[Write] Initial tellp() position: " << outFile.tellp() << "\n";

    outFile << "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::cout << "[Write] tellp() after writing 26 chars: " << outFile.tellp() << "\n";

    // Move put pointer back to index 10 and write '#'
    outFile.seekp(10, std::ios::beg);
    std::cout << "[Write] tellp() after seekp(10, beg): " << outFile.tellp() << "\n";
    outFile << '#';

    outFile.close();

    // --- Input Stream (tellg and seekg) ---
    std::ifstream inFile(demoFilename, std::ios::in);
    std::cout << "\n[Read] Initial tellg() position: " << inFile.tellg() << "\n";

    char ch;
    inFile.get(ch);
    std::cout << "[Read] First char: '" << ch << "', tellg(): " << inFile.tellg() << "\n";

    // Seek get pointer to character index 10
    inFile.seekg(10, std::ios::beg);
    std::cout << "[Read] tellg() after seekg(10, beg): " << inFile.tellg() << "\n";
    inFile.get(ch);
    std::cout << "[Read] Char at index 10: '" << ch << "' (overwritten char)\n";

    // Seek to end of file to get file size
    inFile.seekg(0, std::ios::end);
    std::cout << "[Read] File size measured via seekg(0, end) & tellg(): " << inFile.tellg() << " bytes\n";

    inFile.close();
}

int main() {
    std::string csvFilename = "students.csv";
    std::string demoFilename = "pointer_demo.txt";

    // Sample Student Data
    std::vector<Student> students = {
        {101, "Alice", 88.5f},
        {102, "Bob",   92.0f},
        {103, "Charlie", 79.4f}
    };

    // Step 1: Write CSV File
    writeCSV(csvFilename, students);

    // Step 2: Read CSV File
    readCSV(csvFilename);

    // Step 3: Demonstrate seekg, seekp, tellg, tellp
    demonstrateFilePointers(demoFilename);

    return 0;
}
