#ifndef VERSAN_CORE_PLACEMENTCOUNT_H
#define VERSAN_CORE_PLACEMENTCOUNT_H

namespace VersaN::Core {

class PlacementCount {
  private:
    int count;

  public:
    explicit PlacementCount(int count);

  public:
    PlacementCount operator+(const PlacementCount &other) const;
    PlacementCount operator-(const PlacementCount &other) const;
    PlacementCount &operator+=(const PlacementCount &other);
    PlacementCount &operator-=(const PlacementCount &other);
    bool operator<(const PlacementCount &other) const;
    bool operator>(const PlacementCount &other) const;
    bool operator<=(const PlacementCount &other) const;
    bool operator>=(const PlacementCount &other) const;
    bool operator==(const PlacementCount &other) const;
    bool operator!=(const PlacementCount &other) const;

  public:
    int getCount() const;
    void setCount(PlacementCount placementCount);
};

} // namespace VersaN::Core

#endif // VERSAN_CORE_PLACEMENTCOUNT_H
