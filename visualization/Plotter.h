#pragma once

#include <string>
#include <vector>

namespace visualization {

// One CSV column pair rendered as a line/point series.
struct Series {
    std::string label;
    int x_column{1};  // 1-based gnuplot column index
    int y_column{2};
    std::string style{"lines"};  // "lines", "points", "linespoints"
};

// Generates gnuplot scripts from logged CSV files (and optionally runs gnuplot).
class Plotter {
public:
    Plotter(const std::string& csv_path, const std::string& output_png_path);

    void setTitle(const std::string& title);
    void setAxisLabels(const std::string& x_label, const std::string& y_label);
    void addSeries(const Series& series);

    // Writes a .gnuplot script; returns its path.
    std::string writeScript(const std::string& script_path) const;

    // Invokes gnuplot on the generated script. Returns false if gnuplot is absent.
    bool render(const std::string& script_path) const;

private:
    std::string csv_path_;
    std::string output_png_path_;
    std::string title_;
    std::string x_label_{"x"};
    std::string y_label_{"y"};
    std::vector<Series> series_;
};

}  // namespace visualization
