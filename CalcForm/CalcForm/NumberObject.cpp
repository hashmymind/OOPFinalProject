#include "NumberObject.h"

//
//
// NumberObject below
//
//

std::ostream& operator<<(std::ostream& stream, const NumberObject& rhs){
    rhs.Output(stream);
    return stream;
}
