#ifndef ISNAPSHOT_H
#define ISNAPSHOT_H

class ISnapshot {
public:
    virtual ~ISnapshot() = default;

    virtual void restore(Board& board) const = 0;
};

#endif