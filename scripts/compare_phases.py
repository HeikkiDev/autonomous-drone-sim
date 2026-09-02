import csv
import sys
from pathlib import Path

# TODO: load per-phase CSVs from data/results and print/plot comparative metrics
# (e.g. RMSE of measurement vs estimate, phase 7 vs phase 8 tracking error).


def main(argv: list[str]) -> int:
    raise NotImplementedError("TODO: implement phase comparison")


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
