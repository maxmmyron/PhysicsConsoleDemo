#pragma once

#include <GameObject.h>
#include <Vector.h>

class Particle : public GameObject
{
public:
    /************************
        Structs
    *************************/
    struct ParticleArguments
    {
        double radius;
        GameObject::ObjectArguments objectArguments;
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

    /*************************
         Particle Manipulation
    *************************/
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