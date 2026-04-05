#ifndef VERSAN_CORE_BOARDLENGTH_H
#define VERSAN_CORE_BOARDLENGTH_H

namespace VersaNo::Core {

class BoardLength {
  protected:
    int length;

  public:
    BoardLength(int length);

  public:
    int getLength() const;
};

} // namespace VersaNo::Core

#endif // VERSAN_CORE_BOARDLENGTH_H
