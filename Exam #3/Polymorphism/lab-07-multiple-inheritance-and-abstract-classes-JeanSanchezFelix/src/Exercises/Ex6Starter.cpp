#include "StarterCode.hpp"

/* Collectable Interface */
class Collectable {
  public:
    virtual int getCentury() = 0;

    virtual bool isSuccessful() = 0;

    virtual bool isLegit() = 0;
};

/* Exercise 6A
 * YOU MUST CHANGE THIS BELOW WITH YOUR CURRENT PAINTING CLASS
 * AND IMPLEMENT THE COLLECTABLE METHODS IN PAINTING AFTER THE
 * INHERITING
 */
class Painting {};

/* Exercise 6B
 * YOU MUST CHANGE THIS BELOW WITH YOUR CURRENT SCULPTURE CLASS
 * AND IMPLEMENT THE COLLECTABLE METHODS IN SCULPTURE AFTER THE
 * INHERITING
 */
class Sculpture {};
