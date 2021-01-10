#define _USE_MATH_DEFINES

#include <GameObject.h>
#include <Vector.h>
#include <math.h>

class Particle : public GameObject
{
public:

    struct ParticleArguments
    {
        double radius;
        ObjectArguments objectArguments;
    };

    /************************
        Constructors
    *************************/

    Particle() = default;
    Particle(const char*, double, MovementData&, ParticleArguments&);

    /*************************
         Update
    *************************/
    void Update(double);

    void CheckCollisions(Particle&);

    /*************************
        Getters & Setters
    *************************/

    double GetRadius();
    void SetRadius(double);


protected:
    double _radius = 1;

private:
    void ResolveCollision(Particle&, double, double, double, double, double);
    void FixParticlePositions(Particle&, Vector, double);
};