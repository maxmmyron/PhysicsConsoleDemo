#include "Particle.h"

/*************************
        Constructors
*************************/

using namespace PhysicsEngine;

Particle::Particle(const char* name, double mass, MovementData& movementData, ParticleArguments& particleArguments)
{
    _name = name;
    _mass = mass;
    _position = movementData.position;
    _velocity = movementData.velocity;
    _acceleration = movementData.acceleration;
    _radius = particleArguments.radius;
    _restitution = particleArguments.objectArguments.restitution;
}

/*************************
        Update
*************************/
void Particle::Update(double dt)
{
    BaseUpdate(dt);
}

void Particle::CheckCollisions(Particle & p)
{
    //get the distance between x and y coords of each particle.

    Vector distBetweenRadii(p._position.x - this->_position.x, p._position.y - this->_position.y);

    //get the distance bewteen the centers of each particle
    double distCenter = sqrt(distBetweenRadii.x * distBetweenRadii.x + distBetweenRadii.y * distBetweenRadii.y);

    //check if dist is less than the sum of the radii
    if (this->_radius + p._radius >= distCenter)
    {
        std::cout << "collision!" << std::endl;
        FixParticlePositions(p, distBetweenRadii, distCenter);
    }
}

/*
        Before the two balls change their trajectories, their velocities must first be updated.
        Otherwise overlaps will slowly get worse and lead to major inconsistencies.
*/
void Particle::FixParticlePositions(Particle & p, Vector distBetweenRadii, double distCenter)
{
    //normalize the vectors between the two circles
    const Vector normalizedDistBetweenRadii(distBetweenRadii.x / distCenter,
        distBetweenRadii.y / distCenter);

    //normalize vectors between circles

    //move each particle away from one another, along the same line between the two centers
    const double grazeDist = distCenter * (this->_radius / (this->_radius + p._radius));

    const Vector contactVector(this->_position.x + normalizedDistBetweenRadii.x * grazeDist,
        this->_position.y + normalizedDistBetweenRadii.y * grazeDist);

    //move each particle back, so they just touch one another
    this->_position.x = contactVector.x - normalizedDistBetweenRadii.x * this->_radius;
    this->_position.y = contactVector.y - normalizedDistBetweenRadii.y * this->_radius;

    //move p2 in the other direction
    p._position.x = contactVector.x + normalizedDistBetweenRadii.x * p._radius;
    p._position.y = contactVector.y + normalizedDistBetweenRadii.y * p._radius;

    /*-------------------------------
    set up collision response below
    -------------------------------*/

    //get the direction and velocity of each particle
    const double v1 = sqrt(this->_velocity.x * this->_velocity.x + this->_velocity.y * this->_velocity.y);
    const double v2 = sqrt(p._velocity.x * p._velocity.x + p._velocity.y * p._velocity.y);

    //get the direction of travel of each a
    const double dir1 = atan2(this->_velocity.y, this->_velocity.x);
    const double dir2 = atan2(p._velocity.y, p._velocity.x);

    //get the direction from the center of p1 to the center of p2
    double contactDirection = atan2(normalizedDistBetweenRadii.y, normalizedDistBetweenRadii.x);

    ResolveCollision(p, v1, v2, dir1, dir2, contactDirection);
}

void Particle::ResolveCollision(Particle & p, double scalarVelocityA, double scalarVelocityB, double movementAngleA, double movementAngleB, double contactDirection)
{

    // The formula of each object's new velocity is
    //
    // For 2D moving objects
    // v1,v2 is velocity
    // this->_mass, p.mass is the mass
    // dirA , dirB is the direction of moment
    // contactDirection is the angle of contact;
    //
    //      v1* cos(d1-p) * (m1 - m2) + 2 * m2 * v2 * cos(d2- p)
    // vx = ----------------------------------------------------- * cos(p) + v1 * sin(d1-p) * cos(p + PI/2)
    //                    m1 + m2
    //      v1* cos(d1-p) * (m1 - m2) + 2 * m2 * v2 * cos(d2- p)
    // vy = ----------------------------------------------------- * sin(p) + v1 * sin(d1-p) * sin(p + PI/2)
    //

    const double massDifference = this->_mass - p._mass;
    const double massSum = this->_mass + p._mass;

    const double v1s = scalarVelocityA * sin(movementAngleA - contactDirection);

    const double c_phi = cos(contactDirection);
    const double s_phi = sin(contactDirection);

    double cdp1 = scalarVelocityA * cos(movementAngleA - contactDirection);
    double cdp2 = scalarVelocityB * cos(movementAngleB - contactDirection);

    const double c_phipi = cos(contactDirection + M_PI_2);
    const double s_phipi = sin(contactDirection + M_PI_2);

    double t = (cdp1 * massDifference + 2 * p._mass * cdp2) / massSum;

    this->_velocity.x = t * c_phi +v1s * c_phipi;
    this->_velocity.y = t * s_phi +v1s * s_phipi;

    contactDirection += M_PI;

    const double v2s = scalarVelocityB * sin(movementAngleB - contactDirection);

    cdp1 = scalarVelocityA * cos(movementAngleA - contactDirection);
    cdp2 = scalarVelocityB * cos(movementAngleB - contactDirection);

    t = (cdp2 * -massDifference + 2 * this->_mass * cdp1) / massSum;

    p._velocity.x = t * -c_phi +v2s * -c_phipi;
    p._velocity.y = t * -s_phi +v2s * -s_phipi;

}

/*************************
        Getters & Setters
*************************/

double Particle::GetRadius()
{
    return _radius;
}

void Particle::SetRadius(double r)
{
    _radius = r;
}