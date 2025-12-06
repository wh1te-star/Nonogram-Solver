#ifndef SAMPLEDATAREPOSITORY_H
#define SAMPLEDATAREPOSITORY_H

#include <string>
#include <vector>
#include "HintNumber.h"
#include "RowHintSetList.h"
#include "ColumnHintSetList.h"

class SampleDataRepository {
public:
    enum SampleDataType { Easy, Lambda, Large, Difficult };

private:
    SampleDataRepository() = delete;

    static std::string GetColumnHintString(SampleDataType type);
    static std::string GetRowHintString(SampleDataType type);
    static std::string GetEasyRowHintString();
    static std::string GetEasyColumnHintString();
    static std::string GetLambdaRowHintString();
    static std::string GetLambdaColumnHintString();
    static std::string GetLargeRowHintString();
    static std::string GetLargeColumnHintString();
    static std::string GetDifficultRowHintString();
    static std::string GetDifficultColumnHintString();
    
    static std::vector<std::vector<HintNumber>> parseHints(const std::string& hintString);

public:
    static RowHintSetList getRowHintSetList(SampleDataType type);
    static ColumnHintSetList getColumnHintSetList(SampleDataType type);
};

#endif
