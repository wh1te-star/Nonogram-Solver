#ifndef VERSANO_CORE_HINTNUMBER_H
#define VERSANO_CORE_HINTNUMBER_H

namespace VersaNo::Core {

class HintNumber {
  private:
    int number;

  public:
    explicit HintNumber(int number);

    const int &getNumber() const;

    bool operator==(const HintNumber &other) const;
    bool operator!=(const HintNumber &other) const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_HINTNUMBER_H
