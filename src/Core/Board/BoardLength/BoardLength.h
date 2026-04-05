#ifndef VERSANO_CORE_BOARDLENGTH_H
#define VERSANO_CORE_BOARDLENGTH_H

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

#endif // VERSANO_CORE_BOARDLENGTH_H
