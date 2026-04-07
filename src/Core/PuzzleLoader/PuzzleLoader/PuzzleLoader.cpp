#include "Core/PuzzleLoader/PuzzleLoader/PuzzleLoader.h"

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Hint/HintNumber/HintNumber.h"

#include <cassert>
#include <sstream>

namespace VersaNo::Core {

NonogramBoard PuzzleLoader::getPuzzle(PuzzleType type) {
    RowHintGroup rowHintGroup = getRowHintGroup(type);
    ColumnHintGroup columnHintGroup = getColumnHintGroup(type);
    return NonogramBoard(
      Board(RowLength(rowHintGroup.size()), ColumnLength(columnHintGroup.size())), rowHintGroup,
      columnHintGroup);
}

RowHintGroup PuzzleLoader::getRowHintGroup(PuzzleType type) {
    std::string rowHintNumbersString = GetRowHintString(type);
    std::vector<std::vector<HintNumber>> tempRowHintNumbers = parseHints(rowHintNumbersString);

    std::vector<HintList> HintGroupVector;
    for (int k = 0; k < tempRowHintNumbers.size(); k++) {
        std::vector<HintNumber> HintListVector;
        for (int i = 0; i < tempRowHintNumbers[k].size(); i++) {
            if (tempRowHintNumbers[k][i] == HintNumber(0))
                continue;
            HintListVector.push_back(tempRowHintNumbers[k][i]);
        }
        HintGroupVector.emplace_back(HintListVector);
    }

    RowHintGroup rowHintGroup(HintGroupVector);
    return rowHintGroup;
}

ColumnHintGroup PuzzleLoader::getColumnHintGroup(PuzzleType type) {
    std::string columnHintNumbersString = GetColumnHintString(type);
    std::vector<std::vector<HintNumber>> tempColumnHintNumbers = parseHints(
      columnHintNumbersString);

    std::vector<HintList> HintGroupVector;
    for (int k = 0; k < tempColumnHintNumbers[0].size(); k++) {
        std::vector<HintNumber> HintListVector;
        for (int i = 0; i < tempColumnHintNumbers.size(); i++) {
            if (tempColumnHintNumbers[i][k] == HintNumber(0))
                continue;
            HintListVector.push_back(tempColumnHintNumbers[i][k]);
        }
        HintGroupVector.emplace_back(HintListVector);
    }

    ColumnHintGroup columnHintGroup(HintGroupVector);
    return columnHintGroup;
}

std::vector<std::vector<HintNumber>> PuzzleLoader::parseHints(const std::string &hintString) {
    std::vector<std::vector<HintNumber>> hintMatrix;
    std::stringstream ss(hintString);
    std::string line;

    const char *whitespace = " \t\n\r\f\v";

    while (std::getline(ss, line)) {
        line.erase(0, line.find_first_not_of(whitespace));
        line.erase(line.find_last_not_of(whitespace) + 1);

        if (line.empty()) {
            continue;
        }

        std::vector<HintNumber> row;
        std::stringstream line_ss(line + ',');
        std::string cell;

        while (std::getline(line_ss, cell, ',')) {
            cell.erase(0, cell.find_first_not_of(whitespace));
            cell.erase(cell.find_last_not_of(whitespace) + 1);

            if (cell.empty()) {
                row.emplace_back(0);
            } else {
                row.emplace_back(std::stoi(cell));
            }
        }
        hintMatrix.push_back(row);
    }
    return hintMatrix;
}

std::string PuzzleLoader::GetRowHintString(PuzzleType type) {
    switch (type) {
    case Easy:
        return GetEasyRowHintString();
    case Lambda:
        return GetLambdaRowHintString();
    case Large:
        return GetLargeRowHintString();
    case Difficult:
        return GetDifficultRowHintString();
    default:
        assert(false);
    }
    return "";
}

std::string PuzzleLoader::GetColumnHintString(PuzzleType type) {
    switch (type) {
    case Easy:
        return GetEasyColumnHintString();
    case Lambda:
        return GetLambdaColumnHintString();
    case Large:
        return GetLargeColumnHintString();
    case Difficult:
        return GetDifficultColumnHintString();
    default:
        assert(false);
    }
    return "";
}

std::string PuzzleLoader::GetEasyRowHintString() {
    return
#include "Core/PuzzleLoader/Assets/EasyRow.inc"
      ;
}

std::string PuzzleLoader::GetEasyColumnHintString() {
    return
#include "Core/PuzzleLoader/Assets/EasyColumn.inc"
      ;
}

std::string PuzzleLoader::GetLambdaRowHintString() {
    return
#include "Core/PuzzleLoader/Assets/LambdaRow.inc"
      ;
}

std::string PuzzleLoader::GetLambdaColumnHintString() {
    return
#include "Core/PuzzleLoader/Assets/LambdaColumn.inc"
      ;
}

std::string PuzzleLoader::GetLargeRowHintString() {
    return
#include "Core/PuzzleLoader/Assets/LargeRow.inc"
      ;
}

std::string PuzzleLoader::GetLargeColumnHintString() {
    return
#include "Core/PuzzleLoader/Assets/LargeColumn.inc"
      ;
}

std::string PuzzleLoader::GetDifficultRowHintString() {
    return
#include "Core/PuzzleLoader/Assets/DifficultRow.inc"
      ;
}

std::string PuzzleLoader::GetDifficultColumnHintString() {
    return
#include "Core/PuzzleLoader/Assets/DifficultColumn.inc"
      ;
}

} // namespace VersaNo::Core