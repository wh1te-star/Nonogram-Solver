#ifndef VERSANO_CORE_PUZZLELOADER_H
#define VERSANO_CORE_PUZZLELOADER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Hint/HintGroup/ColumnHintGroup.h"
#include "Core/Hint/HintGroup/RowHintGroup.h"

#include <string>
#include <vector>

namespace VersaNo::Core {

class PuzzleLoader {
  public:
    enum PuzzleType { Easy, Lambda, Large, Difficult };

    static NonogramBoard getPuzzle(PuzzleType type);

  private:
    PuzzleLoader() = delete;

    static RowHintGroup getRowHintGroup(PuzzleType type);
    static ColumnHintGroup getColumnHintGroup(PuzzleType type);
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
