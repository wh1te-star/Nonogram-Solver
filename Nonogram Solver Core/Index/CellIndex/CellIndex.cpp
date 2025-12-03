#include "CellIndex.h"

#include <cassert>
#include "BoardLength.h"
#include "RowIndex.h"
#include "ColumnIndex.h"

CellIndex::CellIndex(int index) : index(index) {}
CellIndex::CellIndex(int index, CellIndexType type) : index(index), type(type) {}

int CellIndex::getIndex() const
{
	return index;
}

CellIndexType CellIndex::getType() const
{
	return type;
}

RowIndex CellIndex::toRowIndex() const
{
	assert(type != CellIndexType::Column);
	return RowIndex(index);
}

ColumnIndex CellIndex::toColumnIndex() const
{
	assert(type != CellIndexType::Row);
	return ColumnIndex(index);
}

CellIndex CellIndex::operator+(int shift) const
{
	return CellIndex(index + shift);
}

CellIndex CellIndex::operator-(int shift) const
{
	return CellIndex(index - shift);
}

CellIndex CellIndex::operator+(BoardLength shift) const
{
	return CellIndex(index + shift.getLength());
}

CellIndex CellIndex::operator-(BoardLength shift) const
{
	return CellIndex(index - shift.getLength());
}

CellIndex CellIndex::operator+(HintNumber shift) const
{
	return CellIndex(index + shift.getNumber());
}

CellIndex CellIndex::operator-(HintNumber shift) const
{
	return CellIndex(index - shift.getNumber());
}

CellIndex CellIndex::operator++()
{
	index++;
	return *this;
}

CellIndex CellIndex::operator--()
{
	index--;
	return *this;
}

CellIndex CellIndex::operator++(int)
{
	CellIndex temp = *this;
	index++;
	return temp;
}

CellIndex CellIndex::operator--(int)
{
	CellIndex temp = *this;
	index--;
	return temp;
}

bool CellIndex::operator==(const CellIndex &other) const
{
	return index == other.index;
}

bool CellIndex::operator!=(const CellIndex &other) const
{
	return index != other.index;
}

bool CellIndex::operator<(const CellIndex &other) const
{
	return index < other.index;
}

bool CellIndex::operator<=(const CellIndex &other) const
{
	return index <= other.index;
}

bool CellIndex::operator>(const CellIndex &other) const
{
	return index > other.index;
}

bool CellIndex::operator>=(const CellIndex &other) const
{
	return index >= other.index;
}
bool CellIndex::operator<(const BoardLength &other) const
{
	return index < other.getLength();
}

bool CellIndex::operator<=(const BoardLength &other) const
{
	return index <= other.getLength();
}

bool CellIndex::operator>(const BoardLength &other) const
{
	return index > other.getLength();
}

bool CellIndex::operator>=(const BoardLength &other) const
{
	return index >= other.getLength();
}

std::vector<CellIndex> CellIndex::range(int first, int last)
{
	const int minVal = std::min(first, last);
	const int maxVal = std::max(first, last);
	const size_t range_size = maxVal - minVal + 1;
	std::vector<CellIndex> indexes = std::vector<CellIndex>(range_size, CellIndex(0));

	for (int index = 0; index <= maxVal - minVal; index++)
	{
		int value = index + minVal;
		indexes[index] = CellIndex(value);
	}

	if (first > last)
	{
		std::reverse(indexes.begin(), indexes.end());
	}

	return indexes;
}
