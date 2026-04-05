#ifndef VERSANO_CORE_PUZZLELOADER_H
#define VERSANO_CORE_PUZZLELOADER_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Hint/HintNumber/HintNumber.h"
#include "Core/Hint/HintSetList/ColumnHintSetList.h"
#include "Core/Hint/HintSetList/RowHintSetList.h"

#include <string>
#include <vector>

namespace VersaNo::Core {

class PuzzleLoader {
  public:
    enum PuzzleType { Easy, Lambda, Large, Difficult };

    static NonogramBoard getPuzzle(PuzzleType type);

  private:
    PuzzleLoader() = delete;

    static RowHintSetList getRowHintSetList(PuzzleType type);
    static ColumnHintSetList getColumnHintSetList(PuzzleType type);
    static std::vector<std::vector<HintNumber>> parseHints(const std::string &hintString);

    static std::string GetRowHintString(PuzzleType type);
    static std::string GetColumnHintString(PuzzleType type);

  private:
    static std::string GetEasyRowHintString();
    static std::string GetEasyColumnHintString();
    static std::string GetLambdaRowHintString();
    static std::string GetLambdaColumnHintString();
    static std::string GetLargeRowHintString();
    static std::string GetLargeColumnHintString();
    static std::string GetDifficultRowHintString();
    static std::string GetDifficultColumnHintString();
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_PUZZLELOADER_H
