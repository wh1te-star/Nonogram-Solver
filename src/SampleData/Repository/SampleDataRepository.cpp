#include "SampleData/Repository/SampleDataRepository.h"

#include "Hint/HintNumber/HintNumber.h"
#include <cassert>
#include <sstream>

std::vector<std::vector<HintNumber>>
SampleDataRepository::parseHints(const std::string &hintString) {
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

RowHintSetList SampleDataRepository::getRowHintSetList(SampleDataType type) {
  std::string rowHintNumbersString = GetRowHintString(type);
  std::vector<std::vector<HintNumber>> tempRowHintNumbers =
      parseHints(rowHintNumbersString);

  std::vector<HintSet> HintSetListVector;
  for (int k = 0; k < tempRowHintNumbers.size(); k++) {
    std::vector<HintNumber> HintSetVector;
    for (int i = 0; i < tempRowHintNumbers[k].size(); i++) {
      if (tempRowHintNumbers[k][i] == HintNumber(0))
        continue;
      HintSetVector.push_back(tempRowHintNumbers[k][i]);
    }
    HintSetListVector.emplace_back(HintSetVector);
  }

  RowHintSetList rowHintSetList(HintSetListVector);
  return rowHintSetList;
}

ColumnHintSetList
SampleDataRepository::getColumnHintSetList(SampleDataType type) {
  std::string columnHintNumbersString = GetColumnHintString(type);
  std::vector<std::vector<HintNumber>> tempColumnHintNumbers =
      parseHints(columnHintNumbersString);

  std::vector<HintSet> HintSetListVector;
  for (int k = 0; k < tempColumnHintNumbers[0].size(); k++) {
    std::vector<HintNumber> HintSetVector;
    for (int i = 0; i < tempColumnHintNumbers.size(); i++) {
      if (tempColumnHintNumbers[i][k] == HintNumber(0))
        continue;
      HintSetVector.push_back(tempColumnHintNumbers[i][k]);
    }
    HintSetListVector.emplace_back(HintSetVector);
  }

  ColumnHintSetList columnHintSetList(HintSetListVector);
  return columnHintSetList;
}

std::string SampleDataRepository::GetRowHintString(SampleDataType type) {
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

std::string SampleDataRepository::GetColumnHintString(SampleDataType type) {
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
