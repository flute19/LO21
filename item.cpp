#include "item.h"

/**Definition of Item's method**/
Litterale& Item::getLitterale() const {
        if (lit == nullptr) throw CalcException("Item : tentative d'acces a une Litterale inexistante");
        return *lit;
}
