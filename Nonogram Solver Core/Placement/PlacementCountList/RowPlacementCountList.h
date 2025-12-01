#ifndef ROWPLACEMENTCOUNTLIST_H
#define ROWPLACEMENTCOUNTLIST_H


#include "PlacementCountList.h"
#include "PlacementCount.h"
#include "RowIndex.h"

class RowPlacementCountList : public PlacementCountList {
public:
    explicit RowPlacementCountList(std::vector<PlacementCount> placementCountList);

public:
    const PlacementCount& operator[](RowIndex index) const; 
    PlacementCount& operator[](RowIndex index); 
};


#endif
