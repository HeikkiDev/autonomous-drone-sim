#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace visualization {

// Streams simulation rows to a CSV file.
class DataLogger {
public:
    DataLogger(const std::string& file_path, const std::vector<std::string>& columns);
    ~DataLogger();

    // Row size must match the header column count.
    void logRow(const std::vector<double>& values);

    void flush();
    void close();
    const std::string& filePath() const;

private:
    std::string file_path_;
    std::vector<std::string> columns_;
    std::ofstream stream_;
};

}  // namespace visualization
