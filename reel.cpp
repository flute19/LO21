#include "reel.h"

/**Definition of Reel's method**/

LitteraleCalculable& Reel::addition(const LitteraleCalculable& l) const{
    const Reel* ptReel = dynamic_cast<const Reel*>(&l);

    if (ptReel != 0){
        // Reel + Reel
        Reel* res = new Reel(value + ptReel->getValue());
        LitteraleCalculable& ref = *res;
        return ref;
    }
}

//end of file
