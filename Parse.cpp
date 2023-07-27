#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    // Step 1: Create and write to the input.txt file
    std::string inputFilename = "input.txt";
    std::ofstream inputFile(inputFilename);
    
    if (!inputFile.is_open()) {
        std::cerr << "Failed to create the input file." << std::endl;
        return 1;
    }
    
    inputFile << "Step,DUT,Leader,Packet No.,test result" << std::endl;
    inputFile << "step1,Leader sends MLE Advertisements Packet to Router with IP Hop limit = 255,1,Pass" << std::endl;
    inputFile << "step2,Leader issue MLE Parent Response Packet to Router,3,Pass" << std::endl;
    inputFile << "step3,Leader issue Child ID Response Packet to Router with following TLVs:,9,Pass" << std::endl;
    inputFile << "step4,Leader sends an Address Solicit Reply Packet to Router with following format: CoAP Code: 2.04 Changed (68),13,Pass" << std::endl;
    inputFile << "step5,Leader sends an unicast Link Accept Message to Router,47,Pass" << std::endl;
    inputFile << "step6,Ping sent from Router,98,Pass" << std::endl;
    inputFile << ",DUT,Router,," << std::endl;
    inputFile << "step1,Router sends a MLE Parent request with Ip Hop limit = 255,7,Pass" << std::endl;
    inputFile << "step2,Router sends a unicast MLE Child ID Request to Leader,10,Pass" << std::endl;
    inputFile << "step3,Router sends an Address Solicit Request,14,Pass" << std::endl;
    inputFile << "step4,Router send a multicast link request to Leader,18,Pass" << std::endl;
    inputFile << "step5,Router send MLE Advertisements to Leader with IP Hop limit = 255,23,Pass" << std::endl;
    inputFile << "step6,Ping sent from Leader,33,Pass" << std::endl;
    inputFile.close();
    
    std::cout << "input.txt created and written successfully." << std::endl;

    // Step 2: Read content from input.txt
    std::vector<std::string> lines;
    std::ifstream inputFileToRead(inputFilename);

    if (!inputFileToRead.is_open()) {
        std::cerr << "Failed to open the input file for reading." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFileToRead, line)) {
        lines.push_back(line);
    }

    inputFileToRead.close();

    // Step 3: Write the content to output.csv
    std::string csvFilename = "output.csv";
    std::ofstream csvFile(csvFilename);

    if (!csvFile.is_open()) {
        std::cerr << "Failed to create the output CSV file." << std::endl;
        return 1;
    }

    for (const std::string& line : lines) {
        csvFile << line << std::endl;
    }

    csvFile.close();

    std::cout << "Content written to output.csv successfully." << std::endl;

    return 0;
}
