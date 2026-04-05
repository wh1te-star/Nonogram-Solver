#include "Core/Board/BoardLength/ColumnLength.h"

#include "Core/Index/CellIndex/ColumnIndex.h"

namespace VersaN::Core {

ColumnLength::ColumnLength(int length) : BoardLength(length) {}

ColumnLength ColumnLength::operator+(ColumnLength length) const {
    return ColumnLength(this->length + length.length);
}

ColumnLength ColumnLength::operator-(ColumnLength length) const {
    return ColumnLength(this->length - length.length);
}

bool ColumnLength::operator==(const ColumnLength& other) const {
	return length == other.length;
}

bool ColumnLength::operator!=(const ColumnLength& other) const {
	return length != other.length;
}

bool ColumnLength::operator<(const ColumnLength& other) const {
	return length < other.length;
}

bool ColumnLength::operator<=(const ColumnLength& other) const {
	return length <= other.length;
}

bool ColumnLength::operator>(const ColumnLength& other) const {
	return length > other.length;
}

bool ColumnLength::operator>=(const ColumnLength& other) const {
	return length >= other.length;
}

bool ColumnLength::operator<(const ColumnIndex& other) const {
	return length < other.getIndex();
}

bool ColumnLength::operator<=(const ColumnIndex& other) const {
	return length <= other.getIndex();
}

bool ColumnLength::operator>(const ColumnIndex& other) const {
	return length > other.getIndex();
}

bool ColumnLength::operator>=(const ColumnIndex& other) const {
	return length >= other.getIndex();
}

} // namespace VersaN::Core