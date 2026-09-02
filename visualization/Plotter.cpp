#include "Plotter.h"

namespace visualization {

// TODO(phase4): implement constructor and the simple setters.
// TODO(phase4): writeScript() -> emit a gnuplot script:
//                 set datafile separator ","
//                 set terminal pngcairo size 1200,800
//                 set output "<png>"
//                 set title/xlabel/ylabel/grid/key
//                 plot "<csv>" every ::1 using X:Y with <style> title "<label>", ...
// TODO(phase4): render() -> run `gnuplot <script>` via std::system and report success.
//               Keep script generation separate from rendering so it stays testable
//               on machines without gnuplot installed.

}  // namespace visualization
